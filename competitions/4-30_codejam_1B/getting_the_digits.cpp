// requires -std=c++11

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> countLetters(const string& in) {
  vector<int> count(26, 0);
  for (int i = 0; i < in.size(); i++) {
    //std::cout << in[i] - 'A' <<std::endl;
    count[in[i] - 'A']++;
  }
  return count;
}

string DPgetNumberRecurse(vector<int> count, const vector<string>& numbers, int iterator, string output) {
  vector<int> tmpCount(count);
  std::cout << iterator << std::endl;
  if(iterator > 9) return ""; // err checking
  for (int i = 0; i < numbers[iterator].size(); i++) {
    //    std::cout << numbers[iterator][i] -'A' << std::endl;
    tmpCount[numbers[iterator][i] - 'A']--;
    if (tmpCount[numbers[iterator][i] - 'A'] < 0) {
      //      std::cout << iterator << std::endl;
      if (iterator == 9) return "";
      else {
	return DPgetNumberRecurse(count, numbers, iterator+1, output);
      }
    }
  }

  // it worked, so check best of two options
  bool complete = true;
  for (int i = 0; i < tmpCount.size(); i++) {
    if (tmpCount[i] != 0) complete = false; 
  }
  if (complete) return output + std::to_string(iterator);

  // first check if we're already done
  string DPoutput = DPgetNumberRecurse(count, numbers, iterator+1, output);
  if (DPoutput != "") return DPoutput;
  DPoutput = DPgetNumberRecurse(tmpCount, numbers, iterator, output + std::to_string(iterator));
  return DPoutput;
}

string getPhoneNumber(const string& in) {
  //std::cout << "here" << in << std::endl;
  vector<int> count(countLetters(in));
  vector<string> numbers = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
  };
  return DPgetNumberRecurse(count, numbers, 0, "");
}


int main () {
  ofstream output;
  string line;
  ifstream input ("1_in");
  output.open ("1_out");
  int testcase = 0;
  if (input.is_open())
    {
      getline(input, line); // ignore number
      while ( getline (input,line) )
	{
	  testcase++;
	  std::cout << line << std::endl;
	  //std::cout << getPhoneNumber(line) << std::endl;
	  output << "Case #" << testcase << ": " << getPhoneNumber(line) << endl;
	}
      input.close();
    }
  //myfile << "Writing this to a file.\n";
  output.close();
  return 0;
}
