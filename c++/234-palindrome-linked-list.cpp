/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        // 计算链表长度
        int len = 0;
        for (ListNode* p = head; p != NULL; p = p->next) {
            ++len;
        }
        // 获取链表中间节点的地址
        ListNode* mid = head;
        for (int i = 1; i != len/2; ++i) {
            mid = mid->next;
        }
        if (len % 2 != 0) mid = mid->next;
        // 将链表中间节点开始的部分反转
        ListNode* pre = NULL;
        ListNode* cur = mid;
        while (cur != NULL) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        // 反转后比较与前半段链表是否相同
        mid = pre;
        ListNode* temp = head;
        for (int i = 0; i != len/2; ++i) {
            if (mid->val != temp->val)
                return false;
            mid = mid->next;
            temp = temp->next;
        }
        return true;
    }
};
