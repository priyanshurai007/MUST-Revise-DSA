class Solution(object):
    def maxProfit(self, prices):
        mini=prices[0]
        maxProfit=0
        for i in range(len(prices)):
            maxProfit=max(maxProfit,prices[i]-mini)
            mini=min(mini,prices[i])

        return maxProfit
        