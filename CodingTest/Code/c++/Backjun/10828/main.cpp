#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int T;
    string message;

    stack<int> st;

    cin >> T;

    while (T--) {
        cin >> message;

        if (message == "push") {
            int num;
            cin >> num;

            st.push(num);

        } else if (message == "pop") {
            if (!st.empty()) {
                printf("%d\n", st.top());
                st.pop();

            } else {
                printf("%d\n", -1);
            }

        } else if (message == "size") {
            printf("%ld\n", st.size());

        } else if (message == "empty") {
            printf("%d\n", st.empty());

        } else if (message == "top") {
            if (!st.empty()) {
                printf("%d\n", st.top());

            } else {
                printf("%d\n", -1);
            }
        }
    }
}