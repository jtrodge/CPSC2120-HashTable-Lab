/*
Jason Rodgers
CPSC 2121
jtrodge@clemson.edu
Brian Dean
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int N, *A;
int main(void) {
  cin >> N;
  A = new int[2*N];
  int k = 0;
  for (int i = 0; i < N; i++) {
    char cmd;
    int num;
    cin >> cmd >> num;
    if(cmd == 'F') A[k++] = 0;
    if(cmd == 'L') A[k++] = 1;
    if(cmd == 'R') A[k++] = 2;
    A[k++] = num;
  }

  int numindex = 0;
  bool match = false;
  for (int index = 1; index < (2*N); index++) {
    match = true;
    for (int j = 0; j < (2*N); j++) {
      if (A[(j+index) % (2*N)] != A[j]) {
        match = false;
        break;
      }
    }
    if (match == true) {
      numindex = index;
      break;
    }
  }
  cout << "Total number of symmetries: " << ((2*N) / numindex) << "\n";
  delete [] A;


  return 0;
}
