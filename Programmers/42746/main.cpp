// 프로그래머스 [42746] - [가장 큰 수]
// https://school.programmers.co.kr/learn/courses/30/lessons/42746
// 주어진 정수 배열을 이어 붙여 만들 수 있는 가장 큰수를 구하는 문제
// 시간복잡도: O(N log N)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 핵심 아이디어
// - 하나의 기준으로 정리하는 문제
// - 따라서 해당 기준을 파악 하는것이 중요
// - 문자열로 만들어서 비교
string solution(vector<int> numbers) {
    string answer;

    //정수를 이어 붙이기 위해 string으로 변환
    vector<string> strNumbers;
    for (int num : numbers) {
        strNumbers.push_back(to_string(num));
    }

    //이어 붙였을 때 어느 조합이 더 큰지를 비교
    //ex) [30, 3]은 303 보다 330이 더 큼
    sort(strNumbers.begin(), strNumbers.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    //0으로만 이루어진 배열 예외 처리
    if (strNumbers[0] == "0") {
        return "0";
    }
    
    //출력 값 정리
    for (const string& str : strNumbers) {
        answer += str;
    }

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({ 3, 30, 34, 5, 9 });

    // 결과 출력
    cout << answer << endl;

    return 0;
}