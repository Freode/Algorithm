// 실버 2 - 2108번 : 통계학
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

double g_sum = 0.0;
vector<int> g_vec;
unordered_map<int, int> g_umap;

// 데이터 크기 초기화
void initData(const int N)
{
    g_vec.reserve(N);
    g_umap.reserve(N);

}

// 데이터 입력에 따른 처리
void inputData(const int N)
{
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;

        g_sum += static_cast<double>(num);
        g_vec.push_back(num);
        g_umap[num]++;
    }
}

void simulateAndPrintResult(const int N)
{
    // 1. 산술 평균
    int ave = static_cast<int>(round(g_sum / N));
    cout << ave << "\n";

    // 2. 중앙값
    sort(g_vec.begin(), g_vec.end());
    cout << g_vec[N >> 1] << "\n";

    // 3. 최빈값
    vector<int> nums;
    nums.reserve(N);
    int count = 0;

    for(auto& each : g_umap)
    {
        if(count < each.second)
        {
            nums.clear();
            count = each.second;
            nums.push_back(each.first);
        }
        else if(count == each.second)
        {
            nums.push_back(each.first);
        }
    }

    if(nums.size() != 1)
    {
        sort(nums.begin(), nums.end());
        cout << nums[1] << "\n";
    }
    else
    {
        cout << nums[0] << "\n";
    }

    // 4. 범위
    cout << g_vec[N-1] - g_vec[0] << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 정수 개수 N
    int N;
    cin >> N;

    initData(N);
    inputData(N);
    simulateAndPrintResult(N);
}