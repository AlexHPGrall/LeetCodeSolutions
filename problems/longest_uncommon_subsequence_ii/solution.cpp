class Solution {
public:
   bool checkSub(string a, string &b)
    {
        int m = a.length();
        int n = b.length();
       if(m==n)
           return false;
       int A=m, B=n;
        
        while(A>0 && B>0)
        {
            int i=m-A, j=n-B;
            if(a[i]==b[j])
                A--;
            B--;
        }
        return A==0;
    }
    int findLUSlength(vector<string>& strs) {
        map<int, unordered_map<string, int>> mp;
        for(string s:strs)
        {
            mp[s.length()][s]++;
        }
        for (auto it = mp.crbegin(); it != mp.crend(); ++it)
        {
            
            for(auto pit:it->second)
            {
                if(pit.second !=1)
                    continue;
                bool sub =false;
                for(string &s:strs)
                {
                    if(checkSub(pit.first, s))
                    {
                        sub= true;
                        break;
                    }
                }
                if(!sub)
                    return it->first;
                    
            }
        }
        return -1;
    }
};