class Solution {
public:
    bool isVowel(const char c)
    {
        return c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        for(string &s:wordlist)
        {
            exact.insert(s);
            string w=s;
            for(char &c:w)
            {
                
                if(c>='a')
                    c=c-'a'+'A';
            }
            if(!caseMap.count(w))
                caseMap[w]=s;
            for(char &c:w)
            {
                if(isVowel(c))
                    c='*';
            }
            if(!vowelMap.count(w))
                vowelMap[w]=s;
        }
        vector<string> res;
        for(string &s:queries)
        {
            if(exact.count(s))
            {
                res.push_back(s);
                continue;
            }
            for(char &c:s)
            {
                if(c>='a')
                    c=c-'a'+'A';
            }
            if(caseMap.count(s))
            {
                res.push_back(caseMap[s]);
                continue;
            }
            for(char &c:s)
            {
                if(isVowel(c))
                    c='*';
                
            }
            if(vowelMap.count(s))
            {
                res.push_back(vowelMap[s]);
                
            }
            else
            {
                res.push_back("");
            }
        }
        
        return res;
    }
};