class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = INT_MIN;   // To store the maximum profit
        int mini = prices[0];      // Track the minimum price so far

        for(int i = 0; i < n; i++){
            int profit = prices[i] - mini;   // Profit if bought at 'mini' and sold today
            mini = min(prices[i], mini);     // Update the minimum price
            maxProfit = max(maxProfit, profit); // Update the maximum profit
        }

        return maxProfit;
    }
};
