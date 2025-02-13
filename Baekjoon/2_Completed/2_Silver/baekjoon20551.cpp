// 실버 4 - 20551번 : Sort 마스터 배지훈의 후계자
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

    // 원소 개수 N, 질문 개수 M
    int N, M;
    cin >> N >> M;

    // 배열 정보 입력
    vector<int> arr(N);
    for(int& each : arr){ cin >> each; }
    sort(arr.begin(), arr.end());

    // 질문 개수만큼 반복
    for(int i = 0; i < M; i++)
    {
        int question;
        cin >> question;

        int start = 0, end = N - 1;
        int mid;
        int result = -1;

        while(start + 1 < end)
        {
            mid = (start + end) / 2;

            if(arr[mid] >= question){ end = mid; }
            else{ start = mid; }
        }
        
        // 존재하는지 확인
        if(arr[start] == question) { result = start; }
        else if(arr[end] == question) { result = end;}

        cout << result << "\n";
    }

}