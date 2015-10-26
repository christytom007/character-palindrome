/*
This program checks whether given string is palindrome or not

...........Created By, Christy Thomas & Parthiv Varma.........

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

char s[100000];
int length,count_1=0;
bool check = false,status=false;

void read_word(int max)
// read at most max–1 characters from is into buffer
{
	char c;
	for (int i = 0;; i++)
	{
		c=getchar();
		if (c == ' ' || c == '\n' || c == '\t')break;
		s[i] = c;
	}
}

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
	count_1++;
	int first = 0;                               // index of first letter
	int last = n-1;                           // index of last letter
	while (first < last)
	{						                  // we haven’t reached the middle
		if (s[first] != s[last]) return false;
		++first;                           // move forward
		--last;                            // move backward
	}
	return true;
}


void swap(int x, int y)
{
	int temp = s[x];
	s[x] = s[y];
	s[y] = temp;

	return;
}

void printArray(int size)
{
	int i;

	for (i = 0; i<size; i++)
		std::cout << s[i] << " ";

	std::cout << std::endl;

	return;
}

//Permutation
void permute(int k, int size)
{
	int i;
	if (!status)
	{
		if (k == 0)
		{
			//printArray(size);
			check = is_palindrome(s, strlen(s));
			if (check)status = true;
		}
		else
		{
			for (i = k - 1; i >= 0; i--)
			{
				swap(i, k - 1);
				permute(k - 1, size);
				swap(i, k - 1);
			}
		}
	}
	return;
}

//Main
int main(int argc, const char * argv[])
{
	int max = 100000;
	read_word(max);
	length = strlen(s);
	cout <<"LENGTH :"<< length << endl;
	//cout << "YES" << endl;
	permute(length, length);
	if (status == true)
		cout << "YES"<<endl;
	else
		cout << "NO"<<endl;
	cout << "COUNT :" << count_1 << endl;
	getchar();
	return 0;
}