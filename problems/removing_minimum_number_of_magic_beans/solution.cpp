class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n=beans.size();
        int s=0;
        unordered_map<int,unsigned long long> freq;
        while(s<n-1 && beans[s]==beans[s+1])
        {freq[beans[s++]]++;}
        if(s==n-1)
            return 0;
        freq[beans[s++]]++;
        unsigned long long sum=0;
        for(int i=s;i<n;++i)
        {
            freq[beans[i]]++;
            sum+=(beans[i]-beans[s-1]);
        }
        
        //cout<<sum<<endl;
        unsigned long long res=sum;
        for(int i=s;i<n;i+=freq[beans[i]])
        {
            sum= (sum - (unsigned long long)(beans[i]-beans[i-1])*(n-i)) + (unsigned long long)beans[i-1]*(unsigned long long)freq[beans[i-1]] ;
            //cout<<sum<<endl;
            
            res=min(res,sum);
        }
        return res;
    }
};