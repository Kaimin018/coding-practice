// leetcode-58
int lengthOfLastWord(char * s){

    int i = 0;
    int num = 0;
    int size = strlen(s);
    
    while ( i <= size-1){
        if(s[size-1-i] != ' ') num++;
        if (num != 0 && s[size-1-i] == ' ') break;
        i++;
    }
    return num;
}