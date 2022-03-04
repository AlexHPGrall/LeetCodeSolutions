class Solution {
public:
    string s;
    bool bt(vector<int> freq, int d )
    {
        if(d==1)
        {
            for(int i =2; ~i;--i)
            {
                if(freq[i])
                {
                    freq[i]--;
                    s.push_back('0'+i);
                    if(bt(freq,2 ))
                        return true;
                    s.pop_back();
                    freq[i]++;
                }
            }
        
        }
        if(d==2)
        {
            int mx=9;
            if(s[0]=='2')
            {
                mx=3;
            }
            for(int i =mx; ~i;--i)
            {
                if(freq[i])
                {
                    freq[i]--;
                    s.push_back('0'+i);
                    if(bt(freq,3))
                        return true;
                    s.pop_back();
                    freq[i]++;
                }
            }
            
        }
        if(d==3)
        {
            s.push_back(':');
            if(bt(freq,4))
                return true;
            s.pop_back();
            
        }
        if(d==4)
        {
            for(int i =5; ~i;--i)
            {
                if(freq[i])
                {
                    freq[i]--;
                    s.push_back('0'+i);
                    if(bt(freq,5))
                        return true;
                    s.pop_back();
                    freq[i]++;
                }
            }
        }
        if(d==5)
        {
            for(int i =9; ~i;--i)
            {
                if(freq[i])
                {
                    
                    s.push_back('0'+i);
                        return true;
                }
            }
        }
        return false;

                
        
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> freq(10,0);
        for(int n:arr)
            freq[n]++;
        if(!freq[0]&& !freq[1]&&!freq[2])
            return "";
        if(bt(freq,1))
            return s;
        else 
            return "";

    }
};