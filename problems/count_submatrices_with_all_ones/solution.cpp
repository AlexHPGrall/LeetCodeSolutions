class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        vector<int> up(n,0);
        for(int i=0;i<m;++i)
        {
            vector<int> st;
            int left=0;
            for(int j=0; j<n;++j)
            {   int tres=0;
                if(!mat[i][j])
                {st.clear();up[j]=0;left=0;continue;}
                up[j]=1+up[j];
                left++;
                while(!st.empty()&&up[st.back()]>=up[j])
                    st.pop_back();
                int prevIndex=j;
                
                for(int stIndex=st.size()-1;~stIndex;--stIndex )
                {
                    
                    tres+= (prevIndex-st[stIndex])*up[prevIndex] ;
                    prevIndex=st[stIndex];
                }
                
                tres+=up[prevIndex]*(prevIndex-(j-left));  
                st.push_back(j);
                res+=tres ;
                //cout<<tres + 1<<" ";
                
                
            }
            //cout<<endl;
            
        }
        return res;
    }
};