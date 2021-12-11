#define ull unsigned long long
class Solution {
public:
    int mod = 1e9 +7;
    int nthMagicalNumber(unsigned long long n, unsigned long long a, unsigned long long b) {
        if(a>=b)
            swap(a,b);
        if(n==1)
            return a;
        if(b%a == 0)
            return ((a%mod)*(n%mod))%mod;
        unsigned long long d = lcm(a,b);
        unsigned long long c = a*n;
        unsigned long long m=c/b - c/d;
        if(m==0)
            return c;
        ull l=n-m;
        ull r=n;
        while(l<r)
        {
            ull mid = l+(r-l)/2;
            c = a*mid;
            m=c/b - c/d;
            if(mid + m == n)
                return c%mod;
            if(mid+m<n)
                l=mid+1;
            else
                r=mid;
        }
        --l;
        c = a*l;
        m=c/b - c/d;
        
        if(l+m==n)
            return c%mod;
        
        else 
        {
           
            c= ((c/b)+(n-(l+m)))*b;
            return c%mod;
        }
        
    }
};