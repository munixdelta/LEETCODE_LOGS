class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1==s2)
            return true;
        if(s1.size()>s2.size())
            return false;
        sort(s1.begin(),s1.end());
        int left=0;
        string ans;
        for(int right=0;right<s2.size();right++){
            ans=s2.substr(left,right-left+1);
            if(ans.size()==s1.size()){
                sort(ans.begin(),ans.end());
                if(ans==s1)
                    return true;
                else
                    left++;
            }
        }
        return false;
    }
};