class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            for(int i=0;i<temp.size();i++){
                string s="";
                s=temp[i];
                ans.push_back(stoi(s));
            }
        }
        return ans;
    }
};