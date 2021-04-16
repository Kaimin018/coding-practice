// uva-674
#include <bits/stdc++.h>
using namespace std;
#define MAX_dollar 7489

int main()
{
    int coin[] = {1, 5, 10, 25, 50};
    int dollar[MAX_dollar+1] = {1};
    int arr_length = sizeof(coin)/sizeof(int);
    
    for (int i=0; i<arr_length; i++){
    	for (int j=0; j<MAX_dollar; j++){
    		
    		if (j + coin[i] > MAX_dollar) break;
    		
    		dollar[j+coin[i]] += dollar[j];
    	}
    }
    int cent;
    while ((cin >> cent)){
    	cout << dollar[cent] << endl;
    	}
    return 0;
}