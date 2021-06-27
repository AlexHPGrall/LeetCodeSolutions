class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> Candies(ratings.size(), 1);
       for(int i= 1; i<ratings.size(); ++i)
       {
           if((ratings[i] < ratings[i-1]) && Candies[i] >= Candies[i-1])
           {
               Candies[i-1] = Candies[i] +1;
           }
           else if((ratings[i] > ratings[i-1]) && Candies[i] <= Candies[i-1])
               Candies[i] = Candies[i-1] +1;
       }
        for(int i= ratings.size() -2; i>=0; --i)
       {
           if((ratings[i] < ratings[i+1]) && Candies[i] >= Candies[i+1])
           {
               Candies[i+1] = Candies[i] +1;
           }
           else if((ratings[i] > ratings[i+1]) && Candies[i] <= Candies[i+1])
               Candies[i] = Candies[i+1] +1;
       }
        int sum = 0;
        for(int c:Candies)
            sum+=c;
       return sum; 
    }
};