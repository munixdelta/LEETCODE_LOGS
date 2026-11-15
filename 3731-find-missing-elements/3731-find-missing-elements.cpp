class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end())
                ans.push_back(i);
        }
        return ans;
    }
};