class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(), people.end(), [](const auto&a, const auto &b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return a[0]<b[0];
             });
        vector<vector<int>> res(n, vector<int>(2,-1));
        for(int i=0; i<n;++i)
        {
            int j=-1,k=0;
            while(j<people[i][1])
            {
                
                if(res[k][0]!=-1 && res[k][0]<people[i][0])
                {++k;continue;}
                ++k;
                ++j;
            }
            //cout<<k<<endl;
            res[k-1]=people[i];
        }
        return res;
    }
};