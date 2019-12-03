#include<iostream>
#include<string>
#include<vector> 
using namespace std;

 vector<string> split(const string &str, string delim) {
        vector<string> results;
        int lastIndex = 0, index;
        while ((index = str.find(delim, lastIndex)) != string::npos) {
            results.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }
        if (lastIndex != str.length()) {
            results.push_back(str.substr(lastIndex, str.length() - lastIndex));
        }
        return results;
    }
vector<string> split1(string &s1, string s2)
{
	vector<string> out;
	for(int i= 0; i < s1.size(); ++i)
	{
		if(s1.substr(i,1) != s2)
		out.push_back(s1.substr(i,1));
	}
	return out;
}

int main(){
	string s1 = "a,b,c,d,e";
	string s2 = ",";
	vector<string> out, out1;
	out = split(s1, ",");
	for(auto s: out)
	cout<<s<<endl;
	out1 = split1(s1, ",");
	for(auto s: out1)
	cout<<s<<endl;
}
