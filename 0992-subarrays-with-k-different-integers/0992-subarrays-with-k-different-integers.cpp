class Solution {
public:
    int atmost(vector<int> &nums,int k){
        if(k<0)return 0;
        int left=0;
        int distinct=0;
        unordered_map<int,int> mp;
        int count=0;
        for(int right=0;right<nums.size();right++){
            if(mp.find(nums[right])==mp.end())distinct++;
            mp[nums[right]]++;
            while(distinct>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    distinct--;
                    mp.erase(nums[left]);
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