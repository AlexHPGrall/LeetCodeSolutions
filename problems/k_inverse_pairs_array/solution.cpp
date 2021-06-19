class Solution {
public:
  int kInversePairs(int n, int k) {
        int MOD = 1e9 +7;
       
        vector<int>dpn(k+1,0);
        vector<int>dpn1(k+1,0);
        dpn[0] = dpn1[0] =1;
        for(int N = 1; N<=n; N++){
            for(int K=1;K<=k;K++){
                dpn[K] = (dpn1[K]+dpn[K-1])%MOD;
                if(K-N>=0){
                    dpn[K] = (dpn[K] - dpn1[K-N]+MOD)%MOD;
                }
            }
            swap(dpn, dpn1);
        }
        return dpn1[k];
    }
};