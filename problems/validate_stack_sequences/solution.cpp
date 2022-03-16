class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        int i=0, j=0;
        int n=pu.size();
        stack<int> st;
        while(j<n)
        {
            
            while(i<n && (st.empty() || po[j]!=st.top()))
            {
                st.push(pu[i]);
                ++i;
            }
            if(i>=n && (st.empty() || po[j]!=st.top()))
                return false;
            st.pop();
            ++j;
        }
        return true;
    }
};