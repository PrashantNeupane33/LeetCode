/*You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list. You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 *
 * Example:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 */

#include <cmath>
#include <iostream>
#include <math.h>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;
    ListNode *head = new ListNode(0); // Dummy head
    ListNode *tail = head;
    int carry = 0;
    while (curr1 != nullptr || curr2 != nullptr || carry) {
      int sum = carry;
      if (curr1 != nullptr) {
        sum += curr1->val ;
        curr1 = curr1->next;
      }
      if (curr2 != nullptr) {
        sum += curr2->val ;
        curr2 = curr2->next;
      }
      carry = sum / 10;

      tail->next = new ListNode(sum % 10);
      tail = tail->next;
    }

    return head->next;
  }
};
