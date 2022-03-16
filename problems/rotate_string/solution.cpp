class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;
        int n=s.length();
        if(n!=goal.size())
            return false;
        int k=0;
begin:
        
        while(i<n && s[i]!=goal[0])
            ++i;
        if(i==n)
            return false;
        k=i;
        for(int j=0; j<n;++j )
        {
          
            if(s[i]!=goal[j])
            {i=k+1;goto begin;}
            i=(i+1)%n;
        }
        return true;
    }
};