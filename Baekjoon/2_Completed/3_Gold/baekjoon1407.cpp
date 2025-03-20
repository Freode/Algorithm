// 골드 4 - 1407번 : zvrk
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 범위 구하기
// 2로 나눠서 개수 구하기
// 2가 많은 순서부터 계산 -> 한 단계씩 올라가면서, 중복 개수 제거하면서 처리

// 2^10 = 10^3
// 2^50 = 10^15

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 A와 B
    ll A, B;
    cin >> A >> B;

    vector<ll> counts(51, 0);

    // 2의 제곱 미리 구하기
    vector<ll> pow_2(51, 1);
    for(int i = 1; i < 51; i++)
    {
        pow_2[i] = pow_2[i-1] * 2;
    }

    ll start = A, end = B;
    // 2^i
    for(int i = 0; i < 51; i++)
    {
        // 범위 개수 넣기
        counts[i] = (end - start) + 1;

        // 다음 범위로 이동
        start = (start % 2 == 1) ? (start / 2 + 1) : (start / 2);
        end = end / 2;

        // 더 이상 2로 나눌 수 있는 수가 없음
        if(start > end) break;
    }

    // 계산하기
    ll result = 0;
    ll duplicate_cnt = 0;

    for(int i = 50; i >= 0; i--)
    {
        result += (counts[i]-duplicate_cnt) * pow_2[i];
        // 중복 횟수 구하기
        duplicate_cnt = counts[i];
    }

    cout << result << "\n";
}