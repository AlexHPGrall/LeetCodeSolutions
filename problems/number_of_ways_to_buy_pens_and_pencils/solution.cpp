class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res=0;
        while(total>=0)
        {
            res+=((long long)total/(long long)cost2)+1;
            total-=(long long)cost1;
        }
        return res;
    }
};