class Solution {
public:
    int minPartitions(string n) {
        int res=0;
        for(char c:n)
        {
            res = max(res, static_cast<int>(c-'0'));
        }
        return res;
    }
};