class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n= arr.size();
        vector<int> vis(n,0);
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n;++i)
        {
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q1,q2;
        q1.push(0);
        vis[0]=1;
        int jmps=0;
        while(!q1.empty())
        {
            int i=q1.front();
            q1.pop();
            if(i==n-1)
                return jmps;
            if(i-1>=0 && !vis[i-1])
            {
                vis[i-1] =1;
                q2.push(i-1);
            }
            if(i+1<n && !vis[i+1])
            {
                vis[i+1] =1;
                q2.push(i+1);
            }
            
            for(int j : mp[arr[i]])
            {
                if(!vis[j])
                {
                    vis[j] =1;
                    q2.push(j);
                }
            }
            mp[arr[i]].clear();
            if(q1.empty())
            {
                swap(q1,q2);
                jmps++;
                //cout<<endl;
            }
        }
        
        return jmps;
    }
};