// leetcode-98
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *prev = NULL;
bool func(struct TreeNode* root){
    
    if (!root) return true;
    if (!func(root->left)) return false;
    if (prev && root->val <= prev->val) return false;
    prev = root;
    return func(root->right);
}
bool isValidBST(struct TreeNode* root){

    bool a = func(root);
    prev = NULL;
    return a;   
}