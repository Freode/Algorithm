// 실버 1 - 24092번 : 알고리즘 수업 - 퀵 정렬 3
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& A, int p, int r, int& same, vector<int>& result);

// 결과가 같은지 출력
void CompareVector(vector<int>& A, vector<int>& result, int& same, int n, int m)
{
    if(same == 0)
    {
        // 바꾼 두 위치가 일치하는 경우에만 전체 검사
        if(A[n] == result[n] && A[m] == result[m])
        {
            for(int i = 0; i < (int)A.size(); i++)
            {
                //cout << A[i] << " ";
                if(result[i] != A[i]){ same = 0; break; }
                same = 1;
            }
            //cout << "\n";
        }
    }
}

// 퀵 정렬 - 정복
void quick_sort(vector<int>& A, int p, int r, int& same, vector<int>& result)
{
    if(p < r)
    {
        // 분할
        int q = partition(A, p, r, same, result);
        // 왼쪽 부분 배열 정렬
        quick_sort(A, p, q - 1, same, result);
        // 오른쪽 부분 배열 정렬
        quick_sort(A, q + 1, r, same, result);
    }
}

// 퀵 정렬 - 분할
int partition(vector<int>& A, int p, int r, int& same, vector<int>& result)
{
    int temp;

    // 기준 원소 (현재 집합에서 가장 뒤에 있는 원소값)
    int x = A[r];
    // i는 x보다 작거나 작은 원소들의 끝지점
    int i = p - 1;
    // j는 아직 정해지지 않은 원소들의 시작 지점
    for(int j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp; 
            CompareVector(A, result, same, i, j);
        }
    }
    // p와 r이 다르다면 : 시작점 위치와 끝점 위치가 다른 경우
    if(i + 1 != r)
    {
        temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        CompareVector(A, result, same, i+1, r);
    }

    return i + 1;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;
    
    vector<int> inputs(N, 0);
    vector<int> result(N, 0);
    
    for(int& each : inputs) { cin >> each; }
    for(int& each : result) { cin >> each; }

    int same = 0;

    // 퀵 정렬
    quick_sort(inputs, 0, N - 1, same, result);

    // 출력
    cout << same << "\n";
}