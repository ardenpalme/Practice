#include <iostream>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend std::ostream& operator<<(std::ostream& os, const ListNode& node);

    void print_list(void) {
        int ct = 0;
        std::cout << "[ ";
        for(ListNode *node = this; node != nullptr; node=node->next)
        {
            std::cout << *node << " ";
        }
        std::cout << "] " << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const ListNode& node)
{
    os << node.val;
    return os;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;

        if(head->next == nullptr && n == 1){
            return nullptr;
        }

        ListNode *leading_node = head;
        ListNode *trailing_node = head;
        ListNode *trailing_node_prev = head;
        int idx = 0, num_ele = 0;
        while(leading_node->next != nullptr)
        //@loop_invaiant trailing_node_prev->next == trailing_node
        {
            if(idx >= n-1) {
                trailing_node = trailing_node->next;
            }
            if(idx >= n) {
                trailing_node_prev = trailing_node_prev->next;   
            }
            idx++;
            leading_node = leading_node->next;
        }

        num_ele = idx+1;
        std::cout << num_ele << " elements total" << std::endl;
        std::cout << "tailing node " <<  *trailing_node << std::endl;
        std::cout << "tailing node prev " <<  *trailing_node_prev << std::endl;

        if(trailing_node == trailing_node_prev && trailing_node == head){
            std::cout << "ICI" << std::endl;
            return head->next;
        }

        trailing_node_prev->next = trailing_node->next;
        trailing_node->next = NULL;

        return head;
    }
};