class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st;
        int freq[26]={0}, count[26]={0};
        for(char c:s)
        {
            freq[c-'a']++;
        }
        for(int i=0;i<s.length();++i)
        {
            if(count[s[i]-'a'])
            {freq[s[i]-'a']--;continue;}
            while(!st.empty() && st.back()>s[i])
            {
                if(freq[st.back()-'a'] ==0)
                    break;
                count[st.back()-'a']--;
                st.pop_back();
            }
            count[s[i]-'a']++;
            freq[s[i]-'a']--;
            st.push_back(s[i]);
        }

        return st;
    }
};