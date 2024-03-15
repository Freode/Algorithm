// 실버 4 - 11047번 : 동전 0
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, K;
    cin >> N >> K;

    vector<int> coin_kinds(N, 0);

    for(int &each : coin_kinds)
    {
        cin >> each;
    }

    // 변수 선언
    int coins = 0;
    int values = K;
    int cur_coin = 0;

    // 배수이면서 오름차순으로 선언되어있으므로
    // 나머지 연산으로 처리 가능
    for(int i = N - 1; i >= 0; i--)
    {
        cur_coin = values / coin_kinds[i];
        coins += cur_coin;
        values -= (cur_coin * coin_kinds[i]);
    }

    // 출력문
    cout << coins << "\n";
}