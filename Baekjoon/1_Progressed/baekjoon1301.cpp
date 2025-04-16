// 골드 3 - 1301번 : 비즈 공예
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 구슬 종류 N : 3~5
// 각 구슬 -> 총 합 35이하

// 연속된 3개의 구슬이 같은색이 되면 안됨.
// 구슬 종류 최대 5개
// 각 구슬은 최대 10개
// [2번 전 구슬 선택][1번 전 구슬 선택][1번 구슬][2번 구슬][3번 구슬][4번 구슬][5번 구슬]
// 구슬 선택 : 선택 x ~ 5번 구슬 : 총 6가지
// 구슬 개수 : 0개 ~ 10개 : 총 11가지

// [6][6][11][11][11][11][11]
// 6*6 = 36 * 11^5
// 약 400만~500만 -> 공간 복잡도 : 20'000'000 = 20MB

// 현재 단계에서 선택 가능한 구슬 선택
// -> 1번 전과 2번 전이 일치하지 않는 구슬이면서, 남아 있는 개수가 있다면, 선택 가능

// 출력 범위 : long long -> 7개씩 다 넣어보니, int 범위를 벗어남.

using ll = long long;

using vec_1 = vector<ll>;
using vec_2 = vector<vec_1>;
using vec_3 = vector<vec_2>;
using vec_4 = vector<vec_3>;
using vec_5 = vector<vec_4>;
using vec_6 = vector<vec_5>;
using vec_7 = vector<vec_6>;

vec_7 g_cases;

ll simulate(int pprev, int prev, int a, int b, int c, int d, int e)
{
    // 구슬이 더 이상 남아있지 않은 경우
    if(a+b+c+d+e == 0)
        return 1;

    // 이미 해당 검사 결과가 있는 경우, 바로 반환
    if(g_cases[pprev][prev][a][b][c][d][e] != -1)
        return g_cases[pprev][prev][a][b][c][d][e];

    // 구슬이 남아있는 경우에는 추가로 사용
    // {pprev = prev, prev = 현재 선택한 구슬 번호} 로 변경

    // 변수명이 길어서, 레퍼런스로 두 번째 별칭 정하기
    ll& ref = g_cases[pprev][prev][a][b][c][d][e];
    ref = 0;
    // 1번 구슬 사용 가능
    if(a > 0 && pprev != 1 && prev != 1)
        ref += simulate(prev, 1, a-1, b, c, d, e);
    // 2번 구슬 사용 가능
    if(b > 0 && pprev != 2 && prev != 2)
        ref += simulate(prev, 2, a, b-1, c, d, e);
    // 3번 구슬 사용 가능
    if(c > 0 && pprev != 3 && prev != 3)
        ref += simulate(prev, 3, a, b, c-1, d, e);
    // 4번 구슬 사용 가능
    if(d > 0 && pprev != 4 && prev != 4)
        ref += simulate(prev, 4, a, b, c, d-1, e);
    // 5번 구슬 사용 가능
    if(e > 0 && pprev != 5 && prev != 5)
        ref += simulate(prev, 5, a, b, c, d, e-1);

    // 현재 남은 구슬 상황에서 도달 가능한 경우를 반환
    return ref;
}

// 구슬 정보 입력 및 시뮬레이션
void start(const int N)
{
    // [6][6][11][11][11][11][11] 할당 및 -1으로 모두 초기화
    // -1 초기화 x
    g_cases = vec_7(6, vec_6(6, vec_5(11, vec_4(11, vec_3(11, vec_2(11, vec_1(11, -1)))))));

    // 구슬 정보 입력
    vec_1 sphere = vec_1(5, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> sphere[i];
    }
    ll result = simulate(0, 0, sphere[0], sphere[1], sphere[2], sphere[3], sphere[4]);
    cout << result << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 구슬 종류 N
    int N;
    cin >> N;

    start(N);
}