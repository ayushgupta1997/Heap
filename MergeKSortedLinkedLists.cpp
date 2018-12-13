/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
        int k = lists.size();
        priority_queue<ListNode*,vector<ListNode *>, compare> pq;
        for (int i = 0; i < k; i++) {
            if(lists[i])
               pq.push(lists[i]); // push head of all nodes;
        }
        if(pq.empty()) 
          return NULL;
        ListNode* result = pq.top();
        pq.pop();
        if(result->next) 
            pq.push(result->next);
        ListNode* tail = result;
        
        while(!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next) {
                pq.push(tail->next);
            }
        }
        return result;
        
    }
};
