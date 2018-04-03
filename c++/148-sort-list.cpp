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
    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }
private:
	ListNode* divideList(ListNode* subList) {
		if (subList == NULL) return NULL;
		ListNode* mid = subList;
		ListNode* pos = subList->next;
		while (pos != NULL) {
			pos = pos->next;
			if (pos != NULL) {
				pos = pos->next;
				mid = mid->next;
			}
		}
		ListNode* secondHalf = mid->next;
		mid->next = NULL;
		return secondHalf;
	}
	ListNode* merge(ListNode* first, ListNode* second) {
		ListNode head(0);
		ListNode* tail = &head;
		while (first != NULL && second != NULL) {
			if (first->val < second->val) {
				tail->next = first;
				first = first->next;
			} else {
				tail->next = second;
				second = second->next;
			}
			tail = tail->next;
		}
		if (first != NULL)
			tail->next = first;
		else
			tail->next = second;
		return head.next;
	}
	void mergeSort(ListNode*& subList) {
		if (subList != NULL && subList->next != NULL) {
			ListNode* mid = divideList(subList);
			mergeSort(subList);
			mergeSort(mid);
			subList = merge(subList, mid);
		}
	}
};