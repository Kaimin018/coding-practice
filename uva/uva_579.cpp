// uva-579
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hour, min;
    float p1, p2, res, tmp;
    while (scanf("%d:%d", &hour, &min)){
        
        if (hour ==0 && min ==0) break;
        
        // cout << hour << " " << min << endl;
        if (hour != 12) p1 = hour*30 + 30*(min/60.0);
        else p1 = 30*(min/60.0);
        p2 = min*6;
        
        // cout << p1 << " " << p2 << " ";
        tmp = abs(p1-p2);
        if (tmp > 180) res = 360 - tmp;
        else if (tmp < 0) res = tmp + 360;
        else res = tmp;
        printf("%.3f\n", res);
    }

    return 0;
}
