//uva-11428 Cubes
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM 10000 

int box[MAX_NUM+1]={0};

void find(){
    
    int n;
    for(int i=100; i>0; i--){
        for(int j=i-1; j>0; j--){
          n = pow(i,3) - pow(j,3);
          if(n<=MAX_NUM) box[n]=j;
        }
    }
}

int main() {
    
    int num;
    find();
    while(scanf("%d", &num)!=EOF){
        if(num==0) break;
        if(box[num]){
            int a= pow(box[num], 3) + num;
            float b = pow(a, 1.0/3);
            printf("%.0f %d\n", b, box[num]);
        }
        else printf("No solution\n");
    }
    
    return 0;
    
}