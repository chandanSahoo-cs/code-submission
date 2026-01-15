struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value): key(key), value(value), next(nullptr), prev(nullptr){};
};

class LRUCache {
public:
    int sz;
    Node* tail;
    Node* dummy;

    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        sz=capacity;
        tail = new Node(-1,-1);
        dummy = tail;
    }

    void update(int key,int value){
        Node* temp = mp[key];

        if(temp!=dummy){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            dummy->next = temp;
            temp->next = nullptr;
            temp->prev = dummy;
            dummy = dummy->next;
        }

        temp->value = value;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            update(key,mp[key]->value);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.size()==sz && mp.find(key)==mp.end()){
            tail=tail->next;
            mp.erase(tail->key);
        }

        if(mp.find(key)!=mp.end()){
            update(key,value);
        }else{
            Node* newNode = new Node(key,value);

            dummy->next = newNode;
            newNode->prev = dummy;
            dummy = dummy->next;

            mp[key]=newNode;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
