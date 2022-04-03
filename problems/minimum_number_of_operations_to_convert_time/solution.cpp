class Solution {
public:
    int convertTime(string s, string t) {
        int res=0;
        int t1=0, t2=0;
        t1=(s[0]-'0')*10;
        t1+=(s[1]-'0');
        t1*=60;
        t1+=(s[3]-'0')*10 ;
        t1+=s[4]-'0';
        t2=(t[0]-'0')*10;
        t2+=(t[1]-'0');
        t2*=60;
        t2+=(t[3]-'0')*10 ;
        t2+=t[4]-'0';
        int d=24*60;
        
        
        t2-=t1;
        while(t2)
        {
            if(t2>=60)
            {
                res+=t2/60;
                t2=t2%60;
                    
            }
            else if(t2>=15)
            {
                res+=t2/15;
                t2=t2%15;
            }
            else if(t2>=5)
            {
                res+=t2/5;
                t2=t2%5;
            }
            else
            {
                res+=t2;
                t2=0;
            }
        }
        return res;
    }
};