// 골드 5 - 32347번 : 시간을 돌리고 싶어
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 종강한지 N일차
// 타임머신 최대 K번 사용 가능
// T일 전으로 돌아감 (대신, T일 전이 1일 전이라면, 1일로 이동 -> 최솟값 1일)

// i일에 타임머신 사용 가능 조건 -> i일에 타임머신에 전원 공급
// 타임머신으로 과거로 가서, 과거에서 시간 보내기도 가능

// T를 최소화하며, 1일로 돌아갈 수 있는지 계산 -> T 최솟값

// == 입력 ==
// 현재 일 N, 최대 사용 횟수 K (2~200'000)
// 타임머신 전원 : 1, x : 0

// 이분 탐색
// 1~20만 사이에서 검색
// 불가능하면, start를 mid로
// 가능하면, end를 mid로 옮겨서 검사

const int MAX_VALUE = 200'001;

vector<int> g_dates;
vector<bool> g_visited;

// 정보 입력
void inputData(const int N)
{
    g_dates = vector<int>(N, 0);
    g_visited = vector<bool>(N, false);

    for(int i = 0; i < N; i++)
    {
        cin >> g_dates[i];
    }
}

void resetData(const int N)
{
    for(int i = 0; i < N; i++)
    {
        g_visited[i] = false;
    }
}

// 타임머신 시뮬레이션 시작
bool search(const int N, const int K)
{
    resetData(N);

    int date = N-1;
    g_visited[N-1] = true;

    
}

int simulate(const int N, const int K)
{
    int result = MAX_VALUE;

    int start = 1;
    int end = N;
    int mid;

    while(start < end)
    {
        mid = (start + end) / 2;

        if(search(mid))
        {
            result = min(result, mid);
            start = mid;
        }
        else
            end = mid;
        
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
    cout.tie(nullptr);

    // 현재 일 N, 최대 사용 횟수 K
    int N, K;
    cin >> N >> K;

}