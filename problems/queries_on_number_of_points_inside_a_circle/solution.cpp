class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto &q:queries)
        {
            int r=q[2]*q[2];
            int cnt=0;
            for(auto &p:points)
                cnt +=((p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]) <=r);
            res.push_back(cnt);
        }
        return res;
    }
};