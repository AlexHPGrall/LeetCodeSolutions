class FreqStack {
public:
    unordered_map<int, stack<int>> group;
    unordered_map<int ,int> freq;
    int maxfreq;
    FreqStack() {
        maxfreq=0;
    }

    void push(int val) {
        freq[val]++;
        if(freq[val]>maxfreq)
            maxfreq=freq[val];
        group[freq[val]].push(val);
    }
    
    int pop() {
        int res=group[maxfreq].top();
        group[maxfreq].pop();
        if(group[maxfreq].empty())
            maxfreq--;
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