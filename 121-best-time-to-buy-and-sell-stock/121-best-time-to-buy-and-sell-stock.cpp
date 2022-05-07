class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_i = 0;
        int max_i = 0;
        int i = 0;
        int profit = 0;
        while(i<prices.size())
        {
            if(prices[i]< prices[min_i]) 
            {
                min_i = i;
                max_i = i;
            }
            else if (prices[i] > prices[max_i])
            {
                max_i = i;
            }
            
            if((prices[max_i] - prices[min_i] )> profit )
            {
                profit = (prices[max_i] - prices[min_i] ); 
            }
            i++;
        }
        return profit;
    }
};