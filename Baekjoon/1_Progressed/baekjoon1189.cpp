// 실버 1 - 1189번 : 컴백홈
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

    // 세로 R, 가로 C, 거리 K
    int R, C, K;
    cin >> R >> C >> K;

    // 지도 입력
    vector<string> maps(R);
    for(string& line : maps)
    {
        cin >> line;
    }

    // 경우의 수 모두 구하기 - 가로와 세로 모두 한 줄씩 더 있다고 생각
    vector<vector<int>> cases(R, vector<int>(C, 0));
    // 시작점
    cases[R-1][0] = 1;

    // 왼쪽 아래에서 오른쪽 위로 올라감
    for(int y = R-1; y >= 0; y--)
    {
        for(int x = 0; x < C; x++)
        {
            // 시작점 제외
            if(y == R-1 && x == 0) continue;
            
            int amount = 0;
            // 현재 위치로 올 수 있을 때
            if(maps[y][x] != 'T')
            {
                // 제일 아랫줄 - 왼쪽만 가능
                if(y == R-1) amount = cases[y][x-1];
                // 제일 왼쪽 - 아래만 가능
                else if(x == 0) amount = cases[y+1][x];
                // 나머지 - 왼쪽과 아래에서 가능
                else amount = cases[y+1][x] + cases[y][x-1];

                cases[y][x] = amount;
            }
        }
    }
    cout << cases[0][C-1] << "\n";
}