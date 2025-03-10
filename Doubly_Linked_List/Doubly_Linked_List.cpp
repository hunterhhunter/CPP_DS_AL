#include "Doubly_Linked_List.h"
using namespace DataStructure;

namespace DataStructure {
    Doubly_Linked_List::Doubly_Linked_List()
    {
        headOfList = new ListNode;
    }

    Doubly_Linked_List::~Doubly_Linked_List()
    {
        ListNode* current = headOfList->tail;
        while (current != nullptr)
        {
            ListNode* next = current->tail;
            delete current;
            current = next;
        }
        delete headOfList;
    }

    void Doubly_Linked_List::Append(int data)
    {
        ListNode* prevLinkedNode = headOfList->tail;

        ListNode* newOne = new ListNode;
        newOne->data = data;
        newOne->head = headOfList;

        if (prevLinkedNode != nullptr)
        {
            prevLinkedNode->head = newOne;
            newOne->tail = prevLinkedNode;
        }

        headOfList->tail = newOne;
        length += 1;
    }

    void Doubly_Linked_List::Delete(int data)
    {
        int index = Search(data);
        if (index == 0) {
            std::cout << "삭제하고자 하는 데이터를 찾을 수 없음" << std::endl;
            return;
        }

        ListNode* current = headOfList->tail;

        for (size_t i = 1; i < index; i++)
        {
            ListNode* next = current->tail;
            current = next;
        }
        
        if (current->tail == nullptr)
        {
            current->head->tail = nullptr;
        } else {
            current->head->tail = current->tail;
            current->tail->head = current->head;
        }

        delete current;
        length -= 1;
    }

    int Doubly_Linked_List::Search(int data)
    {
        // 찾으면 인덱스(1부터 시작) 반환, 0 반환시 못 찾은거
        ListNode* current = headOfList->tail;
        int count = 1;

        if (current == nullptr) {
            std::cout << "노드가 존재하지 않음, 검색 불가" << std::endl;
            return 0;
        }

        while (current != nullptr)
        {
            ListNode* next = current->tail;
            if (current->data == data)
                return count;
            current = next;
            count += 1;
        }
        return 0;
    }

    void Doubly_Linked_List::Modify(int from, int to)
    {
        int index = Search(from);
        if (index == 0) {
            std::cout << "변경하고자 하는 데이터를 찾을 수 없음" << std::endl;
            return;
        }

        ListNode* current = headOfList->tail;

        for (size_t i = 1; i < index; i++)
        {
            ListNode* next = current->tail;
            current = next;
        }
        
        current->data = to;

        std::cout << from << "에서 " << to << " 로 변경 완료" << std::endl;
    }

    void Doubly_Linked_List::PrintList()
    {
        ListNode* current = headOfList->tail;

        for (size_t i = 0; i < length-1; i++)
        {
            std::cout << "| " << current->data << " |---";
            current = current->tail;
        }
        std::cout << "| " << current->data << " |" << std::endl;
    }
}