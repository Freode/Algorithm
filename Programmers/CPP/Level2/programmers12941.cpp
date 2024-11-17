// Lv.2 - 12941번 : 최솟값 만들기
// 작성자 : jeonghoe22(최정호)

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    // 가장 큰 수와 가장 작은 수끼리 곱하는 것이 최솟값을 만들 수 있음.
    
    // 오름차순
    sort(A.begin(), A.end());

    // 내림차순
    sort(B.begin(), B.end(), greater<int>());

    // 곱해서 누적합 최솟값 구하기
    for(int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}