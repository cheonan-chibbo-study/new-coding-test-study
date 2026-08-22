class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_price = 0;
        int min_price = prices[0];
        int max_profit = 0;
        int index = 0;

        for(int i = 0; i<prices.size(); i++){
            cur_price = prices[i];

            if(cur_price < min_price){
                min_price = prices[i];
            }
            else{
                if(max_profit < (cur_price-min_price)){
                    max_profit = cur_price-min_price;
                } 
            }
        }
        return max_profit;
    }
};