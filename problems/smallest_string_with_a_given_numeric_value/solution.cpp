class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        int i=0;
        while(n>1)
        {
            
            int c=k-(26*(n-1));
            if(c<=0)
                c=1;
            k-=c;
            res[i]=('a'+c-1);
            ++i;
            n--;
        }
        res[i]=('a'+k-1);
        return res;
    }
};