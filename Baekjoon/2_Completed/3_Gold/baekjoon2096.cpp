// 골드 5 - 2096번 : 내려가기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = 0;
const int MAX = 1;

const int LEFT = 0;
const int MID = 1;
const int RIGHT = 2;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> input(3, 0);
    vector<vector<int>> result(2, vector<int>(3, 0));
    vector<vector<int>> temp(2, vector<int>(3, 0));

    // 첫 줄 입력
    cin >> result[MIN][LEFT] >> result[MIN][MID] >> result[MIN][RIGHT];
    result[MAX][LEFT] = result[MIN][LEFT];
    result[MAX][MID] = result[MIN][MID];
    result[MAX][RIGHT] = result[MIN][RIGHT];

    // 한 줄씩 입력
    for(int i = 1; i < N; i++)
    {
        cin >> input[LEFT] >> input[MID] >> input[RIGHT];
        
        // 깊은 복사
        temp = result;

        // 왼쪽
        result[MIN][LEFT] = min(temp[MIN][LEFT] + input[LEFT], temp[MIN][MID] + input[LEFT]);
        result[MAX][LEFT] = max(temp[MAX][LEFT] + input[LEFT], temp[MAX][MID] + input[LEFT]);

        // 중앙
        result[MIN][MID] = min(min(temp[MIN][LEFT] + input[MID], temp[MIN][MID] + input[MID]), temp[MIN][RIGHT] + input[MID]);
        result[MAX][MID] = max(max(temp[MAX][LEFT] + input[MID], temp[MAX][MID] + input[MID]), temp[MAX][RIGHT] + input[MID]);

        // 오른쪽
        result[MIN][RIGHT] = min(temp[MIN][MID] + input[RIGHT], temp[MIN][RIGHT] + input[RIGHT]);
        result[MAX][RIGHT] = max(temp[MAX][MID] + input[RIGHT], temp[MAX][RIGHT] + input[RIGHT]);
    }

    // 최소 최대 찾기
    int min_result = min(min(result[MIN][LEFT], result[MIN][MID]), result[MIN][RIGHT]);
    int max_result = max(max(result[MAX][LEFT], result[MAX][MID]), result[MAX][RIGHT]);

    // 결과
    cout << max_result << " " << min_result << "\n";
}