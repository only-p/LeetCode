/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    const hash = {};
    const ans = []
    strs.forEach(str => {
        const sorted = str.split('').sort().join('');
        if (!hash[sorted]) {
            hash[sorted] = [];
        }
        hash[sorted].push(str);
    })

    for (const [key, value] of Object.entries(hash)) {
        ans.push(value);
    }
    return ans;
};