class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char c:word1)
            mp1[c]++;
        for(char c:word2)
            mp2[c]++;
        if(mp1.size()!=mp2.size())
            return false;
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end()){
                return false;
            }
        }
        int maxfrequency1=0,maxfrequency2=0;
        for(auto it:mp1)
            maxfrequency1=max(maxfrequency1,it.second);
        for(auto it:mp2)
            maxfrequency2=max(maxfrequency2,it.second);
        if(maxfrequency1!=maxfrequency2)
            return false;
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        for(auto it:mp1){
            freq1[it.second]++;
        }
        for(auto it:mp2){
            freq2[it.second]++;
        }
        for(auto it:freq1){
            if(it.second!=freq2[it.first])
                return false;
        }
        return true;
    }
};