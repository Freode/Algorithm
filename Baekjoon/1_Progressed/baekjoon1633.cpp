// 골드 4 - 1633번 : 최고의 팀 만들기
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

    // 플레이어 능력치 입력
    vector<vector<int>> stats(1001, vector<int>(2, 0));

    int white, black;
    int player_count = 0;
    while(cin >> white)
    {
        cin >> black;
        
        stats[player_count][0] = white;
        stats[player_count][1] = black;
        
        player_count++;
    }

    // dp 배열 만들기
    // 현재 흑돌 인원, 백돌 인원
    vector<vector<int>> cases(16, vector<int>(16, 0));

    // 현재 플레이어 1.흑돌, 2.백돌, 3.안 뽑는다
    for(int i = 1; i <= 15; i++)
    {

    }

}