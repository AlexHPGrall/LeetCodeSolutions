class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        unordered_map<int, int> m;
        stack<int> s;
        for (int i : nums) {
            while (!s.empty() && s.top() < i) s.pop();
            m[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        vector<int> result;
        for (int i : findNums) result.push_back(m[i]);
        return result;
    }
};