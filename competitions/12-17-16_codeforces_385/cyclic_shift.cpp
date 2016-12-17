#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  string input;
  cin >> input;
  unordered_set<string> found;
  for (int i = 0; i < input.size(); i++) {
    found.insert(input);
    input = input[input.size() - 1] + input.substr(0, input.size() - 1);
  }
  cout << found.size() << endl;
}
