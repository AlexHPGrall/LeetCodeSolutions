class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res;
        int n=s.size();
        if(k==1)
        {
            res= s;
            for(int i=1; i<n; ++i)
                res=min(res, s.substr(i)+s.substr(0,i));
        }
        else{
            sort(s.begin(),s.end());
            res=s;
        }
        return res;
    }
};