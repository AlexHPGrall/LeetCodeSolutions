class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int dist=INT_MAX;
        for(int i=1; i<n;++i)
        {
            dist=min(dist,arr[i]-arr[i-1]);
        }
        vector<vector<int>>res;
        cout<<dist<<endl;
        for(int i=1;i<n;++i)
        {
            if(arr[i]-arr[i-1] == dist)
            {
                res.push_back({arr[i-1],arr[i]});
            }
                
        }
        return res;
    }
};