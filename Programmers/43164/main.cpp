// 프로그래머스 [43164] - [여행경로]
// https://school.programmers.co.kr/learn/courses/30/lessons/43164
// 주어진 여행 경로를 모두 방문하는 순서를 구하는 문제
// 시간복잡도: O(N! * N)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 핵심 아이디어
// - 입력: 출발지와 도착지 정보가 포함된 티켓의 정보 tickets
// - 출력: 경유하는 모든 경로를 출력. 단, 항상 ICN에서 출발하며 다른 경로도 있다면 사전순으로 우선인 경로를 출력
// - 핵심 로직: 티켓 정보를 사전순으로 정렬하고 모든 목적지를 경유하는 경로를 출력

// dfs 구현
vector<string> dfs(const vector<vector<string>>& tickets, vector<bool>& visited, vector<string> route) {
    if (route.size() == tickets.size()+1) {
        return route;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        // 현재 도착지와 일치하는 목적지로 깊이 탐색
        if (!visited[i] && tickets[i][0] == route.back()) {
            visited[i] = true;
            route.push_back(tickets[i][1]);

            auto result = dfs(tickets, visited, route);
            if (!result.empty()) return result;
            // 다른 경로도 탐색해야하기 때문에 백트래킹 기법 사용
            route.pop_back();
            visited[i] = false;
        }
    }

    return {};
}

vector<string> solution(vector<vector<string>> tickets) {
    // 사전순으로 앞선 경로가 우선이기 때문에 미리 정렬
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), false);
    vector<string> route = {"ICN"};

    return dfs(tickets, visited, route);
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({ {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });

    // 결과 출력
    for (auto it : answer) {
        cout << it << "->";
    }
    cout << endl;

    return 0;
}