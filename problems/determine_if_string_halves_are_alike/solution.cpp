class Solution {
    static constexpr char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; 
public:
    bool isVowel(char c)
    {
        for(char v : vowels )
        {
            if(c==v)
                return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int v1, v2;
        v1 = v2 = 0;
        
        for(int i = 0; i<n; ++i)
        {
            if(i<n/2)
            {
                if(isVowel(s[i]))
                    ++v1;
            }
                
            
            else{
                if(isVowel(s[i]))
                    ++v2;
                if(v2>v1)
                    return false;
            }
        }
        
        return (v1==v2);
        
    }
};