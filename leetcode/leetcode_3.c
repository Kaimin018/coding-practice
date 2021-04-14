int lengthOfLongestSubstring(char * s){
    
    int str[128] = {0};
    int left = 0, right = 0;
    int res = 0;
    int i = 0;
    
    while (s[i]!='\0'){
        i++;
    }
    int length =i;
    
    while (right<length){
        char r = s[right];
        str[r]++;
        
        while (str[r] > 1){
            char l = s[left];
            str[l]--;
            left++;
        }
        
        res = (res>right-left+1)? res:right-left+1;
        right++;
    }
    
    
    return res;

}
