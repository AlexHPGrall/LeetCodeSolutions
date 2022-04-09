class Solution {
public:
    vector<vector<int>> dep;
    bool findP(vector<vector<int>> &graph, int node, int target)
    {
        
        if(graph[node].empty())
            return false;
        if(dep[target][node]!=-1)
            return dep[target][node];
        bool res=false;
        for(int p:graph[node])
        {
            
            if(p==target)
            {res= true;break;}
            res= res || findP(graph, p, target);
        }
            dep[target][node]=res;
            
            return res;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        dep.resize(numCourses, vector<int>(numCourses,-1));
        for(vector<int> &v:prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            dep[v[0]][v[1]]=1;
        }
        vector<bool> res;
        for(vector<int> &q:queries)
        {
            res.push_back(findP(graph, q[1], q[0]));
        }
        return res;
    }
};