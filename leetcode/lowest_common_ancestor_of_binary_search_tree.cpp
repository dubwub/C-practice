/*
    Lowest common ancestor of a BST
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // when p and q are on opposite sides of the pivot, return the current
        TreeNode* pivot = root;
        while ((p->val > pivot->val && q->val > pivot->val) || 
               (p->val < pivot->val && q->val < pivot->val)) { // can duplicates be in a BST? almost def no
            if (pivot->val > p->val) pivot = pivot->left;
            else pivot = pivot->right;
        }
        return pivot;
    }
};