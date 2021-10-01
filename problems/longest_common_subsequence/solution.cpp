class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m =text1.size(), n =text2.size();
        vector<int> r1 (n+1,0);
        vector<int> r2 (n+1, 0);
        
        for(int i =m-1; ~i; --i)
        {
            for(int j = n-1; ~j; --j)
            {
                r1[j] = (text1[i]==text2[j])?r2[j+1]+1: max(r1[j+1], r2[j]);
            }
            
            swap(r1,r2);
        }
        return r2[0];
    }
};