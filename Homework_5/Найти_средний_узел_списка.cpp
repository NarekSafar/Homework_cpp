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

ListNode* findMiddle(ListNode* head) {
    ListNode* tmp = head;
    while(tmp != nullptr && tmp->next != nullptr) {
        tmp = tmp->next->next;
        head = head->next;
    }
    return head;
}

int main(){
    ListNode* head = createList(1, 2, 3, 4, 5, 6, 7, 8);
    std::cout << findMiddle(head)->data;
    
}