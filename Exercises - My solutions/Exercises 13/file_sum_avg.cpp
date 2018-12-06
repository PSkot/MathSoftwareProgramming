#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

  int main(void) {
    double val; vector<double> v;
    fstream myfile;
    myfile.open("myfile.txt", ios::in);
    if (myfile.fail()) {
      cerr << "Error opening file.." << endl;
      exit(-1);
    }
    while (myfile >> val) {
      v.push_back(val);
      cout << "Current size: " << v.size() << endl;
      cout << "Current capacity: " << v.capacity() << endl;
    }
    myfile.close();
    cout << "Read " << v.size() << " numbers from file." << endl;
    cout << "Total capacity: "  << v.capacity() << endl;
    double sum = 0;

    for (unsigned int i = 0; i < v.size(); i++) {
      sum += v[i];
    }

    cout << "The sum is: " << sum << endl;
    cout << "The mean is: " << sum/v.size() << endl;

    return 0;
  }
