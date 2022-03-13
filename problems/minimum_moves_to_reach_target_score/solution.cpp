class Solution {
public:
    int minMoves(int target, int md) {
        if(!md)
            return target-1;
        if(target==1)
            return 0;
        if(target%2==0)
            return 1+minMoves(target/2,md-1);
        else
            return 2+minMoves((target-1)/2,md-1);
    }
};