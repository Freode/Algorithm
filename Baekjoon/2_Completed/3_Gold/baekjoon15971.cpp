// 골드 4 - 15971번 : 두 로봇
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// N개의 방
// 두 방 사이로 이동
// 두 번 이상 지나지 않는 경로는 유일?

// 통로의 길이 = 선분에 적힌 값
// 두 로봇이 1, 9번방에 위치 -> 2번방과 5번 방으로 이동 후 통신 가능
// 총 거리 합은 14 -> 통로 가능하다는 뜻 : 각 로봇은 통로를 하나 두고 통신 가능

// 통신하기 위해 최소로 이동해야 하는 거리 합의 최솟값

// 방의 개수 N : 1~100'000
// 통로 길이 : ~1'000

// A 로봇 모든 방의 이동 길이 검사 -> 10만번
// B 로봇 모든 방의 이동 길이 검사 -> 10만번
// 모든 방의 주변 방과 이동 길이 검사 -> 10만번

const int MAX_VALUE = numeric_limits<int>::max();

enum Robot
{
    A = 0,
    B = 1,
};

// 선
struct Line
{
    int num = 0;
    int length = 0;

    // 길이 기준 오름차순 정렬
    bool operator<(const Line& other) const
    {
        return length > other.length;
    }
};

// 노드
struct Node
{
    vector<int> robot_length = vector<int>(2, -1);
    vector<Line> connects;

    Node()
    {
        connects.reserve(20);
    }
};

vector<Node> g_nodes;

// 데이터 입력 및 할당
void inputDataAndInit(const int N)
{
    g_nodes = vector<Node>(N+1);

    int start, end, length;
    for(int i = 0; i < N-1; ++i)
    {
        cin >> start >> end >> length;

        g_nodes[start].connects.push_back({end, length});
        g_nodes[end].connects.push_back({start, length});
    }
}

// 특정 로봇 탐사 시작
void goRobot(Robot robot, const int start)
{
    // 초기 설정
    priority_queue<Line> pq;
    pq.push({start, 0});
    g_nodes[start].robot_length[robot] = 0;

    while(pq.empty() == false)
    {
        Line cur = pq.top();
        pq.pop();

        Node& cur_node = g_nodes[cur.num];
        // 현재 비용이 더 높은 경우는 무시
        if(cur_node.robot_length[robot] != -1 && cur_node.robot_length[robot] < cur.length)
            continue;

        // 모든 연결점 검사
        for(const Line& next : cur_node.connects)
        {
            Node& next_node = g_nodes[next.num];
            int cost = next.length + cur.length;

            // 현재 비용이 더 높거나 같으면, 무시
            if(next_node.robot_length[robot] != -1 && next_node.robot_length[robot] <= cost)
                continue;

            // 현재 비용이 더 낮으면 다시 추가
            next_node.robot_length[robot] = cost;
            pq.push({next.num, cost});
        }
    }
}

// 마지막 두 로봇의 이동거리 검사
int check(const int A, const int B)
{
    // 출발지와 도착지가 같을 때
    if(A == B)
        return 0;

    int size = g_nodes.size();
    int result = MAX_VALUE;
    // 현재 A 로봇 기준
    for(int i = 1; i < size; i++)
    {
        // 주변에 있는 B 로봇 이동 거리 검사
        for(const Line& connect : g_nodes[i].connects)
        {
            result = min(result, g_nodes[i].robot_length[Robot::A] + g_nodes[connect.num].robot_length[Robot::B]);
        }
    }

    // 두 로봇이 같이 존재하는 경우
    if(result == MAX_VALUE)
        result = 0;

    return result;
}

// 시뮬레이션
int simulate(const int A, const int B)
{
    // A 로봇 탐사
    goRobot(Robot::A, A);
    // B 로봇 탐사
    goRobot(Robot::B, B);
    // A와 B 이동 거리 모두 검사
    return check(A, B);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 방의 개수 N, 두 로봇의 위치 A, B
    int N, A, B;
    cin >> N >> A >> B;

    inputDataAndInit(N);
    cout << simulate(A, B);
}