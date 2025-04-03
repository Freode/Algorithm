// 골드 4 - 17144번 : 미세먼지 안녕!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Area
{
    int cur = 0;
    int after = 0;
};

vector<vector<Area>> g_areas;

// 맵 입력
void inputArea(const int R, const int C)
{
    g_areas = vector<vector<Area>>(R, vector<Area>(C));

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 R, 가로 C, 시간 T
    int R, C, T;
    cin >> R >> C >> T;



}