
#define  modulus 1000000007
class Solution {
public:

    int func(int n, int k, vector<vector<int>>& dp, int remain, int roll)
    {
        if (remain <= 0) return 0;

        if (dp[roll][remain] != -1) return dp[roll][remain];

        dp[roll][remain] = 0;
        if (roll == n - 1)
        {
            if (remain <= k) dp[roll][remain] = 1;
            return dp[roll][remain];
        }



        for (int i = 0; i < k; i++)
        {
            dp[roll][remain] = ((dp[roll][remain] % modulus) + (func(n, k, dp, remain - (i + 1), roll + 1) % modulus)) % modulus;
        }

        return dp[roll][remain];

    }


    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int count = 0;
        if (n == 1)
        {
            if (target <= k) return 1;
            return 0;
        }
        for (int i = 0; i < k; i++)
        {
            count = ((count % modulus) + (func(n, k, dp, target - (i + 1), 1) % modulus)) % modulus;
        }
        return count;
    }
};
