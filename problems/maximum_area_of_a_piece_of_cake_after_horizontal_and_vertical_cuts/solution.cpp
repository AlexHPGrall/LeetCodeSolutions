
class Solution {
public:
    
    int Partition(vector<int>& A, int p, int r)
    {
        int x= A[r];
        int i = p-1;
        for(int j = p ;j<r; ++j)
        {
            if(A[j]<=x)
            {
                ++i;
                int temp = A[j];
                A[j] = A[i];
                A[i] =temp;
            }
                
        }
        A[r] = A[i+1];
        A[i+1] =x;
        return i+1;
        
    }
    void QuickSort(vector<int>& A, int p, int r)
    {
        if(p<r)
        {
            int q = Partition(A, p,r);
            QuickSort(A, p , q-1);
            QuickSort(A, q+1, r);
        }
    }
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
            ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
         //sort(hCuts.begin(), hCuts.end());
          //sort(vCuts.begin(), vCuts.end());
            QuickSort(hCuts,0, hCuts.size()-1);
            QuickSort(vCuts, 0, vCuts.size()-1);
            int hmax =max(hCuts[0], h-hCuts[hCuts.size()-1]), vmax =max(vCuts[0],w-vCuts[vCuts.size()-1]) , mod = (1e9 +7);
            
            for(int i =1; i<hCuts.size(); ++i)
            {
                    hmax = max(hmax, hCuts[i]-hCuts[i-1]);
            }
            for(int i = 1; i<vCuts.size(); ++i)
            {
                 if(i<vCuts.size())
                    vmax = max(vmax, vCuts[i]-vCuts[i-1]);
        
            }
             
            return ((long)hmax * (long)vmax)% mod;
                
    }
};