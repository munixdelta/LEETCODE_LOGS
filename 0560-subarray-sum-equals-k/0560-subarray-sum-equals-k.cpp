class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixsum;
        long long sum=0;
        for(int x:nums){
            sum+=x;
            prefixsum.push_back(sum);
        }
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<prefixsum.size();i++){
            if(mp.find(prefixsum[i]-k)!=mp.end()){
                ans+=mp[prefixsum[i]-k];
            }
            mp[prefixsum[i]]++;
        }
        return ans;
    }
};