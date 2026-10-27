class Solution {
public:
    bool ispossible(vector<int>& piles, int hours, int k) {
        int totalhours = 0;
        for (int i = 0; i < piles.size(); i++) {
            int time = piles[i] / k;
            if (piles[i]%k!= 0)
                time++;
            totalhours += time;
            if (totalhours > hours)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = -1;
        int low = 1, high = piles[n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low=mid + 1;
            }
        }
        return ans;
    }
};