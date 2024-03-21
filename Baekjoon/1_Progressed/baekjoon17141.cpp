// 골드 4 - 17141번 : 연구소 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 구역 정보
struct Info
{
    int state = 0;
    bool b_is_visited = false;
    int turn_count = 0;
};

// 위치
struct Location
{
    int y = 0;
    int x = 0;

    // 생성자
    Location(){}
    Location(int _y, int _x){ y = _y; x = _x; }
};

// 맵 입력
void InputMap(vector<vector<Info>> &maps, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> maps[i][j].state;
        }
    }
}

// 시뮬레이션 시작
void Simulate(vector<vector<Info>> &maps, int N, int M)
{
    // 바이러스 시작 위치 넣기
    queue<Location> loc_queue;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(maps[i][j].state == 0)
            { 
                loc_queue.push(Location(i, j));
                maps[i][j].b_is_visited = true;
            }
        }
    }

    // 방향 


    // BFS 시작
    while(loc_queue.empty() == false)
    {

    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 맵 크기 입력
    int N, M;
    cin >> N >> M;

    // 맵 입력
    vector<vector<Info>> maps(N, vector<Info>(N));
    InputMap(maps, N);

    // 
}