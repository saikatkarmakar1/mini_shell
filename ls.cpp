#include <cstddef>
#include <dirent.h>
#include <iostream>
#include<vector>

using namespace std;

int main() {
  struct dirent *entry;
  DIR *dir = opendir(".");
  string a = "";
  vector<string> b ;
  // cout << dir << endl;
  if (dir == NULL) {
    cout << "no dir found" << endl;
    return 1;
  }

  while ((entry = readdir(dir)) != NULL) {
    //cout << entry->d_name << endl;
    a += entry->d_name;
    a += " \n";
    b.push_back(entry->d_name);
  }
  cout << a << endl;  
  closedir(dir);
  return 0;
}
