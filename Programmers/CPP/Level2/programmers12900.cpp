// Lv.2 - 12900번 : 2 x n 타일링
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    // f(1) = 1
    // f(2) = 2
    // f(3) = 3
    // f(4) = 5
    // f(n) = f(n-1) + f(n-2)
    // f(n-1)에서 세로로 1개만 추가하는 경우
    // f(n-2)에서 가로 2개짜리를 추가하는 경우

    vector<int> cases(1, 0);

    for(int i = 1; i < n; i++)
    {
        if(i == 1)
        { 
            cases.push_back(1); 
        }
        else if(i == 2)
        { 
            cases.push_back(2); 
        }
        else
        {
            cases.push_back((cases[i-1] + cases[i-2]) % 1000000007 );
        }
    }

    answer = cases[n];

    return answer;
}
