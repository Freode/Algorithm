// 골드 2 - 3964번 : 팩토리얼과 거듭제곱
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    

}