class Solution {
public:
    int count(vector<int> &row)
    {
        int l=0;
        int r=row.size()-1;
        while(l<=r)
        {
            int mid =l+(r-l)/2;
            if(row[mid]==1)
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res(k);
        vector<pair<int,int>> pq;
        int i=0;
        for(auto &v:mat)
        {
            pq.push_back({count(v),i++});
        }
        stable_sort(pq.begin(),pq.end());
        for(int i=0;i<k;++i)
        {
            res[i]=pq[i].second;
        }
        return res;
    }
};