class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums)mp[x]++;
        int ans=k;
        while(mp.find(ans)!=mp.end()){
            ans+=k;
        }
        return ans;
    }
};