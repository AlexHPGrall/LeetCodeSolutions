class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n=a.size();
        if(n==1)
            return true;
        int i,j;
        i=(n/2)-1;
        j=i+1;
        if(n%2==1)
            j++;
        //cout<<i<<' '<<j<<endl;
        while(i>=0 && a[i]==a[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
        int ti=i, tj=j;
        while(i>=0 && a[i]==b[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
        
        i=ti;
        j=tj;
        //cout<<i<<' '<<j<<endl;
        while(i>=0 && b[i]==a[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
        
        
        i=(n/2)-1;
        j=i+1;
        if(n%2==1)
            j++;
        while(i>=0 && b[i]==b[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
         ti=i, tj=j;
        while(i>=0 && a[i]==b[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
        i=ti;
        j=tj;
        while(i>=0 && b[i]==a[j])
        {
            ++j;
            --i;
        }
        if(i<0)
            return true;
        
        return false;
            
        
    }
};