class Solution {
public:
    bool ispossible(vector<int> &nums,int maxi,int check){
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>check){
                curr+=(nums[i]-1)/check;
            }
            if(curr>maxi)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,maxOperations,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};