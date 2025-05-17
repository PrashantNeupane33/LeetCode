/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */




#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    //    int complement = 0;
    //    for (int i = 0; i < nums.size(); i++) {
    //      if (nums.at(i) >= target)
    //        continue;
    //      complement = target - nums.at(i);
    //      auto _ret = find(nums.begin() + i + 1, nums.end(), complement);
    //      if (_ret != nums.end()) {
    //        int j = distance(nums.begin(), _ret);
    //        return {i, j};
    //      }
    //    }
    //    return {};
    //  }
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (hash_map.find(complement) != hash_map.end()) {
        return {i, hash_map[complement]};
      }
      hash_map[nums[i]] = i;
    }
    return {};
  }
};
