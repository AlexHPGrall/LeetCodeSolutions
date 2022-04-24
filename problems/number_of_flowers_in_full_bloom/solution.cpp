class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start,end;
        vector<int> res;
        for(auto &f:flowers)
        {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(int p:persons)
        {
            auto it=upper_bound(start.begin(), start.end(),p);
            int tmp = distance(start.begin(), it);
            //cout<<tmp<<endl;
            it=lower_bound(end.begin(), end.end(),p);
            tmp-=distance(end.begin(), it);
            res.push_back(tmp);
        }
        return res;
    }
};