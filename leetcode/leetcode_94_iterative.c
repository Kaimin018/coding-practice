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

// inorder -> 左中右
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    int *res = NULL;

    if (!root) {
        *returnSize = 0;
        return NULL;
    }
        
    int *left_arr = NULL, *right_arr = NULL, left_size = 0, right_size = 0;
    
    if (root->left) left_arr = inorderTraversal(root->left, &left_size);
    if (root->right) right_arr = inorderTraversal(root->right, &right_size);
    
    *returnSize = left_size + 1 + right_size;
    res = (int*)malloc(*returnSize * sizeof(int));
    
    int i=0;
    for (i=0; i<left_size; i++){
        res[i] = left_arr[i];
    }
    res[i++] = root->val;
    for (int j=0; j<right_size; j++){
        res[i+j] = right_arr[j];
    }
    free(left_arr);
    free(right_arr);
    return res;
}