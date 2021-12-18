class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& dig, int n) {
        int m=dig.size();
        int p=0;
        int np=n;
        while(np)
        {
            np/=10;
            p++;
        }
        vector<int> num(p);
        int res=0;
        np=1;
        int d=n;
        for(int i =0; i<p-1; ++i)
        {
            np*=m;
            res+=np;
            num[i] = d%10;
            d/=10;
        }
        num[p-1]=d%10;
        
        for(int i=p-1; ~i; --i)
        {
            int count =0;
            int j;
           for(j =0; j<m;++j)
           {
               if(dig[j][0]-'0' >= num[i])
               {
                   break;
               }
               count++;
           }
            
           res += count*np;
           
           if(j==m || dig[j][0]-'0'!=num[i])
               break;
            
            if(i==0)
                res+=1;
            //cout<<res<<endl;
            
            np/=m;
        }
        
        return res;
    }
};