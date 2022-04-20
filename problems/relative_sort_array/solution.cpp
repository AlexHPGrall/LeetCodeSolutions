class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>index;
        for(int i=0; i<arr2.size(); ++i)
        {
            index[arr2[i]]=i;
        }
        sort(arr1.begin(), arr1.end(), [&index](int a, int b){
            if(!index.count(a) && !index.count(b))
                return a<b;
            if(!index.count(a))
                return false;
            if(!index.count(b))
                return true;
            return index[a]<index[b];
        });
        return arr1;
    }
};