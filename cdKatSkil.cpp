#include <iostream>
#include <stack>
using namespace std;

int main() {
    int count = 0;
    int jackCount;
    int jillCount;
    int x;
    stack<int> jack;
    stack<int> jill;

    cin >> jackCount;
    cin >> jillCount;
    for(int i=0;i<jackCount;i++) {
        cin >> x;
        jack.push(x);
    }

    for(int i=0;i<jillCount;i++) {
        cin >> x;
        jill.push(x);
    }
    cin >> x;
    cin >> x;

    while(!jack.empty() || !jill.empty()) {
        if(jack.top() < jill.top())  {
            jill.pop();
        } else if(jack.top() > jill.top()) {
            jack.pop();
        } else {
            jack.pop();
            jill.pop();
            count++;
        }
    }
    cout << count << endl;
    return 0;
}