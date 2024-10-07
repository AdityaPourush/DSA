#include <iostream>
#include <vector>

using namespace std;

void printStep(int source, int destination){
    cout << source << " -> " << destination << endl;
}

void towerOfHanoi(int disks, int source, int destination){
    int other = 6 - (source + destination);
    if(disks == 1){
        printStep(source, destination);
        return;
    }
    towerOfHanoi(disks-1, source, other);
    towerOfHanoi(1, source, destination);
    towerOfHanoi(disks-1, other, destination);
}

int main(){
    int disks;
    cout << "Number of disks : ";
    cin >> disks;

    towerOfHanoi(disks, 1, 3);

    return 0;
}