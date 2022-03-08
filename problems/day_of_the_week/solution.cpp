class Solution {
public:
    vector<string> days={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<int> monthsLength={31,28,31,30,31,30,31,31,30,31,30,31};
    string dayOfTheWeek(int day, int month, int year) {
        int leapYears=max((year-1969)/4,0);
        int nextYear=max((year+1-1969)/4,0);
        bool leap=nextYear>leapYears;
        if (year==2100)
            leap=false;
        int startDay=5;
        startDay = (startDay + (year-1971) + leapYears)%7;
        //cout<<startDay<<endl;
        for(int i=1;i<month;++i)
        {
            if(i==2 && leap)
                startDay=(startDay+29)%7;
            else
                startDay=(startDay+monthsLength[i-1])%7;
        }
        startDay= (startDay + (day-1))%7;
        
        cout<<leap<<endl;
        return days[startDay];
        
        
    }
};