struct Node {
    int key;
    int value;
    Node*prev;
    Node*next;

    Node(int key, int value):key(key),value(value),prev(nullptr),next(nullptr){};
};



class LFUCache {
public:
    unordered_map<int,int>freq;
    unordered_map<int,Node*>store;
    unordered_map<int,pair<Node*,Node*>>list;

    int mn;
    int sz;

    LFUCache(int capacity) {
        mn = 0;
        sz = capacity;
    }

    void place(Node* temp, int ind){
        Node* head;
        Node* tail;

        if(list.find(ind)==list.end()){
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;

            list[ind]={head,tail};
        }else{
            auto p = list[ind];
            head = p.first;
            tail = p.second;
        }

        tail->prev->next=temp;
        temp->prev=tail->prev;
        temp->next=tail;
        tail->prev=temp;
    }

    void update(int key,int value){
        Node*temp = store[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next=temp->prev=nullptr;

        temp->value = value;
        int oldFreq = freq[key];
        int ind = ++freq[key];
        place(temp,ind);

        if(list[oldFreq].first->next==list[oldFreq].second && mn==oldFreq){
            mn++;
        }
    }

    void remove(){
        if(list.find(mn)==list.end()) return;
        int ind = mn;

        auto [head,tail] = list[ind];
        int key = head->next->key;
        Node* temp = store[key];
        store.erase(key);
        freq.erase(key);

        head->next=temp->next;
        temp->next->prev=head;

        if(head->next==tail) mn++;
    }
    
    int get(int key) {
        if(store.find(key)!=store.end()){
            update(key,store[key]->value);
            return store[key]->value;
        };
        return -1;
    }
    
    void put(int key, int value) {
        if(store.size()==sz && store.find(key)==store.end()) remove();

        if(store.find(key)!=store.end()){
            update(key,value);
        }else{
            Node* newNode = new Node(key,value);
            freq[key]++;
            mn = freq[key];

            place(newNode,freq[key]);
            store[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
