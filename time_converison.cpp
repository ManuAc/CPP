#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

string parse_time(string time){
    int len = time.length();
    int hr = std::stoi(time.substr(0, 2));
    string type = time.substr(len-2, 2);
    if(type == "AM" && hr == 12)
        time.replace(0, 2, "00");
    else if(type == "PM" && hr != 12)
        time.replace(0, 2, std::to_string(hr+12));
    return time.substr(0, len-2);
}

int main(){
	string time;
	cin >> time;
	cout << parse_time(time) << endl;
	return 0;
}