class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> FileDup;
        vector<vector<string>> res;
        for(string s : paths)
        {
            string path, file, content;
            int n=s.length(), i=0;
            while(s[i]!=' ')
            {
                path.push_back(s[i]);
                ++i;
            }
            
            ++i;
            while(i<n)
            {
                while(s[i] !='(' && i<n)
                {
                    file.push_back(s[i]);
                    ++i;
                }
                
                ++i;
                while(s[i] !=')' && i<n)
                {
                    content.push_back(s[i]);
                    ++i;
                }
                i+=2;
                FileDup[content].push_back(path+"/"+file);
                file = content = "";
            }
        }
        
        for(auto const& i:FileDup)
        {
            if(i.second.size() >1)
                res.push_back(i.second);
        }
            
     return res;   
    }
};