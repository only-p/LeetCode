class Solution {
    int getSqure(int n){
        int ans = 0;
        while(n){
            ans+=((n%10)*(n%10));
            n/=10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_map<int,int>umap;
        // int result =n;
        // int number =0;
        umap[n]=1;
        while(n!=1){
            n = getSqure(n);
            if(n!=1 && umap.find(n)!=umap.end())return false;
            umap[n]=1;

        }
        return true;
        
    }
};