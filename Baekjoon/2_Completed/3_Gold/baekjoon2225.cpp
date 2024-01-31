// 골드 5 - 2225번 : 합분해
// 작성자 : free4760 (jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 1부터 시작해서 오름차순으로 k개까지 해당 값을 구성할 수 있는 경우의 수 계산
// k개로 n을 구성하는 경우의 수는 k-1개로 1~n까지 구성하는 경우의 수 총합과 같음
// 그 이유는 k-1개로 1~n까지 구성하는 경우에서 하나의 수만 추가되어 k개로 n을 구성할 수 있기 때문
// f_k(n) = f_{k-1}(1) + f_{k-1}(2) + ... + f_{k-1}(n-1) + f_{k-1}(n)

// f_k(n-1) = f_{k-1}(1) + f_{k-1}(2) + ... + f_{k-1}(n-2) + f_{k-1}(n-1)
// 따라서, f_k(n) = f_k(n-1) + f_{k-1}(n) 으로 사용 가능 

// 예제 2번
//  k  0  1  2  3  4  5  6
//  1  1  1  1  1  1  1  1
//  2  1  2  3  4  5  6  7
//  3  1  3  6 10 15 21 28
//  4  1  4 10 20 35 56 84
int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // 입력
    int N, K;
    cin >> N >> K;

    // 공간 할당
    vector<vector<int>> cases(K + 1, vector<int>(N + 1, 1));

    // 구한 공식을 바탕으로 계산
    // f_k(n) = f_k(n-1) + f_{k-1}(n)
    for(int i = 2; i < K + 1; i++)
    {
        for(int j = 1; j < N + 1; j++)
        {
            cases[i][j] = (cases[i][j - 1] + cases[i - 1][j]) % 1000000000; 
        }
    }

    // 출력
    cout << cases[K][N] << "\n";

}