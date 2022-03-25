class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)
            return {};
        long long n=num/3;
        vector<long long> res(3,n);
        res[0]-=1;
        res[2]+=1;
        return res;
    }
};