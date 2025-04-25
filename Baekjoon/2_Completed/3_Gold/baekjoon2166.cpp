// 골드 5 - 2166번 : 다각형의 면적
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 순서대로 N개의 좌표가 주어지므로, 문제 없이 신발끈 공식 사용
// 마지막에도 첫 점을 추가해야 함.

using ll = long long;
using ld = long double;

struct Loc
{
    ll x = 0;
    ll y = 0;
};

vector<Loc> g_locs;

// 좌표 정보 입력
void inputLoc(const int N)
{
    g_locs = vector<Loc>(N+1);

    for(int i = 0; i < N; i++)
        cin >> g_locs[i].x >> g_locs[i].y;

    g_locs[N] = g_locs[0];
}

// 계산
ld calculate(const int N)
{
    ld first = 0.0, second = 0.0;

    for(int i = 1; i <= N; i++)
    {
        first += (g_locs[i-1].x * g_locs[i].y);
        second += (g_locs[i-1].y * g_locs[i].x);
    }

    return fabs(first - second) * 0.5f;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // N개 다각형
    int N;
    cin >> N;

    inputLoc(N);
    printf("%.1Lf\n", calculate(N));
}