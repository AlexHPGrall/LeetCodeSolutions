class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for(string &w:words)
        {
            string even, odd;
            for(int i=0; i<w.size();++i)
            {
                if(i&1)
                    odd.push_back(w[i]);
                else
                    even.push_back(w[i]);    
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            st.insert(even+odd);
        }
        return st.size();
    }
};