/*
    LCA of regular binary tree, did this iteratively and kinda slow so maybe recursive is just simpler/better overall
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
        vector<unordered_set<TreeNode*>> pAncestors, qAncestors;
        vector<TreeNode*> levels; // for current traversal
        unordered_set<TreeNode*> visited;
        TreeNode* tmp = root;
        while (true) {
            cout << tmp->val << endl;
            levels.push_back(tmp);
            visited.insert(tmp);
            if (p == tmp) {
                for (int i = 0; i < levels.size(); i++) {
                    if (pAncestors.size() < i + 1) {
                        pAncestors.push_back(unordered_set<TreeNode*>());
                    }
                    pAncestors[i].insert(levels[i]);
                }
            }
            if (q == tmp) {
                for (int i = 0; i < levels.size(); i++) {
                    if (qAncestors.size() < i + 1) {
                        qAncestors.push_back(unordered_set<TreeNode*>());
                    }
                    qAncestors[i].insert(levels[i]);
                }
            }
            if (tmp->left && visited.find(tmp->left) == visited.end()) {
                tmp = tmp->left;
            }
            else if (tmp->right && visited.find(tmp->right) == visited.end()) {
                tmp = tmp->right;
            }
            else {
                if (tmp == root) {
                    break;
                }
                else {
                    levels.pop_back();
                    tmp = levels[levels.size() - 1];
                    levels.pop_back(); // we're going to revisit the last level
                }
            }
        }
        cout << pAncestors.size() << ", " << qAncestors.size() << endl;
        for (int i = min(pAncestors.size()-1, qAncestors.size()-1); i >= 0; i--) {
            for (auto it = pAncestors[i].begin(); it != pAncestors[i].end(); it++) {
                if (qAncestors[i].find(*it) != qAncestors[i].end())
                    return *it;
            }
        }
        return NULL; // should never reach here really
    }
};