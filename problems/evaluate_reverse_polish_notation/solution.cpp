class Solution {
public:
    string calc(string left, string right, string op)
    {
        int l =stoi(left);
        int r= stoi(right);
        if(!op.compare("+"))
            l+=r;
        else if(!op.compare("-"))
            l-=r;
        else if(!op.compare("*"))
            l*=r;
        else
            l= l/r;
        
        return to_string(l);
        }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s :tokens)
        {
             
            if(!(s.compare("+") && s.compare("-") && s.compare("*") && s.compare("/")))
            {
                string r = st.top();
                st.pop();
                string l = st.top();
                st.pop();
                st.push(calc(l, r, s));
            }
            else
                st.push(s);
        }
        return stoi(st.top());
    }
};