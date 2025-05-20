/**
 * @param {number[]} prices
 * @return {number}
 */
function fn(prices, idx, buy, cnt, dp) {
    if (idx === prices.length) return 0;
    if (cnt >= 2) return 0
    if (dp[idx][buy] !== -1) return dp[idx][buy];

    if (buy) {
        const included = -prices[idx] + fn(prices, idx + 1, 0, cnt, dp);
        const notIncluded = fn(prices, idx + 1, 1, cnt, dp);
        return dp[idx][buy] = Math.max(included, notIncluded);
    } else {
        const included = prices[idx] + fn(prices, idx + 1, 1, cnt + 1, dp);
        const notIncluded = fn(prices, idx + 1, 0, cnt, dp);
        return dp[idx][buy] = Math.max(included, notIncluded);

    }
}
var maxProfit = function (prices) {
    let buy1 = -Infinity, sell1 = 0;
    let buy2 = -Infinity, sell2 = 0;
    
    for (let price of prices) {
        buy1 = Math.max(buy1, -price);
        sell1 = Math.max(sell1, buy1 + price);
        buy2 = Math.max(buy2, sell1 - price);
        sell2 = Math.max(sell2, buy2 + price);
    }
    
    return sell2;

};