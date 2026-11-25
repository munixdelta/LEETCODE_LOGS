class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> mp;
        for(string s:patterns)mp[s]++;
        int count=0;
        for(int i=0;i<word.size();i++){
            string str="";
            for(int j=i;j<word.size();j++){
                str+=word[j];
                if(mp.find(str)!=mp.end()){
                    count+=mp[str];
                    mp.erase(str);
                }
            }
        }
        return count;
    }
};