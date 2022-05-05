class MyStack {
    queue<int> q;
    int qtop;
public:
    
    MyStack() {
        
    }
    
    void push(int x) {
        qtop=x;
        q.push(x);
    }
    
    int pop() {
        int n=q.size();
        int x;
        for(int i=1;i<n;++i)
        {
            x=q.front();
            if(i==n-1)
                qtop=x;
            q.pop();
            q.push(x);
        }
        x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return qtop;
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