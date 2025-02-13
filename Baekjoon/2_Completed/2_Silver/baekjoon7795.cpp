// 실버 3 - 7795번 : 먹을 것인가 먹힐 것인가
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InputGroup(vector<int> &inGroupA, vector<int> &inGroupB);
int FindPair(const vector<int>& inGroupA, const vector<int> &inGroupB);


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        // 크기 입력
        int N, M;
        cin >> N >> M;

        vector<int> groupA(N);
        vector<int> groupB(M);

        // 그룹 입력
        InputGroup(groupA, groupB);

        // 쌍 개수 찾기
        int result = FindPair(groupA, groupB);
        cout << result << "\n";

        // 벡터 그룹 초기화
        groupA.clear();
        groupB.clear();
    }
}

// 그룹 입력 
void InputGroup(vector<int> &inGroupA, vector<int> &inGroupB)
{
    for(int& each : inGroupA)
    {
        cin >> each;
    }
    for(int& each : inGroupB)
    {
        cin >> each;
    }

    // 오름차순 정렬
    sort(inGroupB.begin(), inGroupB.end());
}

// 쌍 개수 찾기
int FindPair(const vector<int>& inGroupA, const vector<int> &inGroupB)
{
    int result = 0;

    for(const int& eachGroupA : inGroupA)
    {
        int left = 0;
        int right = inGroupB.size() - 1;
        int mid;

        // 쌍의 개수가 없음
        if(inGroupB[left] >= eachGroupA)
        {
            continue;
        }  
        // 모든 쌍 가능
        else if(inGroupB[right] < eachGroupA)
        {
            result += inGroupB.size();
            continue;
        }

        while(left + 1 < right)
        {
            mid = (left + right) / 2;
            
            // 현재 group a의 수보다 낮은 수 위치까지 찾기
            if(inGroupB[mid] >= eachGroupA)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        result += right;
    }

    return result;
}