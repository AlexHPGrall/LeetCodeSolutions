class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans=keysPressed[0];
        int maxRelease = releaseTimes[0];
        int n=releaseTimes.size();
        for(int i=1;i<n;++i)
        {
            int rel =releaseTimes[i]-releaseTimes[i-1];
            if( rel>maxRelease)
            {
                maxRelease = rel;
                ans=keysPressed[i];
            }
                
            else if(rel==maxRelease)
            {
                ans = ans>keysPressed[i]?ans:keysPressed[i];
            }
        }
        return ans;
    }
};