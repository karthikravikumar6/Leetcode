class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];
        memset(dp,0,sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-2;i>=0;i--){
            //cout<<dp[i+1][n-1]<<"-"<<grid[i][n-1];
            //cout<<endl;
            dp[i][n-1]=dp[i+1][n-1]+grid[i][n-1];
        }
        for(int i=n-2;i>=0;i--){
            dp[m-1][i]+=dp[m-1][i+1]+grid[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j]+grid[i][j],dp[i][j+1]+grid[i][j]);
            }
        }
        
        return dp[0][0];
    }
};