// 골드 4 - 1633번 : 최고의 팀 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int white_idx = 0;
const int black_idx = 1;
const int max_player = 16;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 플레이어 능력치 입력
    vector<vector<int>> stats(1002, vector<int>(2, 0));

    // 유효한 입력이 주어질 때까지 검사
    int white, black;
    int player_count = 1;
    while(cin >> white)
    {
        cin >> black;
        
        stats[player_count][white_idx] = white;
        stats[player_count][black_idx] = black;
        
        player_count++;
    }

    // dp 배열 만들기
    // 현재 흑돌 인원, 백돌 인원
    vector<vector<vector<int>>> cases(1002, vector<vector<int>>(max_player, vector<int>(max_player, 0)));

    // 225 * 10^3
    // 현재 플레이어 1.흑돌, 2.백돌, 3.안 뽑는다

    // 현재 도달 가능한 경우
    // 1. 흑돌 -> [k][i-1][j]에서 도달
    // 2. 백돌 -> [k][i][j-1]에서 도달
    // 3. 뽑지 않음 -> [k-1][i][j]와 비교

    // 선수마다 확인
    for(int p_idx = 1; p_idx < player_count; p_idx++)
    {
        // i = 흑돌 뽑힌 인원 수
        for(int i = 0; i < max_player; i++)
        {
            // j = 백돌 뽑힌 인원 수
            for(int j = 0; j < max_player; j++)
            {

                if(i + j >= p_idx + 1) continue;
                // 1. 흑돌로 뽑힌다. (단, 현재 유효한 경우인지 확인)
                if(i != 0 && p_idx - i >= -1)
                {
                    cases[p_idx][i][j] = max(cases[p_idx][i][j], cases[p_idx-1][i-1][j] + stats[p_idx][black_idx]);
                }

                // 2. 백돌로 뽑힌다. (단, 현재 유효한 경우인지 확인)
                if(j != 0 && p_idx - j >= -1)
                {
                    cases[p_idx][i][j] = max(cases[p_idx][i][j], cases[p_idx-1][i][j-1] + stats[p_idx][white_idx]);
                }

                // 3. 뽑히지 않는다.
                cases[p_idx][i][j] = max(cases[p_idx][i][j], cases[p_idx-1][i][j]);
            }
        }
    }

    cout << cases[player_count-1][max_player-1][max_player-1] << "\n";
}