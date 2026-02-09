// 프로그래머스 [12906] - [같은 숫자는 싫어]
// https://school.programmers.co.kr/learn/courses/30/lessons/12906
// 연속되는 숫자를 제거하는 문제
// 시간복잡도: O(N)

#include <iostream>
#include <vector>

using namespace std;

// 핵심 아이디어
// - 단순 구현 문제
vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    //첫 번째 원소 삽입
    answer.push_back(arr[0]);

    //마지막으로 거쳐간 숫자와 동일한지 비교해서 새로운 숫자면 삽입
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i-1]) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({ 1, 1, 3, 3, 0, 1, 1 });

    // 결과 출력
    for (int it : answer) cout << it << " ";
    cout << endl;

    return 0;
}