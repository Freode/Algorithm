// Lv.3 - 12987번 : 숫자 게임
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 모두 내림차순 정렬
// 이기는 경우 중, 가장 큰 수를 배치
// 지는 경우 중, 가장 낮은 수를 배치

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int a_idx = 0;
    int left = 0;
    int right = B.size() - 1;
    
    while(left <= right)
    {
        if(B[left] > A[a_idx])
        {
            ++answer;
            ++left;
        }
        else
        {
            --right;
        }
        ++a_idx;
    }
    
    return answer;
}