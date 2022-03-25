class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       
        sort(nums.begin(), nums.end());
        long long p=0;
        long long sum=0;
        for(int n:nums)
        {
           if(n-p<=1)
           {p=n;continue;}
            long long l=min((long long)n-1,(long long)p+k);
            //cout<<n<<' '<<p<<' '<<k<<' '<<l<<endl;
            sum+=(l*(l+1))/2 -(p*(p+1))/2;
            k-=(l-p);
            if(!k)
                break;
            p=n;
        }
        long long l=p+k;
        sum+=(l*(l+1))/2 -(p*(p+1))/2;
        return sum;
    }
};