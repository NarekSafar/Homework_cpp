#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val, ListNode* next) : data(val), next(next) {};
};

void printList(ListNode* head) {
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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;  
    while (head != nullptr) {
        ListNode* nextNode = head->next; 
        head->next = prev;               
        prev = head;                     
        head = nextNode;                 
    }
    return prev;
}

int main(){
    ListNode* head = createList(1, 2, 3, 4, 5, 6);
    printList(head);
    printList(reverseList(head));
}