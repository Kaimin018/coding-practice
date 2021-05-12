// leetcode-566
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int r1, c1;
    if (matSize*matColSize[0] == r*c){
        r1 = r;
        c1 = c;
    }
    else if (matSize*matColSize[0]%r == 0){
        r1 = r;
        c1 = matSize*matColSize[0]/r;
    }
    else {
        *returnSize = matSize;
        *returnColumnSizes = malloc(sizeof(void*)*matSize);
        for (int i=0; i<matSize; i++){
            (*returnColumnSizes)[i] = matColSize[0];
        }
        return mat;
    }
    
    int **res = (int**)malloc(sizeof(int*)*r1);
    for(int i=0; i<r1; i++){
        res[i] = (int*)malloc(sizeof(int)*c1);
    }
         
        
    *returnSize = r1;
    *returnColumnSizes = malloc(sizeof(void*)*r1);
    for (int i=0; i<r1; i++){
        (*returnColumnSizes)[i] = c1;
    }
    
    int k=0;
    // printf("%d ", matSize);    
    for(int i=0; i<matSize; i++){
        for(int j=0; j<matColSize[0]; j++){
            res[k/c1][k%c1] = mat[i][j];
            k++;
        }
    }
    return res;
    free(res);
}