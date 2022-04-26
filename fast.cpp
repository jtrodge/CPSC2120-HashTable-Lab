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
  /*
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
  cout << "Symmetry count: " << ((2*N) / numindex) << "\n";
  */
  int hash = 0;
  int p = 1000000007;
  int x = 2;
  //Horner's Rule - Original Hash
  for (int i = 0; i < (2*N); i++) {
    hash = ((((long long)hash * x) % p) + A[i]) % p;
  }
  //(x+y) % p = add to prevent overflow
  //(x-y+p) % p = subtract to prevent underflow
  //((long long)x*y) % p = multiply
  // Updating hash table  - hash - A[i]*x^(2N-1)) * x + A[i]
  int update = 1;
  for (int i = 0; i < (2*N-1); i++) {
    update = ((long long)update * x) % p;
  }

  int numindex = 0;
  //bool match = false;
  int newHash = hash;
  int result = 0;
  for (int index = 0; index < (2*N); index++) {
      //Update New Hash to compare the contents of each hash table
      result = (((long long)A[index]) * update) % p;
      newHash = (newHash - result) % p;
      if (newHash < 0) {
        newHash = (newHash + p);
      }
      newHash = ((long long)newHash * x) % p;
      newHash = ((long long)newHash + A[index]) % p;
      if (hash == newHash && index != 0) {
        bool match = true;
        for (int j = 0; j < (2*N); j++) {
          if (A[(j+index) % (2*N)] != A[j]) {
            match = false;
            break;
          }
        }
        if (match == false) {
          numindex = index + 1;
          break;
        }
      }
    }
  cout << "Total number of symmetries: " << ((2*N) / numindex) << "\n";
  delete [] A;


  return 0;
}
