// uva-299
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int test_case, num, swp = 0;
    cin >> test_case;
    for (int i=0; i<test_case; i++){
        cin >> num;
        int *arr = new int[num];
        for (int j=0; j<num; j++){
            cin >> arr[j];
        }
        for (int j=0; j<num-1; j++){
            for (int k=0; k<num-1-j; k++){
                if (arr[k]>arr[k+1]){
                    swap(arr[k], arr[k+1]);
                    swp+=1;
                }
            }
        }
        cout << "Optimal train swapping takes " << swp << " swaps." << endl;
        swp=0;
    }

    return 0;
}
