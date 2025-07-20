// 골드 2 - 1810번 : 징검다리 달리기 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <functional>

using namespace std;

// x와 y좌표 차이가 2이하인 징검다리로 점프 가능
// 결승선 : x축 평행 직선 -> y좌표 동일한 징검다리에 도달하기만 하면 됨.
// 가장 빠른 경로 찾기
// (x1, y1) -> (x2, y2) : ((x1-x2)^2 + (y1- y2)^2)

// N : 1~50'000
// 좌표 : 0 ~ 1'000'000
// (0,0)은 시작점

using ll = long long;

struct Loc
{
    int y = 0;
    int x = 0;
    double cost = 0;

    // 비용 기준 오름차순 정렬
    bool operator<(const Loc& other) const
    {
        return cost > other.cost;
    }

    // 맵에서 사용할 비교 함수
    bool operator==(const Loc& other) const
    {
        return y == other.y && x == other.x;
    }
};

// 해시 함수
struct LocHash
{
    size_t operator()(const Loc& loc) const
    {
        return hash<int>()(loc.y) ^ (hash<int>()(loc.x) << 1);
    }
};

const int dir[] = {-2, -1, 0, 1, 2};
const double MAX_VALUE = 1'000'000'000'000.0;
unordered_map<Loc, double, LocHash> g_locs;
vector<int> g_goals_x;

void inputData(const int N, const int F)
{
    g_locs.reserve(N);

    int y, x;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        g_locs[{y, x}] = -1.0;

        if(y == F)
            g_goals_x.push_back(x);
    }

    // 시작점이 도착지인 경우
    if(F == 0)
        g_goals_x.push_back(0);
}

double diffPower(const ll& a, const ll& b)
{
    return (a - b) * (a - b);
}

void simulate(const int N)
{
    priority_queue<Loc> pq;
    pq.push({0, 0, 0});
    g_locs[{0, 0}] = 0.0;

    while(pq.empty() == false)
    {
        Loc cur = pq.top();
        pq.pop();
        // cout << "y : " << cur.y << ", x : " << cur.x << ", cost : " << cur.cost << "\n";
        // 방향별로 검사
        for(const int& dy : dir)
        {
            for(const int& dx : dir)
            {
                // 자기 자신인 경우는 무시
                if(dy == 0 && dx == 0)
                    continue;

                int nextY = cur.y + dy;
                int nextX = cur.x + dx;
                // 징검다리가 없다면, 무시
                if(g_locs[{nextY, nextX}] == 0.0)
                    continue;

                double cost = cur.cost + sqrt(diffPower(cur.y, nextY) + diffPower(cur.x, nextX));
                // 현재 비용이 더 비싸거나 같으면서 처음 도착하지 않았을 때, 무시
                if(g_locs[{nextY, nextX}] <= cost && g_locs[{nextY, nextX}] > -0.8)
                    continue;

                // 현재 비용이 더 저렴하다면, 다시 이동 및 검사 시작
                pq.push({nextY, nextX, cost});
                g_locs[{nextY, nextX}] = cost;
            }
        }
    }
}

int getResult(const int F)
{
    double result = MAX_VALUE;
    for(const int& x : g_goals_x)
    {
        if(g_locs[{F, x}] > -0.8)
            result = min(result, g_locs[{F, x}]);
    }

    // 불가능한 경우
    if(result == MAX_VALUE)
        return -1;

    
    return static_cast<int>(round(result));
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 징검다리 개수 N, 결승선 y좌표 F
    int N, F;
    cin >> N >> F;

    inputData(N, F);
    simulate(N);
    cout << getResult(F) << "\n";
}