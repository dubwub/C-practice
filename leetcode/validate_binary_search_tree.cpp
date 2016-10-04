/**
    Problem was to validate binary tree input (make sure all left nodes are smaller than root, etc)
    This solution is O(n), too a few tries to get around INT_MIN, INT_MAX weirdness.
    It's recursive and not iterative, which may be bad.

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
    bool recursiveBSTcheck(TreeNode* root, bool minInfinity, bool maxInfinity, int min, int max) {
        if (!root) return true;
        if ((root->val <= min && !minInfinity) || (root->val >= max && !maxInfinity)) return false;
        if (!recursiveBSTcheck(root->left, minInfinity, false, min, root->val)) return false;
        if (!recursiveBSTcheck(root->right, false, maxInfinity, root->val, max)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return recursiveBSTcheck(root, true, true, INT_MIN, INT_MAX);
    }
};