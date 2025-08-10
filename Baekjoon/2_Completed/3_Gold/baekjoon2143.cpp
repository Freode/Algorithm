// 골드 3 - 2143번 : 두 배열의 합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;

unordered_map<ll, int> g_umap;

vector<int> g_num_a;
vector<int> g_num_b;

// 8 * 2'000'000 = 

// 각 배열마다 모든 구간의 합을 구하기
void searchAllSum(unordered_map<ll, int>& umap, const vector<int>& nums)
{
    for(int start = 0; start < nums.size(); start++)
    {
        ll sum = 0;
        for(int size = 0; start + size < nums.size(); size++)
        {
            int next = start + size;
            sum += (ll)nums[next];
            umap[sum]++;
        }
    }
}

void initAndInputData()
{
    int n;
    cin >> n;
    g_num_a = vector<int>(n);
    for(int& each : g_num_a)
        cin >> each;

    int m;
    cin >> m;
    g_num_b = vector<int>(m);
    for(int& each : g_num_b)
        cin >> each;
}

// 현재 배열에서 가능한 수와 다른 배열에서 가능한 수를 조합할 때, 목표 T의 값을 가지면
// 현재 배열에서 가능한 수의 경우 x 다른 배열에서 가능한 수의 경우를 더하기
ll findResult(const int T)
{
    g_umap.reserve(2'000'000);
    for(int start = 0; start < g_num_a.size(); start++)
    {
        ll sum = 0;
        for(int size = 0; start + size < g_num_a.size(); size++)
        {
            int next = start + size;
            sum += (ll)g_num_a[next];
            g_umap[sum]++;
        }
    }

    ll result = 0;

    for(int start = 0; start < g_num_b.size(); start++)
    {
        ll sum = 0;
        for(int size = 0; start + size < g_num_b.size(); size++)
        {
            int next = start + size;
            sum += (ll)g_num_b[next];
            
            ll diff = T - sum;
            if(g_umap[diff] != 0)
                result += g_umap[diff];
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 목표 값 T
    int T;
    cin >> T;

    initAndInputData();
    cout << findResult(T) << "\n";
}