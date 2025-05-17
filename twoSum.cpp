#include <algorithm>
#include <iterator>
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
