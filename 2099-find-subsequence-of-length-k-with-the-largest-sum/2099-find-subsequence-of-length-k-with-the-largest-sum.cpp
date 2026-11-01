class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int right=temp.size()-1;
        while(k>0){
            mp[temp[right]]++;
            right--;
            k--;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
            }
        }
        return ans;
    }
};