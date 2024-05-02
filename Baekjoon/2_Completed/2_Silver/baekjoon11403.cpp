// 실버 1 - 11403번 : 경로 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 좌표 구조체
struct Point
{
    int x = 0;
    int y = 0;
    Point(){}
    Point(int _y, int _x){ y = _y; x = _x; }
};

// 연결 상태 구조체
struct Connect
{
    vector<int> directions;
};

bool CheckPath(vector<Connect>&connection, int current, int end, vector<vector<bool>> &b_is_visits, vector<Point> &visits)
{
    // 목적지에 도달하지 못했는데 빈칸일 때
    if(connection[current].directions.empty() == true){ return false; }
    // 목적지를 찾는 도중, 연결점이 있을 때
    else
    {
        // 각 연결점 순회
        for(int& each : connection[current].directions)
        {
            // 이미 방문한 경우에는 다음 것으로 넘김
            if(b_is_visits[current][each] == true){ continue; }
            // 목적지 찾은 경우
            if(each == end){ return true; }
            // 해당 연결점이 목적지가 아닌 경우
            else
            {
                b_is_visits[current][each] = true;
                visits.push_back(Point(current, each));
                // 해당 연결점을 통해서 목적지를 찾은 경우
                if(CheckPath(connection, each, end, b_is_visits, visits) == true)
                {
                    return true;
                }
            }
        }

        // 모든 연결점을 통해서 확인해봤지만 목적지를 찾지 못한 경우
        return false;
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int N;
    cin >> N;
    // 그래프 입력
    vector<Connect> connection(N);
    vector<vector<bool>> b_is_visits(N, vector<bool>(N, false));
    vector<Point> visits;
    int temp;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> temp;
            // 연결 상태일 때 해당 연결 점에서 방향 추가
            if(temp == 1){ connection[i].directions.push_back(j); }
        }
    }

    // i에서 j로 가는 경로가 있는지 출력
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            visits.clear();
            temp = CheckPath(connection, i, j, b_is_visits, visits);
            cout << temp << " ";

            // 방문한 곳 다 초기화
            for(Point& each : visits)
            {
                b_is_visits[each.y][each.x] = false;
            }
        }
        cout << "\n";
    }
}