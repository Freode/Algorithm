// Lv.3 - 72413번 : 합승 택시 요금
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 간선 정보
struct Line
{
    int dest = 0;
    int cost = 0;

    Line();
    Line(int in_dest, int in_cost)
    {
        dest = in_dest;
        cost = in_cost;
    }
};

// 지점 정보
struct Point
{
    int cost;
    vector<Line> connects;
};

// 비용 초기화
void cost_init(vector<Point> &points)
{
    for(Point &each : points)
    {
        each.cost = 200000000;
    }
}

// 시작점부터 목적지까지의 비용 계산 함수
int search(vector<Point> &points, int start, int dest1, int dest2)
{
    queue<int> que_points;
    int temp_result = 0, result = 200000000;
    bool b_first_dest = true;

    int cur_loc;

    // 시작점에서 모두 검사
    cost_init(points);
    que_points.push(start);
    points[start].cost = 0;

    while(!que_points.empty())
    {
        cur_loc = que_points.front();
        for(const Line &line : points[cur_loc].connects)
        {
            // 현재 경로가 기존보다 비용이 저렴한 경우
            if(points[cur_loc].cost + line.cost < points[line.dest].cost)
            {
                que_points.push(line.dest);
                points[line.dest].cost = points[cur_loc].cost + line.cost;
            }
        }

        que_points.pop();
    }
    
    // 각자 목적지 도착한 후, 비용 계산
    result = points[dest1].cost + points[dest2].cost;

    return result;
}

// 
int check(vector<Point> &points, int start, int dest1, int dest2)
{
    int result;

    // 각자 갔을 때, 비용 계산
    result = search(points, start, dest1, dest2);

    // 해당 지점에서 각자 따로 갈려고할 때, 각자 갔을 때의 비용보다 작은 경우에 진행
    vector<Line> divide_points;

    for(int i = 1; i < points.size(); i++)
    {
        if(result > points[i].cost)
        {
            divide_points.push_back(Line(i, points[i].cost));
        }
    }

    // 각 지점에서 다시 검사
    int temp = 0;
    for(Line &each_point : divide_points)
    {
        temp = search(points, each_point.dest, dest1, dest2);

        // 해당 지점에서 각자 목적지까지 이동한 것이 더 저렴할 경우
        if(temp + each_point.cost < result)
        {
            result = temp + each_point.cost;
        }
    }

    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // 지점 정보 모두 입력
    vector<Point> points(n+1);
    for(vector<int> &fare : fares)
    {
        points[fare[0]].connects.push_back(Line(fare[1], fare[2]));
        points[fare[1]].connects.push_back(Line(fare[0], fare[2]));
    }
    
    answer = check(points, s, a, b);

    return answer;
}