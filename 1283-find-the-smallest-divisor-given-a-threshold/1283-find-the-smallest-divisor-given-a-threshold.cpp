class Solution {
public:
    bool ispossible(vector<int> &nums,int threshold,int k){
        int totalthreshold=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i]/k;
            if(nums[i]%k!=0)
                x++;
            totalthreshold+=x;
            if(totalthreshold>threshold)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=-1;
        int low=1,high=nums[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};