#include <iostream>

struct ListNode{
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

ListNode* deleteDups(ListNode* head) {
    ListNode* tmp = head;
      while(tmp != nullptr && tmp->next != nullptr) {
            if(tmp->data == tmp->next->data) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
    return head;
}

int main(){
    ListNode* head = createList(1, 1, 2, 3, 3, 3);
    printList(head);
    printList(deleteDups(head));
}