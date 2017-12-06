#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void insert(vector<int>& v, int n)
{
    for (int i = 1; i < n; i++) {
        int elem, j;
        for (elem = v[i], j = i-1; j >= 0 and elem < v[j]; j--)
            v[j+1] = v[j];
        v[j+1] = elem;
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

    insert(v, n);

    print(v);

    return 0;
}


