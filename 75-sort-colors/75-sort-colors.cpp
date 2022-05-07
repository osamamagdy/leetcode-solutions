class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for(int i = 0 ; i< nums.size() ; i++)
        {
            count[nums[i]]++;
        }
        int index = 0;
        for(int j = 0 ; j < 3 ; j ++)
        {
            for(int i = 0 ; i < count[j] ; i++)
            {
                nums[index] = j;
                index++;
            }
        }
        
    }
};