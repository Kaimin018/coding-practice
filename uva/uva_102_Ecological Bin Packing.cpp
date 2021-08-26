// uva-102
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t a[9] = {0};
    while (cin >> a[0] >> a[1] >> a[2] >>
            a[3] >> a[4] >> a[5] >> a[6] >>
            a[7] >> a[8] ){
    
    int64_t min = 0, tmp = 0, flag = 0;
// 將所有a內的數相加
    min = accumulate(a , a+9 , min);
    
    if (a[0]+a[4]+a[8] > tmp){
        tmp = a[0]+a[4]+a[8];
        flag = 1;
    }
    if (a[0]+a[5]+a[7] >= tmp){
        tmp = a[0]+a[5]+a[7];
        flag = 2;
    }
    if (a[1]+a[3]+a[8] > tmp){
        tmp = a[1]+a[3]+a[8];
        flag = 3;
    }
    if (a[1]+a[5]+a[6] > tmp){
        tmp = a[1]+a[5]+a[6];
        flag = 4;
    }
    if (a[2]+a[3]+a[7] > tmp){
        tmp = a[2]+a[3]+a[7];
        flag = 5;
    }
    if (a[2]+a[4]+a[6] > tmp){
        tmp = a[2]+a[4]+a[6];
        flag = 6;
    }
    else if (a[2]+a[4]+a[6] == tmp && flag ==4) flag =6;
    
    if (flag ==1) cout << "BGC ";
    else if (flag ==2) cout << "BCG ";
    else if (flag ==3) cout << "GBC ";
    else if (flag ==4) cout << "GCB ";
    else if (flag ==5) cout << "CBG ";
    else if (flag ==6) cout << "CGB ";
    
    cout << min-tmp << endl;
    }
    return 0;
}
