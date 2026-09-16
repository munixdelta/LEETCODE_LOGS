class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> countnum2;
        for(int x:nums2){
            countnum2[x]=1;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(countnum2[nums1[i]]==1){
                ans.push_back(nums1[i]);
                countnum2[nums1[i]]=0;
            }
        }
        return ans;
    }
};