class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(int i=0;i<wordList.size();++i)
        {
            mp[wordList[i]]=i;
        }
        if(!mp.count(endWord))
            return 0;
        int end=mp[endWord];
        wordList.push_back(beginWord);
        queue<int> q1,q2;
        int dist=1;
        q1.push(wordList.size()-1);
        while(!q1.empty())
        {
            int k=q1.front();
             q1.pop();
            string &s=wordList[k];
           
            if(k==end)
                return dist;
            for(int i=0;i<s.length();++i)
            {
                int ctmp=s[i];
                for(char c ='a';c<='z';++c)
                {
                    s[i]=c;
                    if(mp.count(s) && mp[s]!=-1)
                    {
                        q2.push(mp[s]);
                        mp[s]=-1;
                    }
                }
                s[i]=ctmp;
            }
            if(q1.empty())
            {
                swap(q1,q2);
                dist++;
            }
        }
        
        return 0;
    }
};