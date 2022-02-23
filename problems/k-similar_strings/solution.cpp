class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int res=0;
        int len = s1.length();
        queue<string> q;
        unordered_map<string, int> vis;
        q.push(s1);
        vis[s1]=1;
        
        while(!q.empty())
        {
            int n=q.size();
            //cout<<n<<endl;
            while(n)
            {
                string s=q.front();
                q.pop();
                bool f=false;
                if(s==s2)
                    return res;
                for(int i=0; i<len-1;++i)
                {
                    if(s[i] == s2[i])
                        continue;
                    for(int j=i;j<len;++j)
                    {
                        if(s2[j] == s[j] || s2[i]!=s[j] || s2[j]!=s[i] )
                            continue;
                        swap(s[i],s[j]);
                        if(!vis[s])
                        {
                            vis[s]=1;
                            q.push(s);
                        }
                        swap(s[i],s[j]);
                        f=true;
                    }
                    if(f)
                        break;
                }
                if(f)
                {--n; continue;}
                for(int i=0; i<len-1;++i)
                {
                    if(s[i] == s2[i])
                        continue;
                    for(int j=i;j<len;++j)
                    {
                        if(s2[j] == s[j] || s2[i]!=s[j] )
                            continue;
                        swap(s[i],s[j]);
                        if(!vis[s])
                        {
                            vis[s]=1;
                            q.push(s);
                        }
                        swap(s[i],s[j]);
                    }
                }
                n--;
            }
            res++;
        }
        return res;
        
    }
};