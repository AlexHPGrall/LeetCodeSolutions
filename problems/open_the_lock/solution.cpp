class Solution {
public:
    vector<int> shift(int code)
    {
        vector<int> res;
        
        for(int p= 1; p<10000;p*=10)
        {
            if(code % (p*10)/p == 9)
                res.push_back(code -  (9*p));
            else
            res.push_back(code +p);
            if(code % (p*10)/p == 0)
            res.push_back(code + (9 *p));
            else
                res.push_back(code -p);
        }
        return res;
    }
    int openLock(vector<string>& dead, string target) {
        
        bool seen[10000]={false};
        
        int targ = stoi(target);
        for(auto s:dead)
            seen[stoi(s)] = true;
        if(seen[targ] || seen[0])
            return -1;
        if(!targ)
            return 0;
        seen[0000] = true;
        queue<int> q;
        q.push(0);
        int turn =0;
        while(!q.empty())
        {
            ++turn;
            int qlen = q.size();
            for(int i = 0; i<qlen; ++i)
            {
                vector<int> neighb = shift(q.front());
                for(int next : neighb)
                {
                    if(seen[next])
                        continue;
                    if(next == targ)
                        return turn;
                    q.push(next);
                    seen[next] = true;
                }
                q.pop();
            }
        }
        return -1;
    }
};