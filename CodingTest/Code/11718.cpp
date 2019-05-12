#include <iostream>
#include <string>


using namespace std;

int main() {

  string message;

  while(1){
  	getline(cin,message);
  	
		if( message.size() == 0 ){
  		break;
  	}
  	cout << message << "\n";
  }
}
