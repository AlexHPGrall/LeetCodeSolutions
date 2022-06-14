class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp1(word1.size()+1,0), dp2(word1.size()+1,0);
        for(int i=0;i<=word2.size();++i)
        {
            for(int j=0;j<=word1.size();++j)
            {
                if(i==0 || j==0)
                    continue;
                if(word1[j-1]==word2[i-1])
                    dp2[j]=1+dp1[j-1];
                else
                    dp2[j]=max(dp2[j-1], dp1[j]);
            }
            swap(dp1, dp2);
        }
        cout<<dp1[word1.length()]<<endl;
        return word1.size()+word2.size() -2*(dp1[word1.length()]);
    }
};