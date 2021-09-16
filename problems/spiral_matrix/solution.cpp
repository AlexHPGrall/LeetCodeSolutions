class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int h =n;
        int v= m;
        vector<int> res(n*m);
        int index =0;
        for(int i =0, j=0;;)
        {
            for(int k=0;k<h;++k, ++j)
                res[index++] =matrix[i][j];
            j--;i++; v--;
            if(v<=0)
                break;
           
            for(int k=0;k<v;++k, ++i)
                res[index++] =matrix[i][j];
            j--;i--; h--;
            if(h<=0)
                break;
            
            for(int k=0;k<h;++k, --j)
                res[index++] =matrix[i][j];
            j++;i--; v--;
            if(v<=0)
                break;
            //cout<<i<<" "<<j<<" "<<h<<" "<<v <<endl;
            for(int k=0;k<v;++k, --i)
                res[index++] =matrix[i][j];
            j++;i++; h--;
            if(h<=0)
                break;
            
        }
        
        return res;
    }
};