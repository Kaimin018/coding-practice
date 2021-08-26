// ref: https://blog.csdn.net/mobius_strip/article/details/13631669
#include <bits/stdc++.h>
using namespace std;

int box[51]={0};

int gcd(int a, int b){
    return a%b ? gcd(b, a%b): b;
}

int prime_num(int* box, int num){
    
    int sum=0;
    for(int i=0; i<num-1; i++){
        for(int j=i+1; j<num; j++){
            //判斷box[i]和box[j]是否互質
            if(gcd(box[i], box[j]) == 1) sum++;
        }
    }
    return sum;
}

int main() {
    
    int num;
    while(scanf("%d", &num)!=EOF){
        if(num==0) break;
        
        for(int i=0; i<num; i++){
            scanf("%d", &box[i]);
        }
        int choice = num*(num-1)/2;
        int mutual_prime = prime_num(box, num);
        
        if(mutual_prime){
            double res = 6.0*choice/mutual_prime;
            printf("%.6lf\n", sqrt(res));
        }
        else{
            printf("No estimate for this data set.\n");
        }
    }
    
    return 0;
}