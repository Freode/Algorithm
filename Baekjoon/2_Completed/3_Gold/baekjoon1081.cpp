// 골드 1 - 1081번 : 합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// L <= x <= U 
// 각 자리의 합 구하기
// U -> 20억

// 165
// 1의 자리 -> 0~4 : (5개) * (17), 5 : 17개,  6~9 : (4개) * 16개
// 10의 자리 -> 0~5 : (6개)* (2개) * (10), 6 : 16개, 7~9 : (1개) * (10)
// 100의 자리 -> 1 -> 66개

// 2356
// 1의 자리 -> 0~6 : 236개, 7~9 : 235개
// 10의 자리 -> 0~4 : 24개 * (10), 5 : 230 + 7개, 6~9 : (4번) * 23개 * (10)
// 100의 자리 -> 0~2 : (3개) * 100, 3 : 200개 + 57개 , 4~9 : (2개) * 100
// 1'000의 자리 -> 0~1 : (1개) * 1000, 2 : 357개

// 14
// 1의 자리 -> 0~3 : (4번) * 2개, 4 : (1번) * 2개, 5~9 : (5번) * 1개
// 10의 자리 -> 0 : (1번) * 10개, 1 : (1번) * 4개, 

using ll = long long;

ll simulate(const ll x)
{
    ll result = 0;

    ll div = 10;

    do
    {
        ll base = x / div;

        ll cur_check = div / 10;
        ll rest = x % cur_check;

        ll mid = (x % div) / cur_check;

        for(int i = 0; i < 10; i++)
        {
            if(i < mid)
                result += (i * (base + 1) * cur_check);

            else if(mid == i)
                result += (i * (base * cur_check + rest + 1));
            
            else
                result += (i * (base * cur_check));

            //cout << "cur : " << cur_check << ", i : " << i << ", result : " << result << "\n";
        }

        div *= 10;
    } while(x * 10 / div > 0);

    return result;
}

ll each(const ll x)
{
    string base = to_string(x);
    ll result = 0;
    for(const char& each : base)
        result += (ll)(each - '0');

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 최소 범위 L, 최대 범위 U
    ll L, U;
    cin >> L >> U;

    ll result = simulate(U) - simulate(L) + each(L);

    cout << result << "\n";
}