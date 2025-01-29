#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int str_to_int(string num){
//map storing all the tokens(key values)
	map<string,int>values = {
		        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
			{"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
		        {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
		        {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18},
			{"nineteen", 19}, {"twenty", 20}, {"thirty", 30}, {"forty", 40},
		        {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80},
		        {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000},
			{ "billion", 1000000000}, {"trillion", 1000000000000}
			    };
	//processing the string to remove white spaces, "and", commas,hyphens,and periods
	string new_str;
	for(char i :num){
		if (i == ' ' || i == ',' || i == '.' || i == '-'){
			new_str += ' ';
		}else{
		new_str +=tolower(i);
		}	
	}
	//splittng the string into individual words and removes "and"
	vector<string>tokens;
	stringstream ss(new_str);//reads stream of data from the new_str and stops splits the whitespace
	string token;
	while (ss>>token){
		if(token != "and"){
		tokens.push_back(token);
	}
	}
//accummulating the values
	//	iterate over each token
	int total = 0;
	int current = 0;
	for(const auto i : tokens){
		if(values.find(i) == values.end()){
		
			throw invalid_argument("unknown token: "+ i);
	}
	int value = values[i]; 

	if(value == 100){
		current*=value;
	}else if(value >= 1000){
		current*=value;
		total+=current;
		current = 0;
	}else{
	
		current+=value;
	}
	}
	total += current;
	return total;


}	
int main(){

	string str;
	printf("enter the number in words\n");
	getline(cin,str);
	try{
		int result = str_to_int(str);
		cout<<"result:" <<result<<endl;
	}catch(const invalid_argument &e){
		cout<<"error: "<<e.what()<<endl;
	}
}
