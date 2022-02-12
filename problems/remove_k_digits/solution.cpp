class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<queue<int>> vq(10);
        int n=num.length();
        for(int i=0;i<n;++i)
        {
            vq[num[i]-'0'].push(i);
        }
                 
        string res;

        for(int i=0;i<n;++i)
        {
            bool f=false;
            //cout<<i<<endl;
            if(k==n-i)
                break;
            for(int j=0; k&&j<num[i]-'0';++j)
            {
                if(!vq[j].empty())
                    //cout<<j<<" "<<vq[j].front()<<endl;
                if(!vq[j].empty() && vq[j].front()-i <=k)
                {
                    k--;
                    f=true;
                    break;
                }
            }
            if(!f)
                res.push_back(num[i]);
            //cout<<endl;
            vq[num[i]-'0'].pop();
        }
        if(res.empty())
            res="0";
        int i=0;
        while(i<res.size() && res[i]=='0')
            ++i;
        if(i>=res.size())
            i=res.size()-1;
        return res.substr(i);
    }
};