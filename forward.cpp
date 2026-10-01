#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> x(n), y(n);

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double value;
    cin >> value;

    vector<vector<double>> diff(n, vector<double>(n));

    for(int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for(int j = 1; j < n; j++)
    {
        for(int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    double ans = y[0];
    double term = 1;

    for(int i = 1; i < n; i++)
    {
        term *= (u - (i - 1));

        double fact = 1;

        for(int j = 1; j <= i; j++)
            fact *= j;

        ans += (term / fact) * diff[0][i];
    }

    cout << fixed << setprecision(6);
    cout << "f(" << value << ") = " << ans << endl;

    double extraX, extraY;
    cin >> extraX >> extraY;

    vector<double> ex(n + 1), ey(n + 1);

    for(int i = 0; i < n; i++)
    {
        ex[i] = x[i];
        ey[i] = y[i];
    }

    ex[n] = extraX;
    ey[n] = extraY;

    vector<vector<double>> errorDiff(n + 1, vector<double>(n + 1));

    for(int i = 0; i <= n; i++)
        errorDiff[i][0] = ey[i];

    for(int j = 1; j <= n; j++)
    {
        for(int i = 0; i <= n - j; i++)
        {
            errorDiff[i][j] =
                (errorDiff[i + 1][j - 1] - errorDiff[i][j - 1])
                / (ex[i + j] - ex[i]);
        }
    }

    double product = 1;

    for(int i = 0; i <= n; i++)
        product *= (value - x[i]);

    double error = errorDiff[0][n] * product;

    cout << "Truncation Error = " << error << endl;

    return 0;
}
