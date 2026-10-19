class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> finalans;
        if(p.size()>s.size())
            return finalans;
        int left=0;
        int m=p.size();
        int n=s.size();
        vector<int> freqp(26,0);
        vector<int> freqs(26,0);
        for(char c:p)
            freqp[c-'a']++;
        for(int right=0;right<s.size();right++){
            freqs[s[right]-'a']++;
            if(right-left+1>m){
                freqs[s[right-m]-'a']--;
                left++;
            }
            if(freqp==freqs)
                finalans.push_back(left);
            
        }
        return finalans;
    }
};