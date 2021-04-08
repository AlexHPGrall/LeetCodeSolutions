class Solution {
    char letters[26] = {'a', 'b','c','d','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'q' ,'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'p'};
public: 
    void recComb(vector<string> &vec, string digits, int index, string curr)
    {
        if(index == digits.length())
        {
             vec.push_back(curr);
             return;
        }
        if(digits[index] == '7')
            recComb(vec, digits, index+1, curr + 'p');
        if(digits[index] == '9')
           recComb(vec, digits, index+1, curr + 'z');
        for(int i = 0; i<3;++i)
        {
            
            recComb(vec, digits, index+1, 
                    curr + letters[(int)(digits[index]-'2')*3+i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0)
            return res;
        recComb(res, digits, 0, "");
        return res;
    }
};