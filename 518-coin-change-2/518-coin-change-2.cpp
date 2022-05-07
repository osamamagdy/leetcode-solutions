class Solution {
public:
    int change(int target, vector<int>& coins) {
        vector<int> results (target+1);
        results[0]=1;
        for(int k = 0 ; k < coins.size() ; k++)
        {
            for(int i = coins[k] ; i <= target ; i++)
            {
                results[i] += results[i - coins[k]];
            }
        }
        return results[target];
    }
};