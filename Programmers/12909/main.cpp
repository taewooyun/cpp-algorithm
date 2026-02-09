// 프로그래머스 [12909] - [올바른 괄호]
// https://school.programmers.co.kr/learn/courses/30/lessons/12909
// 괄호가 정상적으로 열리고 닫힌지를 판단하는 문제
// 시간복잡도: O(n)

#include <string>
#include <iostream>

using namespace std;

// 핵심 아이디어
// - 입력: 괄호만으로 이루어진 문자열
// - 출력: 괄호가 정상적으로 닫혀있으면 true, 아니면 false
// - 핵심 로직: 변수를 둔 뒤 괄호가 열리면 1을 더해주고 닫히면 빼주면서 0일 경우를 판단, 닫히는게 먼저 나오면 false 반환
bool solution(string s)
{
    int temp = 0;

    for(auto c : s){
        if(c == '(') ++temp;
        if(c == ')') --temp;
        if(temp < 0) return false;
    }

    return !temp;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution("()()");

    // 결과 출력
    cout << answer << endl;

    return 0;
}