class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st, op;
        for(char c: expression)
        {
            if(c == ')')
            {
                bool tmp=st.top()=='t';
                if(op.top()=='!')
                    tmp= !(tmp);
                st.pop();
                while(st.top()!= '(')
                {
                    if(op.top()=='|')
                        tmp=tmp|| (st.top()=='t');
                    if(op.top()=='&')
                        tmp=tmp && (st.top()=='t');
                    st.pop();
                }
                st.pop();
                op.pop();
                if(tmp)
                    st.push('t');
                else
                    st.push('f');
            }
            else if(c== '&' || c=='|' || c=='!')
                op.push(c);
            else if(c==',')
                continue;
            else st.push(c);
        }
        
        return (st.top()=='t');
    }
};