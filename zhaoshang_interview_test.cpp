//1-2-3-4 变换为 1-4-2-3
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
    void reorderList(ListNode *head) {
        if(head==nullptr) return;
        if(head->next==nullptr) return;
        if(head->next->next==nullptr) return;
        // 尾部节点放在首节点的后面
        ListNode* cur = head -> next;
        ListNode* cur_pre = head;
        ListNode* left = head->next;
        while(cur->next!=nullptr){
            cur = cur->next;
            cur_pre = cur_pre->next;
        }
        cur_pre -> next = nullptr;
        head->next = cur;
        cur->next = left;
        // 调用
        reorderList(cur->next);
        return;
    }
};