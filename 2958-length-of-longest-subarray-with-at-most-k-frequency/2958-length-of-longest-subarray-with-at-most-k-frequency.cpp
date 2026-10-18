class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left=0;
        int maxfrequency=0;
        int maxLen=0;
        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            maxfrequency=max(maxfrequency,freq[nums[right]]);
            while(maxfrequency>k){
                if(freq[nums[left]]==maxfrequency){
                    maxfrequency--;
                }
                freq[nums[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};