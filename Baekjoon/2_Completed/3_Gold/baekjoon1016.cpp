// 골드 1 - 1016번 : 제곱 ㄴㄴ 수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 입력 수 범위 -> 1~10^12
// 개수 범위 -> 10^6
// 시간복잡도 -> 10^6 * log(10^6) = 6*10^6

using ll = long long;

vector<bool> g_checks(1'000'001, false);

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시작 S, 끝 E
    ll S, E;
    cin >> S >> E;

    // 현재 검사 전 개수
    int count = E - S + 1;

    // 제곱수에 대해 모두 검사
    for(ll idx = 2; idx * idx <= E; idx++)
    {
        ll base = idx * idx;
        // 제곱수에 대한 배수만 구하기
        for(ll quotient = S / base; quotient <= (E / base); quotient++)
        {
            ll check = quotient * base;
            // 현재 검사 범위보다 작을 경우 무시
            if(check < S)
                continue;

            // 이미 제곱수이면, 무시
            if(g_checks[check - S])
                continue;

            // 제곱수의 배수면, 제곱 ㄴㄴ 수를 1개 감소
            g_checks[check - S] = true;
            count--;
        }
    }

    cout << count << "\n";
}