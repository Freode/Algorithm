// 골드 5 - 1660번 : 캡틴 이다솜
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // N개 대포알
    int N;
    cin >> N;

    vector<int> tastrahedrons;
    tastrahedrons.push_back(1);

    int triangle = 1;
    int seq = 2;
    int new_tastrahedron = 1;
    bool b_continue = true;
    // 사면체 개수 정보 미리 입력
    while(b_continue)
    {
        // 사면체 만드는 방법 = 새롭게 넓어진 삼각형 + 바로 직전 사면체
        triangle += seq;
        new_tastrahedron = triangle + tastrahedrons[tastrahedrons.size()-1];
        seq++;

        if(new_tastrahedron <= 300000)
        {
            tastrahedrons.push_back(new_tastrahedron);
        }
        else
        {
            b_continue = false;
        }
    }

    // 사면체 개수 제작
    int result = 300000;
    // 사면체 가능 경우를 하나씩 줄이기
    for(int j = tastrahedrons.size()-1; j >= 0; j--)
    {
        int count = 0;
        int bullets = N;
        // 가능한 사면체별로 순환
        for(int i = j; i >= 0; i--)
        {
            int each_count = bullets / tastrahedrons[i];

            count += each_count;
            bullets -= each_count * tastrahedrons[i];
        }
        // 사면체를 제작할 수 있을 때, 최솟값 구하기
        if(count != 0) result = min(result, count);
    }   

    cout << result << "\n";
}