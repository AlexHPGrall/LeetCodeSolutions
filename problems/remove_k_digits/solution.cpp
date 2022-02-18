class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        int n=num.size();
        if(k==n)
            return "0";
        for(int i=0;i<n;++i)
        {       
            //cout<<i<<" "<<st.size()<<endl;
            if(st.size() + (n-i) == n-k)
            {
                while(i<n)
                {
                    st.push_back(num[i]);
                    ++i;
                }
                break;
            }
            
            while(!st.empty() && st.back()>num[i] && st.size()+n-i !=n-k)
            {
                st.pop_back();
            }
            st.push_back(num[i]);
        }
         while(!st.empty() && st.size()>n-k)
            {
                st.pop_back();
            }
        string res;
        int i=0;
        
        while(i<st.size() && st[i]=='0')
            ++i;
        while(i<st.size())
        {
            res.push_back(st[i]);
            ++i;
        }
         
        if(res.empty())
            res="0";
        return res;
    }
};