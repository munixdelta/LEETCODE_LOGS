class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int strictlydec = 1;
        int strictlyinc = 1;
        int currdec=1;
        int currinc=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currinc++;
                strictlyinc=max(strictlyinc,currinc);
            }
            else{
                currinc=1;
            }
            if(nums[i]<nums[i-1]){
                currdec++;
                strictlydec=max(strictlydec,currdec);
            }
            else{
                currdec=1;
            }
        }
        return max(strictlydec,strictlyinc);
    }
};