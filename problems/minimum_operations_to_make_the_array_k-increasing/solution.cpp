class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int res=0;
        int n=arr.size();
        for(int i=0;i<k&&i<n;++i)
        {
            vector<int> st;
            for(int j=i; j<n;j+=k)
            {
                if(st.empty()||st.back()<=arr[j])
                    st.push_back(arr[j]);
                else
                {
                    int l=0;
                    int r=st.size()-1;
                    while(l<r)
                    {
                        int mid=l+(r-l)/2;
     
                        if(st[mid]<=arr[j])
                            l=mid+1;
                        else
                            r=mid;
                    }
                    
                    st[l]=arr[j];
                }
            }
            res+=st.size();
            cout<<st.size();
        }
        return n-res;
    }
};