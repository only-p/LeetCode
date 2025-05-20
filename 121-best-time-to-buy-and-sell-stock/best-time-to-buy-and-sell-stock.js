/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let minTill = prices[0];
    let ans = 0;
    for (let i = 1; i < prices.length; i++) {
        ans = Math.max(ans, prices[i] - minTill);
        minTill = Math.min(minTill, prices[i])
    }
    return ans;
};