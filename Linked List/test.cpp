#include "linked_list.h"
using namespace DataStructure;
using namespace std;

int main() {
    LinkedList list;
    int input = 0;
    while (input != 6) {
        std::cout << "1. 출력    2. 검색    3. 삽입    4. 삭제    5. 수정    6. 종료: ";
        std::cin >> input;

        if (input == 1) {
            list.PrintList();
        } else if (input == 2)
        {
            int searchInput;
            cout << "검색할 데이터를 입력해주세요: ";
            cin >> searchInput;

            int searchResult = list.Search(searchInput);
            
            if (searchResult != 0) {
                cout << "검색하신 " << searchInput << "의 인덱스는 " << searchResult << "입니다. (시작: 1)" << endl;
            }
        } else if (input == 3)
        {
            int inputData;
            cout << "삽입할 데이터를 입력해주세요: ";
            cin >> inputData;

            list.Append(inputData);
        } else if (input == 4)
        {
            int inputData;
            cout << "삭제할 데이터를 입력해주세요: ";
            cin >> inputData;

            list.Delete(inputData);
        } else if (input == 5)
        {
            int mIdx, mInput;
            cout << "수정할 인덱스와 값을 입력해주세요: ";
            cin >> mIdx >> mInput;

            list.Modify(mIdx, mInput);
        }
        list.PrintList();
    }
    return 0;
}