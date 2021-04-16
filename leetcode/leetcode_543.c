/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int diameterOfBinaryTree(struct TreeNode* root){

    int max_depth = 0;
    DFS(root, &max_depth);
    return max_depth;
}

int DFS(struct TreeNode *root, int *max_depth){
    
    int ld, rd;
    if (!root) return 0;
    
    ld = DFS(root->left, max_depth);
    rd = DFS(root->right, max_depth);
    
    if (ld + rd > *max_depth) *max_depth = ld + rd;
    return (ld+1)>(rd+1)? ld+1: rd+1;
}