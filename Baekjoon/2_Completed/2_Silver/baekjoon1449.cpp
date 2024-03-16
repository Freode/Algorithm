// 실버 3 - 1449번 : 캠핑
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 물이 새는 곳 개수와 테이프 길이
    int N, L;
    cin >> N >> L;

    // 물이 새는 위치 입력
    vector<int> loc(N);
    for(int& each : loc) { cin >> each; }

    // 오름차순 정렬
    sort(loc.begin(), loc.end());

    int count = 0;
    int current_loc = -10000;

    // 테이프 붙인 위치와 테이프 길이를 비교
    // 연속으로 붙일 수 있는 경우에는 무시
    for(int i = 0; i < N; i++)
    {
        if(current_loc + L - 1 < loc[i])
        {
            current_loc = loc[i]; 
            count++;
        }
    }

    // 출력
    cout << count << "\n";
}