class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c=='('||c=='['|| c=='{')
                st.push(c);
            else
            {
                if(st.empty())
                    return false;
                int o=st.top();
                st.pop();
                if((c==')' && o=='(') ||(c=='}' && o=='{') ||(c==']' && o=='[') )
                    continue;
                else
                    return false;
            }
                
        }
        return st.empty();
        
    }
};