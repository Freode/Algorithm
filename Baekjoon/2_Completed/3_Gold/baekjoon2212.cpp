// 골드 5 - 2212번 : 센서
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, K;
    cin >> N >> K;

    // 위치 입력
    vector<int> locs(N, 0);
    for(int& loc : locs){cin >> loc;}

    // 위치 오름차순
    sort(locs.begin(), locs.end());

    // 다음 센서 위치와의 거리 구하기
    vector<int> diff(N-1, 0);
    for(int i = 0; i < N - 1; i++){ diff[i] = locs[i + 1] - locs[i]; }

    // 거리 내림차순으로 정렬
    sort(diff.begin(), diff.end(), [](int a, int b)
    {
        return a > b;
    });

    // 다음 센서와의 거리가 가장 먼 순서대로 나눠서 집중국을 설치해야 함.
    // 따라서, 집중국 n-1개까지 거리가 가장 먼 순서대로 제거해서 더하기.
    int sum = 0;
    for(int i = K - 1; i < N - 1; i++){ sum += diff[i]; }

    // 출력
    cout << sum << "\n";
}
