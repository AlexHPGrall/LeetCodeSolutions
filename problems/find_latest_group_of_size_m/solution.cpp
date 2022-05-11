class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n =arr.size();
        vector<int>left(n+2,0);
        vector<int> right(n+2,0);
        int t=1;
        int last=-1;
        int cnt=0;
        for(int i:arr)
        {
            //left[i]=1;
            if(i>0)
            {
                if(right[i+1]==m)
                    cnt--;
                if(left[i-1]==m)
                    cnt--;
                right[i-left[i-1]]+=right[i+1] +1;
                left[i+right[i+1]]+=left[i-1]+1;
                if(left[i+right[i+1]]==m)
                    cnt++;
            }
            else
            {
                if(right[i+1]==m)
                    cnt--;
                right[i]=right[i+1]+1;
                left[i]=1;
                if(right[i]==m)
                    cnt++;
            }
            //cout<<cnt<<endl;
            if(cnt!=0)
                last=t;
            ++t;
            
        }
        return last;
    }
};