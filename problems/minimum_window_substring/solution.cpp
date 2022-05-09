class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int l=0,r=(1e5)+1;
        unordered_map<char, int> freq;
        int diff=0;
        for(char c:t)
        {
            freq[c]++;
        }
        for(auto& [c, f]:freq)
        {
            diff+=-f;
        }
        if(freq.count(s[0]))
        {
            diff++;
            freq[s[0]]--;
        }
        //cout<<diff<<endl;
        if(diff==0 && j-i<r-l)
        {

             l=i;
             r=j;
        }
        while(i<=j)
        {
            //cout<<i<<' '<<j<<' '<<diff<<endl;
            if(diff<0&& j<s.size()-1)
            {
                ++j;
                if(freq.count(s[j]))
                {
                    freq[s[j]]--;
                    if(freq[s[j]]>=0)
                        diff++;
                }
                if(diff==0 && j-i<r-l)
                {
                    //cout<<s[j]<<endl;
                    l=i;
                    r=j;
                }
                
            }
            else if(i!=j && diff>=0)
            {
                if(freq.count(s[i]))
                {
                    freq[s[i]]++;
                    if(freq[s[i]]>0)
                        diff--;
                }
                ++i;

                if(diff==0 && j-i<r-l)
                {
                    //cout<<s[j]<<endl;
                    l=i;
                    r=j;
                }
                
            }
            else
                break;
                
        }

        if(r<((1e5)+1))
        {
           
            return s.substr(l, r-l+1);
        }
        
        return "";
    }
};