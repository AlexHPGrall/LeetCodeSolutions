class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(st.empty())
            {
                if(c=='a')
                    st.push(c);
                else
                    return false;
            }
            else if(c=='b')
            {
                if(st.top()=='a')
                    st.push(c);
                else 
                    return false;
            }
            else if(c=='c')
            {
                if(st.top()=='b')
                {
                    st.pop();
                    st.pop();
                }
                else
                    return false;
            }
            else
                st.push(c);
            
        }
        return st.empty();
    }
};