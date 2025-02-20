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
        // 30만 개 이상은 필요 없으므로 무시
        else
        {
            b_continue = false;
        }
    }

    // 사면체 개수 제작
    int result = 300000;
    vector<int> cases(N+1);

    // 1개짜리만 사용할 때, 사면체 개수 넣기
    for(int i = 0; i < N+1; i++)
    {
        cases[i] = i;
    }

    // 목표 대포알 개수까지 반복
    for(int i = 1; i < N+1; i++)
    {
        // 사면체 수량만큼 반복
        for(const int& tastrahedron : tastrahedrons)
        {
            // 사면체 개수가 유효 대포알보다 많은 경우도 무시
            if(tastrahedron > i) break;
            // 현재 목표 개수에서 사면체를 사용하는 경우가 더 나은 경우
            // 1개를 추가하는 이유 : 여러 개를 사용할 때는 이미 더 작은 사면체로 갱신됨
            cases[i] = min(cases[i], cases[i-tastrahedron] + 1);
        }
    }

    cout << cases[N] << "\n";
}