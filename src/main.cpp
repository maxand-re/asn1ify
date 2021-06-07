#include <iostream>
#include <string>
#include <stdlib.h>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

static inline void replaceAll(std::string &str, const std::string& from, const std::string& to);
void recursiveASN1(const string& directory);
string intToHex(const int &value);
void printHelp();

int main(int argc, char** args) {

    const char* home = getenv("HOME");

    string path;
    string help[2] = {"--help", "-h"};

    for (int i = 0; i < argc; i++) {
        if(args[i] == help[0] || args[i] == help[1]) {
            printHelp();
            return 0;
        }

        if(args[i][0] != '-') {
            path = args[i];
        }
    }

    if (home) {
        replaceAll(path, "~", home);
    }

    if(fs::is_directory(path)) {
        recursiveASN1(path);

        fs::current_path(path);

        cout << endl << "Result: " << endl;
        for(auto& p: fs::recursive_directory_iterator(".")) {
            string currentPath = p.path();
            replaceAll(currentPath, "/", " ");
            replaceAll(currentPath, ".", "");

            cout << "\t" << currentPath << endl;
        }
    } else {
        cout << "ERROR: Directory \"" << path << "\" not found" << endl;
        return -1;
    }

    return 0;
}

void recursiveASN1(const string& directory) {
    int value = 0;

    for(auto& p: fs::directory_iterator(directory)) {
        if(p.is_directory()) {
            recursiveASN1(p.path());
        }

        string oldPath = p.path();
        string newPath = p.path().parent_path().string() + "/" + intToHex(value);

        fs::rename(oldPath, newPath);

        cout << p.path() << " => " << newPath << '\n';
        value++;
    }
}

void printHelp() {
    cout << endl
         << "Usage:" << endl
         << "\tasn1ify [options] <path>" << endl << endl
         << "Options:" << endl
         << "\t<path>\t\tThe path you want to transform" << endl
         << "\t-h, --help\tPrint help (cancel asn)" << endl;
}

/*
 * UTILS
 */
static inline void replaceAll(std::string &str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

string intToHex(const int &value){
    const string hex = "0123456789ABCDEF";
    string res;

    if(value == 0) return "00";
    if(value <= 15) res += "0";

    int num = value;
    while(num > 0) {
        res += hex[num % 16];
        num /= 16;
    }

    return res;
}