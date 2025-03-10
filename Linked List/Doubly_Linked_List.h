#include <iostream>
#include "linked_list.h"

namespace DataStructure {
    class Doubly_Linked_List
    {
    private:
        ListNode* head = new ListNode;
    public:
        Doubly_Linked_List(/* args */);
        ~Doubly_Linked_List();
        void Append(int data);
        void Delete(int data);
        int Search(int data);
        void Modify(int from, int to);
        void PrintList();
    };
}