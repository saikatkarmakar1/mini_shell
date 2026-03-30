#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // input_from_user();
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
    string final_command = "";
    for (size_t a = 0; a < tocs.size(); ++a) {
      final_command += tocs[a];
      if (a < tocs.size() - 1) {
        final_command += " ";
      }
    };
    system(final_command.c_str());
    cout << tocs[0] << endl;
  }
  return 0;
}
