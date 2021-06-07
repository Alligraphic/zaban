#include <iostream>
#include <string>
using namespace std;

int countIn(string joft, string str)
{
    int m = joft.length();
    int n = str.length();
    int res = 0;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (str[i+j] != joft[j])
                break;
        if (j == m)
        {
           res++;
           j = 0;
        }
    }
    return res;
}
int main()
{
    char inp = 'a';
    int a = 0, jc[200] = {0}, cursor = 0, pc = 0, result;
    string inps, strs1[200];
    while (1)
    {
        cin >> inp;
        strs1[a] = inp;
        jc[a] = -1;if (inp == '0') break;
        a++;
        pc++;

        for (int i = 0 ; i < inp - '0' ; i++)
        {
            cin >> strs1[a];
            jc[a] += countIn("aa",strs1[a]);
            jc[a] += countIn("ee",strs1[a]);
            jc[a] += countIn("ii",strs1[a]);
            jc[a] += countIn("oo",strs1[a]);
            jc[a] += countIn("uu",strs1[a]);
            a++;
        }
    }
//    for(int i = 0 ; i < 11 ; i++)
//        cout << a<<endl;
    for (int i = 0 ; i < pc ; i++)
    {
        cursor++;
        if (cursor >= a-1) break;
        result = cursor;
        while ( jc[cursor] != -1)
        {
            if (jc[cursor] > jc[result])
                result = cursor;
            cursor++;
        }

        cout << strs1[result] << endl;
    }
    return 0;
}
