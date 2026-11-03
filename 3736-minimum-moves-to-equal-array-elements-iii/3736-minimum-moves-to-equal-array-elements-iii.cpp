class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int maxi=*max_element(nums.begin(),nums.end());
        for(int x:nums){
            sum+=maxi-x;
        }
        return sum;
    }
};