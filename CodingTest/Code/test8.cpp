#include <iostream>

using namespace std;

int main() {
    
    int a,b;
    int T;
		int num = 1;
    
    cin >> T;
    
    while(T--) {
				
				
        cin >> a >> b;
        
        cout << "Case #  " << num << a+b << "\n";
				num++;
    }
}
