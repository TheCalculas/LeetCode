class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = 0, notBuy = 0;
        for(int i=prices.size()-1;i>=0;i--){
            int curBuy , curNotBuy ;
            curBuy = max(-prices[i] + notBuy, buy);
            curNotBuy = max(prices[i] - fee + buy, notBuy);

            buy = curBuy;
            notBuy = curNotBuy;
        }

        return buy;
    }
};