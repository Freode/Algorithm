// 실버 2 - 30804번 : 과일 탕후루
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
    cout.tie(nullptr);

    vector<int> counts = vector<int>(11, 0);

    // 과일 개수 N
    int N;
    cin >> N;

    // 과일 정보 입력
    vector<int> fruits = vector<int>(N);
    for(int& fruit : fruits)
    {
        cin >> fruit;
    }

    int left = 0, right = 0, result = 0, count = 0;
    bool b_add = true;
    // 왼쪽 경계와 오른쪽 경계에 대한 정보로 검사
    // 유효한 범위일 때만 검사 진행
    while(left <= right && right < N)
    {
        // 과일 개수 검사
        // 1. 과일 추가
        if(b_add)
        {
            counts[fruits[right]]++;
            // 새로운 과일 종류 추가한 경우
            if(counts[fruits[right]] == 1) count++;
        }
        // 2. 과일 제거
        else
        {
            // 제거되어서 left가 이미 오른쪽으로 한 칸 이동했기 때문에, left-1로 검사
            int check = left - 1;
            counts[fruits[check]]--;
            // 과일 종류가 하나 줄은 경우
            if(counts[fruits[check]] == 0) count--;
        }

        // 과일 종류에 대한 검사
        // 1. 과일 종류가 2개 이하일 때, 뒤에 하나 더 추가해서 검사
        if(count <= 2)
        {
            // 과일 개수 최대값인지 검사
            result = max(result, right-left+1);
            b_add = true;
            right++;
        }
        // 2. 과일 종류가 2개 초과일 때, 앞에 하나를 제거해서 검사
        else
        {
            b_add = false;
            left++;
        }
    }
    cout << result << "\n";
}