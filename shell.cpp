#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main() {
  //input_from_user();
  while (true) {
    string a;
    cout << "Saikat@Saikat $ ";
    getline(cin, a);
    stringstream ss(a);
    string toc;
    vector<string> tocs;
    while (ss >> toc) {
      tocs.push_back(toc);
      break;
    }
    cout << tocs[0] << endl;
  }
  return 0;
}
