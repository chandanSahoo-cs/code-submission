class LRUCache {
public:
    struct Node {
        int key,value;
        Node*next=nullptr;
        Node*prev=nullptr;
        Node(int k,int v) : key(k),value(v),next(nullptr),prev(nullptr){};
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int k;


    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        this->k=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void moveToTail(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;

        node->prev=tail->prev;
        tail->prev->next=node;
        node->next=tail;
        tail->prev=node;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            moveToTail(mp[key]);
            return mp[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->value = value;
            moveToTail(mp[key]);
        }
        else{
            if(mp.size()==k){
                mp.extract(head->next->key);
                head->next->next->prev = head;
                head->next= head->next->next;
            }
            Node* newNode = new Node(key,value);
            mp[key] = newNode;
            newNode->prev = tail->prev;
            newNode->next = tail;
            tail->prev->next=newNode;
            tail->prev=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
