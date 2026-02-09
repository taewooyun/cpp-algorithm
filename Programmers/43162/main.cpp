// 프로그래머스 [43162] - [네트워크]
// https://school.programmers.co.kr/learn/courses/30/lessons/43162
// 컴퓨터와 각 컴퓨터의 연결에 대한 정보가 주어졌을때 형성된 네트워크의 수를 구하는 문제
// 시간복잡도: O(n²)

#include <iostream>
#include <string>
#include <vector>
    
using namespace std;

// 핵심 아이디어
// - 입력: 각 컴퓨터가 연결된 정보를 담은 2차원 배열 computers
// - 출력: 간선으로 연결된 정점에대한 집합의 수
// - 핵심 로직: 완전 탐색을 수행하고 한번도 방문하지 않은 정점일 때 카운트 = 네트워크의 수

// dfs 구현
void dfs(int idx, const vector<vector<int>>& computers, bool visited[]) {
    visited[idx] = true;

    for (int i = 0; i < computers.size(); ++i) {
        // 연결된 정점을 방문
        if (computers[idx][i] == 1 && !visited[i]) {
            dfs(i, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[200] = {false};

    // 네트워크 탐색 시작
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, computers, visited);
            ++answer;
        }
    }

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});

    // 결과 출력
    cout << answer << endl;

    return 0;
}