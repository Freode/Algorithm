// 골드 1 - 1176번 : 섞기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N명
// 키 차이 K

// 만족하는 조건 수

// 키 조건을 만족하면 추가로 배치
// [현재 배치된 학생 번호][배치한 학생]

// 2^16 * 20 = 10^5 * 20 = 8MB

// 가능한 배열의 개수 -> 

using ll = long long;

vector<int> g_students;
vector<vector<ll>> g_cases;

void inputInfo(const int N)
{
    g_students = vector<int>(N);

    for(int& each : g_students)
    {
        cin >> each;
    }

    g_cases = vector<vector<ll>>(N, vector<ll>(1 << N, -1));
}

ll simulate(const int N, const int K, const int num, const int place, const int cur)
{
    // 모든 학생이 배치된 경우 -> 가능한 배열 경우 1 증가
    if(N == num)
        return 1;

    // 현재 검사 위치
    ll& ref = g_cases[cur][place];

    // 이미 처리가 된 경우, 반환
    if(ref != -1)
        return ref;

    // 방문했으므로 0으로 처리하고 시작
    ref = 0;
    // 다른 학생의 키를 비교해서 배치
    for(int i = 0; i < N; i++)
    {
        // 이미 배치된 학생인 경우 무시
        if(place & (1 << i))
            continue;

        // 키 차이가 K 이하인 경우 무시
        if(abs(g_students[i] - g_students[cur]) <= K)
            continue;

        // 학생을 추가로 배치
        ref += simulate(N, K, num+1, place | (1 << i), i);
    }
    return ref;
}

// 첫 번째로 오는 경우를 모두 대입
ll search(const int N, const int K)
{
    ll result = 0;

    // 처음으로 배치할 학생 정하기
    for(int i = 0; i < N; i++)
    {
        result += simulate(N, K, 1, 1 << i, i);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 학생 수 N, 키 차이 K
    int N, K;
    cin >> N >> K;

    inputInfo(N);
    cout << search(N, K) << "\n";
}