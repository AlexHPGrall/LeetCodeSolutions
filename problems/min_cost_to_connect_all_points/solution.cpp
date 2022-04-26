class Solution {
public:
    int parent[1000]={};
    int size[1000]={};
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        parent[x]=parent[parent[x]];
        return find(parent[x]);
    }
    void merge(int x, int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
            return;
        if(size[x]>=size[y])
        {
            parent[y]=x;
            size[x]+=size[y];
        }
        else
        {
            parent[x]=y;
            size[y]+=size[x];
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0; i<n;++i)
        {
            parent[i]=i;
            size[i]=1;
        }
        auto cmp = [](pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
        {
            return p1.first>p2.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        int res=0;
        while(size[find(0)] !=n)
        {
            auto [d,p]=pq.top();
            auto [i, j]=p;
            pq.pop();
            if(find(i)!=find(j))
            {
                res+=d;
                merge(i,j);
            }
            
        }
        return res;
    }
};