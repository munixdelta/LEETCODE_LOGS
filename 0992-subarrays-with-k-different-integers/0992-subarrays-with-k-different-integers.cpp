class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int left=0;
        int count=0;
        unordered_map<int,int> freq;
        int diff=0;
        int maxfrequency=0;
        for(int right=0;right<nums.size();right++){
            if(freq.find(nums[right])==freq.end()){
                diff++;
            }
            freq[nums[right]]++;
            while(diff>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    diff--;
                    freq.erase(nums[left]);
                }
                left++;
            }
                count+=right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};