#include "Doubly_Linked_List.h"
using namespace DataStructure;
using namespace std;

int main() {
    Doubly_Linked_List* list = new Doubly_Linked_List();
    int input;

    while (true)
    {
        cout << "1. 삽입, 2. 삭제, 3. 수정, 4. 검색, 5. 출력, 6. 종료: ";
        cin >> input;

        if (input == 1) {
            int inputData;
            cout << "삽입하고자 하는 데이터를 입력하세요: ";
            cin >> inputData;
            
            list->Append(inputData);
        } else if (input == 2) {
            int deleteData;
            cout << "삭제하고자 하는 데이터를 입력하세요: ";
            cin >> deleteData;

            list->Delete(deleteData);
        } else if (input == 3) {
            int from, to;
            cout << "from to를 입력해주세요: ";
            cin >> from >> to;

            list->Modify(from, to);
        } else if (input == 4) {
            int searchData;
            cout << "검색하고자 하는 데이터를 입력해주세요";
            cin >> searchData;
            
            int index = list->Search(searchData);
            if (index == 0) {
                cout << "검색하신" << searchData << "는 존재하지 않습니다." << endl;
            } else {
                cout << "검색하신 " << searchData << "는 " << index << "번째에 위치해있습니다." << endl;
            }
        } else if (input == 5) {
            continue;
        } else if (input == 6)
        {
            break;
        }
        list->PrintList();
    }
    return 0;
}