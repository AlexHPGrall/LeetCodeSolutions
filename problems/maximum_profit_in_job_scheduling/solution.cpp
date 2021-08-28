class Solution {
public:
    vector<pair<int, int>> arr;
     int GetIndex(int i, int target)
    {
        int low =0;
        int high = i-1;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid].first <= target)
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
     
        int n=startTime.size();
        
        
        for(int i=0; i<n; ++i)
        {
            arr.push_back({endTime[i], i});
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n);
       
        dp[0] =profit[arr[0].second];
        for(int i=1;i<n;++i)
        {   
            
            int maxProfitIndex=GetIndex(i, startTime[arr[i].second]);
            
            int maxProfit =maxProfitIndex==-1?0:  dp[maxProfitIndex];
            maxProfit+=profit[arr[i].second];
            dp[i] = max(dp[i-1], maxProfit);
            
        }
        return dp[n-1];
    }
};