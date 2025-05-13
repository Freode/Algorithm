// 골드 5 - 3020번 : 개똥벌레
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 석순과 종유석 구별
// 오름차순 후, 현재 높이보다 바로 한 칸 큰 것까지 찾아야 함. upper bound로 찾기

// N : 2~200'000
// H : 2~500'000

vector<int> g_up;
vector<int> g_down;

void inputData(const int N)
{
    g_up.reserve(N);
    g_down.reserve(N);

    int input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        if(i % 2 == 0)
            g_down.push_back(input);
        else
            g_up.push_back(input);
    }

    // 오름차순 정렬
    sort(g_up.begin(), g_up.end());
    sort(g_down.begin(), g_down.end());
}

// upper_bound 찾기
int find(const vector<int>& vec, const int cur)
{
    int left = 0, right = vec.size();
    int mid;

    if(cur < vec[0]) return 0;
    if(cur > vec.back()) return right;

    while(left + 1 < right)
    {
        mid = (left + right) >> 1;

        if(vec[mid] <= cur)
            left = mid;
        else
            right = mid;
    }

    return right;
}

void simulate(const int N, const int H)
{
    int result = numeric_limits<int>::max();
    int count = 0;

    for(int cur = 0; cur < H; cur++)
    {
        int down = g_down.size() - find(g_down, cur);
        int up = g_up.size() - find(g_up, H - 1 - cur);

        int total = down + up;
        // 새로운 최솟값 발견
        if(result > total)
        {
            result = total;
            count = 1;
        }
        // 현재 최솟값과 동일
        else if(result == total)
            count++;
    }

    cout << result << " " << count << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 장애물 개수 N, 높이 H
    int N, H;
    cin >> N >> H;

    inputData(N);
    simulate(N, H);
}