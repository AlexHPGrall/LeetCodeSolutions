class Solution {
public:
    char nxt(char c)
    {
        if(c=='c')
            return 'r';
        if(c=='r')
            return 'o';
        if(c=='o')
            return 'a';
        if(c=='a')
            return 'k';
        if(c=='k')
            return 'c';
        return 'c';
    }
    
    int minNumberOfFrogs(string croakOfFrogs) {
        int fcount=0;
        unordered_map<char, vector<int>> frogs;
        for(char c:croakOfFrogs)
        {
            if(frogs[c].size()==0)
            {
                if(c=='c')
                {
                    fcount++;
                    frogs['r'].push_back(fcount);
                    continue;
                }
                else
                    return -1;
            }
            int f=frogs[c].back();
            frogs[c].pop_back();
            frogs[nxt(c)].push_back(f);
        }
        //cout<<fcount<<endl;
        for(auto&it:frogs)
        {
            if(it.second.size()!=0 && it.first!='c')
                return -1;
            //cout<<it.first<<' '<<it.second.size()<<endl;
        }
        return fcount;
    }
};