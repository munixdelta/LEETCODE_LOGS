class Solution {
public:
    bool ispossible(vector<int> &nums,long long k,int pile){
        long long curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i]/pile;
            if(curr>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for(int x:candies)sum+=x;
        if(k>sum)return 0;
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};