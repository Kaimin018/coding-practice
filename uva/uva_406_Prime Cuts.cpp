//uva-406 Prime Cuts
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 1000

bool is_prime(int n){
    
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    
    bool box[MAX_NUM+1]={0};
    for(int i=1; i<=MAX_NUM; i++){
        box[i] = is_prime(i);
        // if(box[i]==1) printf("%d ", i);
    }
    int num, c;
    while(scanf("%d %d", &num, &c)!=EOF){
        
        int count = 0;
        int* res = (int*)malloc(sizeof(int)*num);
        for(int i=1; i<=num; i++){
            if(box[i]==1) res[count++] = i;
        }
        res = (int*)realloc(res, sizeof(int)*count);
        printf("%d %d:", num, c);
        if (num==1){
            printf(" 1");
        }
        else if(2*c>count){
            for(int i=0; i<count; i++){
                printf(" %d", res[i]);
            }
        }
        else if(count%2==1){
            for(int i=(count/2)-c+1, j=0; j<2*c-1; i++, j++){
                printf(" %d", res[i]);
            }
        }
        else{
            for(int i=(count/2)-c, j=0; j<2*c; i++, j++){
                printf(" %d", res[i]);
            }
        }
        putchar('\n');putchar('\n');
        free(res);
    }
    
    return 0;
    
}