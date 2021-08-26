// uva-10420 
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int lines;
    string country[2001];
    string name;
    
    cin >> lines;
    for (int i=0; i<lines; i++){
    	
    	cin >> country[i];
    	getline(cin, name);
    }
    
    sort(country, country + lines);
    
    for (int i=0; i<lines; i++){
    	printf("%s", country[i].c_str());
    	
    	int count = 0; 
    	int j;
    	for (j=i; j<lines; j++){
    		if (country[i] != country[j]) break;
    	
    		count++;
    	}
    	printf(" %d\n", count);
    	i = j-1;	
    }
    return 0;
}