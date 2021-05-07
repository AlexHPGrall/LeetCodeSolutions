class Solution {
public:
    //get size of longest common substr
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        if(m<n)
        {swap(word1,word2);swap(m,n);}
        vector<int> last(n+1,0), curr(n+1,0);
       for(char c: word1)
        { 
            for(int j=0; j<n;++j)
            {
               curr[j+1] = (word2[j] == c)?last[j]+1:max(curr[j],last[j+1]);              
            }
            swap(curr, last);
        }
        
        return (n-last[n]) +(m-last[n]);
    }
};