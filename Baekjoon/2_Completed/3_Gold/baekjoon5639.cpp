// 골드 4 - 5639번 : 이진 검색 트리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 전위 순회 결과 입력
// 50 30 24 5 28 45 98 52 60

// 50 기준 -> 탐색 범위 idx = 1 ~ N-1
// 왼쪽 노드 : 30 24 5 28 45
// 오른쪽 노드 : 98 52 60

// 새로운 왼쪽 기준 : 현재 기준 idx + 1 
// 새로운 오른쪽 기준 : 나눠진 기준 idx

// 30 기준 -> 탐색 범위 idx = 2 ~ 값이 98인 idx -1
// 왼쪽 노드 : 24 5 28
// 오른쪽 노드 : 45

// 98 기준 -> 탐색 범위 idx = 현재+1 ~ N-1
// 왼쪽 노드 : 52 60
// 오른쪽 노드 : x 

vector<int> g_nodes(10001, 0);

// 수 입력
int inputNode()
{
    int num = 0, idx = 0;
    while(cin >> num && num != 0)
    {
        g_nodes[idx] = num;
        idx++;
    }
    return idx-1;
}

// 후위 순회 출력
void postSearch(const int start, const int end)
{
    // 존재하지 않는 경우는 제외
    if(start > end) return;
    
    int base = g_nodes[start];
    int cut_idx = start + 1;
    // 나눠지는 지점 찾기 - 현재 기준보다 값이 큰 경우
    for(int i = start + 1; i <= end; i++)
    {
        if(base < g_nodes[i]) 
        {
            cut_idx = i;
            break;
        }
    }

    // 1.왼쪽 노드가 존재할 경우
    postSearch(start + 1, cut_idx - 1);
    // 2.오른쪽 노드가 존재할 경우
    postSearch(cut_idx, end);
    // 3.본인 출력
    cout << base << endl;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 전위 순회 입력
    int length = inputNode();
    // 후위 순회 출력
    postSearch(0, length);
}