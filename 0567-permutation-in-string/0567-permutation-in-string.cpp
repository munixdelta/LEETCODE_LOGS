class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        sort(s1.begin(),s1.end());
        if(n>m)return false;
        int left=0;
        for(int right=0;right<s2.size();right++){
            if(right-left+1==n){
                string s=s2.substr(left,right-left+1);
                sort(s.begin(),s.end());
                if(s1==s)
                    return true;
                else
                    left++;
            }
            
        }
        return false;
    }
};