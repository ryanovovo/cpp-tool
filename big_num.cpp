#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int convert_string_to_int(string str){
	int ret = 0;
	reverse(str.begin(), str.end());
	int mutipl = 1;
	for(unsigned int i = 0; i < str.size(); i++){
		int str_i = str[i] - '0';
		ret += str_i * mutipl;
		mutipl*=10;
	}
	return ret;
}
string convert_int_to_string(int str){
	string ret;
	while(str>0){
		ret.push_back((str % 10) + '0');
		str /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string convert_char_to_string(char cha){
	string ret;
	ret.push_back(cha);
	return ret;
}
bool operator >(const string &lhs_str, const string &rhs_str){
	if(lhs_str.size() > rhs_str.size()){
		return true;
	}
	else if(lhs_str.size() < rhs_str.size()){
		return false;
	}
	else{
		for(unsigned int i = 0; i < lhs_str.size(); i++) {
			if(lhs_str[i] > rhs_str[i]){
				return true;
			}
			else if(lhs_str[i] < rhs_str[i]){
				return false;
			}
		}
	}
	return false;
}
bool operator <(const string &lhs_str, const string &rhs_str){
	if(lhs_str.size() < rhs_str.size()){
		return true;
	}
	else if(lhs_str.size() > rhs_str.size()){
		return false;
	}
	else{
		for(unsigned int i = 0; i < lhs_str.size(); i++) {
			if(lhs_str[i] < rhs_str[i]){
				return true;
			}
			else if(lhs_str[i] > rhs_str[i]){
				return false;
			}
		}
	}
	return false;
}
string operator +(string augend, string addend){
	if(augend < addend){
		swap(augend, addend);
	}
	int diff = augend.size() - addend.size();
	reverse(augend.begin(), augend.end());
	reverse(addend.begin(), addend.end());
	for(int i = 0; i < diff; i++){
		addend.push_back('0');
	}
	int carry = 0;
	string ret;
	for(unsigned int i = 0; i < augend.size(); i++){
		int augend_i = augend[i] - '0';
		int addend_i = addend[i] - '0';
		ret.push_back((augend_i+addend_i+carry)%10 + '0');
		carry = (augend_i+addend_i+carry)/10;
	}
	if(carry > 0){
		ret.push_back(carry + '0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string operator *(string multiplicant, string multiplier){
	if(multiplier > multiplicant){
		swap(multiplicant, multiplier);
	}
	reverse(multiplicant.begin(), multiplicant.end());
	reverse(multiplier.begin(), multiplier.end());
	string ret;
	int carry = 0;
	for(unsigned int i = 0; i < multiplier.size(); i++) {
		string tmp_str;
		carry = 0;
		for(unsigned int j = 0; j < multiplicant.size(); j++) {
			int multiplier_i = multiplier[i] - '0';
			int multiplicant_j = multiplicant[j] - '0';
			tmp_str.push_back((multiplier_i*multiplicant_j+carry)%10 + '0');
			carry = (multiplier_i*multiplicant_j+carry)/10;
		}
		if(carry > 0){
			tmp_str.push_back(carry + '0');
		}
		reverse(tmp_str.begin(), tmp_str.end());
		for(unsigned int k = 0; k < i; k++) {
			tmp_str.push_back('0');
		}
		ret = ret + tmp_str;
	}
	reverse(ret.begin(), ret.end());
	while(ret.size() > 1&&ret.back() == '0') ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}
string operator -(string minuend, string subtrahend){
	bool negative = false;
	if(minuend < subtrahend){
		negative = true;
		swap(minuend, subtrahend);	
	}
	reverse(minuend.begin(), minuend.end());
	reverse(subtrahend.begin(), subtrahend.end());
	int diff = minuend.size() - subtrahend.size();
	for(int i = 0; i < diff; i++){
		subtrahend.push_back('0');
	}
	string ret;
	int borrow = 0;
	for(unsigned int i = 0; i < minuend.size(); i++){
		int minuend_i = minuend[i] - '0';
		int subtrahend_i = subtrahend[i] - '0';
		if(subtrahend_i + borrow > minuend_i){
			ret.push_back((minuend_i + 10 - subtrahend_i - borrow) + '0');
			borrow = 1; 
		}
		else{
			ret.push_back((minuend_i - subtrahend_i - borrow) + '0');
			borrow = 0;
		}
	}
	while(ret.size() > 1&&ret.back() == '0') ret.pop_back();
	if(negative == true){
		ret.push_back('-');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string operator /(string dividend, string divisor){
	if(divisor == "0"){
		return "in valid input";
	}
	if(divisor > dividend){
		return "0";
	}
	string tmp;
	string ret;
	for(unsigned int i = 0; i < dividend.size(); i++) {
		tmp.push_back(dividend[i]);
		if(divisor > tmp){
			ret.push_back('0');
			reverse(tmp.begin(), tmp.end());
			while(tmp.size() > 0&&tmp.back() == '0') tmp.pop_back();
		}
		else{
			int it = 0;
			while(!(tmp < (convert_int_to_string(it)*divisor))){
				it++;
			}
			it--;
			if((tmp-(convert_int_to_string(it)*divisor))>"0"){
				tmp = (tmp-(convert_int_to_string(it)*divisor));
			}
			else{
				tmp.clear();
			}
			ret.push_back(it + '0');
		}

	}
	reverse(ret.begin(), ret.end());
	while(ret.size() > 1&&ret.back() == '0') ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}
int main(){
}
