// 골드 3 - 16236번 : 아기 상어
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 같은 거리에 다른 크기의 물고기가 존재 -> 같은 크기의 물고기부터 섭취

// N*N 크기 (최댓값 20)
// 물고기 M마리

// 입력
// 0 : 빈칸, 1~6 : 물고기, 9 : 자기 자신 위치
// 초기 : 자기 자신 크기 2

// 같은 크기의 물고기 하나 먹으면, 크기 1씩 증가
// 1초씩 상하좌우 하나 이동 가능

// 출력 : 물고기를 잡아먹을 수 있는 시간

// 같은 크기의 물고기로 이동
// 먹은 후, 다시 가능한 물고기 검색 후, 이동
// 더 큰 크기의 물고기여도 해당 칸으로 이동 가능(겹치기 가능)
// BFS로 이동

vector<vector<int>> g_areas;
vector<vector<int>> g_ables;

struct Loc
{
    int y;
    int x;
};

// 정보 입력
void input(const int N)
{
    g_areas = vector<vector<int>>(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_areas[i][j];
        }
    }
}

void setTarget(const Loc& start)
{

}

void search(const Loc& start, const int size)
{

}

int simulate()
{
    int result = 0;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
}