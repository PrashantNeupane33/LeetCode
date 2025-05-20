/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays. The overall run time complexity should
 * be O(log (m+n)).*/

#include <climits>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();
    int low = 0;
    int high = x;

    while (low <= high) {
      int partition_nums1 = (low + high) / 2;
      int partition_nums2 = (x + y + 1) / 2 - partition_nums1;

      int left_nums1 =
          (partition_nums1 == 0) ? INT_MIN : nums1[partition_nums1 - 1];
      int right_nums1 =
          (partition_nums1 == x) ? INT_MAX : nums1[partition_nums1];

      int left_nums2 =
          (partition_nums2 == 0) ? INT_MIN : nums2[partition_nums2 - 1];
      int right_nums2 =
          (partition_nums2 == y) ? INT_MAX : nums2[partition_nums2];

      if (left_nums1 <= right_nums2 && left_nums2 <= right_nums1) {
        if ((x + y) % 2)
          return max(left_nums1, left_nums2);
        else
          return (max(left_nums1, left_nums2) + min(right_nums1, right_nums2)) /
                 2.0;
      } else if (left_nums1 > right_nums2)
        high = partition_nums1 - 1;
      else
        low = partition_nums1 + 1;
    }
    return -1;
  }
};

// Solution:

/* Array 1: [A1, A2, A3, A4, A5, A6]
 *           Left_A  |  Right_A
 * Array 2: [B1, B2, B3, B4, B5]
 *           Left_B  |  Right_B
 */

// We need to partition such that left_A+left_B=right_A+right_B
// the partition should satify the condition that every element in right must be greater than each element in left.
// The search for indices from which such partition is obtained is done by binary search.
