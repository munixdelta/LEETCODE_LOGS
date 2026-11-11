class Solution {
public:
    int total(int num,vector<int> &potions,long long success){
        int low=0;
        int high=potions.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long calc=(long long)num*potions[mid];
            if(calc>=success){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==-1)return 0;
        return potions.size()-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int result=total(spells[i],potions,success);
            ans.push_back(result);
        }
        return ans;
    }
};