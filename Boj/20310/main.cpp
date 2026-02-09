// 백준 [20310] - [타노스]
// https://www.acmicpc.net/problem/20310
// 0과 1로 이루어진 문자열에서 각 갯수의 절반을 삭제한다 했을 때 사전순으로 가장 빠른 문자열을 구하는 문제
// 시간복잡도: O(N)
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 핵심 아이디어
// - 입력: 1과 0으로 이루어진 문자열
// - 출력: 1과 0을 각각 절반씩 제거했을 때 사전순으로 가장 빠른 문자열
// - 핵심 로직: 절반에 해당하는 갯수를 0은 앞에서 부터, 1은 뒤에서 부터 저장
int main()
{
    string s;
    cin >> s;

    vector<pair<int, char>> v;
    int zero = 0, one = 0;

    for (auto i : s)
    {
        if (i == '0')
            ++zero;
        else
            ++one;
    }

    zero /= 2;
    one /= 2;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s.at(i) == '0')
        {
            v.push_back({i, '0'});
            --zero;
        }
        if (zero <= 0)
            break;
    }

    for (int i = s.length() - 1; 0 <= i; --i)
    {
        if (s.at(i) == '1')
        {
            v.push_back({i, '1'});
            --one;
        }
        if (one <= 0)
            break;
    }

    sort(v.begin(), v.end());

    stringstream ss;
    for (auto i : v)
    {
        ss << i.second;
    }
    cout << ss.str();

    return 0;
}