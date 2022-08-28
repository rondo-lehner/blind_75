#include <unordered_set>
#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {};
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    // Initial idea:
    // 1. Initialise and empty set
    // 2. traverse the list and check if the next pointer of the current node is in the set, if it is then return true
    // 3. add the next pointer to the set and repeat step 2 until a null pointer is encountered
    // Note: this solution has time and space complexity of O(n)

    // TODO: solve problem for space complexity of O(1)

public:
    static bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> nodes;
        nodes.insert(head);
        while(head->next != nullptr){
            if(nodes.count(head->next) > 0) return true;
            head=head->next;
            nodes.insert(head);
        }
        return false;
    }
};

int main(){
    ListNode* node1 = new ListNode(-4);
    ListNode* node2 = new ListNode(0, node1);
    ListNode* node3 = new ListNode(2, node2);
    ListNode* head = new ListNode(3, node3);
    node1->next = node2;

    std::cout << Solution::hasCycle(head) << std::endl;

    return -1;
}

// [3,2,0,-4]