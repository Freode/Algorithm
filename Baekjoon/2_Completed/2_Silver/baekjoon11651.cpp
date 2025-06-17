// 실버 5 - 11651번 : 좌표 정렬하기 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Loc
{
    int y;
    int x;
};

vector<Loc> g_locs;

void inputData(const int N)
{
    g_locs = vector<Loc>(N);

    for(int i = 0; i < N; i++)
    {
        cin >> g_locs[i].x >> g_locs[i].y;
    }
}

void simulate(const int N)
{
    sort(g_locs.begin(), g_locs.end(), [](const Loc& a, const Loc& b)
    {
        if(a.y != b.y)
            return a.y < b.y;

        return a.x < b.x;
    });
}

void printResult(const int N)
{
    for(const Loc& each : g_locs)
    {
        cout << each.x << " " << each.y << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 점의 개수 N
    int N;
    cin >> N;

    inputData(N);
    simulate(N);
    printResult(N);
}