// uva-623
#include <bits/stdc++.h>
using namespace std;

#define e 2.71828
#define pi 3.14159
#define arr_size 501

int main()
{
	int a;
	while (cin >> a){
		// find the digits
		// double digits = 0.5*(log10(2*pi) + log(a)) + a*log10(a) - a*log10(e)+1; //follow the formula
		// int arr_size = ceil(digits)/4;
		int arr[arr_size] = {1};
		
		for (int i=2; i<=a; i++){
			for (int j=0; j<arr_size; j++){
				arr[j] *=i;
			}
			// cout << i << "!=";
			for (int j=0; j<arr_size; j++){
				if (arr[j] >= 1000000){
					arr[j+1] = arr[j+1] + arr[j]/1000000;
					arr[j] = arr[j]%1000000;
				}
				// cout << setw(7) << arr[j] << " ";
			}
			// cout << endl;
		}
		int end = arr_size -1;
		while (end > 0 && !arr[end]) --end;
		cout << a << "!" << endl << arr[end--];
		while (end >=0) printf("%06d", arr[end--]);
		cout << endl;
	}
	return 0;
}
