class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        bool flag=false;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                flag=true;
                return mid;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        int ans=nums.size();
        if(!flag){
            for(int i=0;i<nums.size();i++){
                if(nums[i]>target && i!=nums.size()){
                    ans=i;
                    break;
                }
            }
        }
        return ans;

    }
};