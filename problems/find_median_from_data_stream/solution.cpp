class MedianFinder {
    priority_queue<int, vector<int>, less<int>> low;
    priority_queue<int, vector<int>, greater<int>> high;
    int n;
public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        ++n;
        if(low.empty()|| num<=low.top())
            low.push(num);
        else
            high.push(num);
        while(low.size()>((n+1)/2))
        {
            high.push(low.top());
            low.pop();
        }
        while(high.size()>n/2)
        {
            low.push(high.top());
            high.pop();
        }

    }
    
    double findMedian() {
        if(low.size()==high.size())
            return ((double)low.top()+(double)high.top())/2.0f;
        else
            return low.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */