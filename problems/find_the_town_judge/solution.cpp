class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n,0);
        vector<int> trustedby(n,0);
        unordered_set<int> candidates;
        if(n==1)
            return 1;
        for(int i=0; i<trust.size();++i)
        {
            trusts[trust[i][0] -1]++;
            if(candidates.count(trust[i][0]))
                candidates.erase(trust[i][0]);
            trustedby[trust[i][1]-1]++;
            if(!trusts[trust[i][1] -1] && !candidates.count(trust[i][1]))
                candidates.insert(trust[i][1]);
        }
        if(candidates.size() ==1)
        {
            auto elem=candidates.begin();
            if(trustedby[*elem-1]==n-1)
                return *elem;
        }
        return -1;
    }
};