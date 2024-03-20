// 실버 2 - 2630번 : 색종이 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 구역 정보
struct AreaInfo
{
    int is_blue = 0;
    int connect_value = 1;
    bool b_is_checked = false;
};

// 맵 입력
void InputMap(vector<vector<AreaInfo>> &area, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> area[i][j].is_blue;
        }
    }
}

// 모든 공간이 같은 색깔인지 확인
bool IsEntireSameColor(vector<vector<AreaInfo>> &area, int N)
{
    bool is_blue = area[0][0].is_blue;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 다른게 하나라도 있으면 거짓 반환
            if(is_blue != area[i][j].is_blue)
            {
                return false;
            }
        }
    }

    return true;
}

void CheckMap(vector<vector<AreaInfo>> &area, int N, int square)
{
    int max_check = 0;
    int interp = 0;
    int add = 0;
    // 현재 2의 몇 제곱하는지
    for(int cur_square = 2; cur_square <= square; cur_square++)
    {
        // 현재 간격 ex) 2제곱이면 -> 2칸씩 이동
        interp = (int)pow(2, cur_square - 1);
        // 검사할 횟수 ex) 2제곱이면 -> 4번 검사
        max_check = N / interp;
        // 검사하는 위치와 그 주변 검사 위치 ex) 2제곱이면 -> +1
        add = interp / 2;

        for(int i = 0; i < max_check; i++)
        {
            for(int j = 0; j < max_check; j++)
            {
                // 4점이 모두 같은 연결값을 가지고 같은 색깔일 때, 1단계 상승
                // 
                if( 
                area[interp * i][interp * j].is_blue == area[interp * i][interp * j + add].is_blue &&
                area[interp * i][interp * j].is_blue == area[interp * i+ add][interp * j].is_blue &&
                area[interp * i][interp * j].is_blue == area[interp * i+ add][interp * j + add].is_blue &&
                area[interp * i][interp * j].connect_value == area[interp * i][interp * j +add].connect_value &&
                area[interp * i][interp * j].connect_value == area[interp * i+ add][interp * j].connect_value &&
                area[interp * i][interp * j].connect_value == area[interp * i+ add][interp * j + add].connect_value)
                {
                    // 나머지 점은 방문했다고 설정
                    area[interp * i][interp *j+add].b_is_checked = true;
                    area[interp *i+add][interp *j].b_is_checked = true;
                    area[interp *i+add][interp *j+add].b_is_checked = true;

                    // 모든 점 1단계 상승
                    area[interp *i][interp *j].connect_value++;
                    area[interp *i][interp *j+add].connect_value++;
                    area[interp *i+add][interp *j].connect_value++;
                    area[interp *i+add][interp *j+add].connect_value++;
                }
            }
        }
    }
}

// 파란색, 흰색 구역 각각 출력
void PrintResult(vector<vector<AreaInfo>> &area, int N)
{
    int white = 0;
    int blue = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 방문하지 않은 경우에만 카운트 증가
            if(area[i][j].b_is_checked == false)
            {
                if(area[i][j].is_blue) { blue++; }
                else { white++; }
            }
        }
    }
    // 출력
    cout << white << "\n" << blue << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int N;
    cin >> N;

    // 2의 몇 제곱인지 찾기
    int square = 0;
    for(int i = 1; i < 8; i++)
    {
        if((int)pow(2, i) == N)
        {
            square = i;
            break;
        }
    }

    // 구역 입력
    vector<vector<AreaInfo>> area(N, vector<AreaInfo>(N));
    InputMap(area, N);

    // 구역 분할이 필요한지 확인
    if(IsEntireSameColor(area, N))
    {
        // 파란색
        if(area[0][0].is_blue){ cout << "0\n1\n"; }
        // 흰색
        else { cout << "1\n0\n"; }
    }
    else
    {
            // 구역 확인
        CheckMap(area, N, square);

        // 구역 출력
        PrintResult(area, N);
    }
}