// 골드 4 - 14500번 : 테트로미노
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SHAPE_CNT = 19;

int shapes[SHAPE_CNT][4][2] = 
{   
    // 일자
    {{0,0}, {1,0}, {2,0}, {3,0}},
    {{0,0}, {0,1}, {0,2}, {0,3}},
    // 사각형
    {{0,0}, {0,1}, {1,0}, {1,1}},
    // L자
    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {0,1}, {0,2}, {1,0}},
    {{0,0}, {0,1}, {1,1}, {2,1}},
    {{0,0}, {1,0}, {1,-1}, {1,-2}},
    {{0,0}, {1,0}, {2,0}, {2,-1}},
    {{0,0}, {1,0}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {0,2}, {1,2}},
    // Z자
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {0,-1}, {1,-1}, {1,-2}},
    {{0,0}, {1,0}, {1,-1}, {2, -1}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    // ㅗ자
    {{0,0}, {0,1}, {0,2}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {1,-1}},
    {{0,0}, {0,1}, {0,2}, {-1,1}},
    {{0,0}, {1,0}, {2,0}, {1,1}}
};

// 해당 도형이 맵 범위 안에 있는지 확인
bool isInBoard(const int loc[4][2], const int y, const int x, const int N, const int M)
{
    for(int i = 0; i < 4; i++)
    {
        int temp_y = y + loc[i][0];
        int temp_x = x + loc[i][1];

        if((temp_y >= 0 && temp_x >= 0 && temp_y < N && temp_x < M) == false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;

    // 맵 입력
    vector<vector<int>> areas(N, vector<int>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> areas[i][j];
        }
    }

    int result = 0;
    // 칸마다 검사
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 도형마다 검사
            for(int shape = 0; shape < SHAPE_CNT; shape++)
            {
                if(isInBoard(shapes[shape], i, j, N, M) == false) continue;

                // 값의 합을 구하기
                int temp = 0;
                for(int loc = 0; loc < 4; loc++)
                {
                    int check_y = i + shapes[shape][loc][0];
                    int check_x = j + shapes[shape][loc][1];
                    temp += areas[check_y][check_x];
                }

                result = max(result, temp);
            }
        }
    }
    // 출력
    cout << result << "\n";
}