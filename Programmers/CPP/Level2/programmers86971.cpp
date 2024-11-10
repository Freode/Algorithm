// Lv.2 - 86971번 : 전력망을 둘로 나누기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// 점에 대한 연결 라인
struct Point
{
    vector<int> con_locs;
};

// 전력망마다 이어진 송전탑 개수 검사
int search(vector<Point> &points, pair<int, int> &disconnect, int start_loc)
{
    vector<bool> visits(points.size(), false);
    
    // 시작 지점 큐에 추가
    queue<int> que_points;
    que_points.push(start_loc);
    visits[start_loc] = true;

    // 임의의 변수
    int check_loc;
    int result = 1;

    // BFS
    while(que_points.empty() == false)
    {
        check_loc = que_points.front();
        // 연결된 와이어 모두 검사
        for(int& each : points[check_loc].con_locs)
        {
            // 끊어진 와이어인 경우
            if((disconnect.first == each && disconnect.second == start_loc)
            || (disconnect.first == start_loc && disconnect.second == each))
            {
                // 무시
                continue;
            }

            // 아직 방문하지 않은 경우
            if(visits[each] == false)
            {
                visits[each] = true;
                que_points.push(each);
                result++;
            }

            // 방문한 경우에는 무시
        }
        
        // 검사 완료
        que_points.pop();
    }

    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;

    vector<Point> points(n+1);
    pair<int, int> disconnect;

    // 연결
    for(int i = 0; i < wires.size(); i++)
    {
        points[wires[i][0]].con_locs.push_back(wires[i][1]);
        points[wires[i][1]].con_locs.push_back(wires[i][0]);
    }

    // 하나씩 전력망 끊기
    for(int i = 0; i < wires.size(); i++)
    {
        // 전력망 끊는 점
        disconnect.first = wires[i][0];
        disconnect.second = wires[i][1];
        
        // 끊어진 두 군데 확인
        int first_count = search(points, disconnect, disconnect.first);
        int second_count = search(points, disconnect, disconnect.second);
        
        // 두 전력망 차이 확인
        if(abs(first_count - second_count) < answer)
        {
            answer = abs(first_count - second_count);
        }
    }

    return answer;
}