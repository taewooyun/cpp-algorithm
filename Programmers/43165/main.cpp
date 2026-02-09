// 프로그래머스 [43165] - [타겟 넘버]
// https://school.programmers.co.kr/learn/courses/30/lessons/43165
// 주어진 정수들을 더하거나 빼서 타겟 넘버를 만들 수 있는 경우의 수를 구하는 문제
// 시간복잡도: O(2ⁿ)

#include <iostream>
#include <vector>

using namespace std;

// 핵심 아이디어
// - 핵심 로직: 더하는 경우와 빼는 경우를 모두 탐색하고 타겟 넘버에 해당하면 카운트
int answer = 0;
vector<int> numbers;
int target;

// dfs 구현
void dfs(int idx, int sum) {
    if (idx == numbers.size()) {
        if (sum == target) {
            ++answer;
        }
        return;
    }
    // 더하는 경우와 빼는 경우 모두 탐색
    dfs(idx + 1, sum + numbers[idx]);
    dfs(idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    ::numbers = numbers;
    ::target = target;
    
    dfs(0, 0);

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({ 4, 1, 2, 1 }, 4);

    // 결과 출력
    cout << answer << endl;

    return 0;
}