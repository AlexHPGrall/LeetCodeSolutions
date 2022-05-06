class Solution {
public:
    bool Dfs(int root, vector<int>& leftChild, vector<int>& rightChild, vector<int> &vis)
    {
        if(root==-1)
            return true;
        if(vis[root])
            return false;
        vis[root]=1;
        return Dfs(leftChild[root],leftChild,rightChild, vis)&&Dfs(rightChild[root],leftChild,rightChild,vis);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n,-1);
        vector<int> vis(n,0);
        int root=-1;
        for(int i=0; i<n;++i)
        {
            if(leftChild[i]!=-1)
            {
                if(parent[leftChild[i]]!=-1)
                    return false;
                parent[leftChild[i]]=i;
            }
            if(rightChild[i]!=-1)
            {
                if(parent[rightChild[i]]!=-1)
                    return false;
                parent[rightChild[i]]=i;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(parent[i]==-1)
            {
                if(root!=-1)
                    return false;
                root=i;
            }
        }
        
        if(!Dfs(root, leftChild, rightChild,vis))
        {
            return false;
        }
        for(int i=0;i<n;++i)
            if(!vis[i])
                return false;
        return true;
    }
};