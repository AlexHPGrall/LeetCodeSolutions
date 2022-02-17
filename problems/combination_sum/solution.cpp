class Solution {
public:
    void recFind(vector<int> &arr, vector<int> &curr,vector<vector<int>> &res, int index, int k)
    {
        for(int i=index;i<arr.size();++i)
        {
            if(arr[i] >k)
                break;
            curr.push_back(arr[i]);
            if(arr[i]==k)
                res.push_back(curr);
            else
                recFind(arr, curr, res, i, k-arr[i]);
            curr.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        recFind(candidates, cur, res,0,target);
        return res;
    }
};