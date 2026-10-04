class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalSubarrays = 0;
        int pMin = -1, pMax = -1, pBad = -1;
        int sz = nums.size();

        for (int idx = 0; idx < sz; ++idx) {
            const int val = nums[idx];

            if (val < minK || val > maxK) {
                pBad = idx;
            }
            if (val == minK) {
                pMin = idx;
            }
            if (val == maxK) {
                pMax = idx;
            }

            int closestValidStart = (pMin < pMax) ? pMin : pMax;
            if (closestValidStart > pBad) {
                totalSubarrays += (closestValidStart - pBad);
            }
        }

        return totalSubarrays;
    }
};
