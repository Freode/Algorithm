// 골드 4 - 7662번 : 이중 우선순위 큐
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 최대힙을 만들어서 내림차순으로 만들기

void PrintVector(vector<int>& vec)
{
    for(int& each : vec)
    {
        cout << each << " ";
    }
    cout << "\n";
}

// 교환
void Swap(int& a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 최소 힙 만들기
void MakeMinHeap(vector<int>& priority_queue, int last_index)
{
    int index = last_index;

    int parent;
    while(index > 0)
    {
        // 왼쪽 자식일 경우
        if(index % 2 == 1){ parent = (index - 1) / 2; }
        // 오른쪽 자식일 경우
        else { parent = (index - 2) / 2; }

        // 수 교환
        if(priority_queue[index] < priority_queue[parent])
        {
            Swap(priority_queue[index], priority_queue[parent]);
            index = parent;
        }
        else { break; }
    }
    cout << "make max vector : ";
    PrintVector(priority_queue);
}

// 최소 힙 삭제하기
void DeleteMinHeap(vector<int>&priority_queue, int len)
{
    int index = 0;
    int left = 0, right = 0;
    while(index < len)
    {
        left = -1, right = -1;
        // 자식 존재 여부 확인
        if(index * 2 + 1 < len){ left = index * 2 + 1; }
        if(index * 2 + 2 < len){ right = index * 2 + 2; }

        // 양쪽 자식 모두 존재
        if(right != -1)
        {
            // 왼쪽 자식과 교체
            if(priority_queue[left] <= priority_queue[right] && priority_queue[left] < priority_queue[index])
            {
                Swap(priority_queue[left], priority_queue[index]);
                index = left;
            }
            // 오른쪽 자식과 교체
            else if(priority_queue[left] > priority_queue[right] && priority_queue[right] < priority_queue[index])
            {
                Swap(priority_queue[right], priority_queue[index]);
                index = right;
            }
            // 교체 x
            else { break; }
        }
        // 왼쪽 자식만 존재
        else if(left != -1)
        {
            // 왼쪽 자식과 교체
            if(priority_queue[left] < priority_queue[index])
            {
                Swap(priority_queue[left], priority_queue[index]);
                index = left;
            }
        }
        // 자식 존재하지 않음.
        else{ break; }
    }
}

// 내림차순으로 정렬
void Sort(vector<int>& priority_queue)
{
    for(int i = (int)priority_queue.size() - 2; i >= 0; i--)
    {
        Swap(priority_queue[i], priority_queue[0]);
        DeleteMinHeap(priority_queue, i-1);
    }
}

void InsertNum(vector<int>& priority_queue, int num)
{
    // 추가하고 최대힙 만들기
    priority_queue.push_back(num);
    MakeMinHeap(priority_queue, (int)priority_queue.size() - 1);

    // 내림차순 정렬
    Sort(priority_queue);
    cout << "sort : ";
    PrintVector(priority_queue);
}

void DeleteNum(vector<int>& priority_queue, int num)
{

}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int T;
    cin >> T;

    int k, num;
    char oper;
    // 테스트 케이스 반복
    for(int i = 0; i < T; i++)
    {
        // 연산 개수 입력
        cin >> k;

        vector<int> priority_queue;

        // 연산 입력
        for(int j = 0; j < k; j++)
        {
            cin >> oper >> num;
            // 데이터 추가
            if(oper == 'I')
            {
                InsertNum(priority_queue, num);
            }
            // 데이터 삭제
            else
            {
                // 데이터가 존재할 때, 삭제 진행
                if((int)priority_queue.size() > 0)
                {

                }
            }
        }
    }
}
