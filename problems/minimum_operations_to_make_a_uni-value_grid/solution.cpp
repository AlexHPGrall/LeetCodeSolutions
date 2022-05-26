class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> vec;
        int rem=grid[0][0]%x;
        for(auto &v:grid)
        {
            for(int i:v)
            {
                if(i%x!=rem)
                    return -1;
                vec.push_back(i);
            }
        }
        sort(vec.begin(), vec.end());
        int med;
        if(vec.size()%2==0)
            med=(int)round((vec[(vec.size())/2-1]+vec[vec.size()/2])/2);
        else
            med=vec[vec.size()/2];
        int target=med+rem-med%x;
        if(abs(target-med)> abs(target +x -med))
            target+=x;
        if(abs(target-med)>abs(med+rem-med%x-x-med))
            target=med+rem-med%x-x;
        
        int res=0;
        //cout<<med<<endl;
        for(int i:vec)
        {
            res+=abs(i-target)/x;
        }
        return res;
    }
};