class Solution {
public:
    vector<int> monts={31,28, 31,30,31,30,31,31,30,31,30,31};
    bool isLeap(int y)
    {
        return (y%4==0) &&(y%100!=0 || y%400==0);
    }
    int daysSince71(string date)
    {
        string ys, ms,ds;
        int y,m,d;
        int res=0;
        for(int i=0;i<4;++i)
        {
            ys.push_back(date[i]);
           
        }
        y=stoi(ys);
        for(int i=5; i<7; ++i)
        {
            ms.push_back(date[i]);
        }
        m=stoi(ms);
        for(int i=8; i<10; ++i)
        {
            ds.push_back(date[i]);
        }
        d=stoi(ds);
        
        for(int ty=1971;ty<y;++ty)
        {
            res+=365+isLeap(ty);
        }    
        for(int tm=1; tm<m;++tm)
        {
            res+=monts[tm-1];
        }
        return res+d+(m>2 && isLeap(y)); 
    }
    int daysBetweenDates(string date1, string date2) {
        int d1=daysSince71(date1);
        int d2=daysSince71(date2);
        
        return abs(d1-d2);
    }
};