/*

Code by - Devesh Jha, IIIT-H MTech(20-22)

Little Lilly is on a mission to build an empire with cubes.
She wants to paint each visible side of an individual block of cube with a unique colour.
First she picks a base B with length l and width w to start building on it.
On every cell Lilly stacks certain number of cubes which is given as B[i][j].
B[i][j] are the number of cubes stacked at ith row and jth column.

As she's too small help her in calculating how many different colours she needs for painting.

Input Format

The first line contains the length and the width of the base as two space-separated integers.

The next l lines contain w integers. The jth integer in ith line denotes B[i][j].

Constraints

    1 <= l, w <= 100
    1 <= B[i][j] <= 100

Output Format

Print the number of different colours required.

Sample Input 0

2 2
1 2
0 1

Sample Output 0

18

Explanation 0

3 surfaces in the top side, 3 surfaces in the bottom side, 3 surfaces in the left side, 3 surfaces in the right side, 3 surfaces in the front side and 3 surfaces in the back side of the empire. So in total it is 18. 

*/



#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, w, ans, left, right, up, down;
    cin >> l >> w;
    int a[l][w];
    for(int i = 0; i < l; i++)
        for(int j = 0; j < w; j++)
            cin >> a[i][j];
    ans = 0;
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(a[i][j] != 0)
            {
                if(j == 0)
                    left = a[i][j];
                else
                    left = max(0, a[i][j] - a[i][j-1]);
                if(j == w-1)
                    right = a[i][j];
                else
                    right = max(0, a[i][j] - a[i][j+1]);
                if(i == 0)
                    up = a[i][j];
                else
                    up = max(0, a[i][j] - a[i-1][j]);
                if(i == l-1)
                    down = a[i][j];
                else
                    down = max(0, a[i][j] - a[i+1][j]);
                ans += left + right + up + down + 2;
            }
        }
    }
    cout << ans;
    return(0);
}
