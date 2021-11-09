class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res(puzzles.size(),0);
        unordered_map<int, int> mp;
        for(int i=0; i<words.size();i++)
        {
            int mask=0;
            for(char c: words[i])
            {
                mask |= (1<<(c-'a'));
            }
            
            mp[mask]++;
            
        }
        for(int i=0; i<puzzles.size(); i++)
        {
            for(int j=1; j<(1<<7); j+=2)
            {
                int mask = 0;
                for(int k =0; k<7;++k)
                    if((j&(1<<k)))
                        mask |= (1<<(puzzles[i][k]-'a'));
               
                res[i]+=mp[mask];
            }
        }
        
        return res;
    }
};