class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(start);
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            if(arr[i] == 0)
                return true;
            vis[i] = true;
            if(i+arr[i] <n && i+arr[i]>=0 && !vis[i+arr[i]])
                q.push(i+arr[i]);
            if(i-arr[i] <n && i-arr[i]>=0 && !vis[i-arr[i]])
                q.push(i-arr[i]);
        }
        return false;
        
        }
};