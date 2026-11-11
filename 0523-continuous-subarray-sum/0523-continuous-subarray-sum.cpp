class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefixsum;
        int sum = 0;
        for (int x : nums) {
            sum += x;
            prefixsum.push_back(sum);
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        bool ans=false;
        for(int i=0;i<prefixsum.size();i++){
            if(mp.find(prefixsum[i]%k)!=mp.end()){
                if(i-mp[prefixsum[i]%k]>=2){
                    ans=true;
                    break;
                }
            }
            else
                mp[prefixsum[i]%k]=i;
        }
        return ans;
    }
};