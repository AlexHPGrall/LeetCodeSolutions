class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int>size;
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
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        set<int> indices;
        for(auto &p:pairs)
        {
            if(!parent.count(p[0]))
            {
                parent[p[0]]=p[0];
                size[p[0]]=1;
            }
            if(!parent.count(p[1]))
            {
                parent[p[1]]=p[1];
                size[p[1]]=1;
            }
            merge(p[0],p[1]);
            indices.insert(p[0]);
            indices.insert(p[1]);
        }
        unordered_map<int, string> mp;
        for(int i:indices)
        {
            mp[find(i)].push_back(s[i]);
        }
        for(auto &[key, w]:mp)
        {
            //cout<<w<<endl;
            sort(w.begin(), w.end(), greater<char>{});
        }
        
        for(int i:indices)
        {
                s[i]=mp[find(i)].back();
                mp[find(i)].pop_back();
        }
        return s;
    }
};