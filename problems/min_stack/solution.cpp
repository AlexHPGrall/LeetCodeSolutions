class MinStack {
    int stck[30000];
    int stcktop =0;
    int stckmin[30000];
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        stck[stcktop++] =val;
        if(stcktop ==1)
            stckmin[stcktop]=val;
        else
            stckmin[stcktop] =min(stckmin[stcktop-1],val);
    }
    
    void pop() {
        stcktop--;
    }
    
    int top() {
        return stck[stcktop-1];
    }
    
    int getMin() {
        return stckmin[stcktop];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */