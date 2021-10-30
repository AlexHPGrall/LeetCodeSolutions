class Solution {
public:
    int n;
    vector<int> hash;
    vector<long long>power;
    void RabinHash(string &s)
    {
       
        int mod = 1000000007;
        
       
        for(int i = 0; i < n; i++)  
            power[i] = (i == 0) ? 1 : (power[i-1] * 31) % mod;
        //cout<<"test"<<endl;
         for(int i = 0;i<n;i++){
            hash[i+1] = (hash[i] + (s[i]- 'a' + 1)*power[i])%mod;
        }  
        
    }
    
    
    
    int RabinKarp(string &s, int m)
    {
        unordered_map<int,vector<int>> hshmap;
        int mod = 1000000007;
        //cout<<hash<<endl;
        for(int i =0; i<=n-m; ++i)
        {
            long long cur_h = (hash[i+m] - hash[i] + mod)%mod;
            cur_h = (cur_h * power[n-i-1]) % mod;
            //cout<<rolhsh<<endl;
            if(hshmap.count(cur_h) != 0)
            {
                for(int index:hshmap[cur_h])
                    if(s.substr(index,m).compare(s.substr(i,m)) == 0)
                        return index;
                
            }
            hshmap[cur_h].push_back(i);
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        n =s.length();
        string res;
        if(n==2)
        {
            if(s[0] == s[1])
            {
                res.push_back(s[0]);
                return res;
            }
                
            return "";
        }
        if(n==3)
        {
            if(s.substr(0,2).compare(s.substr(1,2)) == 0)
                return s.substr(0,2);
            if(s[0] == s[1] || s[0] == s[2])
                {
                res.push_back(s[0]);
                return res;
            }
            if(s[1] == s[2])
               {
                res.push_back(s[1]);
                return res;
            }
            return "";
        }
        hash.resize(n+1,0);
        power.resize(n);
        
        RabinHash(s);
        int l =1;
        
        int r =n;
        
        while(l<r)
        {
            int mid =(l+r)/2;
            bool found=false;
            //cout<<l<<" "<<mid<<" "<<r<<" "<<n<<endl;
            int i = RabinKarp(s, mid);
            if(i!=-1)
            {
                //cout<<i<<" "<<mid<<endl;
                res=s.substr(i,mid);
                found =true;
            }
            if(found)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        
        return res;
    }
};