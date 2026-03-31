#include <cstddef>
#include <dirent.h>
#include <filesystem>
#include <iostream>
#include <malloc.h>
#include <sys/stat.h>
#include <vector>

using namespace std;

namespace fs = std::filesystem;
void findsize(string path) {
  long long size = 0;

  DIR *dir = opendir(path.c_str());
  if (!dir)
    cout << "not find dir " << endl;
  cout << dir << endl;
  struct dirent *entry;
  struct stat info;

  // size_t size = 0;
  while ((entry = readdir(dir)) != nullptr) {
    cout << &entry << endl;
    cout << malloc_usable_size(&entry) << endl;
    if (stat(entry->d_name, &info) == 0) {
      cout << info.st_size << endl;
    }
  }
  closedir(dir);
}

int main() {
  struct dirent *entry;
  DIR *dir = opendir(".");
  string a = "";
  vector<string> b;
  // cout << dir << endl;
  if (dir == NULL) {
    cout << "no dir found" << endl;
    return 1;
  }

  while ((entry = readdir(dir)) != NULL) {
    // cout << entry->d_name << endl;
    a += entry->d_name;
    a += " \n";
    b.push_back(entry->d_name);
  }
  cout << a << endl;
  closedir(dir);
  fs::path main_path = filesystem::current_path();
  findsize(main_path);

  return 0;
}
