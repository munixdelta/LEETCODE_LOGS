class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=nums[0];
        int mini=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            if(maxi-mini>k){
                maxi=nums[i];
                mini=nums[i];
                count++;
            }
            if(i==nums.size()-1){
                count++;
            }
        }
        return count;
    }
};