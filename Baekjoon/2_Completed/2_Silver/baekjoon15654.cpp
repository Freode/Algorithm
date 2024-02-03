// 실버 3 - 15654번 : N과 M (5)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 재귀랑 백트래킹으로 해결
// 해당 계층에서 방문하지 않은 값을 찾았을 때,
// 해당 수를 방문했다고 설정하고 값을 순서 vector에 저장
// 다시 Repeat 함수를 호출
// 해당 함수 반환 시, 해당 값 방문을 초기화

// 현재 계층이 최대치에 도달한 경우, 저장된 순서 vector의 값을 출력

// 반복
void Repeat(vector<int> &values, vector<int> &saved, vector<bool> &bIsVisited, int currentHiearchy, int maxHiearchy)
{
	// 반복문.
	for (int i = 0; i < values.size(); i++)
	{
        // 방문하지 않았을 때만, 저장
        if(!bIsVisited[i])
        {
            // 방문 설정과 값 저장
            saved[currentHiearchy - 1] = values[i];
            bIsVisited[i] = true; 

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

            // 방문 해제
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

    // 오름차순 정렬
    sort(values.begin(), values.end());

    // 방문 여부
    vector<bool> bIsVisited(N, false);
    
    // 값 저장
    vector<int> saved(N, 0);

    Repeat(values, saved, bIsVisited, 1, M);
}