class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val): val(val), next(nullptr), prev(nullptr){};
    };

public:
    ListNode* head;
    ListNode* tail;
    int size;
    
    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

     ListNode* getCur(int index){
        if (index >= size/2){
        ListNode* cur = tail;
        for( int i = 0 ; i < size - index ; i++ ){
            cur = cur->prev;
        } 
        return cur;
        }
        else {
        ListNode* cur = head;
        for(int i = 0; i <= index; i++ ){
            cur = cur->next;
        }
        return cur;
        }
    }
    
    int get(int index) {
        if (index >= size) return -1;
        return getCur(index)->val;
    }

   
    
    void addAtHead(int val) {
        addAtIndex(0, val); 
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode* node = new ListNode(val);
        ListNode* cur = getCur(index);
        node->next = cur;
        node->prev = cur->prev;
        cur->prev = node;
        node->prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* cur = getCur(index);
        
        ListNode* temp = cur;
        ListNode* prev = cur->prev;
        cur = cur->next;
        cur->prev = prev;
        prev->next = cur;
        delete temp;
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