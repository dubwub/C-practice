/*
  Problem

You are a teacher at the brand new Little Coders kindergarten. You have N kids in your class, and each one has a different student ID number from 1 through N. Every kid in your class has a single best friend forever (BFF), and you know who that BFF is for each kid. BFFs are not necessarily reciprocal -- that is, B being A's BFF does not imply that A is B's BFF.

Your lesson plan for tomorrow includes an activity in which the participants must sit in a circle. You want to make the activity as successful as possible by building the largest possible circle of kids such that each kid in the circle is sitting directly next to their BFF, either to the left or to the right. Any kids not in the circle will watch the activity without participating.

What is the greatest number of kids that can be in the circle?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines. The first line of a test case contains a single integer N, the total number of kids in the class. The second line of a test case contains N integers F1, F2, ..., FN, where Fi is the student ID number of the BFF of the kid with student ID i.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the maximum number of kids in the group that can be arranged in a circle such that each kid in the circle is sitting next to his or her BFF.

Limits

1 ≤ T ≤ 100.
1 ≤ Fi ≤ N, for all i.
Fi ≠ i, for all i. (No kid is their own BFF.)
Small dataset

3 ≤ N ≤ 10.
Large dataset

3 ≤ N ≤ 1000.
Sample


Input 

Output 
 
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3

Case #1: 4
Case #2: 3
Case #3: 3
Case #4: 6

In sample case #4, the largest possible circle seats the following kids in the following order: 7 9 3 10 4 1. (Any reflection or rotation of this circle would also work.) Note that the kid with student ID 1 is next to the kid with student ID 7, as required, because the list represents a circle.
 */
#include <iostream>
#include <vector>
#include <map>

struct BFFSolver
{
  std::vector<int> BFF_list;
  int solve();
  BFFSolver(std::vector<int> _list) : BFF_list(_list) {};
};

int BFFSolver::solve()
{
  int max_ring = 0;
  for (int i = 0; i < BFF_list.size(); i++) {
    int current = BFF_list[i];
    int step = 2;
    std::map<int, int> cycle;
    cycle[i] = 1;
    while (cycle.count(current) == 0) {
      cycle[current] = step;
      step++;
      current = BFF_list[current];
    } // finished cycle, see if we can add
    int this_length = step;
    if (step - cycle[current] == 2) {
      int end1 = i;
      int end2 = BFF_list[current];
      bool iterate = true;
      while (iterate) {
	iterate = false;
	for (int i = 0; i < BFF_list.size(); i++) {
	  if (cycle.count(i) == 0) {
	    if (BFF_list[i] == end1) {
	      this_length++; end1 = i;
	    }
	    else if (BFF_list[i] == end2) {
	      this_length++; end2 = i;
	    }
	  }
	}
      }
    }
    if (this_length > max_ring) max_ring = this_length;
  }
  return max_ring;
}

int main()
{
  int numcases;
  std::cin >> numcases;
  std::vector<int> outputs;
  for (int i = 0; i < numcases; i++) {
    int input_size;
    std::cin >> input_size;
    std::vector<int> input;
    for (int j = 0; j < input_size; j++) {
      int new_value;
      std::cin >> new_value;
      std::cout << new_value << std::endl;
      input.push_back(new_value-1);
      outputs.push_back(BFFSolver(input).solve());
    }
  }

  for (int i = 0; i < numcases; i++) {
    std::cout << "Case #" << i+1 << ": " << outputs[i] << std::endl;
  }
}
