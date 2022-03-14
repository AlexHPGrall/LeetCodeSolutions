class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        while(n>1 && path[n-1]=='/')
            n--;
        vector<int> st;
        st.push_back(0);

        
        for(int i=0;i<n;)
        {
            //cout<<i<<endl;
            while(i<n && path[i]=='/')
                ++i;
            st.push_back(i);
            
            int dotCount=0;
            while(i<n&& path[i]=='.')
            {++dotCount;++i;}
            if(i<n&&path[i]!='/')
                dotCount=0;
            if(dotCount ==1||dotCount==2)
            {
                if(st.size()>1)
                    st.pop_back();
                
            }
            if(dotCount==2)
            {
                if(st.size()>1)
                    st.pop_back();   
            }
            while(i<n&&path[i]!='/')
                ++i;
        }
        string res;
        
        for(int i=0;i<st.size();++i)
        {
            int j=st[i];
           
            
            if(j==0)
            {continue;}
             res.push_back('/');
            while( j<n && path[j]!='/')
            {
                
                res.push_back(path[j]);
                j++;
            }
           
            
        }
    if(res.empty())
        return "/";
      return res;
    }
};