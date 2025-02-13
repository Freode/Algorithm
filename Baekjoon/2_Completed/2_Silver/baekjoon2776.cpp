// 실버 4 - 2776번 : 암기왕
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

    // 테스트 케이스 개수
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        // 수첩 1
        int N;
        cin >> N;

        vector<int> noteA(N);
        for(int& each : noteA){ cin >> each; }
        sort(noteA.begin(), noteA.end());

        // 수첩 2
        int M;
        cin >> M;

        vector<int> noteB(M);
        for(int& each : noteB){ cin >> each; }

        // 수첩 2의 수가 수첩 1에 존재하는지 각각 탐색
        for(const int& each : noteB)
        {
            int start = 0;
            int end = N - 1;
            int mid;
            int result = 0;

            while(start + 1 < end)
            {
                mid = (start + end) / 2;
                
                // 범위 조절
                if(noteA[mid] > each){ end = mid; }
                else if(noteA[mid] < each) { start = mid; }
                // 존재하는 경우
                else 
                { 
                    result = 1;
                    break;
                }
            }

            // 마지막 검사 추가
            if(result == 0){ result = (noteA[start] == each || noteA[end] == each); }

            cout << result << "\n";
        }
    }

}