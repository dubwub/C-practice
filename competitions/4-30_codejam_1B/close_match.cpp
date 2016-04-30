// requires -std=c++11
// not working: abandoned

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int getInt(char c) {
  return c - '0';
}

vector<string> initArray(const string& in) {
  string string1 = in.substr(0, in.find(' '));
  string string2 = in.substr(in.find(' ') + 1);
  while (string1.size() < string2.size()) string1 = '?' + string1;
  while (string2.size() < string1.size()) string2 = '?' + string2;
  vector<string> strings = {string1, string2};
  return strings;
}

string getMinScores(const string& in) {
  vector<string> strings = initArray(in);
  int pivot = in.size();
  int greater = 0; int lesser = 1;
  for (int i = 0; i < strings[0].size(); i++) {
    if (strings[0][i] == '?' && strings[1][i] != '?') strings[0][i] = strings[1][i];
    else if (strings[1][i] == '?' && strings[0][i] != '?') strings[1][i] = strings[0][i];
    else if (strings[0][i] != '?' && strings[1][i] != '?' && strings[1][i] != strings[0][i] && i < pivot) {
      pivot = i;
      if (strings[1][i] < strings[0][i]) {
	if (strings[0][i] < '5') {
	  greater = 0; lesser = 1;
	  
	}
	else {
	  
	}
      }
      else {
	greater = 1; lesser = 0;
      }
    }
  }

  for (int i = 0; i < strings[0].size(); i++) {
    if (strings[0][i] == '?' || strings[1][i] == '?') {
      if (i < pivot) {
	strings[greater][i] = '0'; strings[lesser][i] = '0';
      }
      else {
	strings[greater][i] = '0'; strings[lesser][i] = '9';
      }
    }
  }

  return strings[0] + " " + strings[1];
}


int main () {
  ofstream output;
  string line;
  ifstream input ("2_in");
  output.open ("2_out");
  int testcase = 0;
  if (input.is_open())
    {
      getline(input, line); // ignore number
      while ( getline (input,line) )
	{
	  testcase++;
	  std::cout << line << std::endl;
	  //std::cout << getPhoneNumber(line) << std::endl;
	  output << "Case #" << testcase << ": " << getMinScores(line) << endl;
	}
      input.close();
    }
  //myfile << "Writing this to a file.\n";
  output.close();
  return 0;
}
