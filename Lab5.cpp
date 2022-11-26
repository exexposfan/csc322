#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

int frames = 3;
static bool findUpdate(int x, int array[], bool second_chance[]) { // if page is found, updates the 2nd chance bit
  for (int i = 0; i < frames; i++) {
    if (array[i] == x) {
      second_chance[i] = true; // Marks page that gets 2nd chance
      return true; // if there is a hit, no need to replace page
    }
  } 
  return false; // replace page if page not found
} 
static int replaceUpdate(int x, int array[], bool second_chance[], int pointer) { // updates page in memory and returns  the pointer
  while(true) {
    if(!second_chance[pointer]) { // found the page to replace
      array[pointer] = x; // replace with new page
      return (pointer + 1) % frames; // return updated pointer
    } 
  }
  second_chance[pointer] = false; // will be replaced next time it's accessed
  pointer = (pointer + 1) % frames; // pointer updated in round robin manner
} 
static void outputPageFaults(string reference) { 
  int pointer = 0; // consider frame 0 to be replaced
  int pageFaults = 0; // number of page faults
  int array[frames]; // array to hold page numbers
  string str[1000]; // reference string of up to 1000  page references
  ofstream MyFile("results.txt"); //creates text file
  for (int i = 0; i < frames; i++ ) { // 
    if { // (Page fault)
      MyFile << "PF\n";
    }
    else { // not page fault)
      MyFile << "NPF\n";
    }
  } 
  MyFile << "The number of page faults in this string is ";
  MyFile << pageFaults;
  MyFile << ".\n";
  MyFile.close(); //closes file
}
int main() {
  string reference = "";
  int frames = 3;
  print outputPageFaults(reference, frames);
  return 0;
} 
