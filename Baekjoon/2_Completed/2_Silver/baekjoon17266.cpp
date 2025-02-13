// 실버 4 - 17266번 : 어두운 굴다리
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

    // 총 거리
    int N;
    cin >> N;

    // 가로등 개수
    int M;
    cin >> M;

    int last_loc = 0;
    int light_loc;
    vector<int> intervals;
    // 가로등 위치 입력
    for(int i = 0; i < M; i++)
    {
        cin >> light_loc;

        // 시작점은 가로등이 없기에 바로 빼기
        if(i == 0)
        {
            intervals.push_back(light_loc - last_loc);
        }
        else
        {
            // 가로등 사이의 거리여서 양쪽으로 비추기에 / 2
            // 반드시 올림으로 만들기
            intervals.push_back((light_loc - last_loc + 1) / 2);
        }
        last_loc = light_loc;
    }

    // 마지막 추가
    intervals.push_back(N - last_loc);

    // 오름차순
    sort(intervals.begin(), intervals.end());

    // 가장 마지막인 길이 값이 정답
    cout << intervals[intervals.size() - 1] << "\n";
}