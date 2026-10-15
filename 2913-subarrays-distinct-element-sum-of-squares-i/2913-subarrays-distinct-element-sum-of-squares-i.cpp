class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int distinct=0;
            unordered_map<int,int> freq;
            for(int j=i;j<nums.size();j++){
                if(freq[nums[j]]==0){
                    distinct++;
                    
                }
                sum+=distinct*distinct;
                freq[nums[j]]++;
            }
        }
        return sum;
    }
};