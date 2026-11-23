class Solution {
public:
    bool checkString(string s) {
        int cnta=0,cntb=0;
        for(char c:s){
            if(c=='a')cnta++;
            else cntb++;
            if(c=='a' && cntb>0)return false;
        }
        return true;
    }
};