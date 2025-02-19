// 골드 5 - 2240번 : 자두나무
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시간 T, 움직이는 횟수 W
    int T, W;
    cin >> T >> W;

    // 위치, 바꾼 횟수, 시간
    vector<vector<vector<int>>> cases(2, vector<vector<int>>(W+1, vector<int>(T+1, 0))); 

    int apple_loc;

    // 1초
    cin >> apple_loc;
    if(apple_loc == 1){ cases[0][0][1] = 1; }
    else{ cases[1][1][1] = 1;}

    for(int time = 2; time <= T; time++)
    {
        cin >> apple_loc;

        for(int change = 0; change <= W; change++)
        {
            int plus_loc_1 = apple_loc == 1;
            int plus_loc_2 = apple_loc == 2;
            // 한 번도 바꾸지 않음
            if(change == 0)
            {
                // 시작 위치가 1번이여서 2번 위치에서 한 번도 바꾸지 않은 경우는 불가능
                cases[0][0][time] = cases[0][0][time-1] + plus_loc_1;
                continue;
            }
            
            // 최댓값 비교 - 바꿔서 도착할 경우 & 바꾸지 않고 도착한 경우
            cases[0][change][time] = max(cases[1][change-1][time-1] + plus_loc_1, cases[0][change][time-1] + plus_loc_1);
            cases[1][change][time] = max(cases[0][change-1][time-1] + plus_loc_2, cases[1][change][time-1] + plus_loc_2);
        }
    }

    // 마지막 시간에서 최댓값 구하기
    int result = 0;
    for(int i = 0; i <= W; i++)
    {
        result = max(result, max(cases[0][i][T], cases[1][i][T]));
    }

    cout << result << "\n";
}