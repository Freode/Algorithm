// 골드 5 - 27738번 : 연산자 파티
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1 <= N <= 10^12
// 실질적으로 자릿수가 변경되는건 A만 있음.
// A로 아무리 값이 증가해도 >> i로 인해서 계속 0으로 초기화됨. (2^i)
// N - F 마지막 배수값에서 부터 검사하면 됨.

using ll = long long;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, A, B, C, D, E, F;
    cin >> N >> A >> B >> C >> D >> E >> F;

    ll start = N - (N % F) + 1;
    ll result = 0;

    for(ll i = start; i <= N; i++)
    {
        if(i % A == 0)
            result += i;

        if(i % B == 0)
            result %= i;

        if(i % C == 0)
            result = (result & i);

        if(i % D == 0)
            result = (result ^ i);

        if(i % E == 0)
            result = (result | i);

        if(i % F == 0)
            result = (result >> i);
    }

    cout << result << "\n";
}