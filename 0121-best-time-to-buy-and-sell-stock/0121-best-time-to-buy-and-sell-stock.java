class Solution {
    public int maxProfit(int[] prices) {
        int mini=prices[0];
        int maxProfit=0;
        for(int i=0; i<prices.length; i++){
            maxProfit=Math.max(maxProfit,prices[i]-mini);
            mini=Math.min(mini,prices[i]);
        }

        return maxProfit;
    }
}