class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    int total=0;
     int m = s.length(), n=t.length();
     int left =0, right =0;
     int minL=0, minR=m;
     string res;
    if(!n ||!m)
        return res;
    for(char c:t)
    {
        if(!mp.count(c))
            mp[c]= 1;
        else
            ++mp[c];
       total++;
    }
   
   
    char c=s[0];
    
    if(mp.count(c))
    {
        mp[c] -=1;
        total -=1;
    }    
    if(total ==0)
    {
        minL=minR=0;
        left =right+1;
    }
    
    
         
    while(left<=right)
    {
        if(right == m-1 && total>0)
            break;
        if(left==m-1)
            break;
        if(total>0)
        {
            
            ++right;
            c=s[right];
            //cout<<"right "<<c<<endl;
            
            if(mp.count(c))
            {
                mp[c] -=1;
                if(mp[c]>=0)
                 total -=1;
            }
        }
        else if(total ==0)
        {
            c=s[left];
            //cout<<"left "<<c<<endl;
            if(mp.count(c))
            {
                mp[c] +=1;
                if(mp[c]>0)
                    total +=1;
            }
            ++left;
        }
        if(total==0)
        {
            
            if(right-left< minR-minL)
            {
                minR=right;
                minL=left;
            }
        }
        //cout<<total<<endl;
    }
        
    if(minR==m)
        return res;
     res=s.substr(minL, minR-minL +1 );   
        
    return res;    
    }
};