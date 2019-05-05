
#include <iostream>

using namespace std;

int main() {

  int num;

	int a,b;

	while(scanf("%d %d", &a,&b) != EOF) {
  
	  if(a == 0 && b == 0){
      break;
		} else {
      cout << a+b <<"\n";
		}
	}

}
