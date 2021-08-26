//uva-12503
//string提取數字 ref: https://blog.csdn.net/qq_23082575/article/details/108469344
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    scanf("%d", &n);
    int num;
    for(int i=0; i<n; i++){
        
        int step;
        string str;
        scanf("%d", &step);
        
        int sum=0;
        int *p = new int[step];
        // 把換行符號吃掉
        char c = getchar();
        
        for(int j=0; j<step; j++){
            
            getline(cin, str);
            if(str =="LEFT") p[j]=-1;
            else if(str =="RIGHT") p[j]=1;
            else {
                //提取數字部分
                string s0 = str.substr(8, str.size());
                stringstream s1(s0);
                s1>> num;
                p[j] = p[num-1];
            }
            sum+=p[j];
        }
        delete p;
        cout << sum << endl;
    }
    
    return 0;
}