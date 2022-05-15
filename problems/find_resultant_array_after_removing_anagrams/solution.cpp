class Solution {
public:

    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> freq(n, vector<int>(26,0));
        
        for(int i=0;i<n;++i)
        {
            for(char c:words[i])
            {
                freq[i][c-'a']++;
            }
        }
        vector<int> st;
        st.push_back(0);
        for(int i=1;i<n;++i)
        {
            
                int j=st.back();
                for(int l=0;l<26;++l)
                {
                    if(freq[j][l]!=freq[i][l])
                    {   
                        //cout<<words[i]<<' '<<words[j]<<' '<<freq[j][l]<<' '<<freq[i][l]<<endl;
                        st.push_back(i);
                        break;
                    }
                }

        }
        vector<string> res;
        for(int i:st)
            res.push_back(words[i]);
        return res;
        
        
    }
};