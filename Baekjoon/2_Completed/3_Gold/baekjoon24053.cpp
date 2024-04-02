// 골드 5 - 24053번 : 알고리즘 수업 - 삽입 정렬 3
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

    vector<int> inputs(5, 0);
    vector<int> result(5, 0);

    for(int& each : inputs){ cin >> each; }
    for(int& each : result){ cin >> each; }

    int loc = 0;
    int new_item = 0;
    int same = 0;
    bool b_is_samed = false;
    for(int i = 1; i < N; i++)
    {
        loc = i - 1;
        new_item = inputs[i];

        // 이전 값이 현재 값보다 더 클 경우
        while(0 <= loc && new_item < inputs[loc])
        {
            inputs[loc + 1] = inputs[loc];

            // 바꾼 값이 결과와 일치하는 경우에만 전체 비교
            if(inputs[loc + 1] == result[loc + 1] && inputs[loc] == result[loc])
            {
                b_is_samed = true;
                for(int j = 0; j < N; j++)
                {
                    if(inputs[j] != result[j])
                    { 
                        b_is_samed = false;
                        break;
                    }
                }

                // 전체가 같은 경우에만 변경
                if(b_is_samed) { same = 1; }
            }
            loc--;
        }

        // 이전 값이 현재 값보다 더 큰 경우가 없을 때
        // loc = i - 1일 때
        if(loc + 1 != i){ inputs[loc + 1] = new_item; }
    }
    // 출력
    cout << same << "\n";
}