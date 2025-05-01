// 골드 2 - 3964번 : 팩토리얼과 거듭제곱
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

using namespace std;

// n! k^i

// n-> 2~10^18 -> long long
// k-> 2~10^12

// 5 2
// 5! -> 120
// 2^i -> 8

// 7! = 5040
// 8! = 40320
// 9! = 362880
// 10! = 3628800
// i = 2 -> 100

// 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10
// 2 -> 10/2 = 5
// 2 -> 5/2 = 2
// 2 -> 2/2 = 1
// 2 -> 1/2 = 0

// 2^(10^8) = 2^(100'000'000) = 10^3^(10'000'000)

// 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10
// 10 -> 10/10 = 1
// 10 -> 1/10 = 0 -> x

// 소인수분해 해서 구성 개수를 바탕으로 i 제곱 구하기
// 

using ll = long long;

const ll MAX_VALUE = numeric_limits<ll>::max();

unordered_map<ll, int> g_nums;

// 소인수분해 
void getNums(const ll mul)
{
    g_nums.clear();
    ll num = mul;

    for(ll i = 2; i * i <= num; i++)
    {
        // 소인수 더하기
        if(num % i == 0)
        {
            g_nums[i]++;
            num /= i;
            i--;
        }
    }
    // 마지막 남은거 추가
    g_nums[num]++;
}

void simulate()
{
    // n!, k^i
    ll n, k;
    cin >> n >> k;

    getNums(k);

    ll result = MAX_VALUE;
    for(const auto& num : g_nums)
    {
        // 현재 n!을 구성하는 num의 개수 구하기
        ll check = n;
        ll count = 0;
        while(check > 0)
        {
            check /= num.first;
            count += check;
        }
        // 최솟값으로 구할 수 있는지 확인
        result = min(result, count / num.second);
    }

    cout << result << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        simulate();
    }
}