//uva-136
//ref: https://onlinejudgesolution.blogspot.com/2017/04/uva-136-ugly-numbers-solution-in-c.html
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int res[1500] ={1};
	int t2=0, t3=0, t5=0;
	int j=1;
	int tmp;
	
	for(int i=1; i<1500; i++){
			
			while(res[t2]*2 <= res[i-1]) t2++;
			while(res[t3]*3 <= res[i-1]) t3++;
			while(res[t5]*5 <= res[i-1]) t5++;
			
			tmp = res[t2]*2;
			if(res[t3]*3 < tmp) tmp = res[t3]*3;
			if(res[t5]*5 < tmp) tmp = res[t5]*5;
			res[i] = tmp;

	}

	printf("The 1500'th ugly number is %d.\n", res[1499]);
	
	return 0;
}