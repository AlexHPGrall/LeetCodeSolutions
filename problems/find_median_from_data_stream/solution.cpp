class MedianFinder {
    vector<int> nums;
    int n;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        int i=0;
        while(i<n && num>nums[i])
            ++i;
        nums.insert(nums.begin() + i, num);
        n++;
    }
    
    double findMedian() {
    
        if(n&1)
            return (double)nums[n/2];
        else
        {
            return (double)(nums[n/2] +nums[(n/2)-1])/2.0f;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */