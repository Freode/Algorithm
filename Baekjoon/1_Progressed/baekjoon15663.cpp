// 실버 2 - 15663번 : N과 M (9)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 중복 제거

// 재귀랑 백트래킹으로 해결
// 해당 수가 이전 계층의 수보다 크거나 같을 때, 해당 값을 순서 vector에 저장
// 다시 Repeat 함수를 호출
// 해당 함수 반환 시, 해당 값 방문을 초기화

// 현재 계층이 최대치에 도달한 경우, 저장된 순서 vector의 값을 출력

// 반복
void Repeat(vector<int> &values, vector<int> &saved, vector<bool> &bIsVisited, int currentHiearchy, int maxHiearchy)
{
	// 반복문.
	for (int i = 0; i < values.size(); i++)
	{
        // 이전 계층에서는 해당 값을 방문하지 않았을 때
        if(!bIsVisited[i])
        {
            // 방문 설정과 값 저장
            bIsVisited[i] = true;
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
                Repeat(values, saved, bIsVisited, currentHiearchy + 1, maxHiearchy);
            }

            // 방문 설정 해제
            bIsVisited[i] = false;
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

    // 중복 제거
    set<int> newValues(values.begin(), values.end());

    // 다시 벡터로 이동
    values.clear();
    values.assign(newValues.begin(), newValues.end());

    // 값 저장과 방문 여부
    vector<int> saved(values.size(), 0);
    vector<bool> bIsVisited(values.size(), false);

    Repeat(values, saved, bIsVisited, 1, M);
}