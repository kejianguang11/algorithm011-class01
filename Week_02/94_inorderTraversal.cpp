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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     if(!root) return ret;
    //     inorderImp(root,ret);
    //     return ret;
    // }
    // void inorderImp(TreeNode* root,vector<int>& vec) {
    //     if(!root) return;
    //     inorderImp(root->left,vec);
    //     vec.push_back(root->val);
    //     inorderImp(root->right,vec);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            ret.push_back(top->val);
            st.pop();
            cur = top->right;
        }
        return ret;
    }
};
