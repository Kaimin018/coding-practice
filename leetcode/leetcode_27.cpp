int removeElement(int* nums, int numsSize, int val){
    
    int *a = (int*)malloc(numsSize * sizeof(int));
    int j=0;
    
    for(int i=0; i<numsSize; i++){
        if (nums[i]!=val){
            a[j] = nums[i];
            j++;
        }
    }
    a = (int*)realloc(a, j * sizeof(int));
    for (int i=0; i<j; i++){
        // printf("%d ", *(a+i));
        nums[i] = a[i];
    }
    // printf("\n");
    return j;
    free(a);

}
