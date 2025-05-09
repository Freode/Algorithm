// 골드 5 - 1011번 : Fly me to the Alpha Centauri
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// k 광년 이동 -> k-1, k, k+1광년만을 다시 이동 가능

// 1광년 이동 -> 다음 0 1 2 광년 가능
// 2광년 이동 -> 다음 1 2 3 광년 가능

// x지점에서 y지점까지 최소한 작동 횟수로이동
// y 지점 도착하기 바로 직전의 이동 거리는 반드시 1광년

// y 지점에서 거꾸로 이동

// 2^31 = 20억 -> int형 데이터 -> 8'000'000'000 = 8GB
// 단순 DP x

// 가속하는 것이 이득
// 횟수  최대 거리  종류
// 1    1       1
// 2    2       1 1
// 3    4       1 2 1
// 4    6       1 2 2 1
// 5    9       1 2 3 2 1
// 6    12      1 2 3 3 2 1
// 7    16      1 2 3 4 3 2 1
// 8    20      1 2 3 4 4 3 2 1
// 9    25      1 2 3 4 5 4 3 2 1
// 최대 거리 사이에는 수를 일부 조정해서 사용 가능

using ll = long long;

vector<ll> g_cases;

void simulate()
{
    g_cases.reserve(100'000);
    g_cases.push_back(0);
    int result = 0;

    const ll distance = numeric_limits<int>::max();
    ll sum = 0;
    int add = 1;

    while(sum < distance)
    {
        sum += add;
        result++;
        if(result % 2 == 0)
            add++;

        g_cases.push_back(sum);
    }
}

int search(const int start, const int end)
{
    const int distance = end - start;

    int result = 0;

    for(int i = 1; i < g_cases.size(); i++)
    {
        if(distance <= g_cases[i])
            return i;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    simulate();
    for(int i = 0; i < T; i++)
    {
        int start, end;
        cin >> start >> end;

        int result = search(start, end);
        cout << result << "\n";
    }
}