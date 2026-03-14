class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0,ans=0;
        unordered_map<int,int>m;
        for(int high=0;high<fruits.size();high++){
            m[fruits[high]]++;
            while(m.size()>2 ){
                if(m[fruits[low]]==1)m.erase(fruits[low]);
                else m[fruits[low]]--;
                low++;
            }
            ans=max(ans,high-low+1);

        }
        return ans;
        
    }
};