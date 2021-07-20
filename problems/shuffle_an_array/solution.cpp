class Solution {
    vector<int> original;
    int n;
    uint64_t a;
    uint64_t b;
public:
    
    
    Solution(vector<int>& nums) {
        original = nums;
        
        n=nums.size();
        int64_t i =-1;
        a=time(NULL);
        b= time(NULL)+100;
        
        
    }
    
    uint64_t XORShift()
    {
       	uint64_t t = a;
	    uint64_t const s = b;
	    a = s;
	    t ^= t << 23;		// a
	    t ^= t >> 17;		// b
	    t ^= s ^ (s >> 26);	// c
	    b = t;
	    return t + s;


    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return original;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = original;
        for(int i =n-1; i>0; --i)
        {
            int j = XORShift()% (i+1);
            
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */