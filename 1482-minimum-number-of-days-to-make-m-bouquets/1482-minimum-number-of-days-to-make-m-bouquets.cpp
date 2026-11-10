class Solution {
public:
    bool ispossible(vector<int> &nums,int day,int m,int k){
        int bouqeycount=0;
        int countflowers=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=day){
                countflowers++;
                if(countflowers==k){
                    bouqeycount++;
                    countflowers=0;
                }
            }
            else{
                countflowers=0;//adjacent flower bloom nhi hua hai. so count=0
            }
            if(bouqeycount>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>bloomDay.size())return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};