class Solution {
public:
    int res=0;
    int DFS(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &len,string &s)
    {
        if(vis[i])
            return len[i];
        vis[i]=1;
        int p1=0;
        int n1=-1;
        int p2=0;
        int n2=-1;
        for(int nei:graph[i])
        {
            if(s[nei]!=s[i])
            {
                int tmp=DFS(nei,graph, vis, len,s);
                if(tmp>p1)
                {
                    p2= p1;
                    n2=n1;
                    p1=tmp;
                    n1=nei;
                }
                else if(tmp > p2 && nei != n1)
                {
                    p2=tmp;
                    n2=nei;
                }
            }
        }
        
        len[i]=p1+1;
        res=max(res,p1+p2+1);
        return p1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(s.size());
        for(int i=1; i<parent.size();++i)
        {
            //graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        
       vector<int> vis(s.size(),0); 
        vector<int> len(s.size(),0); 
        for(int i=0; i<s.size();++i)
        {
            if(vis[i])
                continue;
            DFS(i, graph, vis, len,s);
        }
        return res;
    }
};