#include <iostream> 
#include <cassert>
#include <vector> 

using namespace std;

int main()
{
    vector<int> v;
    vector<int> w;
    
    v.push_back(1);
    w.push_back(2);

    cout << v[0] << endl;
    cout << w[0] << endl << endl;
    
    v=w;
    
    cout << v[0] << endl; 
}
