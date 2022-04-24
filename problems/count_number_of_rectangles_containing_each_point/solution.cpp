class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> mp(101);
        sort(rectangles.begin(), rectangles.end());
        vector<int> res;
        for(auto &rec:rectangles)
        {
            for(int i=1; i<=rec[1];++i)
                    mp[i].push_back(rec[0]);
        }
        /*
        for(int i=1;i<=5;++i)
        {for(int n:mp[i])
                cout<<n<<' ';
         cout<<endl;
        }*/
        for(auto &p:points)
        {
            int sum=0;
            int i=p[1];
            auto it=lower_bound(mp[i].begin(), mp[i].end(), p[0]);
            //cout<<distance(it, mp[i].end())<<endl;
            sum+=distance(it, mp[i].end());
            res.push_back(sum);
        }
        return res;
            
    }
};