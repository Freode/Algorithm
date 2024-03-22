// 실버 3 - 28116번 : 선택 정렬의 이동거리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<int> nums(N, 0);
    vector<int> movements(N, 0);
    map<int, int> loc_nums;

    // 수 입력과 현재 인덱스 위치 저장
    for(int i = 0; i < N; i++)
    { 
        cin >> nums[i];
        loc_nums[nums[i]] = i;
    }

    int current_idx;
    // 수 제자리로 돌리기
    for(int i = 0; i < N; i++)
    {
        // 현재 위치가 맞는 경우 통과
        if(loc_nums[i + 1] == i) { continue; }
        
        current_idx = loc_nums[i + 1];

        // 움직이는 거리 계산
        movements[i] += current_idx - i;
        movements[nums[i] - 1] += current_idx - i;

        // 수 위치 변경
        nums[current_idx] = nums[i];
        nums[i] = i + 1;

        // 인덱스 위치 변경
        loc_nums[nums[current_idx]] = current_idx;
        loc_nums[nums[i]] = i;
    }

    // 출력
    for(int& movement : movements)
    {
        cout << movement << " ";
    }
    cout << "\n";
}