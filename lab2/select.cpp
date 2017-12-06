#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void select(vector<int>& v, int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

void print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        v[i] = rand() % 1000000;

    select(v, n);

    print(v);

    return 0;
}
