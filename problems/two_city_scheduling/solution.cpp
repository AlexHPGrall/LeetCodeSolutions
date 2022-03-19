class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(),costs.end(),[](vector<int> &a, vector<int> &b){return abs(a[0]-a[1])>abs(b[0]-b[1]);});
        int a=0,b=0, sum=0;
        int n=costs.size();
        for(vector<int> &v:costs)
        {
            //cout<<v[0]<<' '<<v[1]<<' '<<abs(v[0]-v[1])<<endl;
            if(a==n/2)
                sum+=v[1];
            else if(b==n/2)
                sum+=v[0];
            else
            {
                if(v[0]>v[1])
                {++b; sum+=v[1];}
                else
                {++a; sum+=v[0];}
            }
        }
        return sum;
        
    }
};