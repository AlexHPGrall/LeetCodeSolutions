class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c:s)
        {
            if(!st.empty() && st.top().first == c)
                st.top().second++;
            else
                st.push({c,1});
            if(!st.empty() && st.top().second==k)
            {
                st.pop();
            }
        }
        string res;
        for(;!st.empty();)
        {
            //cout<<st.top().first<<endl;
            for(int i=0;i<st.top().second;++i)
                res.push_back(st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};