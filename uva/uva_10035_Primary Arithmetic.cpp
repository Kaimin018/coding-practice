// uva-10035
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t a, b;
	while(scanf("%lld %lld", &a, &b)){
		if (a == 0 && b == 0) break;
		int carry = 0, count = 0;
		
		while(a || b){
			
			if (a%10 + b%10 + carry >= 10){
				carry = 1;
				count++;
			}
			else carry = 0;
			a/=10;
			b/=10;
		}
		if (count == 1) printf("1 carry operation.\n");
		else if (count > 1) printf("%d carry operations.\n", count);
		else printf("No carry operation.\n");
	}
	
	return 0;
}
