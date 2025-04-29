// 골드 5 - 2247번 : 실질적 약수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 실질적 약수 : 1과 자기 자신(N)을 제외한 약수
// 6 -> 2,3
// 13 -> x

// SOD 함수 -> 실질적 약수의 합
// SOD(6) = 5
// SOD(13) = 0

// CSOD(n) = SOD(1) + ... SOD(n)

// 1    0
// 2    0
// 3    0
// 4    2
// 5    0
// 6    2,3
// 7    0
// 8    2,4
// 9    3
// 10   2,5
// 11   0
// 12   2,3,4,6
// 13   0
// 14   2,7
// 15   3,5
// 16   2,4,8
// 17   0
// 18   2,3,6,9
// 19   0
// 20   2,4,5,10

// 20 -> / 2 = 10 -> 2*(10-1)
// 20 -> / 3 = 6 -> 3*(6-1)
// 20 -> / 4 = 5 -> 4*(5-1)
// 20 -> / 5 = 4 -> 5*(4-1)
// 20 -> / 6 = 3 -> 6*(3-1)
// 20 -> / 7 = 2 -> 7*(2-1)
// 10까지 -> 절반까지

const int DIV = 1'000'000;

int csod(const int n)
{
    const int half = n / 2;
    int sum = 0;
    for(int i = 2; i <= half; i++)
    {
        int count = n / i;
        sum += (i * (count-1));
        sum %= DIV;
    }

    return sum;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정수 n
    int n;
    cin >> n;

    cout << csod(n) << "\n";
}