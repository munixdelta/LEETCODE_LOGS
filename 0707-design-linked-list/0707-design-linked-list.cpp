class MyLinkedList {
    struct Node{
        int data;
        Node* next;

        Node(int val,Node* nextnode){
            data=val;
            next=nextnode;
        }
    };
    Node* head;
    int size;
public:
    MyLinkedList() {
        head=nullptr;
        size=0; 
    }
    
    int get(int index) {
        if(index<0 || index>=size)return -1;
        Node* current=head;
        for(int i=0;i<index;i++){
            current=current->next;
        }
        return current->data;
    }
    
    void addAtHead(int val) {
        Node* newnode=new Node(val,head);
        head=newnode;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size)return;
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* prev=head;
        for(int i=0;i<index-1;i++){
            prev=prev->next;
        }
        Node* newnode=new Node(val,prev->next);
        prev->next=newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size)return;
        if(index==0){
            Node* oldhead=head;
            head=head->next;
            delete oldhead;
        }
        else{
            Node* prev=head;
            for(int i=0;i<index-1;i++){
                prev=prev->next;
            }
            Node* nodetodel=prev->next;
            prev->next=nodetodel->next;
            delete nodetodel;
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