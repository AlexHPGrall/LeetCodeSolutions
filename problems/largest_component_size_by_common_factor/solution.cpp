class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x)
    {
        
        while(x!=parent[x])
        {
            parent[x] = parent[parent[x]];
            x=parent[x];
        }
        return x;
    }
    void my_union(int x, int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
            return;
        if(size[x]<size[y])
            swap(x,y);
        parent[y] =x;
        size[x] += size[y];
    }
vector<int> computePrimes(int P)
{
    vector<bool> pri(P+1, true);
    vector<int> prime;
    for(int i=2;i<=P;i++){
            if(!pri[i]) continue;
            prime.push_back(i);
            for(int j=i;j<=P;j+=i) pri[j]=false;
        }
    return prime;
}
    int largestComponentSize(vector<int>& nums) {
        
        int n=nums.size();
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; ++i)
            parent[i] =i;
        
        sort(nums.begin(), nums.end());
        vector<int> Prime = computePrimes(nums[n - 1]);
        
        unordered_map<int, int> mp;
        for(int i =0; i<n; ++i)
            mp[nums[i]] =i;
        for(int p:Prime)
        {
            int node = -1;
            for(int i=p; i<=nums[n-1]; i+=p)
            {
                if(mp.count(i))
                {
                    if(node == -1)
                        node = mp[i];
                    else
                        my_union(node, mp[i]);
                }
            }
        }
        int res=1;
        for(int i=0; i<n; ++i)
            res= max(res, size[i]);
        return res;
        
    }
};