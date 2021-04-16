class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
        char p=(char) 0;
        for(int i =0; i<s.length(); ++i)
        {
            if(i>0 && s[i] == s[i-1])
            {
                st.top()++;
                if(st.top() == k)
                {
                    s.erase(i+1 - k, k);
                    i = i-k;
                    st.pop();
                }
            }
                
            else
                st.push(1);
        }
        return s;
    }
};