class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=p.size();
        int m=s.size();
        if(n>m)return ans;
        int left=0;
        vector<int> freqp(26,0);
        vector<int> freqs(26,0);
        for(char c:p)
            freqp[c-'a']++;
        for(int right=0;right<m;right++){
            freqs[s[right]-'a']++;
            if(right-left+1>n){
                freqs[s[right-n]-'a']--;
                left++;
            }
            if(freqp==freqs)ans.push_back(left);
        }
        return ans;
    }
};