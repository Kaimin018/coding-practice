/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//leetcode-78 subset
#define LEN 65536

int num = 0;
int pos = 0;
int arr[LEN] = {0};
int size[LEN] = {0};

void dfs(int **ret, int *nums, int numsSize, int start, int SubNum)
 {
     int i = 0;
     if(SubNum == pos)
     {
         ret[num] = malloc(sizeof(int)*numsSize); //二维数组每个数组长度为numsSize
         memcpy(ret[num], arr, sizeof(int)*numsSize);
         size[num] = SubNum;                      //每行长度
         num++;                                   //总共处理后的行数
         return;
     }

     for(i = start; i<numsSize;i++)
     {
         arr[pos++] = nums[i];  //存进一个元素,每行长度pos增加1
         dfs(ret, nums, numsSize, i+1, SubNum);
         pos--;                 //减回去
         
     }
 }

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int **ret = malloc(sizeof(int*)*LEN);
    int i = 0;

    num = 0;
    for(i = 0;i<=numsSize;i++)
    {
        pos = 0;    //处理后的每行长度
        dfs(ret, nums, numsSize, 0, i);
    }

    *returnSize = num;//返回行数

    *returnColumnSizes = malloc(sizeof(void*)*num);
    for(i = 0;i<num;i++)
    {
        (*returnColumnSizes)[i] = size[i];//返回的每行的长度
    }

    return ret;
}