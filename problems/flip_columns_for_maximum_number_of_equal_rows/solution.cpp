class Solution {
public:
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> freq;
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;
        for(int i=0;i<m;++i)
        {
            bool flip=false;
            if(matrix[i][0]==0)
                flip=true;
            string s;
            for(int j=0; j<n;++j)
            {
                if(flip)
                {
                    matrix[i][j]=(matrix[i][j]+1)%2;
                }
                s.push_back('0'+matrix[i][j]);
            }
            //cout<<s<<endl;
            freq[s]++;
            res=max(res, freq[s]);
        }
        return res;
    }
};