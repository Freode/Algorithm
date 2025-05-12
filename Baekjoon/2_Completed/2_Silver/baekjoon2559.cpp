// 실버 3 - 2559번 : 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 날짜 수 N, 연속 K일
    int N, K;
    cin >> N >> K;

    // 온도 입력
    vector<int> tmps(N);
    int start = 0, end = 0;
    int sum = 0;
    int result = numeric_limits<int>::min();

    for(int i = 0; i < N; i++)
    {
        cin >> tmps[i];

        // 처음 연속 K일 온도 합 구하기
        if(end < K)
        {
            end++;
            sum += tmps[i];
        }
    }

    // 처음 연속 K일과 비교
    result = max(result, sum);

    // 시작과 끝의 투 포인터로 옆으로 한 칸씩 계속 밀어서 검사
    while(end < N)
    {
        sum -= tmps[start];
        start++;

        sum += tmps[end];
        end++;

        result = max(result, sum);
    }

    cout << result << "\n";
}