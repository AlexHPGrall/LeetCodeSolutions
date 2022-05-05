class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> start, end;
        int currmax=0;
        for(int n:nums)
        {
            int endN=0, startN=0;
            if(start.count(n+1))
                startN=start[n+1];
            if(end.count(n-1))
                endN=end[n-1];
            int len=1+startN+endN;
            //cout<<n<<' '<<n-end[n-1]<<' '<<n-end[n-1]+len-1<<' '<<len<<endl;
            start[n]=max(start[n],1+startN);
            end[n]=max(end[n],1+endN);
            start[n-endN]=max(len, start[n-endN]);
            end[n-endN+len-1]=max(len,end[n-endN+len-1]);
            currmax=max(currmax, len);
        }
        
        return currmax;
    }
};