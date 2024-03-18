// 실버 4 - 11399번 : ATM
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 인출 시간이 적은 사람부터 뽑도록 하면 
// 모든 사람의 돈 인출 필요 시간 합의 최솟값을 구할 수 있음.
int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    // 각 사람이 돈을 뽑는데 걸리는 시간 입력
    vector<int> time(N);
    for(int& each : time)
    {
        cin >> each;
    }

    // 오름차순으로 정렬
    sort(time.begin(), time.end());

    // 순서대로 더하기
    int total = 0;
    int before_sum = 0;
    for(int& each : time)
    {
        before_sum += each;
        total += before_sum;
        cout << total << "\n";
    }

    // 출력문
    cout << total << "\n";
}
