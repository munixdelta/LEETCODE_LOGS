class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        long long sum = 0;
        int left = 0;
        long long maxsum = 0;
        for (int right = 0; right < nums.size(); right++) {
            while(st.count(nums[right])){
                sum-=nums[left];
                st.erase(nums[left]);
                left++;
            }
            if (right - left + 1 > k) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            st.insert(nums[right]);
            if (right - left + 1 == k) 
                maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};