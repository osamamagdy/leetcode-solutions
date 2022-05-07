class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> result(amount+1);
        result[0]=0;
        sort(coins.begin(), coins.end());
        for(int i=1; i<= amount ; i++)
        {
            result[i] = INT_MAX;
            for(int j=0 ; j< coins.size() ; j++)
            {
                if(coins[j] > i) break;
                if(result[i-coins[j]] == INT_MAX) continue;
                result[i] = min(result[i] , result[i-coins[j]]+1);
            }
        }
        if(result[amount]==INT_MAX) result[amount] = -1;
        return result[amount];
    }
};