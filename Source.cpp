#include<iostream>
#include <vector>
using namespace std;

vector<int> readMesage() {
	std::cout << "Enter the message: ";

	vector<int> message;
	string stringMessage;

	cin >> stringMessage;
	for (size_t i = 0; i < stringMessage.size(); i++) {
		char substring = stringMessage.at(i);


		message.push_back(int(substring) - '0');
	}
	std::cout << "The message is: " << endl;
	for (int i : message) {
		std::cout << i;
	}
	std::cout << endl;
	return message;

}
int XOR(int a, int b) {
	if (a == b) return 0;
	else return 1;
}
vector<int> readPolynom() {
	std::cout << "Enter the generator polynom: ";

	vector<int> polynom;
	string stringPolynom;

	cin >> stringPolynom;
	for (size_t i = 0; i < stringPolynom.size(); i++) {
		char substring = stringPolynom.at(i);


		polynom.push_back(int(substring) - '0');
	}
	std::cout << "The generator polynom is: " << endl;
	for (int i : polynom) {
		std::cout << i;
	}
	std::cout << endl;
	return polynom;

}
bool verifyBytes(vector<int>& message) {
	for (int i : message) {
		if ((i != 1) && (i != 0)) return false;
	}
	return true;
}
bool validationPolynom(vector<int>& polynom) {
	if ((verifyBytes(polynom)) && (polynom[0] == 1) && (polynom[polynom.size()] == 1)) return true;
	return false;
}
bool verifyDimension(vector<int>& message) {
	if (message.size() % 7 == 0) return true;
	return false;

}


vector<int> getExtendedMessage(vector<int>& message, vector<int>& polynom) {

	for (int i = 0; i < polynom.size() - 1; i++) {
		message.push_back(0);
	}
	std::cout << "Extented message: ";
	for (int i = 0; i < message.size(); i++) {
		std::cout << message[i];
	}
	std::cout << endl;
	return message;


}
void getFinalMessage(vector<int>& extendedMessage, vector<int>& r) {
	vector<int> finalMessage;
	for (int i = 0; i < extendedMessage.size() - 2;i++) {
		finalMessage.push_back(extendedMessage[i]);
	}
	int contor = 0;
	for (int j = extendedMessage.size() - 2; j < extendedMessage.size(); j++) {
		finalMessage.push_back(XOR(r[contor], extendedMessage[j]));
		contor++;
	}

	for (int i = 0; i < finalMessage.size(); i++) {
		std::cout << finalMessage[i];
	}

}
//int VectorToInt(vector<int> v)
//{
//	reverse(v.begin(), v.end());
//	int decimal = 1;
//	int total = 0;
//	for (auto& it : v)
//	{
//		total += it * decimal;
//		decimal *= 10;
//	}
//	return total;
//}
vector<int> getR(vector<int>& extendedMessage, vector<int>& c) {

	vector<int> currentResult = extendedMessage;
	vector<int> partialResult;
	vector<int> result;

	while (currentResult.size() > c.size()) {
		for (int i = 0; i < c.size(); i++) {

			partialResult.push_back(XOR(currentResult[i], c[i]));

		}
		for (int i = c.size(); i < currentResult.size(); i++) {
			partialResult.push_back(currentResult[i]);
		}
		int contor = 0;
		for (int i = 0; i < partialResult.size(); i++) {
			if (partialResult[i] == 0)contor++;
			else break;
			
		}
		for (int j = contor; j < partialResult.size(); j++) {
			result.push_back(partialResult[j]);
		}
		/*if (result.size() == c.size()) {
			currentResult = result;
			break;
		}*/
		std::cout << "Current Result: ";
		currentResult = result;

		for (int p : result) {
			std::cout << p;
		}

		std::cout << endl;
		partialResult.clear();
		result.clear();
	}
	std::cout << "R is: ";
	for (int i = 0; i < currentResult.size(); i++) {
		std::cout << currentResult[i];
	}
	std::cout << endl;
	return currentResult;
}




int main() {
	vector<int> message;
	
	vector<int> polynom;
	message = readMesage();
	polynom = readPolynom();
	//if (verifyDimension(message) && verifyBytes(message) && validationPolynom(polynom)) {
		vector<int> extendedMessage = getExtendedMessage(message, polynom);
		vector<int> r = getR(extendedMessage, polynom);
		getFinalMessage(extendedMessage, r);
	//}
	return 0;
}
