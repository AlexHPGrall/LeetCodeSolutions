bool cmp1(long long a, long long b)
    {
        return a<b;
    }
bool cmp2(long long a, long long b)
{
        return a>b;
    }
class Solution {
public:
    

    
    long long smallestNumber(long long num) {
        if(!num)
            return 0;
        bool (*cmp)(long long, long long);
        long long sign=1;
        if(num<0)
        {num*=-1;sign=-1;cmp=&cmp1;}
        else
            cmp=&cmp2;
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        while(num)
        {
            pq.push(num%10);
            num/=10;
        }
        int cnt=0;
        int zcnt=0;
        long long res=0;
        while(!pq.empty())
        {
            int curr=pq.top();
            pq.pop();
            while(!cnt && !curr)
            {
                //ut<<cnt<<' '<<curr<<endl;
                ++zcnt;
                curr=pq.top();
                pq.pop();
                
            }
            while(zcnt--)
                pq.push(0);
            res*=10;
            res+=curr;
            cnt++;
            zcnt=0;
                
        }
        
        return sign*res;  
    }
};