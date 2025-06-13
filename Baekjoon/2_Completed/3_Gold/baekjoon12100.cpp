// 골드 1 - 12100번 : 2048(Easy)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 4방향 밀기 -> 최대 5번
// [5][5][5][5][5][20][20] -> 400 * 2^10

// 완전 탐색
// 

using v1i = vector<int>;
using v2i = vector<vector<int>>;

int simulate(const int N, const v2i& area, const int count);

void inputData(const int N, v2i& areas)
{
    areas = v2i(N, v1i(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> areas[i][j];
        }
    }
}

// 해당 구역에서 가장 큰 값 찾기
int findMaxValue(const int N, const v2i& area)
{
    int result = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            result = max(result, area[i][j]);
        }
    }

    return result;
}

// 왼쪽으로 밀기
int left(const int N, const v2i& area, const int count)
{
    v2i next_area = v2i(N, v1i(N, 0));
    int result = 0;

    for(int y = 0; y < N; y++)
    {
        int prev = 0;
        int use = 0;

        // 기존 한 행의 숫자를 모두 확인
        for(int x = 0; x < N; x++)
        {
            // 0인 경우에는 무시
            if(area[y][x] == 0)
            {
                continue;
            }
            // 누적된 수가 서로 일치하는 경우
            else if(prev != 0 && prev == area[y][x])
            {
                prev = 0;
                next_area[y][use-1] = (next_area[y][use-1] << 1);
            }
            // 누적된 수가 없거나, 누적된 수가 있지만 서로 다른 경우
            else
            {
                prev = area[y][x];
                next_area[y][use] = prev;
                use++;
            }
        }
    }

    // 다음 시뮬레이션 진행
    result = max(result, simulate(N, next_area, count + 1));
    return result;
}

// 오른쪽으로 밀기
int right(const int N, const v2i& area, const int count)
{
    v2i next_area = v2i(N, v1i(N, 0));
    int result = 0;

    for(int y = 0; y < N; y++)
    {
        int prev = 0;
        int use = N-1;

        // 기존 한 행의 숫자를 모두 확인
        for(int x = N-1; x >= 0; x--)
        {
            // 0인 경우에는 무시
            if(area[y][x] == 0)
            {
                continue;
            }
            // 누적된 수가 서로 일치하는 경우
            else if(prev != 0 && prev == area[y][x])
            {
                prev = 0;
                next_area[y][use+1] = (next_area[y][use+1] << 1);
            }
            // 누적된 수가 없거나, 누적된 수가 있지만 서로 다른 경우
            else
            {
                prev = area[y][x];
                next_area[y][use] = prev;
                use--;
            }
        }
    }

    // 다음 시뮬레이션 진행
    result = max(result, simulate(N, next_area, count + 1));
    return result;
}

// 위쪽으로 밀기
int up(const int N, const v2i& area, const int count)
{
    v2i next_area = v2i(N, v1i(N, 0));
    int result = 0;

    for(int x = 0; x < N; x++)
    {
        int prev = 0;
        int use = 0;

        // 기존 한 열의 숫자를 모두 확인
        for(int y = 0; y < N; y++)
        {
            // 0인 경우에는 무시
            if(area[y][x] == 0)
            {
                continue;
            }
            // 누적된 수가 서로 일치하는 경우
            else if(prev != 0 && prev == area[y][x])
            {
                prev = 0;
                next_area[use-1][x] = (next_area[use-1][x] << 1);
            }
            // 누적된 수가 없거나, 누적된 수가 있지만 서로 다른 경우
            else
            {
                prev = area[y][x];
                next_area[use][x] = prev;
                use++;
            }
        }
    }

    // 다음 시뮬레이션 진행
    result = max(result, simulate(N, next_area, count + 1));
    return result;
}

// 아쪽으로 밀기
int down(const int N, const v2i& area, const int count)
{
    v2i next_area = v2i(N, v1i(N, 0));
    int result = 0;

    for(int x = 0; x < N; x++)
    {
        int prev = 0;
        int use = N-1;

        // 기존 한 열의 숫자를 모두 확인
        for(int y = N-1; y >= 0; y--)
        {
            // 0인 경우에는 무시
            if(area[y][x] == 0)
            {
                continue;
            }
            // 누적된 수가 서로 일치하는 경우
            else if(prev != 0 && prev == area[y][x])
            {
                prev = 0;
                next_area[use+1][x] = (next_area[use+1][x] << 1);
            }
            // 누적된 수가 없거나, 누적된 수가 있지만 서로 다른 경우
            else
            {
                prev = area[y][x];
                next_area[use][x] = prev;
                use--;
            }
        }
    }

    // 다음 시뮬레이션 진행
    result = max(result, simulate(N, next_area, count + 1));
    return result;
}

int simulate(const int N, const v2i& area, const int count)
{
    // 5번 모두 진행한 경우, 가장 큰 값 찾기
    if(count == 5)
        return findMaxValue(N, area);

    int result = 0;
    // 4방향으로 모두 밀어보기
    result = max(result, left(N, area, count));
    result = max(result, right(N, area, count));
    result = max(result, up(N, area, count));
    result = max(result, down(N, area, count));

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 보도 크기 N
    int N;
    cin >> N;

    vector<vector<int>> area;
    inputData(N, area);
    cout << simulate(N, area, 0) << "\n";
}