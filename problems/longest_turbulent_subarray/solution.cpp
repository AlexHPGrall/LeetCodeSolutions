class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 1;
        int res= 1;
        int curr=res;
        bool b=!(arr[0]<arr[1]);
        for(int i=0; i<n-1; ++i)
        {
            if(arr[i]==arr[i+1])
            {
                curr=1;
                while(i<n-1 && arr[i]==arr[i+1])
                    ++i;
                if(i<n-1 && arr[i]!=arr[i+1] )
                {curr =2;b=(arr[i]<arr[i+1]); res=max(curr, res);}
                
            }
                
            else
            {
                if(b != (arr[i]<arr[i+1]))
                {
                    ++curr;
                    res=max(curr, res);
                    
                    
                }
                else
                {
                    curr=min(2,n);
                }
                b=(arr[i]<arr[i+1]);
            }
        }
        
        return res;
            
    }
};