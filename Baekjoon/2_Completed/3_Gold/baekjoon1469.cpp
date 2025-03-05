// 골드 5 - 1469번 : 숌 사이 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> g_nums;
vector<int> g_seqs;

bool isCompleted()
{
    int count = 0;
    // 각 숫자 사용 개수 확인
    vector<int> counts(17, 0);
    for (auto it = g_seqs.begin(); it != g_seqs.end(); ++it)
    {
        // -1 은 무시
        if (*it == -1) continue;
        counts[*it]++;
        // 2개 사용한 개수 확인
        if (counts[*it] == 2) count++;
    }
    return count == g_nums.size();
}

int search(const int in_idx)
{
    // 끝까지 검사했을 때, 목표 달성했는지 확인
    if (in_idx == g_seqs.size())
    {
        return isCompleted();
    }
    // 현재 인덱스 사용 중
    if (g_seqs[in_idx] != -1)
    {
        // 다음 인덱스로 넘기기
        return search(in_idx + 1);
    }

    int result = 0;
    for (vector<int>::iterator it = g_nums.begin(); it != g_nums.end(); ++it)
    {
        const int num = (*it);
        // 이미 사용한 숫자는 무시
        if (num == -1) continue;

        // 다음에 넣을 위치가 존재하고 대입하는게 가능한지 확인
        int next_idx = in_idx + num + 1;
        if (next_idx < g_seqs.size() == false) continue;
        if (g_seqs[next_idx] != -1) continue;

        // 넣을 공간이 있으면, 추가
        *it = -1;
        g_seqs[in_idx] = num;
        g_seqs[next_idx] = num;

        result = search(in_idx + 1);
        // 목표 달성했으면, 끊어야 함.
        if (result == 1) break;

        // 원래대로 초기화
        g_seqs[in_idx] = -1;
        g_seqs[next_idx] = -1;
        *it = num;
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 N
    int N;
    cin >> N;

    // 수 입력
    g_nums = vector<int>(N);
    for (int& num : g_nums)
    {
        cin >> num;
    }

    // 사전 순으로 빠른 것 출력이므로 오름차순
    sort(g_nums.begin(), g_nums.end());

    // N <= 8
    g_seqs = vector<int>(N * 2, -1);

    int result = search(0);

    // 결과 존재 시, 모두 출력
    if (result == 1)
    {
        for (auto it = g_seqs.begin(); it != g_seqs.end(); ++it)
        {
            cout << *it << " ";
        }
    }
    // 결과 존재하지 않음
    else
    {
        cout << "-1";
    }
    cout << "\n";
}