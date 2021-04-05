class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n= A.size();
        
        if(n == 1)
            return true;
        for(int i = 0;i < n-1;  ++i)
        {
            
        
            if(A[i] != i)
            {
                
                if(A[i+1]!=i || A[i] != i+1 )
                return false;
                
                ++i;
            }
            
        }
        if(A[n-1] != n-1 && A[n-1] !=n -2)
            return false;
        return true;
    }
};