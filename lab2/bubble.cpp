#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void bubble(vector<int>& v, int n)
{
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);
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

    bubble(v, n);

    print(v);

    return 0;
}
