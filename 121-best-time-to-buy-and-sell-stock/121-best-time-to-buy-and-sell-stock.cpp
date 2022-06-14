class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
       
        int leastNo = INT_MAX;
        int profit = 0;
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<leastNo)
                leastNo = prices[i];
            profit = prices[i]-leastNo;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};