/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays. The overall run time complexity should
 * be O(log (m+n)).*/

#include <vector>
using namespace std;
void merge(int *arr, int l, int mid, int h) {
  int i = l, j = mid + 1, k = 0, size = h - l;
  int temp[size + 1];
  while (i <= mid && j <= h) {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  for (; i <= mid; i++)
    temp[k++] = arr[i];

  for (; j <= h; j++)
    temp[k++] = arr[j];

  for (k = 0; k <= size; k++)
    arr[l++] = temp[k];
}

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int size = nums1.size() + nums2.size();
    std::vector<int> temp(size);
    // merging two sorted arrays
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j])
        temp[k++] = nums1[i++];
      else
        temp[k++] = nums2[j++];
    }
    for (; i < nums1.size(); i++)
      temp[k++] = nums1[i];
    for (; j < nums2.size(); j++)
      temp[k++] = nums2[j];
    if (size % 2 == 1)
      return temp[size / 2];
    else
      return (temp[(size / 2) - 1] + temp[size / 2]) / 2.0;
  }
};
