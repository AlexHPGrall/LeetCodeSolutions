class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
        string res;
        int rem=0;
        while(~i || ~j)
        {
            //cout<<i<<" "<<j<<endl;
            if(i<0)
            {
                char c= num2[j]+rem;
                rem=0;
                if(c>'9')
                {
                    c-=10;
                    rem=1;
                }
                res.push_back(c);
                j--;
            }
                
            else if(j<0)
            {
                char c= num1[i]+rem;
                rem=0;
                if(c>'9')
                {
                    c-=10;
                    rem=1;
                }
                res.push_back(c);
                i--;
            }
            else
            {
                char c= num1[i]+(num2[j]-'0')+rem;
                rem=0;
                if(c>'9')
                {
                    c-=10;
                    rem=1;
                }
                res.push_back(c);
                j--;i--;
            }   
        }
        if(rem)
            res.push_back('1');
        for(int i=0;i<res.length()/2;++i)
        {
            swap(res[i],res[res.length()-i-1]);
        }
        return res;
    }
};