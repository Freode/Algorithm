// 골드 4 - 1633번 : 최고의 팀 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int white_idx = 0;
const int black_idx = 1;

struct Info
{
    int cost_white = 0;
    int cost_black = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 플레이어 능력치 입력
    vector<vector<int>> stats(1001, vector<int>(2, 0));

    int white, black;
    int player_count = 0;
    while(cin >> white)
    {
        cin >> black;
        
        stats[player_count][white_idx] = white;
        stats[player_count][black_idx] = black;
        
        player_count++;
    }

    // dp 배열 만들기
    // 현재 흑돌 인원, 백돌 인원
    vector<vector<Info>> cases(16, vector<Info>(16));

    // 225 * 10^3
    // 현재 플레이어 1.흑돌, 2.백돌, 3.안 뽑는다
    for(const vector<int> &stat : stats)
    {
        // 현재 i번째 흑돌 또는 j번째 백돌에 뽑힐지 결정
        for(int i = 0; i <= 15; i++)
        {
            for(int j = 0; j <= 15; j++)
            {
                // 둘 다 안 뽑힌 상태에서는 검사할 필요 없음.
                if(i == 0 && j == 0) continue;

                Info& info = cases[i][j];

                // 1. 흑돌로 뽑히는 경우
                if(i == 1) // 처음 뽑힘
                {
                    info.cost_black = max(info.cost_black, stat[black_idx]);
                }
                // 이전에 뽑힌 사람이 있음.
                else if(i != 0)
                {
                    Info& prev_info = cases[i-1][j];
                    // 0은 이전에 뽑힌 사람이 없다는 뜻이여서 무시
                    if(prev_info.cost_black == 0) continue;

                    info.cost_black = max(info.cost_black, prev_info.cost_black + stat[black_idx]);
                }
                // 2. 백돌로 뽑히는 경우
                if(j == 1) // 처음 뽑힘
                {
                    info.cost_white = max(info.cost_white, stat[white_idx]);
                }
                // 이전에 뽑힌 사람이 있음.
                else if(j != 0)
                {
                    Info& prev_info = cases[i][j-1];
                    // 0은 이전에 뽑힌 사람이 없다는 뜻이여서 무시
                    if(prev_info.cost_white == 0) continue;

                    info.cost_white = max(info.cost_white, prev_info.cost_white + stat[white_idx]);
                }

                // 3. 안 뽑히는 경우
            }
        }
    }
    cout << cases[15][15].cost_black + cases[15][15].cost_white << "\n";
}