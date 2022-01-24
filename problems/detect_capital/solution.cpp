class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(n==1)
            return true;
        
        bool caps=true;
        if(word[0]<'a'&& word[1]<'a')
        {
            for(int i=2;i<n;++i)
                if(word[i]>='a')
                    return false;
            return true;
        }
        else
        {
            for(int i=1;i<n;++i)
                if(word[i]<'a')
                    return false;
            return true;
        }
    }
};