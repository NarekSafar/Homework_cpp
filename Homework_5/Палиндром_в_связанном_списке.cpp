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

ListNode* findMiddle(ListNode* head) {
    ListNode* tmp = head;
    while(tmp != nullptr && tmp->next != nullptr) {
        tmp = tmp->next->next;
        head = head->next;
    }
    return head;
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

bool isPalindrome(ListNode* head) {
    ListNode* tmp = head;
    ListNode* reversedHalfOfList = reverseList(findMiddle(head));
    while(reversedHalfOfList != nullptr) {
        if(head->data != reversedHalfOfList->data) {
            return false;
        }
        head = head->next;
        reversedHalfOfList = reversedHalfOfList->next;
    }
    return true;
}

int main(){
    ListNode* head_1 = createList(1, 2, 3, 3, 2, 1);
    ListNode* head_2 = createList(1, 4, 3, 4, 2);
    printList(head_1);
    printList(head_2);
    std::cout << std::boolalpha << isPalindrome(head_1) << "\n";
    std::cout << std::boolalpha << isPalindrome(head_2);
}