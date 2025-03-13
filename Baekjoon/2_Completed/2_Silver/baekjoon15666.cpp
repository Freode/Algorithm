// 실버 2 - 15666번 : N과 M (12)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> g_nums;
vector<int> g_select;

void search(int idx, int M)
{
    // 목표에 도달
    if(idx == M)
    {
        for(const int& each : g_select)
        {
            cout << each << " ";
        }
        cout << "\n";
        return;
    }

    // 아직 목표에 도달하지 않음
    int size = g_nums.size();
    int num = g_select[max(idx-1, 0)];

    // 수 고르기
    for(int i = 0; i < size; i++)
    {
        // 현재 마지막 수보다 크거나 같을 경우에만 선택
        if((num <= g_nums[i]) == false) continue;

        g_select[idx] = g_nums[i];
        search(idx + 1, M);
        // 어차피 덮어씌워서 초기화 할 필요 x
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력 개수 N, 뽑는 수 M
    int N, M;
    cin >> N >> M;

    // 수 입력
    int num;
    set<int> temp_set;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        temp_set.insert(num); 
    }

    // set을 vector로 옮기기
    g_nums = vector<int>(temp_set.begin(), temp_set.end());
    g_select = vector<int>(M, 0);

    search(0, M);
}