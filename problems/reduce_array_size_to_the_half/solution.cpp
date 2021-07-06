class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i:arr)
        {
            ++mp[i];
        }
        vector<int> val;
        for(auto p:mp)
        {
            val.push_back(p.second);
        }
        sort(val.begin(), val.end());
        int sum=0, res=0;
        for(int i=val.size()-1; i>=0; --i)
        {
            sum += val[i];
            res++;
            if(sum>= n/2)
                return res;
        }
        return res;
    }
};