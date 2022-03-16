class Solution {
public:
    int p[1001];
    int size[1001];
    vector<unordered_set<int>> fbd;

    int find(int x)
    {
        if(p[x]==x)
            return x;
        else
            p[x]=p[p[x]];
        return find(p[x]);
    }
    void merge(int x, int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            if(size[x]<size[y])
            {p[x]=y; size[y]+=size[x];
             for(int z:fbd[x])
                fbd[find(x)].insert(z);
            }
            else
            {
            for(int z:fbd[y])
                fbd[find(x)].insert(z);
                p[y]=x; size[x]+=size[y];
            }
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        for(int i=0; i<n;++i)
        {
            p[i]=i;
            size[i]=1;
        }
        fbd.resize(n);
        for(auto &res:restrictions)
        {
            fbd[res[0]].insert(res[1]);
            fbd[res[1]].insert(res[0]);
        }
        vector<bool> result;
        for(auto &req:requests)
        {
            int x=find(req[0]);
            int y=find(req[1]);
            for(int z:fbd[x])
                if(find(z)==y)
                {
                    result.push_back(false);
                    goto end;
                }
            for(int z:fbd[y])
                if(find(z)==x)
                {
                    result.push_back(false);
                    goto end;
                }
            merge(x,y);
            result.push_back(true);
            end:;
        
                    
        }
        return result;
    }
};