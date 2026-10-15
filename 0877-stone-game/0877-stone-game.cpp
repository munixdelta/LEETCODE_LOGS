class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int low=0,high=piles.size()-1;
        int alicesum,bobsum=0;
        while(low<=high){
            alicesum+=max(piles[low],piles[high]);
            low++;
            high--;
            bobsum+=max(piles[low],piles[high]);
            low++;
            high--;
        }
        return alicesum>bobsum ?true:false;
    }
};