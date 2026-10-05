class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x += nums[i];
            prefix[i] = x;
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int needed=prefix[i]-k;
            if(mp.find(needed)!=mp.end())
                count+=mp[needed];
            mp[prefix[i]]++;
        }
        return count;
    }
};