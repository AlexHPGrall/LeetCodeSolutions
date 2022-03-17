class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res(s.length()+spaces.size(),' ');
        int offset=0;
       
        for(int i=0,j=0; i<s.length(); ++i)
        {
            
            if(j<spaces.size()&&i==spaces[j])
            {
                ++j;
                res[i+offset]=' ';
                offset++;
            }
            
            res[i+offset]=s[i];
        }
        return res;
        
    }
};