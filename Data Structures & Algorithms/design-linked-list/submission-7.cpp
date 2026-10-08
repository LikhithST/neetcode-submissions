class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val): val(val), next(nullptr){};
    };

public:
    ListNode* head;
    int size;
    
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        ListNode* cur = head->next;
        for (int i = 0; i < index ; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node; 
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = new ListNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode* cur = head;
        ListNode* node = new ListNode(val);
        for(int i = 0; i < index; i++ ){
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
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