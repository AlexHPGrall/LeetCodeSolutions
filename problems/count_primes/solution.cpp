class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seen(n, false);
        int ans =0;
        for(int i = 2; i<n; ++i)
        {
            if(seen[i])
                continue;
            ans++;
            for(unsigned long num=(unsigned long)i*i; num <n; num+=i)
                seen[num]=true;
        }
        return ans;
    }
};