class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left=0;
        int maxlen=0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            int windowsize=right-left+1;
            while(windowsize-mp[1]>k){
                mp[nums[left]]--;
                left++;
                windowsize--;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};