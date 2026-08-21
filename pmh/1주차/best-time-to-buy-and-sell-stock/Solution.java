class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.length; i++) {
            // 오늘 팔았을 때 얻을 수 있는 이익
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);

            // 지금까지의 최소 가격 갱신
            minPrice = Math.min(minPrice, prices[i]);
        }

        return maxProfit;
    }
}