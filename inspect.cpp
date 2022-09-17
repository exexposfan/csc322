#include <iostream>
#include <fstream> 

using namespace std;

string get_version(); // Shows Linux Version
string get_utime(); // Shows time spent in user mode
string get_stime(); // Shows time spent in system mode
string get_itime(); // Shows time spent idle
string get_context(); // Shows amount of context switches
string get_created(); // Shows amount of created processes
string get_running(); // Shows amount of running processes
string get_blocked(); // Shows amount of blocked processes

int main() {
  string version, utime, stime, itime, context, created, running, blocked;
  
  version = get_version();
  utime = get_utime();
  stime = get_stime();
  itime = get_itime();
  context = get_context();
  created = get_created();
  running = get_running();
  blocked = get_blocked();
  cout << "Linux version: " << version << endl;
  cout << "Time spent in user mode: " << utime << endl;
  cout << "Time spent in system mode: " << stime << endl;
  cout << "Time spent idle: " << itime << endl;
  cout << "Number of Context Switches: " << context << endl;
  cout << "Number of Created Processes: " << created << endl;
  cout << "Number of Running Processes: " << running << endl;
  cout << "Number of Blocked Processes: " << blocked << endl;
  return 0;
}

string get_version() { 
  ifstream inFile;
  string token, version_info;
  
  inFile.open("/proc/version");
  if(!inFile) {
    cout << "File not found (/proc/version)" << endl;
  }
  else {
    inFile >> token >> token; 
  }
}
  
string get_utime() { 
  ifstream inFile;
  string token;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    inFile >> token >> token; // /proc/stats prints out the following: (CPU Random Number here), so inFile >> token >> token takes out CPU and prints just the number
  }
}

string get_stime() { 
  ifstream inFile;
  string token;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    inFile >> token >> token >> token >> token; 
  }
}
  
string get_itime() { 
  ifstream inFile;
  string token;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    inFile >> token >> token >> token >> token >> token; 
  }
}

string get_context() { 
  ifstream inFile;
  string token;
  int i = 0;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    while (i < 4) {
      getline(inFile, token);
      i++;
    } // this while loop goes to the next line until it reaches the desired line, in this case, context
    inFile >> token >> token; 
  }
}

string get_created() { 
  ifstream inFile;
  string token;
  int i = 0;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    while (i < 6) {
      getline(inFile, token);
      i++;
    } 
    inFile >> token >> token; 
  }
  return token;
}

string get_running() { 
  ifstream inFile;
  string token;
  int i = 0;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    while (i < 7) {
      getline(inFile, token);
      i++;
    } 
    inFile >> token >> token; 
  }
  return token;
}

string get_created() { 
  ifstream inFile;
  string token;
  int i = 0;
  
  inFile.open("/proc/stats");
  if(!inFile) {
    cout << "File not found (/proc/stats)" << endl;
  }
  else {
    while (i < 8) {
      getline(inFile, token);
      i++;
    } 
    inFile >> token >> token; 
  }
  return token;
}
