class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel={'a','e','i','o','u'};
        int maxcount=0;
        int left=0;
        int currentmax=0;
        for(int right=0;right<s.size();right++){
            if(vowel.find(s[right])!=vowel.end())
                currentmax++;
            while(right-left+1>k){
                if(vowel.find(s[left])!=vowel.end())
                    currentmax--;
                left++;
            }
            maxcount=max(maxcount,currentmax);
        }
        return maxcount;
    }
};