class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int maxlen=0;
        int maxfreq=INT_MIN;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            maxfreq=max(maxfreq,mp[s[right]]);
            while(maxfreq>1){
                if(s[left]==s[right])
                    maxfreq--;
                mp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};