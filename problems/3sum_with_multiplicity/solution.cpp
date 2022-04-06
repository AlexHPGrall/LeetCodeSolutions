class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int res=0;
        int mod=(1e9)+7;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-2;++i)
        {
            int currt=target-arr[i];
            int j=i+1, k=n-1;
            
            while(j<k)
            {
                
                if(arr[j]+arr[k] == currt && arr[j]!=arr[k])
                {
                    int t1=1;
                    //cout<<arr[i]<<arr[j]<<arr[k]<<endl;
                    while(arr[j+1]==arr[j])
                    {++j;++t1;}
                    int t2=1;
                    while(arr[k-1]==arr[k])
                    {--k;++t2;}
                    //cout<<t1*t2<<endl;
                    res+=(t1*t2)%mod;
                    res%=mod;
                    ++j;
                    --k;
                }
                else if(arr[j]+arr[k] == currt && arr[j]==arr[k])
                {
                    int t1=1;
                     //cout<<arr[i]<<arr[j]<<arr[k]<<endl;
                    while(j<n-1&&arr[j+1]==arr[j])
                    {++j;++t1;}
                    //cout<<(t1*(t1-1))/2<<endl;
                    res+=((t1*(t1-1))/2)%mod;
                    res%=mod;
                    break;
                }
                else if(arr[j]+arr[k] > currt)
                    --k;
                else 
                    ++j;
                
            }
        }
        return res%mod;
    }
};