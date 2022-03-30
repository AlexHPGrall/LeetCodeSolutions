class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int l=0;
        int r=m-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]>target)
            {
                if(mid==0)
                    return false;
                if(matrix[mid-1][0]<=target)
                {l=mid-1;break;}
                r=mid-1;
            }
                
            else
            {
                if(mid==m-1 || matrix[mid+1][0]>target)
                {l=mid;break;}
             
                l=mid+1;
            }
                
        }
        cout<<l<<endl;
        if(l<0 || l>=m||matrix[l][0]>target)
            return false;
        int tgr=l;
        l=0;
        r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(matrix[tgr][mid]==target)
                return true;
            if(matrix[tgr][mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        //cout<<l<<endl;
        if(l<0 || l>=n||matrix[tgr][l]!=target)
            return false;
        return true;
        
    }
};