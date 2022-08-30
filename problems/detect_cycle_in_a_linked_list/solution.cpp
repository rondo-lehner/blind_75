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

    // Space complexity of O(1):
    // Idea stems from looking at a solution. 

public:
    static bool hasCycleTime(ListNode *head) {
        std::unordered_set<ListNode*> nodes;
        nodes.insert(head);
        while(head->next != nullptr){
            if(nodes.count(head->next) > 0) return true;
            head=head->next;
            nodes.insert(head);
        }
        return false;
    }

    static bool hasCycleSpace(ListNode *head) {
        ListNode* walker = head;
        ListNode* runner = head;
        while(walker != nullptr && runner->next->next != nullptr){
            walker = walker->next;
            runner = runner->next->next;
            if(runner == walker) return true;
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

    std::cout << Solution::hasCycleTime(head) << std::endl;
    std::cout << Solution::hasCycleSpace(head) << std::endl;

    return -1;
}

// [3,2,0,-4]