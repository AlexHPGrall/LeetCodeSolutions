class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low=lower_bound(begin(nums), end(nums), target);
        auto up= upper_bound(begin(nums), end(nums), target);
        if(low == end(nums) || *low!=target)
            return {-1, -1};
        return {(int)distance(begin(nums), low),
                (int)distance(begin(nums), up-1)};
    }
};