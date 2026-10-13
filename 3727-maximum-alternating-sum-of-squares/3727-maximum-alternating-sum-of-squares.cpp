class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]*=-1;
            }
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(i==j){
                sum+=(nums[i]*nums[i]);
                break;
            }
            else{
                sum+=(nums[j]*nums[j])-(nums[i]*nums[i]);
                i++;
                j--;
            }
        }
        return sum;
    }
};