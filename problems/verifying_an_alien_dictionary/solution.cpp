class Solution {
    string alphabet="abcdefghijklmnopqrstuvwxyz";
public:
    vector<string> correct(vector<string>& words, string order)
    {
        vector<string> correctWords(words);
        for(int j = 0; j< correctWords.size(); ++j)
        {
            for(int i =0; i<correctWords[j].size(); ++i)
            {
                correctWords[j][i] = alphabet[order.find(correctWords[j][i])];
            }
        }
        
        return correctWords;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> correctedWords = correct(words, order);
        for(int i = 1 ;i < correctedWords.size(); ++i)
            if(correctedWords[i]<correctedWords[i-1])
                return false;
        return true;
        
    }
};