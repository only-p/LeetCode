/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {

    const memo = new Map();
    function dp(coins, amount) {
        if (amount === 0) return 0;
        if (amount < 0) return -1
        if (memo.has(amount)) {
            return memo.get(amount);
        }
        let ans = Infinity;
        coins.forEach(item => {
            const subAns = dp(coins, amount - item);
            if (subAns >= 0) ans = Math.min(ans, subAns + 1);
        })
        const result = ans === Infinity ? -1 : ans
        memo.set(amount, result);
        return result;
    }
    const ans = dp(coins, amount)
    return ans;
};