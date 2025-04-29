// 골드 5 - 2436번 : 공약수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 두 수 합이 가장 작은 것

// 6 180
// 6x 6y

// 6 * x * y = 180
// x * y = 30
// x와 y는 서로소

// 자연수 입력 : 2~100'000'000

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 최대공약수 a, 최소공배수 b
    int a, b;
    cin >> a >> b;

    int target = b / a;

    int x, y;

    for(int i = 1; i <= (int)sqrt(target); i++)
    {
        // gcd -> 1 : 공약수가 존재하지 않음
        if(target % i == 0 && gcd(i, target / i) == 1)
        {
            x = i;
            y = target / i;
        }
    }

    cout << a * x << " " << a * y << "\n";
}