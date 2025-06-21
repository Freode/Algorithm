// 실버 4 - 18110번 : solved.ac
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> g_nums;

void inputData(const int n)
{
    g_nums = vector<int>(n);

    for(int& num : g_nums)
        cin >> num;

    sort(g_nums.begin(), g_nums.end());
}

int simulate(const int n)
{
    if(n == 0)
        return 0;

    double dcut = n * 0.15;
    int icut = (int)round(dcut);

    double sum = 0;
    for(int i = icut; i < n - icut; i++)
        sum += g_nums[i];

    sum /= (n - 2 * icut);
    return (int)round(sum);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 난이도 의견 수 n
    int n;
    cin >> n;

    inputData(n);
    cout << simulate(n) << "\n";
}