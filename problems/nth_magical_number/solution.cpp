class Solution {
public:
    int mod =(1e9)+7;
    int nthMagicalNumber(int n, int a, int b) {
        unsigned long long al=a, bl=b;
        unsigned long long k=lcm(al,bl);
        unsigned long long l=(k/al)+(k/bl)-1;
        unsigned long long res=k*(n/l);
        unsigned long long i=1, j=1;
        
        //cout<<res<<endl;
        unsigned long long tres=0;
        for(unsigned long long m=0;m<n%l;++m)
        {
            if(al*i< bl*j)
            {
                tres=al*i;
                ++i;
            }
            else
            {
                tres=bl*j;
                ++j;
            }
            //cout<<res<<endl;
        }
        return ((int)(res%mod)+(int)(tres%mod))%mod;
    }
};