class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<int> vis(n+1,0);
        unordered_map<int, vector<vector<int>>> mp;
        for(vector<int> v:times)
        {
            mp[v[0]].push_back({v[1],v[2]});
        }
        vector<int> st;
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        st.push_back(k);
        vis[k] = 1;
        while(!st.empty())
        {
            int currNode=st.back();
            st.pop_back();
            vis[currNode]=1;
            for(vector<int> v:mp[currNode])
            {
                int next=v[0];
                int currdist=v[1];
                if(dist[next]>dist[currNode]+currdist)
                {
                    dist[next]=dist[currNode]+currdist;
                    st.push_back(next);
                }
            }
        }
        for(int i=1;i<n+1;++i)
            if(vis[i]==0)
                return -1;
        int res=0;
        for(int i=1;i<n+1;++i)
        {
            res=max(res, dist[i]);
        }
        
        return res;
    }
};