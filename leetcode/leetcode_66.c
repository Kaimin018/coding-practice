/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    
    for (int i=digitsSize-1; i>=0; i--){
        if (digits[i]==9)   digits[i]=0;
        else {
            digits[i]++;
            break;
        }
    }
    if (digits[0]==0) *returnSize = digitsSize +1;
    else *returnSize = digitsSize;
    
    int *arr = (int*)malloc(*returnSize * sizeof(int));
    
    if (digitsSize == *returnSize){
        for (int i=digitsSize-1; i>=0; i--){
        arr[i] = digits[i];
        }
    }
    else {
        arr[0] = 1;
        for (int i=digitsSize; i>0; i--){
        arr[i] = digits[i-1];
        }
    }
    return arr;
    free(arr);
}