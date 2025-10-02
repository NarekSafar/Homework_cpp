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
    std::cout << " -> nullptr\n";
}

size_t listLenght(ListNode* head){
    size_t count = 0;
    while(head != nullptr){
        count++;
        head = head -> next;
    }
    return count;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    printList(head);
    std::cout << "Длина: " << listLenght(head);
}