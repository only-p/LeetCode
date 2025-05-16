/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {

    const umap = {}
    let cnt =0;
    let ans =1;
    let left =0;
    if(s.length ===0)return 0;
    umap[s[0]]=1;
    for(let right=1;right<s.length;right++){
        while(umap[s[right]]){
            delete umap[s[left]];
            left++
        }
        umap[s[right]] = 1;
        ans = Math.max(ans,right-left+1);
    }
    return ans;
};