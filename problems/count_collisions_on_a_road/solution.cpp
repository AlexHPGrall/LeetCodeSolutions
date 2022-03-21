class Solution {
public:
    int countCollisions(string dir) {
        int i=0;
        while(dir[i]=='L')
            ++i;
        stack<char> st;
        int res=0;
        int n=dir.size();
        while(i<n)
        {
            if(dir[i]=='R')
            {
                st.push(dir[i]);
            }
            else if(dir[i]=='S')
            {
                while(!st.empty() && st.top()!='S')
                {st.pop();++res;}
                if(st.empty())
                    st.push('S');
            }
            else
            {
                if(st.top()=='R')
                {
                    res+=2;
                    st.pop();
                    while(!st.empty() && st.top()!='S')
                    {st.pop();++res;}
                    if(st.empty())
                        st.push('S');
                }
                else
                    res++;
                
                
                
            }
            ++i;

        }
        return res;
    }
};