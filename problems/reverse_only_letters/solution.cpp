#define OK(a) (((a)>='a' &&(a)<='z') || ((a)>='A' && (a)<='Z'))

class Solution {
public:
    string reverseOnlyLetters(string s) {

        for(int i =0, j=s.length()-1; i<j;)
        {
            if(OK(s[i]) && OK(s[j]))
               {
                  swap(s[i], s[j]);
                ++i;
                --j;
               }
               else 
               {
                   if(!OK(s[i]))
                    {++i;}
                   if(!OK(s[j]))
                      {--j;}
                }
               
        }
        return s;
    }
};