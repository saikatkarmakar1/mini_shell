#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ls.h"
#include <unistd.h>    // For fork() and execv()
#include <sys/wait.h>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

void execute_file(std::string path) {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        // execv requires: 1. Full path, 2. Argument array (ending in NULL)
        char* args[] = {(char*)path.c_str(), NULL};
        
        if (execv(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(1); 
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for your 'ls' code to finish
    } else {
        std::cerr << "Failed to fork." << std::endl;
    }
}

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
      // break;
    }
    string final_command = "";
    for (size_t a = 0; a < tocs.size(); ++a) {
      final_command += tocs[a];
      if (a < tocs.size() - 1) {
        final_command += " ";
      }
    };
    if (fs::exists("./" + tocs[0])) {
            std::cout << "[Found locally] Running " << tocs[0] << "...\n";
            execute_file("./" + tocs[0]);
        } else {
            system(final_command.c_str());
        }
    
    //cout << tocs[0] << endl;
  }
  return 0;
}
