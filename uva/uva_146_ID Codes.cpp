//uva-146
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	char a[51];
	while(scanf("%s", a) && *a !='#'){
	
		if( next_permutation(a, a+strlen(a)) ) printf("%s\n", a);
		else printf("No Successor\n");
	}
	
	return 0;
}