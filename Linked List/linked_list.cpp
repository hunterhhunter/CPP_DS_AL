#include "linked_list.h"

namespace DataStructure {

    LinkedList::LinkedList() {
        headOfList = new ListNode;
    }

    LinkedList::~LinkedList() {
        ListNode* current = headOfList->tail;
        while (current != nullptr) {
            ListNode* next = current->tail;
            delete current;
            current = next;
        }
        delete headOfList;
    }

    void LinkedList::Append(int data) {
        // 데이터를 가장 앞에 삽입하는 함수
        ListNode* newOne = new ListNode;
        newOne->data = data;

        newOne->tail = headOfList->tail;
        headOfList->tail = newOne;

        length += 1;
        std::cout << "Appended: " << data << std::endl;
    }

    void LinkedList::Delete(int data) {
        // 선형검색 및 삭제
        ListNode* prev = headOfList;
        ListNode* current = headOfList->tail;
        if (current == nullptr) {
            std::cout << "리스트내 데이터가 없습니다." << std::endl;
            return;
        }
        while (current->data != data) {
            ListNode* next = current->tail;
            if (next == nullptr) {
                std::cout << "cannot find " << data << std::endl;
                return;
            }
            prev = current;
            current = next;
        }
        prev->tail = current->tail;
        delete current;
        length -= 1;
    }

    void LinkedList::Modify(int location, int data) {
        if (location > length) {
            std::cout << "수정 희망 위치 재확인 요망" << std::endl;
            std::cout << "현재 리스트 길이" << length << std::endl;
            return;
        }
        ListNode* current = headOfList->tail;
        for (size_t i = 0; i < location-1; i++)
        {
            ListNode* next = current->tail;
            current = next;
        }
        int prev = current->data;
        current->data = data;
        std::cout << "데이터 수정 완료: " << prev << "->" << current->data << std::endl;
    }

    int LinkedList::Search(int data) {
        ListNode* current = headOfList->tail;
        int idx = 1;
        if (current == nullptr) {
            std::cout << "리스트에 데이터가 없습니다." << std::endl;
            return 0;
        }
        while (current->data != data) {
            ListNode* next = current->tail;
            if (next == nullptr) {
                std::cout << "찾고자 하는 데이터가 없습니다." << std::endl;
                return 0;
            }
            current = next;
            idx++;
        }
        return idx;
    }

    void LinkedList::PrintList() {
        // 수정필요
        ListNode* current = headOfList->tail;
        while (current != nullptr) {
            std::cout << "| " << current->data << " |";
            ListNode* next = current->tail;
            current = next;
        }
        std::cout << "\n";
    }
}