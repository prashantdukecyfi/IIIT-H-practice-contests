/*

Code by - Prashant Raj, IIIT-H MTech(20-22)

Neel has moved to Hyderabad recently and is on a search for a place to stay.
He wants to stay in a flat with the flat number having 7s and 4s only and with the equal number of both the digits.
He also wants the flat number to be as small as possible. He's given apartment names and the corresponding flat numbers.
Help him with the best option possible by printing the Apartment name.
If there's no flat available meeting his requirement print -1.

Input Format

    The first line is an integer N denoting the number of flats
    The next N lines contain the apartment names(a) and the corresponding flat numbers(f)

Constraints

    1 <= N <= 10^5
    1 <= |a| <= 10
    1 <= |f| <= 10^9

Output Format

    Print the apartment name of the best option available to Neel.
    If the criteria doesn't satisy, print -1.

Sample Input 0

5
PalashNivas 474744477
PaarijatNivas 747774
SurajNivas 744
ChampaNivas 448477
KamalNivas 74

Sample Output 0

KamalNivas

Explanation 0

As KamalNivas satisfies the criteria and also has the least value as the room number

*/




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, num, freq=0, flag=0;
    string s;
    map<int, string> m;
    map<int, string>::iterator it;
    cin >> n;
    if(n<1 || n>100000)
    {
        cout << -1;
        return(0);
    }
    while(n--)
    {
        cin >> s >> num;
        if(s.length() > 10 || num > 1000000000 || num < 1 || s.length() < 1)
            continue;
        m.insert(make_pair(num, s));
    }
    for(it = m.begin(); it != m.end(); it++)
    {
        flag = 0;
        freq = 0;
        num = it->first;
        while(num>0)
        {
            if(num%10 == 7)
                freq++;
            else if(num%10 == 4)
                freq--;
            else
            {
                flag = 1;
                break;
            }
            num = num/10;
        }
        if(freq == 0 && flag == 0)
        {
            flag = 1;
            cout << it->second;
            break;
            return(0);
        }
    }
    if(flag == 0 || it == m.end())
        cout << -1;
    return 0;
}

