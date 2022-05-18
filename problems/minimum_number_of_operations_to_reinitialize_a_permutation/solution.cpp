class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr(n), perm(n);
        for(int i=0; i<n;++i)
        {
            perm[i]=i;
        }
        int cnt=0;
        int p=0;
        while(cnt!=n)
        {
            cnt=0;
            p++;
            for(int i=0; i<n;++i)
            {
                if(i%2==0)
                    arr[i]=perm[i/2];
                else
                    arr[i] = perm[(n/2) + ((i - 1)/2)];
                if(arr[i]==i)
                    cnt++;
            }
            swap(perm,arr);
        }
        return p;
    }
};