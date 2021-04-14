// uva-10082
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char keyboard[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
    char a;
    char *foo;
    while((a = getchar()) != EOF){
        // cin >> a;
        // a = getchar();
        if (a==' '|| a=='\n') cout << a;
        else{
            foo = find(begin(keyboard), end(keyboard), a);
            printf("%c", *(foo-1));
            // printf("%c %d\n", *foo, foo);
        }
    }
    return 0;
}
