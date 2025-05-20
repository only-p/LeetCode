/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    const n = prices.length;
    // Create a 3D DP table: dp[idx][buy][cnt]
    const dp = Array.from({ length: n }, () =>
        Array.from({ length: 2 }, () =>
            Array(2).fill(-1)));

    function fn(idx, buy, cnt) {
        if (idx === n) return 0;
        if (cnt >= 2) return 0;
        if (dp[idx][buy][cnt] !== -1) return dp[idx][buy][cnt];

        if (buy) {
            const buyStock = -prices[idx] + fn(idx + 1, 0, cnt);
            const skipBuy = fn(idx + 1, 1, cnt);
            dp[idx][buy][cnt] = Math.max(buyStock, skipBuy);
        } else {
            const sellStock = prices[idx] + fn(idx + 1, 1, cnt + 1);
            const skipSell = fn(idx + 1, 0, cnt);
            dp[idx][buy][cnt] = Math.max(sellStock, skipSell);
        }
        return dp[idx][buy][cnt];
    }

    return fn(0, 1, 0);
};