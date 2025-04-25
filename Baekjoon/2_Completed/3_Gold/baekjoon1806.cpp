// 골드 4 - 1806번 : 부분합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 길이 N -> 10~100'000
// 각 수열 요소 -> 10'000 이하 자연수
// 연속된 수들의 부분합 중에 그 합이 S 이상 되는 것 중, 가장 짧은 것의 길이 구하기

// 처음과 끝 투 포인터로 풀기
// 합보다 작으면, 끝 + 1
// 합보다 크면, 시작 + 1
// 끝까지 반복

const int MAX_VALUE = numeric_limits<int>::max();

vector<int> g_seqs;

// 수열 정보 입력
void inputInfo(const int N)
{
    g_seqs = vector<int>(N);

    for(int& each : g_seqs)
        cin >> each;
}

// 수열 중 조건을 만족하는 가장 짧은 길이 구하기
int simulate(const int N, const int S)
{
    int start = 0, end = 0;
    int result = MAX_VALUE;

    int sum = g_seqs[0];
    while(start < N && end < N)
    {
        // 조건이 맞는 경우, 범위를 줄이기
        if(sum >= S && (start <= end))
        {
            result = min(result, (end - start + 1));
            
            sum -= g_seqs[start];
            start++;
        }
        // 조건이 맞지 않는 경우, 범위를 늘리기
        else
        {
            end++;
            sum += g_seqs[end];
        }
    }
    
    if(result == MAX_VALUE)
        result = 0;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수열 길이 N, 합 S
    int N, S;
    cin >> N >> S;

    inputInfo(N);
    cout << simulate(N, S) << "\n";
}