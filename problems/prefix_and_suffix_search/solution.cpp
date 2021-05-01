class WordFilter {
        unordered_map<string, int> dico;

public:
    WordFilter(vector<string>& words) {
        int index =0;
        for(string s : words)
        {
            int s_size = s.size();
            for(int i =0; i<s_size ;++i)
            {
                string suff = s.substr(i, s_size-i);
                for(int j=s_size; j>=0;--j)
                {
                    string pref = s.substr(0,j);
                    string filter = suff;
                    filter.push_back('#');
                    filter.append(pref);
                    dico[filter] = index;
                }
                
            }
            ++index;
        }
    }
    
    int f(string prefix, string suffix) {
        string filter = suffix;
        filter += "#";
        filter += prefix;
        auto got = dico.find(filter);
        if(got != dico.end())
            return got->second;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */