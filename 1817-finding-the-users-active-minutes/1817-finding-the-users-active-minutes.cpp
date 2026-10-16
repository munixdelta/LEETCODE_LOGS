class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k,0);
        unordered_map<int,set<int>> mp;
        for(int i=0;i<logs.size();i++){
            int id=logs[i][0];
            mp[id].insert(logs[i][1]);
        }
        for(auto it:mp){
            ans[it.second.size()-1]++;
        }
        return ans;
    }
};