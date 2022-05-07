class Solution {
public:
 bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        if(sum %2!=0 || n==1)
            return false;
        sum/=2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<=sum; j++){
                if(j==0){
                    dp[i][0]=true;
                    continue;
                }
                if(i>0 && dp[i-1][j]){
                    dp[i][j]=true;
                    continue;
                }
                if(i>0 && j>=nums[i-1] && dp[i-1][j-nums[i-1]]){
                    dp[i][j]=true;
                    continue;
                }
            }
            if(dp[i][sum]==true)
                return true;
        }
        return false;
    }};