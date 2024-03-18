// 실버 2 - 21736번 : 헌내기는 친구가 필요해
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 캠퍼스 구역 정보
struct Campus
{
    char info = 'a';
    bool b_is_visited = false;

    // 생성자
    Campus(){}
    Campus(char _info){ info = _info; }
};

// 위치 정보
struct Location
{
    int y = 0;
    int x = 0;

    // 생성자
    Location(){}
    Location(int _y, int _x){ y = _y; x = _x; }
};

// 캠퍼스 구역 정보 입력
Location InputCampusInfo(vector<vector<Campus>> &area, int N, int M)
{
    char temp_input;
    Location me;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> temp_input;
            area[i][j].info = temp_input;

            // 본인 위치 기록 및 방문했다고 설정
            if(temp_input == 'I')
            {
                me.y = i;
                me.x = j;
                area[i][j].b_is_visited = true;
            }
        }
    }

    return me;
}

// 사람 찾기
void FindPeople(vector<vector<Campus>> &area, int N, int M, Location me)
{
    // 방향 정의
    // 위쪽, 오른쪽, 아래쪽, 왼쪽
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    // 시작 위치 입력
    queue<Location> loc_queue;
    loc_queue.push(me);

    // 임시 변수
    int y, x;
    // 만날 수 있는 사람 수
    int total = 0;

    // BFS
    while(loc_queue.empty() == false)
    {
        for(int i = 0; i < 4; i++)
        {
            y = loc_queue.front().y;
            x = loc_queue.front().x;

            // 방향 입력
            y += dy[i];
            x += dx[i];

            // 범위 안이면서 방문하지 않았는지 확인
            if(x >= 0 && x < M && y >= 0 && y < N && area[y][x].b_is_visited == false) 
            {
                // 방문했다고 설정
                area[y][x].b_is_visited = true;

                // 사람일 경우
                if(area[y][x].info == 'P')
                {
                    total++;
                    loc_queue.push(Location(y,x));
                }
                // 빈 공간일 경우
                else if(area[y][x].info == 'O')
                {
                    loc_queue.push(Location(y,x));
                }

                // 빈 공간일 경우는 무시

                // 처음 본인 위치는 방문 여부 확인 조건에서 걸러짐.
            }
        }
        // 큐의 맨 처음은 검사가 완료되었으므로 제거
        loc_queue.pop();
    }

    // 출력문
    // 0일 경우는 TT 출력
    if(total == 0)
    {
        cout << "TT\n";
    }
    else
    {
        cout << total << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 캠퍼스 크기 입력
    int N, M;
    cin >> N >> M;

    // 캠퍼스 구역 정보 입력
    Location me;
    vector<vector<Campus>> area(N, vector<Campus>(M));
    me = InputCampusInfo(area, N, M);

    // 캠퍼스 내 몇 명 만날 수 있는지 검사
    FindPeople(area, N, M, me);
}