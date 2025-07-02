// 브론즈 2 - 29614번 : 학점계산프로그램
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <string>

using namespace std;

double changeToScore(const char& each)
{
    if(each == 'F')
        return 0.0;

    int num = 'A' - each + 4;
    return static_cast<double>(num);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;
    
    double sum = 0.0;
    int count = 0;
    for(const char& each : input)
    {
        if(each == '+')
        {
            sum += 0.5;
        }
        else
        {
            sum += changeToScore(each);
            count++;
        }
    }

    cout << sum / (double)count << "\n";
}