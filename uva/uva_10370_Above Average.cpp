// uva-10370
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, num;
	cin >> a;
	for (int i=0; i<a; i++){
		cin >> num;
		int *arr = new int[num];
		int sum = 0, count = 0;
		for (int j=0; j<num; j++){
			cin >> arr[j];
			sum += arr[j];
		}
		sum /=num;
		for (int j=0;j<num; j++){
			if (arr[j]>sum) count++;
		}
		printf("%.3f%%\n", (float)100*count/num);
		delete(arr);
	}
	
	return 0;
}