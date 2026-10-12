class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for (int i = 0; i < q.size() - 1; i++){ // loop one element less than the size of queue so we can read the element to pop and return
            q.push(q.front());
            q.pop();
        }
            int pop_ele = q.front();
            q.pop();
            return pop_ele;
    }
    
    int top() {
        for (int i = 0; i < q.size() - 1; i++){
            q.push(q.front());
            q.pop();
        }
        int top = q.front();
        q.pop();
        q.push(top); // we need to push back the front elements to the queue because we have maintain the order of elements for the algorithm to work in subsequent runs
            return top;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */