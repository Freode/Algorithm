// 실버 3 - 17253번 : 삼삼한 수 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// 3진법
// 3으로 나눴을 때, 몫이 2가 되면 안됨.

bool simulate(ll num)
{
    // 0은 제외
    if(num == 0)
        return false;

    ll rest = 1;
    ll div = 3;

    // 3의 배수로 몫과 나머지를 구하면서, 비교
    while(num > 0)
    {
        ll check = (num % div) / rest;

        if(check == 2)
            return false;

        num -= (check * rest);
        div *= 3;
        rest *= 3;
    }

    return true;
}

void printResult(bool bResult)
{
    if(bResult)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수 입력 num
    ll num;
    cin >> num;

    bool bResult = simulate(num);
    printResult(bResult);
}