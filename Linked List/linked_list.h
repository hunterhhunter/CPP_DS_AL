#pragma once
#include <iostream>
#include "../Node.cpp"

namespace DataStructure {
    class LinkedList
    {
    private:
        /* data */
        ListNode* headOfList;
        int length = 0;
    public:
        LinkedList(/* args */);
        ~LinkedList();
        void Append(int data);
        int Search(int data);
        void Delete(int data);
        void Modify(int location, int data);
        int getLength() {return length;}
        void PrintList();
    };
}