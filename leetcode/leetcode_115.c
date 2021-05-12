//leetcode-115
int numDistinct(char * s, char * t){

    uint64_t M = strlen(s);
    uint64_t N = strlen(t);
    
    uint64_t **dp = (uint64_t**)calloc(sizeof(void*), (N+1));
    for(int i=0; i<N+1; i++){
        dp[i] = (uint64_t*)calloc(sizeof(uint64_t), (M+1));
    }
    
    for(int j=0; j<M+1; j++){
        dp[0][j] = 1;
    }
    for (int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if (s[j-1] == t[i-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[N][M];
    free(dp);
}