//Mariah Diaz
//CIS 3501
//Fall 2019
//Prof. John P. Baugh
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//Function prototypes - Fleshed out functions are found after int main()
int countRepeats(vector<int> cnt);
bool checkForAnagram(string str1, string str2);
void deleteElement(vector<int>& values, int val);

int main()
{
	int count, amountClassification;
	vector<string>words;
	vector<int>wordsCount;
	string word;
	
	ifstream in("words.txt");
	
	//if the file cannot be  found/opened
	if (!in) {
		cout << "File not found!!!" << endl;
		exit(0);
	}

	//Read in the first line of the file
	in >> count >> amountClassification;

	//Load the words from the file into a vector to be used
	for (int i = 0; i < count; i++) {
		in >> word;
		words.push_back(word);
		wordsCount.push_back(word.length());
	}
	
	in.close();

	//The following loops are for the number classes words will be
	//classified in

	int j = 0;
	
	while (j < amountClassification) {

		vector<string>classification;
		int cnt = countRepeats(wordsCount);
		for (int i = 0; i < count; i++) {
			if (words[i].size() == cnt) {
				classification.push_back(words[i]);
			}
		}

		if (classification.size() == 2 && classification.size() <= amountClassification) {
			if (checkForAnagram(classification[0], classification[1])) {
				cout << "Class of size " << classification.size() << ": ";
				for (int i = 0; i < classification.size(); i++) {
					cout << classification[i] << " ";
				}
				cout << endl;
			}
			else {
				cout << "Class of size " << classification.size() - 1 << ": " << classification[0] << endl;
				j++;
				if (j < amountClassification) {
					cout << "Class of size " << classification.size() - 1 << ": " << classification[1] << endl;
				}
			}

		}
		
		else {
			
			//The following will placed matched anagrams together
			vector<string>match;
			match.push_back(classification[0]);
			for (int i = 1; i < classification.size(); i++) {
				if (checkForAnagram(classification[0], classification[i])) {
					if (!std::count(match.begin(), match.end(), classification[i])) {
						match.push_back(classification[i]);
					}
				}
			}

			if (match.size() <= amountClassification) {
				sort(match.begin(), match.end());
				cout << "Class of size " << match.size() << ": ";
				for (int i = 0; i < match.size(); i++) {
					cout << match[i] << " ";
				}
				cout << endl;
			}
			deleteElement(wordsCount, cnt);
			match.clear();
		}
		classification.clear();
		j++;
	}

	system("pause");
}

//The following function gets the values for repeated length words
//Its input is the vector of words from the file, but it does not output
//any data - it is a simple getter function, getting the frequencies
//of which anagrams appear in the file (counting how many anagrams for each word)
int countRepeats(vector<int> cnt) {

	sort(cnt.begin(), cnt.end());
	int max = 1, result = cnt[0], cur = 1;

	//The following gets the values of the lengths that
	//show up/are counted the most
	for (int i = 1; i < cnt.size(); i++) {
		if (cnt[i] == cnt[i - 1])
			cur++;
		else {
			if (cur > max) {
				max = cur;
				result = cnt[i - 1];
			}
			cur = 1;
		}
	}
	if (cur > max)
	{
		max = cur;
		result = cnt[cnt.size() - 1];
	}
	return result;
}
//The following function checks if two words are anagrams
//Its input are two strings from the vector/file to be compared
//The function does not have output. It either returns true or false
//depending on if the words in question are indeed anagrams
bool checkForAnagram(string str1, string str2) {
	if (str1.length() != str2.length())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	for (int i = 0; i < str1.length(); i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}
//The following function deletes values in the vector that have already
//been accounted for. Its imput is a pointer to the word in the vector and 
//its position. It simply goes through the vector and clears up the memory after
//the anagrams have been found and placed in their specific classifications
void deleteElement(vector<int>& values, int val) {
	int i = 0;
	while (i < values.size()) {
		if (values[i] == val) {
			values.erase(values.begin() + i);
		}
		else {
			i++;
		}

	}
}