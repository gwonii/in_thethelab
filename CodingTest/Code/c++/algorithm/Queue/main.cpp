#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

    int T;
    string message;

    queue<int> queue;

    cin >> T;

    while (T--) {
        cin >> message;

        if (message == "push") {
            int num;
            cin >> num;

            queue.push(num);

        } else if (message == "pop") {

            if (!queue.empty()) {
                printf("%d\n", queue.front());
                queue.pop();

            } else {
                printf("%d\n", -1);
            }

        } else if (message == "size") {
            printf("%d\n", queue.size());
        } else if (message == "empty") {
            if (queue.empty()) {
                printf("%s\n", "queue는 비어있습니다.");
            } else {
                printf("%s\n", "queue는 비어있지 않습니다.");
            }
        }
    }
}