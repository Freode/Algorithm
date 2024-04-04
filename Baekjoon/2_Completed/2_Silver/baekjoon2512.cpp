// 실버 2 - 2512번 : 예산
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    int left = 0, right = 0, pivot = 0;
    vector<int> inputs(N, 0);
    for(int& each : inputs)
    { 
        cin >> each;
        // 최댓값 찾기
        if(each > right) { right = each; }
    }

    int budget;
    cin >> budget;

    // 계산
    int temp_total = 0;
    // 왼쪽과 오른쪽 차이가 없거나 역전될 때까지 찾기
    while(left <= right)
    {
        // 중심점과 임시 변수
        pivot = (left + right) / 2;
        temp_total = 0;
        // 예산 계산
        for(int& each : inputs)
        {
            temp_total += (each - pivot >= 0 ? pivot : each);
        }

        // 예산 초과일 경우, 최대 예산 배정값을 줄여야하므로 오른쪽을 pivot으로 옮김. 
        if(temp_total > budget) { right = pivot - 1; }
        // 예산이 남으므로 최소 예산 배정값을 늘리므로 왼쪽을 pivot으로 옮김.
        else if(temp_total < budget) { left = pivot + 1; }
        // 정확한 예산을 찾았으므로 멈춤
        else{ right = pivot; break; }
    }

    // 출력
    cout << right << "\n";
}