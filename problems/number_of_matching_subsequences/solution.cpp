class Solution {
public:
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
     int res =0;
     unordered_map<char, vector<int>> hshmp;
     int n=s.size();
    for(int i =0; i<n; ++i)
    {
        hshmp[s[i]].push_back(i);
    }
    for(string const &sub:words)
    {
        int m=sub.size();
        int j=0, k=0;
        bool ctn =true;
        for(int i=0;i<m && ctn;++i)
        {
            if(hshmp.find(sub[i]) == hshmp.end())
                break;
            else
            {
                for(int index:hshmp[sub[i]])
                {
                    ctn =false;
                
                    if(index == k)
                    {
                        k++;
                        j++;
                        ctn =true;
                        break;
                    }
                    else if(index >k)
                    {
                        k = index+1;
                        j++;
                        ctn =true;
                        break;
                    }
                }
                
                    
            }
        }
        if(j==m)
            res++;
    }
        return res;
    }
};