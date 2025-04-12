// 골드 2 - 1513번 : 경로 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N*M (각 1~50)
// 세준이네 집 위치 1,1 -> 학원 N,M

// 오락실 개수 C -> (0~50)
// 오락실 위치 중복 x
// 오락실 번호는 증가하는 순서대로만 갈 수 있음.
// 2번 오락실 : x -> 2번 or x -> 1번 -> 2번

// 이동 : 아래와 오른쪽만 가능
// 오락실 0개 방문부터 C번 방문까지 모두 출력
// 경우의 수는 1'000'007을 나머지 연산해서 출력

// N*M = 2'500
// 오락실 개수 : *50 = 125'000
// 오락실 방문 개수 : *50 = 6'250'000 -> 24MB

// 오락실 번호(50) * 방문 횟수(50)
// 오락실에 방문하면, 해당 오락실 번호의 방문 횟수 + 1해서 옮기기
// 같은 방문 횟수와 오락실 번호끼리 더하기
// 마지막에 방문 횟수끼리 묶어서 출력

const int DIV = 1'000'007;

struct Area
{
    int idx = 0;
    vector<vector<int>> vec;
    
    Area()
    {
        vec = vector<vector<int>>(51, vector<int>(51, 0));
    }
};

vector<vector<Area>> g_areas;

// 오락실 위치 입력
void inputInfo(const int N, const int M, const int C)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(M));

    int y, x;
    for(int i = 1; i <= C; i++)
    {
        cin >> y >> x;
        g_areas[y-1][x-1].idx = i;
    }
}

// 시뮬레이션
void simulate(const int N, const int M, const int C)
{
    // 첫 위치 설정
    int idx = g_areas[0][0].idx;
    int tmp = (int)(idx > 0);
    g_areas[0][0].vec[idx][tmp] = 1;

    // y
    for(int y = 0; y < N; y++)
    {
        // x
        for(int x = 0; x < M; x++)
        {
            idx = g_areas[y][x].idx;

            // 오락실 번호
            for(int num = 0; num <= C; num++)
            {
                // 오락실 방문 횟수
                for(int cnt = 0; cnt <= C; cnt++)
                {
                    // 오락실이 없는 경우
                    if(idx == 0)
                    {
                        // 위쪽에서 가져오기 가능
                        if(y != 0)
                            g_areas[y][x].vec[num][cnt] += g_areas[y-1][x].vec[num][cnt];

                        // 왼쪽에서 가져오기 가능
                        if(x != 0)
                            g_areas[y][x].vec[num][cnt] += g_areas[y][x-1].vec[num][cnt];

                        g_areas[y][x].vec[num][cnt] %= DIV;
                    }
                    
                    // 오락실이 있는 경우
                    // 오락실 번호가 더 작은 경우에만 지나갈 수 있음
                    // 마지막은 제외
                    else if(idx != 0 && cnt != C && num < idx)
                    {
                        // 해당 오락실 번호로 모두 이동
                        // 위쪽에서 가져오기 가능
                        if(y != 0)
                            g_areas[y][x].vec[idx][cnt+1] += g_areas[y-1][x].vec[num][cnt];

                        // 왼쪽에서 가져오기 가능
                        if(x != 0)
                            g_areas[y][x].vec[idx][cnt+1] += g_areas[y][x-1].vec[num][cnt];

                        g_areas[y][x].vec[idx][cnt+1] %= DIV;
                    }
                }
            }
        }
    }
}

// 결과 출력
void printResult(const int N, const int M, const int C)
{
    vector<int> results(C+1, 0);
    for(int cnt = 0; cnt <= C; cnt++)
    {
        for(int num = 0; num <= C; num++)
        {
            results[cnt] += g_areas[N-1][M-1].vec[num][cnt];
            results[cnt] %= DIV; 
        }
    }

    for(const int& result : results)
        cout << result << " ";
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M, 오락실 개수 C
    int N, M, C;
    cin >> N >> M >> C;

    inputInfo(N, M, C);
    simulate(N, M, C);
    printResult(N, M, C);
}