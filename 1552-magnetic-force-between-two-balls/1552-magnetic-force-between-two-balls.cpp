class Solution {
public:
    bool ispossible(vector<int>& position, int magnets, int dist) {
        int cntmagnets = 1, last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                cntmagnets++;
                last = position[i];
            }
            if (cntmagnets >= magnets)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int ans = -1;
        int low = 1, high = position[n - 1] - position[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(position, m, mid)) {
                low = mid + 1;
                ans = mid;
            } else
                high = mid - 1;
        }
        return ans;
    }
};