class MyQueue {
    stack<int> pushStack,popStack;
public:
    MyQueue() {
        
    }
    void fillStack()
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        if(popStack.empty())
        {
            fillStack();
        }
        int res=popStack.top();
        popStack.pop();
        return res;
    }
    
    int peek() {
        if(popStack.empty())
            fillStack();
        return popStack.top();
        
    }
    
    bool empty() {
        return (popStack.empty() && pushStack.empty());
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */