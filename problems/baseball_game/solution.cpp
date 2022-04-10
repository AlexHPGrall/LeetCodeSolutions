class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for(string &s:ops)
        {
            char c=s[0];
            
                
            switch(c)
            {
                case '+':
                    st.push_back(st.back() +*(st.rbegin()+1));
                    break;
                case 'C':
                    st.pop_back();
                    break;
                case 'D':
                    st.push_back(2*st.back());
                    break;
                default:
                    st.push_back(stoi(s));
                    break;
            }
            //cout<<st.back()<<endl;
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};