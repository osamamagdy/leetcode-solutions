class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector< unsigned long long int> result(target+1);
        sort(nums.begin(), nums.end());
        result[0]=1;
        for(int i = 1 ; i <= target ; i++)
        {
            for(int k = 0 ; k<nums.size(); k++)
            {
                if(i<nums[k]) break;
                result[i] += result[i-nums[k]];
            }
        }
        return result[target];
    }
};