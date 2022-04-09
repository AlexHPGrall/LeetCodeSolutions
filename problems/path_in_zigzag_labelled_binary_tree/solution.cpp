class Solution {
public:
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while(label)
        {
            res.push_back(label);
            label/=2;
        }
        int n=res.size();
        for(int i=1; i<n-1; i+=2)
        {
            
            int x=res[i]-(1<<(n-i-1));
            res[i] = (1<<(n-i))-x-1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};