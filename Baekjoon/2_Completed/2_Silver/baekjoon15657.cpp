// 실버 3 - 15657번 : N과 M (8)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 재귀랑 백트래킹으로 해결
// 해당 수가 이전 계층의 수보다 크거나 같을 때, 해당 값을 순서 vector에 저장
// 다시 Repeat 함수를 호출
// 해당 함수 반환 시, 해당 값 방문을 초기화

// 현재 계층이 최대치에 도달한 경우, 저장된 순서 vector의 값을 출력

// 반복
void Repeat(vector<int> &values, vector<int> &saved, int currentNum, int currentHiearchy, int maxHiearchy)
{
	// 반복문.
	for (int i = 0; i < values.size(); i++)
	{
        // 이전 계층 값보다 현재 계층의 값이 크거나 같을 때
        if(currentNum <= values[i])
        {
            // 값 저장
            saved[currentHiearchy - 1] = values[i];

            // 계층이 최대로 나아갔을 때, 출력.
            if (currentHiearchy == maxHiearchy)
            {
                // 출력.
                for (int i = 0; i < maxHiearchy; i++)
                {
                    cout << saved[i] << " ";
                }

                // 한 줄 띄우기.
                cout << "\n";
            }

            // 계층이 최대로 나아가지 않았을 때, 반복.
            else
            {
                Repeat(values, saved, values[i], currentHiearchy + 1, maxHiearchy);
            }
        }
	}
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M;
    cin >> N >> M;

    // 수 입력
    vector<int> values(N);
    for(int &value : values)
    {
        cin >> value;
    }

    // 오름차순 정렬
    sort(values.begin(), values.end());
    
    // 값 저장
    vector<int> saved(N, 0);

    Repeat(values, saved, 0, 1, M);
}