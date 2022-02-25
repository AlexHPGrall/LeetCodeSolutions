class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        int m=version1.length();
        int n=version2.length();
        while(i<m || j<n)
        {
            int v1=0;
            while(i<m && version1[i]!='.')
            {
                v1*=10;
                v1+=version1[i]-'0';
                ++i;
            }
            ++i;
            int v2=0;
            while(j<n && version2[j]!='.')
            {
                v2*=10;
                v2+=version2[j]-'0';
                ++j;
            }
            ++j;
            cout<<v1<<" "<<v2<<endl;
            if(v1<v2)
                return -1;
            if(v1>v2)
                return 1;
        }
        
        return 0;
    }
};