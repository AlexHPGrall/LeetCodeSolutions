class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>>mp;
    int maxFreq=0;
public:
    FreqStack() {

    }
    
    void push(int val) {
        //cout<<val<<endl
        freq[val]++;
        mp[freq[val]].push(val);
        maxFreq=max(maxFreq, freq[val]);
        //cout<<maxFreq<<endl;
    }
    
    int pop() {
        //cout<<maxFreq<<endl;
        if(mp[maxFreq].empty())
          maxFreq--;
        int res=mp[maxFreq].top();
        mp[maxFreq].pop();
        freq[res]--;
        return res;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */