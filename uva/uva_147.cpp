// uva-147
#include <bits/stdc++.h>
using namespace std;
#define a_length 300/0.05

int main()
{
	float input;
	int tmp;
	int a_len = (int)a_length;
	int64_t a[(int)a_len + 2] = {1};
	// float coin[] = {0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10, 20, 50, 100};
	int coin[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};  //全部乘20
	int coin_kinds = sizeof(coin)/ sizeof(coin[0]);
	
	for (int i=0; i<coin_kinds; i++){
			for (int j=0; j<a_len; j++){
				if (j + coin[i] > a_len)  break;
				
				a[j + coin[i]] += a[j];
				
				// int subscript = (int)((j*0.05 + coin[i])*20);  // 除0.05 = 乘20
				// int cc = (int)(coin[i]*20);						// 除0.05 = 乘20
				// a[subscript] = a[subscript] + a[subscript-cc];
			}
			
		// 	for (int j=0; j<15; j++){
		// 		printf("%3d", a[j]);
		// 	}
		// cout << endl;
	}
	
	while (cin >> input){
		if (input == 0) break;
		
		tmp = (int)(input*20);    // 除0.05 = 乘20
		printf("%6.2f %16lld\n", input, a[tmp]);
	}
	return 0;
}
