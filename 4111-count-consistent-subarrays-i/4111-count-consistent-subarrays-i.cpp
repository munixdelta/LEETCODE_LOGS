class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count=0;
        int mini;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            mini=nums[i];
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
                a=a & nums[j];
                if(a==mini)count++;  
            }
        }
        return count;
    }
};