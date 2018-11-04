#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
using namespace std;

/*
void display(stack<int> tower) {
    while(!tower.empty()) {
        cout << ' ' << tower.top();
        tower.pop();
    }
    cout << endl;
}
*/

int main() {
    int count = 0;
    int jackCount;
    int jillCount;
    int x;
    ifstream inFile;
    stack<int> jack;
    stack<int> jill;

    inFile.open("test.txt");
    if(!inFile) {
        cout << "Unable to open file";
        exit(1); //terminate with error
    }

    inFile >> jackCount;
    inFile >> jillCount;
    for(int i=0;i<jackCount;i++) {
        inFile >> x;
        jack.push(x);
    }

    for(int i=0;i<jillCount;i++) {
        inFile >> x;
        jill.push(x);
    }

    //display(jack);
    //display(jill);

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

    inFile.close();
    cout << count << endl;
    return 0;
}