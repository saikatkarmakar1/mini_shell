#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void input_from_user(void) {
  while (true) {
    string a;
    cout << "Saikat@Saikat $ ";
    cin >> a;
    stringstream ss(a);
    string toc;
    vector<string> tocs;
    while (ss >> toc) {
      tocs.push_back(toc);
    }
    cout << tocs[0] << endl;
  }
}
int main() {
  input_from_user();
  return 0;
}
