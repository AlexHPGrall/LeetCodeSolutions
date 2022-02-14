class Solution {
public:
    void makeMStack(int k, vector<int> &st, vector<int> &arr)
    {
        for(int i=0; i< arr.size();++i)
        {
           
            if(st.size() + (arr.size()-i) ==k)
            {
                
                for(;i<arr.size();++i)
                {
                    st.push_back(arr[i]);
                }
                break;
            }
            while(!st.empty() && st.back()<arr[i] && st.size() + (arr.size()-i) >k)
            {
                st.pop_back();
            }
            st.push_back(arr[i]);
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k,0),tmpres(k,0);
        for(int i=0; i<=k;++i)
        {
           
            if(i>nums1.size() || k-i >nums2.size())
                continue;
            vector<int> st1,st2;
            makeMStack(i,st1,nums1);
            makeMStack(k-i,st2,nums2);
            //cout<<i<<endl;
            
            int m=0,n=0;
            int j;
            bool ok =false;
            for(j=0;j<k;++j)
            {
                int curr;
                if(m==st1.size() || (n<st2.size()&&st2[n]>st1[m]))
                {
                    curr=st2[n++];
                }
                else if(m<st1.size() && n<st2.size()&& st1[m]==st2[n])
                {
                    int tm=m;
                    int tn=n;
                    while(tm<st1.size() && tn<st2.size() && st1[tm] == st2[tn])
                    {++tm;++tn;}
                    if(tm==st1.size() || (tn<st2.size()&&st2[tn]>st1[tm]))
                    {
                        curr=st2[n++];
                    }
                    else
                    {
                        curr=st1[m++];
                    }
                }
                else
                {
                    curr=st1[m++];
                }
                if(!ok && curr<res[j])
                    break;
                if(!ok && curr>res[j])
                    ok=true;
                tmpres[j]=curr;
                
            }
            if(j==k )
                swap(res,tmpres);
            
        }
        
        return res;
    }
};