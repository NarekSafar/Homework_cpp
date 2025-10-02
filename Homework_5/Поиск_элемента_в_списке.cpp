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

bool findNode(ListNode* head, int value) {
    while(head != nullptr){
        if(head->data == value) {
            return true;
        } 
        head = head -> next;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    printList(head);
    int val_1 = 2, val_2 = 5;
    std::cout << "Ищем " << val_1 << " -> " << std::boolalpha << findNode(head, val_1);
    std::cout << "\nИщем " << val_2 << " -> " << std::boolalpha << findNode(head, val_2);
}