class Solution {
public:
    struct TrieNode
    {
        TrieNode *next[2]={0,0};
    };
    void insert(TrieNode *root, int n)
    {
        int i=31;
        while(i>=0)
        {
            int j=n&(1<<i)?1:0;
            if(root->next[j])
                root=root->next[j];
            else
            {
                root->next[j] = new TrieNode;
                root=root->next[j];
            }
            --i;
        }
    }
    int find(TrieNode *root,  int n)
    {
        int i=31;
        int m=0;
        while(i>=0)
        {
            int j=n&(1<<i)?1:0;
            if(root->next[j])
            {
                root=root->next[j];
                m|=(j<<i);
            }
                
            else
            {
                root=root->next[!j];
                m|=(!j)<<i;
            }
            --i;
        }
        return m;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root=new TrieNode;
        for(int n:nums)
        {
            insert(root, n);
        }
        int res=0;
        for(int n:nums)
        {
           int m =~n;
            res = max(res,find(root,m)^n);
        }
        
        return res;
    }
};