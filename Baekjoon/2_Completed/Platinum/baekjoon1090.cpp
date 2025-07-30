// 플레티넘 4 - 1090번 : 체커
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// 2 1
// 2 3
// 1 2
// 3 2

// 평균과 차 -> 이동 거리
// 어떤 점을 선택해야하는가?

// 1번 고정?하면 안됨
// 모든 점을 경계라고 생각하고, 그 범위 내에 존재

// 각 점마다 다른 점들을 거리 기준으로 오름차순 정렬
// 각 점마다 앞에서 k개씩 묶어서 평균(반올림)해서 거리차를 구하고
// 가장 짧은 것을 구하기 

// 무조건 평균이 빠른 건 아님.
// 사이에 있는 점으로 이동하는게 가장 빠를 수도 있음.

// 평균이 아니라, 현재 위치한 좌표의 y와 x값을 조합해서 나오는 경우 중 하나가 가장 최적의 좌표
// 50 * 50 = 2'500(경우)
// 2'500 * 50(기존 좌표 거리 구하기) * 50(점의 개수)
// 6'250'000

const int MAX_VALUE = numeric_limits<int>::max() >> 2;

struct Loc
{
    int y = 0;
    int x = 0;
    int dist = 0;
};

vector<Loc> g_locs;
vector<Loc> g_checks;

int getDist(const int y, const int x, const int other_y, const int other_x)
{
    return abs(y - other_y) + abs(x - other_x);
}

void initAndInputData(const int N)
{
    g_locs = vector<Loc>(N);
    g_checks.reserve(N * N);

    // 점 데이터 추가
    for(int i = 0; i < N; i++)
    {
        cin >> g_locs[i].x >>  g_locs[i].y; 
    }

    // 각 기준점마다 y와 x좌표를 조합
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            g_checks.push_back({g_locs[y].y, g_locs[x].x});
        }
    }
}

void simulate(const int N)
{
     // 각 기준점마다 검사하는 좌표와의 거리를 구해서 정렬하고, 묶는 점의 개수만큼 거리를 더하기
    for(int cnt = 1; cnt <= N; cnt++)
    {
        int result = MAX_VALUE;
        for(const Loc& check : g_checks)
        {
            for(Loc& loc : g_locs)
            {
                loc.dist = getDist(check.y, check.x, loc.y, loc.x);
            }

            sort(g_locs.begin(), g_locs.end(),
            [](const Loc& A, const Loc& B)
            {
                return A.dist < B.dist;
            });

            int dist = 0;
            for(int i = 0; i < cnt; i++)
            {
                dist += g_locs[i].dist;
            }

            result = min(result, dist);
        }

        cout << result << " ";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 체커 N개
    int N;
    cin >> N;

    initAndInputData(N);
    simulate(N);
}