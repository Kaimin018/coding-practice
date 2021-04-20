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
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    int *result= NULL;
    *returnSize = 0;
    
    // stack 用來暫時儲存父節點的值
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode*));
    int cur = 0;
    
    while (cur > 0 || root != 0){
        
        if (root){
            stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*) * (cur+1));
            stack[cur++] = root;
            root = root->left;
        }
        else {
            root = stack[--cur];
            result = (int*)realloc(result, sizeof(int) * (*returnSize+1));
            result[*returnSize] = root->val;
            *returnSize +=1;
            root = root->right;
            }
    }
    return result;

}