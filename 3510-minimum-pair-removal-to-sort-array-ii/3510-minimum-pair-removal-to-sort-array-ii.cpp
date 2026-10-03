#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    struct TrackedPair {
        long long aggregate_sum;
        int left_element_id;

        bool operator<(const TrackedPair& secondary) const {
            if (aggregate_sum != secondary.aggregate_sum) {
                return aggregate_sum < secondary.aggregate_sum;
            }
            return left_element_id < secondary.left_element_id;
        }
    };

public:
    int minimumPairRemoval(vector<int>& nums) {
        int total_elements = nums.size();
        if (total_elements <= 1) return 0;

        vector<long long> working_values(total_elements);
        vector<int> left_neighbor(total_elements), right_neighbor(total_elements);

        for (int i = 0; i < total_elements; ++i) {
            working_values[i] = nums[i];
            left_neighbor[i] = i - 1;
            right_neighbor[i] = i + 1;
        }
        right_neighbor[total_elements - 1] = -1;

        set<TrackedPair> active_pairs;
        int unsorted_violations = 0;

        for (int i = 0; i < total_elements - 1; ++i) {
            active_pairs.insert({working_values[i] + working_values[i + 1], i});
            if (working_values[i] > working_values[i + 1]) {
                unsorted_violations++;
            }
        }

        int completed_operations = 0;

        while (unsorted_violations > 0 && !active_pairs.empty()) {
            auto lowest_pair = *active_pairs.begin();
            active_pairs.erase(active_pairs.begin());

            int target_u = lowest_pair.left_element_id;
            int target_v = right_neighbor[target_u];

            if (target_v == -1 || left_neighbor[target_v] != target_u) {
                continue;
            }

            int forward_ptr = right_neighbor[target_v];
            int backward_ptr = left_neighbor[target_u];

            if (forward_ptr != -1) {
                active_pairs.erase({working_values[target_v] + working_values[forward_ptr], target_v});
                if (working_values[target_v] > working_values[forward_ptr]) {
                    unsorted_violations--;
                }
            }
            if (backward_ptr != -1) {
                active_pairs.erase({working_values[backward_ptr] + working_values[target_u], backward_ptr});
                if (working_values[backward_ptr] > working_values[target_u]) {
                    unsorted_violations--;
                }
            }
            if (working_values[target_u] > working_values[target_v]) {
                unsorted_violations--;
            }

            working_values[target_u] = lowest_pair.aggregate_sum;
            right_neighbor[target_u] = forward_ptr;
            if (forward_ptr != -1) {
                left_neighbor[forward_ptr] = target_u;
            }

            if (backward_ptr != -1) {
                active_pairs.insert({working_values[backward_ptr] + working_values[target_u], backward_ptr});
                if (working_values[backward_ptr] > working_values[target_u]) {
                    unsorted_violations++;
                }
            }
            if (forward_ptr != -1) {
                active_pairs.insert({working_values[target_u] + working_values[forward_ptr], target_u});
                if (working_values[target_u] > working_values[forward_ptr]) {
                    unsorted_violations++;
                }
            }

            completed_operations++;
        }

        return completed_operations;
    }
};