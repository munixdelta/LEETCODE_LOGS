class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(i+1<s.size() && s[i+1]==')'){
                    i++;//yaha hm check kr rhe ki ) ke baad wala bhi ) hi ho toh )) bn gya then hmlog 1 step aur jump krenge. toh loop wale i++ se )) skip hoga.
                }
                else{
                    ans++;
                    //ek closing brace missing tha toh ans me 1 add krdo.
                }// yaha tak closing braces handle hogya hai.. ab opening brace handle krenge.
                if(open>0){
                    open--;// ( hai toh remove krdo.
                }
                else{
                    ans++; // ( missing hai toh ans++.
                }
            }
        }
        return ans+(2*open);
    }
};