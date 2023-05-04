#include <bits/stdc++.h>
using namespace std;

int day_of_week(int y, int m, int d) //Function to calculate day of week
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

void solve()
{
    // INPUT1
    // string key[] = {"2020-01-01", "2020-01-02", "2020-01-03", "2020-01-04", "2020-01-05", "2020-01-06", "2020-01-07","2020-01-08"}; //Input key
    // int val[] = {4,4,6,8,2,-6,2,-2}; //Input value
    // INPUT2
    string key[] = {"2020-01-01", "2020-01-04", "2020-01-05", "2020-01-06", "2020-01-07"}; //Input key
    int val[] = {6, 12, 14, 2, 4}; //Input value
    int n = sizeof(key) / sizeof(key[0]);
    string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    map<int, int> ans;
    vector<bool> check(7, false);

    for (int i = 0; i < n; i++) //Simple
    {
        string s = key[i];
        int year = stoi(s.substr(0, 4));
        int month = stoi(s.substr(5, 7));
        int date = stoi(s.substr(8, 10));
        int day = day_of_week(year, month, date);
        check[day] = true;
        ans[day] += val[i];
    }
    for (int i = 0; i < 7; i++) //If a day of week is missing: Output the mean of prev and next day
    {
        if (!check[i])
        {
            int prev = (i - 1 + 7) % 7;
            int next = (i + 1) % 7;
            int c = 2;
            while (!check[next])
            {
                next = (next + 1) % 7;
                c++;
            }
            int add = (ans[next] - ans[prev]) / c; //calculating mean for each day
            int j = i;
            while (!check[j])
            {
                ans[j] = ans[(j - 1+7)%7] + add;
                check[j] = true;
                j = (j + 1) % 7;
            }
        }
    }
    for (auto x : ans)
    {
        cout << week[x.first] << " " << x.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
