// uva-11332
#include <bits/stdc++.h>
using namespace std;

int64_t sum_digit(int64_t a){
    
    int64_t sum=0;
    for (int i=a; i>0; i/=10){
        sum += i%10;
    }
    if (sum >= 10) return sum_digit(sum);
    else return sum;
}

int main()
{
    int64_t num;
    while (cin >> num &&  num!=0){
        cout << sum_digit(num) << endl;
    }
    return 0;
}
