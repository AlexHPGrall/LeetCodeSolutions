class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        for(char c : s)
        {
            if(c==')')
            {
              int sum=0;
                while(st.top()!=-1)
                {
                    sum+=st.top();
                    st.pop();
                }
                st.pop();
                if(!sum)
                    st.push(1);
                else
                    st.push(2*sum);
            }
                
            else
            {
                st.push(-1);
            }
                
        }
        int res=0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};