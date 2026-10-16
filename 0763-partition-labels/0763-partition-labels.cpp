class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        int i=0;
        while(i<s.size()){
            int index=mp[s[i]];
            int maxi=index;
            int k=i;
            while(k<=index){
                int newindex=mp[s[k]];
                maxi=max(maxi,newindex);
                index=maxi;
                k++;
            }
            ans.push_back(index-i+1);
            i=1+index;
            
        }
        return ans;
    }
};