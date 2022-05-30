class Solution {
public:
    int divide(int dend, int dor) {
        if(dor==1)
            return dend;
        if(dend==dor)
            return 1;
        if(dor==INT_MIN)
            return 0;
        if(dend==INT_MIN&&dor==-1)
        {
            return INT_MAX;
        }
        int sign=(dend>0)^(dor>0);
        int res=0;
        if(dend==INT_MIN)
        {
            dend+=abs(dor);
            res+=1;
        }
        int a=abs(dend);
        int b=abs(dor);
        //cout<<a<<' '<<b<<endl;
        while(a>=0)
        {
           int n=0;
           while(a-(b<<n)>=0)
           {
               if((b<<(n+1))<0)
               {
                   ++n;
                   break;
               }
               //cout<<(dor<<n)<<endl;
               ++n;
               //cout<<n<<endl;
           }
            if(n==0)
            {
                a=a-(b<<(n));
            }
            else
            {
                res+=(1<<(n-1));
                a=a-(b<<(n-1));
            }
        }
        if(sign)
            return -res;
        return res;
    }
};