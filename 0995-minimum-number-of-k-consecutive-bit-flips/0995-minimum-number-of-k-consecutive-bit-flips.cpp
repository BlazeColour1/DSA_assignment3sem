class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int sz = nums.size();
        int active = 0;
        int res = 0;

        for (int i = 0; i < sz; ++i) {
            if (i >= k && nums[i - k] == 3) {
                active--;
            }
            if ((nums[i] + active) % 2 == 0) {
                if (i + k > sz) {
                    return -1;
                }
                nums[i] = 3;
                active++;
                res++;
            }
        }

        return res;
    }
};
