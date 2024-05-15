// Lv.2 - 42577번 : 전화번호 목록 
// 작성자 : jeonghoe22

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 정렬
    sort(phone_book.begin(), phone_book.end());
    
    bool b_is_all_same = true;
    // 다음의 전화번호에서 포함하고 있는지 확인
    for(int i = 0; i < (int)phone_book.size() - 1; i++)
    {
        // 정렬을 했으므로 접두사로 포함되어 있으려면, 뒤에 전화번호부가 더 길어야 함.
        // 접둣로 포함되어 있으면, false로 반환.
        if((int)phone_book[i].size() <= (int)phone_book[i+1].size())
        {
            b_is_all_same = true;
            for(int j = 0; j < (int)phone_book[i].size(); j++)
            {
                // 접두사가 아닌 경우, 종료
                if(phone_book[i][j] != phone_book[i+1][j])
                {
                    b_is_all_same = false;
                    break;
                }
            }
            
            // 접두사가 있는 경우, false로 반환
            if(b_is_all_same == true)
            {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}