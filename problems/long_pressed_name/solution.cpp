class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        int m=name.length();
        int n=typed.length();
        while(i<m && j<n)
        {
            int cnt=0;
            char c=name[i];
            if(typed[j]!=c)
                return false;
            while(i<m && name[i]==c)
            {
                ++i;
                ++cnt;
            }
            while(j<n&&typed[j]==c)
            {
                ++j;
                --cnt;
            }
            if(cnt >0)
                return false;
        }
        if(j!=n || i!=m)
            return false;
        return true;
    }
};