#include <iostream>

struct ListNode{
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val), next(nullptr) {}
};

void printList(ListNode* head){
    std::cout  << "Список: " << head -> data;
    head = head -> next;
    while(head != nullptr){
        std::cout << " -> " << head -> data;
        head = head->next;
    }
    std::cout << " -> " << "nullptr\n";
}

ListNode* deleteValue(ListNode* head, int val) {
    if (head == nullptr) return nullptr;
    head->next = deleteValue(head->next, val);
    if (head->data == val) {
        ListNode* temp = head->next;
        delete head;
        return temp;
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    printList(deleteValue(head, 2));
}