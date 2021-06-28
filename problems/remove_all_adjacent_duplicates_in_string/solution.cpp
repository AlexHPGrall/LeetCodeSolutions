class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for(char c:s)
        {
            if(!st.empty())
            {
                if(st.back() == c)
                {
                    st.pop_back();
                    continue;
                }
                    
            }
            st.push_back(c);
        }
        string res;
        for(auto c:st)
            res.push_back(c);
        
        return res;
    }
};