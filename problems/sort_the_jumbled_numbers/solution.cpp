class Solution {
public:
    unordered_map<int,int> mp;
    int mapped(int a, vector<int>& mapping)
    {
        if(mp.count(a))
            return mp[a];
       
        int res=0;
        int p=1;
        int b=a;
        do
        {
            int d=a%10;
            a/=10;
            res=res+p*mapping[d];
            p*=10;
        }while(a);
        mp[b]=res;
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a, int b){
            return mapped(a,mapping)<mapped(b,mapping);
        });
        
        return nums;
    }
};