class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfrequency=0;
        int maxLen=0;
        int left=0;
        vector<int> freq(26,0);
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxfrequency=max(maxfrequency,freq[s[right]-'A']);
            int windowsize=right-left+1;
            if(windowsize-maxfrequency>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};