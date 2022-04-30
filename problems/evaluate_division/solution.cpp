class Solution {
public:
    int parent[40]={};
    double weight[40]={};
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        else
        {   
            int p=parent[x];
            parent[x]=find(parent[x]);
            weight[x]*=weight[p];
            
            
        }
        return parent[x];
    }
    void merge(int x, int y, double val)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
            return;
        parent[px]=py;
        weight[px]=val*(weight[y]/weight[x]);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> Nodes;
        int nodeCount=0;
        int i=0;
        for(auto &eq:equations)
        {
            string a=eq[0], b=eq[1];
            if(!Nodes.count(a))
            {
                Nodes[a]=nodeCount++;
                parent[Nodes[a]]=Nodes[a];
                weight[Nodes[a]]=1.0f;
            }
            if(!Nodes.count(b))
            {
                Nodes[b]=nodeCount++;
                parent[Nodes[b]]=Nodes[b];
                weight[Nodes[b]]=1.0f;
            }
            merge(Nodes[a], Nodes[b], values[i]);
            //cout<<a<<' '<<b<<' '<<weight[Nodes[a]]<<' '<<weight[Nodes[b]]<<endl;
            ++i;
        }
      
        vector<double> res;
        for(auto &q:queries)
        {
            if(!Nodes.count(q[0])||!Nodes.count(q[1]))
            {
                res.push_back(-1.0f);
                continue;
            }
            int a=Nodes[q[0]];
            int b=Nodes[q[1]];
            if(find(a)!=find(b))
            {
                res.push_back(-1.0f);
                continue;
            } 
            res.push_back(weight[a]/weight[b]);
        }
        return res;
    }
};