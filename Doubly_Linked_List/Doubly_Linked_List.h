#include <iostream>
#include "../Node.cpp"

namespace DataStructure {
    class Doubly_Linked_List
    {
    private:
        // new로 선언한 멤버 변수는 heap에 저장되므로 소멸자에서 명시적으로 삭제해줘야함
        // int, float같은 기본 타입은 stack에 저장되어 자동 소멸됨
        ListNode* headOfList = nullptr;
        int length = 0;
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