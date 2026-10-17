class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winner;
        unordered_map<int,int> loser;
        vector<vector<int>> ans(2);
        for(int i=0;i<matches.size();i++){
            winner[matches[i][0]]++;
            loser[matches[i][1]]++;
        }
        for(auto it:winner){
            if(loser.find(it.first)==loser.end()){
                ans[0].push_back(it.first);
            }
        }
        for(auto it:loser){
            if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};