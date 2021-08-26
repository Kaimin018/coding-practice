/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode tn;

int cnt(tn* root){
    
    if(root) return 1 + cnt(root->left) + cnt(root->right);
    return 0;
}

void inorder(tn* root, int** res){
    
    if(root){
        inorder(root->left, res);
        *((*res)++) = root->val;
        inorder(root->right, res);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    *returnSize = cnt(root);
    int* res = (int*)malloc(sizeof(int)*(*returnSize));
    memset(res, 0, (*returnSize)*sizeof(int));
    int *cpy = res;
    inorder(root, &cpy);
    return res;
}