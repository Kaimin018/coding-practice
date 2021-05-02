// uva-10107
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int64_t tmp;
	int ind;
	vector <int64_t> v;
	int i=1; // how much numbers
	while ( cin >> tmp){
		v.push_back(tmp);
		sort(v.begin(), v.begin()+i);
		
		if (i&1 == 1) {
			// cout << "i= " << i << " median= " << v[i/2] << endl;}
			cout << v[i/2] << endl;}
		
		else {
			// cout << "i= " << i << " median= " << (v[i/2]+v[i/2-1])/2 << endl;}
			cout << (v[i/2]+v[i/2-1])/2 << endl;}
			
		i++;
		
		// for(auto j=0; j<i-1; j++){
		// 	cout << v[j] << " ";
		// }
		// cout << endl;
	}
	
	return 0;
}