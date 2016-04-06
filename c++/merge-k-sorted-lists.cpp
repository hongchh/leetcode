/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* heap */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& givenLists) {
        vector<ListNode*> lists;
        for (int i = 0; i < givenLists.size(); ++i)
            if (givenLists[i] != NULL)
                lists.push_back(givenLists[i]);
        ListNode result(0);
        ListNode* lastNode = &result;
        buildHeap(lists);
        int heapSize = lists.size();
        while (heapSize > 0) {
            lastNode->next = lists[0];
            lastNode = lists[0];
            lists[0] = lists[0]->next;
            if (lists[0] == NULL) {
                swap(lists[0], lists[--heapSize]);
                minHeapfy(lists, 0, heapSize);
            } else {
                minHeapfy(lists, 0, heapSize);
            }
        }
        lastNode->next = NULL;
        return result.next;
    }
private:
    void buildHeap(vector<ListNode*>& lists) {
        int size = lists.size();
        for (int i = size/2-1; i >= 0; --i)
            minHeapfy(lists, i, size);
    }
    void minHeapfy(vector<ListNode*>& lists, int i, int size) {
        int min = i, l = 2*i+1, r = 2*i+2;
        if (l < size && lists[l]->val < lists[i]->val)
            min = l;
        if (r < size && lists[r]->val < lists[min]->val)
            min = r;
        if (min != i) {
            swap(lists[i], lists[min]);
            minHeapfy(lists, min, size);
        }
    }
};

//////////////////////////////////////////////////////////////////////////////
/* mergeSort */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& givenLists) {
        if (givenLists.size() == 0) return NULL;
        return recursive_merge(givenLists, 0, givenLists.size()-1);
    }
private:
    ListNode* recursive_merge(vector<ListNode*>& lists, int left, int right) {
        if (left < right) {
            int mid = (left+right)/2;
            ListNode* l = recursive_merge(lists, left, mid);
            ListNode* r = recursive_merge(lists, mid+1, right);
            return merge(l, r);
        } else {
            return lists[left];
        }
    }
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode combine(0);
        ListNode* lastNode = &combine;
        while (l != NULL && r != NULL) {
            if (l->val < r->val) {
                lastNode->next = l;
                l = l->next;
            } else {
                lastNode->next = r;
                r = r->next;
            }
            lastNode = lastNode->next;
        }
        if (l != NULL)
            lastNode->next = l;
        else
            lastNode->next = r;
        return combine.next;
    }
};