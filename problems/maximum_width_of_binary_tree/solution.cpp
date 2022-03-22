/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<unsigned long long> indexQ;
        q.push(root);
        indexQ.push(1);
        unsigned long long res=1;
        while(!q.empty())
        {
            long long start=INT_MAX;
            long long end=INT_MIN;
            int count=q.size();
            int sz=count-1;
            long long startIndex=-1;
            while(count--)
            {
                long long i=indexQ.front();
                if(startIndex==-1)
                    startIndex=i;
                
                i-=startIndex;
                TreeNode* curr=q.front();
                q.pop();
                indexQ.pop();
                
                if(curr->left)
                {
                    q.push(curr->left);
                    indexQ.push(2*i);
                    start=min(start, (2*i));
                    end=max(end,(2*i));
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    indexQ.push((2*i)+1);
                    start=min(start, (2*i)+1);
                    end=max(end,(2*i)+1);

                        
                }
                
            }
            //cout<<start<<endl;
            if(start!=INT_MAX && end!=INT_MIN)
                res=max(res, (unsigned long long) end-start+1);
        }
        return (int)res;
        
    }
};