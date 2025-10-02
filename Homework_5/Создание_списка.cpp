#include <iostream>

struct ListNode{
    int data;
    ListNode* next;
    
    explicit ListNode(int val, ListNode* next) : data(val), next(next) {}
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

ListNode* createList() {
    return nullptr;
}

template<typename T, typename... Args>
ListNode* createList(T first, Args... rest) {
    return new ListNode(first, createList(rest...));
}


int main(){
    printList(createList(1, 2, 3, 4, 5));
}