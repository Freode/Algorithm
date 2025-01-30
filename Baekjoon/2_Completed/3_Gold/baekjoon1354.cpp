// 골드 5 - 1354번 : 무한 수열 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 타입 정의
typedef long long ll;

// 2^10 = 10^3
// 2^50 = 10^15
// 최대로 계산하는 경우의 max -> 약 50번 미만

// 수열 계산
ll calculate(map<ll, ll> &c_map, ll n, ll &p, ll &q, ll &x, ll &y)
{
    // n이 음수나 0인 경우
    if(n <= 0)
    {
        return 1;
    }
    // 해당 n에 대해서 아직까지 한 번도 검색하지 않은 경우
    if(c_map[n] == 0)
    {
        ll first = n / p - x;
        ll second = n / q - y;
        // 재귀로 검사
        c_map[n] = calculate(c_map, first, p, q, x, y) + calculate(c_map, second, p, q, x, y);
        return c_map[n];
    }
    // 해당 n에 대해서 한 번이라도 검색한 경우, 값을 반환
    else
    {
        return c_map[n];
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    long long n, p, q, x, y;
    cin >> n >> p >> q >> x >> y;

    map<ll, ll> c_map;

    // 수열 계산
    ll result = calculate(c_map, n, p, q, x, y);

    // 출력
    cout << result << "\n";
}