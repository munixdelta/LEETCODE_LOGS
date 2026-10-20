class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int x=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans+=pow(26,x)*(columnTitle[i]-'A'+1);
            x++;
        }
        return ans;
    }
};