#include <bits/stdc++.h>
using namespace std;

int main(){
	
	vector <int> v;
	int tmp;
	while(cin >> tmp){
		v.push_back(tmp);
	}
	
	// bubble sort
	for (auto i = v.begin(); i<v.end(); i++){
		int ind = distance(v.begin(), i);
		for (auto j= v.begin(); j!=v.end()-ind-1; j++){
			if (*j > *(j+1)) swap(*j, *(j+1));
		}
	}
	
	for (int i:v){
		cout << i << " ";
	}
	
	return 0;
}