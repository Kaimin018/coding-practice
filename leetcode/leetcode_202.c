// leetcode-202
bool isHappy(int n){
    
    int sum=0;
    while(n>0){
        sum+= (n%10)*(n%10);
        n = n/10;
    }
    if (sum>=10) isHappy(sum);
    else{
        if (sum==1 || sum==7) return 1;
        else return 0;
    }
    return;
}