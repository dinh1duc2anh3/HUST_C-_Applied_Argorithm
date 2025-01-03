#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

struct Call{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

vector <Call> calls;

bool checkPhoneNumber(const string &phone_number){
    if (phone_number.size != 10) return false;
    for (i=0; i<phone_number.length(); i++){
        if (!phone_number[i]>=0 && phone_number[i]<=9 ) return false;
    }
    return true;
}

int time_to_seconds( const string &time_str){
    int h,m,s;
    sscanf(time_str.c_str(), "%d:%d:%d", &h,&m,&s);
    return 3600*h+60*m+s;
}

int get_call_duration(const string &from_time,const string &end_time){
    return time_to_seconds(end_time) - time_to_seconds(from_time);
}


void process_call_data(){
    string line;
    while (getline(cin,line)){
        if (line == '#') break;

        Call c;
        stringstream ss(line);
        string prefix;
        ss >> prefix >> c.from_number >> c.to_number >> c.date >> c.fromtime >> c.endtime;

        calls.push_back(c);
    }
}

void process_queries(){
    string line;
    while (getline(cin,line)){
        if (line == '#') break;

        stringstream ss(line);
        string query;
        ss>>query;

        if (query == "?check_phone_number") {
            bool all_valid = true;
            for (const Call $c : calls) {
                all_valid = false;
                break;
            }
        }
    }
}
