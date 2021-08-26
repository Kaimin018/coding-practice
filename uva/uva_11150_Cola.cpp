//uva-11150 Cola
// ref: https://ssdoz2sk.blogspot.com/2014/05/uva-11150-cola.html
//利用歸納法
//     n:  1   2   3   4   5   6   7   8   9  10
// total:  1   3   4   6   7   9  10  12  13  15
#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 200
int box[MAX_NUM+1]={0};

void func(){
    for(int i=1; i<=MAX_NUM; i++){
        if(i==1) box[i]=1;
        else if(i%2==0) box[i] = box[i-1]+2;
        else box[i] = box[i-1]+1;
    }
    
}

int main() {
    
    func();
    int n;
    while(scanf("%d", &n)!=EOF){
        printf("%d\n", box[n]);
    }
    return 0;
}