class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixsum;
        long long sum=0;
        for(int x:nums){
            sum+=x;
            prefixsum.push_back(sum);
        }
        int count=0;
        int n=prefixsum.size();
        for(int i=0;i<n;i++){
            if(i!=n-1){
                if(prefixsum[i]>=(prefixsum[n-1]-prefixsum[i]))count++;
            }
        }
        return count;
    }
};