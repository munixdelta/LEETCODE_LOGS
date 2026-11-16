class Solution {
public:
    int sumofdigits(string str){
        int sum=0;
        for(int i=0;i<str.size();i++){
            sum+=str[i]-'0';
        }
        return sum;
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            string newstr="";
            for(int i=0;i<s.size();i+=k){
                if(s.size()-i>=k)
                    newstr+=to_string(sumofdigits(s.substr(i,k)));
                else
                    newstr+=to_string(sumofdigits(s.substr(i,s.size()-i)));
            }
            s=newstr;
        }
        return s;
    }
};