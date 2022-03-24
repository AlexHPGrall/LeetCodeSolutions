class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0;
        int n=people.size();
        int j=n-1;
        int res=0;
        while(i<j)
        {
            if(people[j]+people[i]<=limit)
            {
                res++;
                ++i;
                --j;
            }
            else
            {
                res++;
                --j;
            }
        }
        if(j==i)
            res++;
        return res;
    }
};