class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        unordered_map<int, int> mp;
        int res =0, m=matrix.size(), n=matrix[0].size();
        for(int row=0; row < m; ++row)
            for(int col =1; col < n; ++col)
                matrix[row][col] += matrix[row][col-1];
        
        for(int colStart=0;colStart<n;++colStart)
            for(int colEnd = colStart; colEnd < n; ++colEnd)
            {
                int sum = 0;
                mp={{0,1}};
                for(int row=0; row<m; ++row)
                {
                    sum += matrix[row][colEnd] -(colStart?matrix[row][colStart-1]:0);
                    res +=mp[sum -target];
                    ++mp[sum];
                }
                    
            }
        return res;
    }
};