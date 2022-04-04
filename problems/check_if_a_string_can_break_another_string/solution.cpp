class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n=s1.length();
        int i;
        for( i=0; i<n && s1[i]==s2[i];++i);
        if(i==n)
            return true;
        if(s1[i]<s2[i])
        {
            for(;i<n;++i)
                if(s1[i]>s2[i])
                    return false;
        }
        else
        {
            for(;i<n;++i)
                if(s1[i]<s2[i])
                    return false;
        }
        return true;
    }
};