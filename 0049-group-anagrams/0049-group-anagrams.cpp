class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        int a=0;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(mp.find(strs[i])==mp.end()){
                mp[strs[i]]=a;
                ans.push_back({});
                a++;
            }
            int index=mp[strs[i]];
            ans[index].push_back(s);
        }

        return ans;
    }
};