class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A.empty()||B.empty())  
            return 0;  
        int dp[A.length()+1][B.length()+1];  
        memset(dp,0,sizeof(dp));  
        int n=A.length();  
        int m=B.length();  
        int maxp=INT_MIN;  
        for(int i=1;i<=n;++i)  
            for(int j=1;j<=m;++j){  
                if(A[i-1]==B[j-1])  
                    dp[i][j]=dp[i-1][j-1]+1;  
                else  
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
                maxp=max(dp[i][j],maxp);      
            }  
        return maxp;      
    }
};
