class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        vector<int> dp(tasks.size(),-1);
        int freq=1;
        for(int i=1;i<tasks.size();++i)
        {
            //cout<<tasks[i]<<' ';
            if(tasks[i-1]==tasks[i])
                ++freq;
            else if(dp[i-1] ==-1)
                return -1;
            else
            {
                freq=1;
                //cout<<dp[i]<<endl;
                continue;
            }
            if(i>=3 &&(freq==2 || freq==3))
                dp[i]=dp[i-freq]+1;
            else if(i<3 && (freq==2 || freq ==3))
                dp[i]=1;
            else
            {
                if(freq > 3)
                dp[i]=dp[i-2]+1;
                if(freq >4)
                    dp[i]=min(dp[i], dp[i-3]+1);
            }
            //cout<<dp[i]<<endl;
        }
        return dp[tasks.size()-1];
    }
};