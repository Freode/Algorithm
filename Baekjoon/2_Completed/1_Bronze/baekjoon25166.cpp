// 브론즈 1 - 25166번 : 배고픈 아리의 샌드위치 구매하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 동전 10가지 : 2^0, 2^1, ..., 2^9
// 10가지 동전 각각 1개씩 총 10개

// 쿠기 -> 10가지 중 몇 가지의 동전을 하나씩만 가지고 있음.
// 쿠기의 돈 총합 M -> 여기서 돈 빌리기 가능

// 아리 돈으로만 구매 가능 -> No thanks
// 쿠기 도움 -> Thanks
// 구매 불가능 -> Impossible

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 샌드위치 가격 S, 쿠기 금액 M
    int S, M;
    cin >> S >> M;

    // 동전 종류
    vector<int> coins(10, 0);
    int coin_size = 10;
    coins[0] = 1;
    for(int i = 1; i < coin_size; i++)
    {
        coins[i] = coins[i-1] << 1;
    }

    // 아리 돈으로 구매 가능한 범위를 확인
    int money = 0;
    for(int i = coin_size-1; i >= 0; i--)
    {
        // 현재 동전으로 구매 가능
        if(S - money >= coins[i])
        {
            money += coins[i];
        }
    }

    // 아리 돈으로 해결 가능
    if(money == S)
    {
        cout << "No thanks\n";
        return 0;
    }

    // 쿠기 동전 확인
    vector<bool> cookie(10, 0);
    for(int i = coin_size-1; i >= 0; i--)
    {
        // 해당 동전이 있음.
        if(M >= coins[i])
        {
            M -= coins[i];
            cookie[i] = true;
        }
    }

    // 쿠기 돈 빌리기
    for(int i = coin_size-1; i >= 0; i--)
    {
        // 해당 동전이 있고, 해당 동전으로 커버 가능
        if(cookie[i] == true && S - money >= coins[i])
        {
            money += coins[i];
        }
    }

    // 쿠기 돈을 빌려서 구매 가능
    if(money == S)
    {
        cout << "Thanks\n";
    }
    else
    {
        cout << "Impossible\n";
    }
}