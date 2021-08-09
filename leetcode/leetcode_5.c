// reference: https://blog.csdn.net/AI_lalaland/article/details/78874855
char get_s[5000] = {0};                 

char* longestPalindrome(char* s) {
    
    int i, j, max, flag = 0;
    int n = 0;
    n = (int)strlen(s);
    int len[10000] = {0};               //构建新串，原串每相邻字符间插入'*'，遍历奇数/偶数最大回文子串时对应处理易于理解
    char new_s[10000] = {0};            //记录对应各个位置的最大回文子串长度   

    //构建新串
    new_s[0] = s[0];
    for(i = 1; i < n; ++i){
        new_s[2 * i - 1] = '*';
        new_s[2 * i] = s[i];
    }

    //计算对应各个位置的最大回文子串长度，录入数组
    for(i = 0; i < 2 * n - 1; ++i){
        j = 1;
        max = 0;
        while(i - j >= 0 && i + j < 2 * n - 1 && new_s[i - j] == new_s[i + j])
        {
            ++j;
            ++max;
        }
        
        len[i] = (i % 2 == 0) ? max / 2 * 2 + 1 : (max + 1) / 2 * 2;
    }

    //找到最大值下标（如相同，取最后的）
    for(i = 1; i < 2 * n - 1; ++i){
        flag = len[i] >= len[flag] ? i : flag;
    }

    //将对应子串录入全局变量
    for(i = 0, j = flag / 2 - (len[flag] - 1) / 2; j < flag / 2 + len[flag] / 2 + 1; ++i, ++j)
        get_s[i] = s[j];
    
    get_s[i] = '\0';
    //返回

    return get_s;
}
