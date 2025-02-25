// 골드 5 - 1360번 : 되돌리기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Oper
{
    string command = "";
    char c;
    int un_t;
    int t;
    // previous : 명령어 수행하기 전
    string previous = "";
    // previous : 명령어 수행한 후
    string after = "";
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 명령의 개수 N
    int N;
    cin >> N;
    
    // 명령어 입력
    vector<Oper> opers(N);

    for(int i = 0; i < N; i++)
    {
        Oper &oper = opers[i];
        cin >> oper.command;

        // 명령어 type
        if(oper.command == "type")
        {
            cin >> oper.c >> oper.t;
            // 첫 명령어가 아닐 경우에만, 이전에서 추가
            if(i != 0)
            {
                oper.after = opers[i-1].after + oper.c;
                oper.previous = opers[i-1].after;
            }
            // 첫 명령어 일 경우는 이전에서 추가할 필요가 없어 바로 초기화
            else
            {
                oper.after = oper.c;
            }
        }
        // 명령어 undo
        else
        {
            cin >> oper.un_t >> oper.t;

            int start_time = oper.t - 1;
            int undo_time = oper.un_t;

            int loc = i-1;
            bool b_is_break = false;

            while(loc >= 0)
            {
                // 시간 차이를 보고 되돌리지 말지 결정
                // undo 시간에 포함되지 않음.

                if(start_time - undo_time >= opers[loc].t)
                {

                    b_is_break = true;
                    break;
                }
                loc--;
            }

            // 부분 초기화
            if(b_is_break)
            {
                oper.after = opers[loc].after;
            }
            // 전체 초기화
            else
            {
                oper.after = "";
            }
        }
    }

    cout << opers[N-1].after << "\n";
}