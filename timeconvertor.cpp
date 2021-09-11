/*
* converts 12 hour time format to 24 hour time format
*/
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s)
{
    /*
     * Write your code here.
     */
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 5));
    int ss = stoi(s.substr(6, 8));

    string time = s.substr(8, 10);
    string res = "";
    string h1;
    string m1;
    string s1;
    if (time == "AM")
    {
        if (hh == 12)
            hh = 0;
        else if (hh >= 1)
        {
            hh = hh;
        }
    }
    else if (time == "PM")
    {
        if (hh == 12)
            hh = 12;
        else if (hh >= 1)
            hh += 12;
    }
    h1 = (hh < 10) ? ("0" + to_string(hh)) : to_string(hh);
    m1 = (mm < 10) ? ("0" + to_string(mm)) : to_string(mm);
    s1 = (ss < 10) ? ("0" + to_string(ss)) : to_string(ss);
    res = h1 + ":" + m1 + ":" + s1;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
