//uva-11559 
#include <bits/stdc++.h>
using namespace std;

//只要某一個禮拜的床位 > N 即可

int main() {
    
    int N, B ,H, W;
    while(scanf("%d %d %d %d", &N, &B, &H, &W)!=EOF){
        
        int res=B+1;
        
        //for each hotel
        for(int i=0; i<H; i++){
            
            int price;
            scanf("%d", &price);
            
            bool flag=0;
            int *week = (int*)malloc(sizeof(int)*W);
            
            for(int j=0; j<W; j++){
                scanf("%d", &week[j]);
                if(week[j]>=N && res > N*price){
                    res = N*price;
                }    
            }
            free(week);
        }
        if(res==B+1) printf("stay home\n");
        else printf("%d\n", res);
        
    }
    return 0;
}