struct query
{
    int l;
    int s;
    int d;
    int index;
};
int find(int x, vector<int> &p)
{
    while(p[x]!=x)
    {
        p[x]=p[p[x]];
        x=p[x];
    }
    return x;
}
void merge(int x, int y, vector<int> &p, vector<int> &w)
{
    x=find(x,p);
    y=find(y,p);
    if(x==y)
        return;
    if(w[x]>w[y])
        p[y]=x;
    else
        p[x]=y;
}
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<query> vq;
        int i=0;
        
        for(auto &e:edgeList)
        {
            vq.push_back({e[2], e[0], e[1], -1 });
        }
        for(int i=0; i<queries.size();++i)
        {
            auto e=queries[i];
            vq.push_back({e[2]-1, e[0], e[1], i });
        }
        sort(vq.begin(), vq.end(), [](query a, query b){if(a.l!=b.l)return a.l<b.l;return a.index<b.index;});
        vector<int> p(n);
        vector<int> w(n);
        for(int i=0; i<n;++i)
        {p[i]=i; w[i]=1;};
        vector<bool> res(queries.size());
        for(auto &q:vq)
        {
            //cout<<q.l<<' '<<q.s<<' '<<q.d<<' '<<q.index<<endl;
            if(q.index==-1)
            {
                merge(q.s, q.d, p, w);
            }
            else
            {
                if(find(q.s, p) == find(q.d,p))
                    res[q.index]=true;
                else
                    res[q.index]=false;
                //cout<<res[q.index]<<endl;
            }
            
        }
        return res;
    }
};