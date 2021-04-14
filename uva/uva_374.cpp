// uva-374
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli big_mod(lli a, lli b, lli c){
    if (b==0) return 1;
    else if (b==1) return (a%c);
    else {
        lli divided = big_mod(a, b/2,c);
        if ((b&1) == 0) return (divided* divided) %c;
        else return (divided* divided*a) %c;
    }
}

int main() {
    
    lli b, p, m;
    while (cin >> b >> p >> m){
        cout << big_mod(b,p,m) << endl;
    }
    return 0;
}
