class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> freq(2,0);
        freq[0]=1;
        long long ans=0;
        long long sum=0;
        const int MOD=1e9+7;
        for(int x:arr){
            sum+=x;
            long long rem=sum%2;
            ans=(ans+freq[1-rem])%MOD;
            freq[rem]++;
        }
        return ans;
    }
};