class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if (sum > 9 * num) return "";
        while(num--){
            if(sum>9){
                ans+="9";
                sum-=9;
            }
            else if(sum>0){
                ans+=to_string(sum);
                sum=0;
            }
            else{
                ans+="0";
            }
        }
        return ans;
    }
};