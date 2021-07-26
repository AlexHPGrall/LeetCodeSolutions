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
    TreeNode* TreeBuilder(vector<int>& nums, int l, int r)
    {
        
        TreeNode *root=new TreeNode();
        if(r==l)
        {
            root->val = nums[r];
            return root;
        }
        if(r-l ==1)
        {
            root->val=nums[l];
            TreeNode *right=new TreeNode();
            right->val = nums[r];
            root->right =right;
            return root;
        }
        int mid =(l+r)/2;
        root->val = nums[mid];
        root->left = TreeBuilder(nums,l,mid-1);
        root->right = TreeBuilder(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return TreeBuilder(nums, 0, nums.size()-1);
    }
};