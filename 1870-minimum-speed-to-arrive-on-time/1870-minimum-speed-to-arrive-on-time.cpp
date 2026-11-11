class Solution {
public:
    bool ispossible(vector<int> &nums,double hour,int speed){
        double curr=0;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1)
                curr+=(double)nums[i]/speed;
            else
                curr+=ceil((double)nums[i]/speed);
            if(curr>hour)return false;
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=10000000;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(dist,hour,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};