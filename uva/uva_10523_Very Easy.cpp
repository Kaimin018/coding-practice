// uva-10523
//Ref: https://blog.csdn.net/mobius_strip/article/details/8278366
#include <bits/stdc++.h>
using namespace std;

#define N 10000000000000
#define arr_size 40
int64_t arr[arr_size+1];
int64_t s[arr_size+1];

int main() {
    
    int n, a;
    while(scanf("%d %d", &n, &a)!=EOF){
        
        memset(arr, 0, sizeof(arr));
        memset(s, 0, sizeof(s));
        arr[0]=a;
        s[0]=a;
        for(int i=2; i<=n; i++){
            for(int j=0; j<=arr_size; j++){
                arr[j]*=a;
            }
            for(int j=0; j<=arr_size; j++){
                arr[j+1] += arr[j]/N;
                arr[j] = arr[j]%N;
            }
            for(int j=0; j<=arr_size; j++){
                s[j]+= arr[j]*i;
            }
            for(int j=0; j<=arr_size; j++){
                s[j+1] += s[j]/N;
                s[j] = s[j]%N;
            }
        }
        int end = arr_size;
		while (end > 0 && !s[end]) end--;
		printf("%lld", s[end--]);
		while (end >=0) printf("%013lld", s[end--]);
		cout << endl;
    
    }
    return 0;
}