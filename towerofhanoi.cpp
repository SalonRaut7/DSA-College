#include<iostream>
using namespace std;
void towerOfHanoi(int n, char source, char middle, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, middle);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, middle, source, destination);
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    cout << "Tower of Hanoi steps:" << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
