#include <fstream>
#include "prototypes.h"

void writeFile() {
    ofstream fout("data.dat", ios::out | ios::binary);
    for (int i = 200; i <= 400; i += 10) 
        fout.write((char*)&i, sizeof(int));
    fout.close();
}

int getSum(){
    int x, sum = 0;
    ifstream fin("data.dat", ios::in | ios::binary);
    while(fin.read((char*)&x, sizeof(int)))
        sum += x;
    fin.close();
    return sum;
}

int main() {
    writeFile();
    cout << "The sum is: " << getSum() << endl;
    return 0;
}
