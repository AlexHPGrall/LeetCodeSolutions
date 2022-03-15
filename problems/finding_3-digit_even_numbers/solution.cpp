class Solution {
public:
    vector<int> res;
    int arr[1000]={0};
    void rec(vector<int> &dig,int i,int curr)
    {
        int tmp;
        if(i==1)
        {
            for(int j=0;j<dig.size();++j)
            {
                if(dig[j]%2==0)
                {
                    tmp=dig[j];
                    dig[j]=-1;
                    rec(dig, 2,tmp);
                    dig[j]=tmp;
                }
            }
        }
        if(i==2)
        {
            for(int j=0;j<dig.size();++j)
            {
                if(dig[j]!=-1)
                {
                    
                    tmp=dig[j];
                    dig[j]=-1;
                    rec(dig, 3,(10*tmp)+curr);
                    dig[j]=tmp;
                }
            }
        }
        if(i==3)
        {
            for(int j=0;j<dig.size();++j)
            {
                if(dig[j]!=0 && dig[j]!=-1)
                {
                    tmp=curr+(100*dig[j]);
                    if(!arr[tmp])
                    {
                        arr[tmp]=1;
                        res.push_back(tmp);
                    }
                }
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        rec(digits,1,0);
        sort(res.begin(),res.end());
        return res;
    }
};