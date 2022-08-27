#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // Implemented the iterative solution
    
public:
    static ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr;
        while(head->next != nullptr){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
        return head;
    }

    static void printList(ListNode* head) {
        if(head == nullptr) return;
        while(head->next != nullptr){
            std::cout << head->val << std::endl;
            head = head->next;
        }
        std::cout << head->val << std::endl;
        return;
    }
};

int main(){
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(4, node1);
    ListNode* node3 = new ListNode(3, node2);
    ListNode* node4 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node4);

    Solution::printList(head);
    std::cout << "reversed list: " << std::endl;
    head = Solution::reverseList(head);
    Solution::printList(head);

    return -1;
}