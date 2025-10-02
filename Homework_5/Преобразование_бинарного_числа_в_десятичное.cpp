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

void printBinary(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->data;
        head = head->next;
    }
}

ListNode* createList() {
    return nullptr;
}

template<typename T, typename... Args>
ListNode* createList(T first, Args... rest) {
    return new ListNode(first, createList(rest...));
}

int toDec(ListNode* head) {
    int num = 0;
    while(head != nullptr) {
        num = num * 2 + head->data;
        head = head->next;
    }
    return num;
}


int main(){
    ListNode* head = createList(1, 1, 0, 0, 1, 0, 1, 1);
    printList(head);
    std::cout  << "Бинарное число: ";
    printBinary(head);
    std::cout << "\nДесятичное число: " << toDec(head);
}