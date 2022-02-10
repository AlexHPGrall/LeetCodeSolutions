class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr2.size();++i)
            mp[arr2[i]]=i;
        sort(arr1.begin(), arr1.end(), [&mp](int a, int b) {
            if(!mp.count(a))
            {
                if(!mp.count(b))
                 return a<b;
                else
                    return false;
            }
            if(!mp.count(b))
                return true;
            return mp[a] < mp[b];
    });
        
        return arr1;
    }
};