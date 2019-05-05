#include <iostream>

using namespace std;

int main() {
    int h;
    int m;
    int during;
    
    cin >> h >> m;
    cin >> during;
    
    cout << (h + (m + during)/60) % 24  << " " << (m + during) % 60 << "\n";  
}
