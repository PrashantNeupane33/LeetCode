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

std::string add_big_ass_number(std::string int1, std::string int2) {
  std::string result = "";
  int carry = 0, sum = 0, i = int1.size() - 1, j = int2.size() - 1;
  while (i >= 0 || j >= 0 || carry) {
    sum = carry;
    if (i >= 0)
      sum += int1[i--] - '0';
    if (j >= 0)
      sum += int2[j--] - '0';
    carry = sum / 10;
    result.insert(result.begin(), (sum % 10) + '0');
  }

  return result;
}

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    std::string integer1 = "";
    std::string integer2 = "";
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;
    while (curr1 != nullptr) {
			integer1.insert(integer1.begin(),curr1->val+'0');
      //integer1 += std::to_string(curr1->val);
      curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
			integer2.insert(integer2.begin(),curr2->val+'0');
			//integer2 += std::to_string(curr2->val);
      curr2 = curr2->next;
    }
    std::string result = add_big_ass_number(integer1, integer2);

    // making node of results
    ListNode *head = new ListNode(0);
    ListNode *tail = head;

    for (int i = result.size() - 1; i >= 0; i--) {
			tail->next= new ListNode(result[i]-'0');
			tail=tail->next;
    }

    return head->next;
  }
};

int main()
{
	std::string int1="9";
	std::string int2="";
	std::string results=add_big_ass_number(int1,int2);
	std::cout<<results<<std::endl;
	return 0;
}
