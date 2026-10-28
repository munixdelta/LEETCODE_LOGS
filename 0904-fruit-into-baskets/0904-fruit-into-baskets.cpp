class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left=0;
        int maxlen=0;
        int distinct=0;
        for(int right=0;right<fruits.size();right++){
            if(mp.find(fruits[right])==mp.end())
                distinct++;
            mp[fruits[right]]++;
            while(distinct>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    distinct--;
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};