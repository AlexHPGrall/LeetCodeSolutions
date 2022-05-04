class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int &n:arr)
        {   
            if(n>=0)
                n%=k;
            else
                n=(k-(-n%k))%k;
            freq[n]++;
            //cout<<n<<endl;
        }
        for(auto &[key, val]: freq)
        {
            if(key==0 || 2*key==k)
            {
                if(val%2==1)
                {
                    return false;
                }
            }
            else
            {
                if(!freq.count(k-key) || val!=freq[k-key])
                    return false;
            }
        }
        return true;
        
    }
};