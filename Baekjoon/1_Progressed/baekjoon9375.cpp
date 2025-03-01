// 실버 3 - 9375번 : 패션왕 신해빈
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 종류에 따른 옷의 수
struct Clothes
{
    string kind;
    int count;
};

// 옷 경우 계산
void CalculateCloth(vector<Clothes> &kind_vec, int remain, int temp, int int& result)
{
    // 아직 종류 계산이 가능
    if(remain != 1)
    {
        
    }
    // 마지막꺼까지 계산 완료
    else
    {

    }
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 입력
    int T;
    cin >> T;

    int n;
    vector<Clothes> kind_vec;
    string name, kind;
    bool b_is_same;
    int result;
    for(int i = 0; i < T; i++)
    {
        cin >> n;

        kind_vec.clear();
        for(int j = 0; j < n; j++)
        {
            cin >> name >> kind;

            b_is_same = false;
            for(int k = 0; k < (int)kind_vec.size(); k++)
            {
                // 수량 증가
                if(kind_vec[k].kind == kind)
                {
                    b_is_same = true;
                    kind_vec[k].count++;
                    break;
                }
            }
            // 같은 종류가 없는 경우는 새롭게 추가
            if(b_is_same == false)
            {
                Clothes new_cloth;
                new_cloth.count = 1;
                new_cloth.kind = kind;
                kind_vec.push_back(new_cloth);
            }
        }

        // 결과 계산하기
        result = 0;
        for(int j = 0; j < (int)kind_vec.size(); j++)
        {
            
        }   
    }
}