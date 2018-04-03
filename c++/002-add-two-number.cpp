/*
 * O(n)
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode header(0);
    ListNode* cur = &header;
    int carry = 0, sum;
    while (l1 != NULL && l2 != NULL) {
      sum = l1->val + l2->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur->next = new ListNode(sum);
      l1 = l1->next;
      l2 = l2->next;
      cur = cur->next;
    }
    while (l1 != NULL) {
      sum = l1->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur->next = new ListNode(sum);
      l1 = l1->next;
      cur = cur->next;
    }
    while (l2 != NULL) {
      sum = l2->val + carry;
      carry = sum / 10;
      sum %= 10;
      cur->next = new ListNode(sum);
      l2 = l2->next;
      cur = cur->next;
    }
    if (carry != 0) {
      cur->next = new ListNode(carry);
      cur = cur->next;
    }
    return header.next;
  }
};