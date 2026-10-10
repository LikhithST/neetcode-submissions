class Deque {
    struct QueueNode{
        int val;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(int val): val(val), next(nullptr),prev(nullptr){};
    };
public:
        QueueNode* head;
        QueueNode* tail;
    Deque() {
        head =  new QueueNode(0);
        tail = new QueueNode(0);
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        if (head->next == tail) return true;
        return false;
    }

    void append(int value) {
        QueueNode* node = new QueueNode(value);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

    void appendleft(int value) {
        QueueNode* node = new QueueNode(value);
        node->prev = head;
        node->next = head->next; 
        head->next->prev = node;
        head->next = node;
    }

    int pop() {
        if (isEmpty()) return -1;
        QueueNode* pop = tail->prev;
        int pop_val = pop->val;
        tail->prev = pop->prev;
        pop->prev->next = tail;
        delete pop;
        return pop_val;
    }

    int popleft() {
        if (isEmpty()) return -1;
        QueueNode* popleft = head->next;
        int popleft_val = popleft->val;
        head->next = popleft->next;
        popleft->next->prev = head;
        delete popleft;
        return popleft_val;
    }
};
