#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode *node = head;        
        ListNode *prev_node = nullptr;        
        while(node != NULL) {
            if(prev_node != nullptr) {
                swap_nodes(prev_node, node, node->next);
            }

            prev_node = node;
            node = node->next;
        }
    }

    void swap_nodes(ListNode *prev_node, ListNode *node, ListNode *swap_node) {
        //@assert(node1->next == node2)
        int tmp_val = node->val;
        node->val = swap_node->val;
        swap_node->val = tmp_val;

        ListNode *tmp_node = swap_node->next;
        node2->next = node1;
        node1->next = tmp_node;

        prev_node->next = 
    }
};