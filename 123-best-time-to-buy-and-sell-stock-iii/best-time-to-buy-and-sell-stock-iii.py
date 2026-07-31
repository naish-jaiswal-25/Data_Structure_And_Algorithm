class Solution:
    def maxProfit(self, prices):
        n = len(prices)
        dp = {}

        def solve(i, transactions, buy):
            if i == n or transactions == 0:
                return 0

            if (i, transactions, buy) in dp:
                return dp[(i, transactions, buy)]

            if buy:
                sell = prices[i] + solve(i + 1, transactions - 1, 0)
                not_sell = solve(i + 1, transactions, 1)
                dp[(i, transactions, buy)] = max(sell, not_sell)

            else:
                buy_stock = -prices[i] + solve(i + 1, transactions, 1)
                not_buy = solve(i + 1, transactions, 0)
                dp[(i, transactions, buy)] = max(buy_stock, not_buy)

            return dp[(i, transactions, buy)]

        return solve(0, 2, 0)