class Solution {
public:
    int n;
   inline int SquareD(vector<int> &a)
    {
        return (a[0]*a[0])+(a[1]*a[1]);
    }
    void partition(int l, int r, vector<vector<int>> &p, int k)
    {
        int i=l-1;
        int pi=l+(r-l)/2;
        int pivot = SquareD(p[pi]);
        swap(p[pi],p[r]);
        for(int j=l;j<r;++j)
        {
            if(SquareD(p[j])<pivot)
            {
                
                ++i;
                swap(p[i],p[j]);
            }
        }
        ++i;
        swap(p[i],p[r]);    
        if(i==k)
            return;
        else if(i<k)
            partition(i+1,r,p,k);
        else
            partition(l,i-1,p,k);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        if(k==n)
            return points;
        partition(0,n-1,points,k);

        vector<vector<int>> res(k,vector<int>(2));
        for(int i=0;i<k;++i)
        {
            res[i]=points[i];
        }
        return res;
    }
};