class Solution {
public:
    void GetTop(vector<vector<int>> &top)
    {
        vector<vector<int>> top2;
        bool chg=true;
        
        while(chg)
        {
            chg=false;
            top2.clear();
            top2.push_back(top[0]);
            int j =0;
            for(int i=1; i<top.size()-1; ++i)
            {
                int coef1=(top[i+1][1]-top2[j][1])*(top[i][0]-top2[j][0]);
                int coef2=(top[i][1]-top2[j][1])*(top[i+1][0]-top2[j][0]);
                if(coef1<=coef2)
                {
                    top2.push_back(top[i]);
                    ++j;
                }
                else
                    chg=true;
            }
            top2.push_back(top[top.size()-1]);
            swap(top, top2);
        }
    }
    void GetBottom(vector<vector<int>> &top)
    {
        vector<vector<int>> top2;
        bool chg=true;
        
        while(chg)
        {
            chg=false;
            top2.clear();
            top2.push_back(top[0]);
            int j =0;
            for(int i=1; i<top.size()-1; ++i)
            {
                int coef1=(top[i+1][1]-top2[j][1])*(top[i][0]-top2[j][0]);
                int coef2=(top[i][1]-top2[j][1])*(top[i+1][0]-top2[j][0]);
                if(coef1>=coef2)
                {
                    top2.push_back(top[i]);
                    ++j;
                }
                else
                    chg=true;
            }
            top2.push_back(top[top.size()-1]);
            swap(top, top2);
        }
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        sort(trees.begin(), trees.end(), [](const vector<int> &a,const vector<int> &b)
             {
                 return (a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]));
             });
        vector<vector<int>> top;
        vector<vector<int>> bottom;
        bottom.push_back(trees[0]);
        for(int i=1; i<n; ++i)
        {
            while(i<n && trees[i][0] ==trees[i-1][0])
                ++i;
            if(i<n)
            {
                top.push_back(trees[i-1]);
                bottom.push_back(trees[i]);
            }
                
        }
        
        top.push_back(trees[n-1]);
        
        GetTop(top);
        
        GetBottom(bottom);
        set<vector<int>> res;
        vector<vector<int>> ans;
        
        for(int i=0; i<n &&trees[i][0] == trees[0][0];++i)
            res.insert(trees[i]);
        for(int i=1; i<top.size()-1;++i)
            res.insert(top[i]);
        for(int i=1; i<bottom.size()-1;++i)
            res.insert(bottom[i]);
        for(int i=n-1; i>=0 &&trees[i][0] == trees[n-1][0];--i)
            res.insert(trees[i]);
       
        for(vector<int> v:res)
            ans.push_back(v);
        
        return ans;
    }
};