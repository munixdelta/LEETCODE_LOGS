class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        vector<int> freqt(128,0);
        vector<int> freqs(128,0);
        for(char c:t)freqt[c]++;
        int left=0;
        int minlen=INT_MAX;
        int start=0;
        for(int right=0;right<s.size();right++){
            freqs[s[right]]++;
            //ye walapart ye dekhta hai ki agar window valid hai toh left se shrink kro wrna right se insert kro
            while(true){
                bool valid=true;
                for(int i=0;i<128;i++){
                    if(freqs[i]<freqt[i]){//dekhta hai ki current substring me t poori tarah se aarha hai ki nhi.
                        valid=false;
                        break;
                    }
                }
                if(valid==false)break;//agar window invalid hua toh whileloop se bhaar aajaega aur right se element insert krega map me
                int windowsize=right-left+1;
                if(windowsize<minlen){
                    minlen=windowsize;
                    start=left;
                }
                freqs[s[left]]--;
                left++;
            }

        }
        if(minlen==INT_MAX)return "";
        else return s.substr(start,minlen);
    }
};