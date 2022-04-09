class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int f1[1001]={};
        int f2[1001]={};
        for(int n:target)
        {
            f1[n]++;
        }
        for(int n:arr)
        {
            f2[n]++;
        }
        for(int i=1; i<=1000;++i)
        {
            if(f1[i]!=f2[i])
                return false;
        }
        return true;
    }
};