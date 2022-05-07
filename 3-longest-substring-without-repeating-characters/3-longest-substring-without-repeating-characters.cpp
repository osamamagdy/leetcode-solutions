
#include <map>

class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int result = 0;
    map<char, int> occur;
    int temp_result = 0;
    int i = 0;
    int j = 0;
    while (j < s.size())
    {
        if ( occur[s[j]] >= i+1) //this means that the current character is repeated in the current sequence
            //values in the map are one-indexed as this condition can be used in case of the first character
        {
            //here we need to stop counting and start again
            //get the result first
            temp_result = j - i;
            result = max(result, temp_result);
            //move the cursor one step further
            i = occur[s[j]]; //this considered one step further as the values in the map are one-indexed
            //record the current occurence
            occur[s[j]] = j+1;
        }
        else
        {
            occur[s[j]] = j+1;
        }
        j++;
    }
    return max(result, j-i);
}
};

