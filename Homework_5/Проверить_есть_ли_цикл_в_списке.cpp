#include <iostream>

struct ListNode{
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val) {}
};

bool hasCycle(ListNode* head) {
    ListNode* tmp = head;
    while(tmp != nullptr && tmp->next != nullptr) {
        tmp = tmp->next->next;
        head = head->next;
        if(tmp == head) {
            return true;
        }
    }
    return false;
}

int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n5;
    
    std::cout << std::boolalpha << hasCycle(n1);
    
}