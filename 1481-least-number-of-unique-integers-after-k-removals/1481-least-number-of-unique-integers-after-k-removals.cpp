class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int x:arr)mp[x]++;
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        for(auto it:v){
            if(k>=it.second){
                k-=it.second;
                mp.erase(it.first);
            }
            else{
                break;
            }
        }
        return mp.size();
    }
};