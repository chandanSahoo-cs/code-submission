class Node{
public:
    int val;
    Node*next;
    Node(int val){
        this->val =val;
        this->next = nullptr; 
    }
};

class MyLinkedList {
public:
    Node*head;
    int size;
    MyLinkedList() {
        this->head = nullptr;
        this->size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node*temp = head;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node*temp = new Node(val);
        if(head==nullptr){
            head = temp;
        }
        else{
            Node*temp2 = head;
            while(temp2->next){
                temp2=temp2->next;
            }
            temp2->next = temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size || index<0) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        else{
            Node*newNode = new Node(val);
            Node*temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        else if(index==0){
            head = head->next;
        }
        else{
            Node*temp=head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }
            Node*del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
