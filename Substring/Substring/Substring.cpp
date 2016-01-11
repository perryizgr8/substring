// Substring.cpp : Defines the entry point for the console application.
// Enter 1, abcda, 1, dba. Output should be 3.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int numOccur(string, string);
bool compareFreq(string, string);

int main()
{
	int result = 0;
	int testCases = 0;
	int numQueries = 0;
	string text;
	string query;
	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		cin >> text;
		cin >> numQueries;
		for (int j = 0; j < numQueries; j++)
		{
			cin >> query;
			result = numOccur(text, query);
			cout << result << endl;
		}
	}
	return 0;
}

int numOccur(string text, string pattern)
{
	//cout << "i was called! text:" << text << " patt:" << pattern << endl;
	int res = 0, start = 0, end = 0;
	int patLength = pattern.length();
	int textLength = text.length();
	for (int i = 0; i <= (textLength - patLength); i++)
	{
		for (int j = patLength; j <= textLength - i; j++)
		{
			if (compareFreq(pattern, text.substr(i, j)) == true)
			{
				res++;
			}
		}
	}
	return res;
}

bool compareFreq(string one, string two)
{
	char count1[256] = { 0 }, count2[256] = { 0 };
	int length1 = one.length();
	int length2 = two.length();
	for (int i = 0; i < length1; i++)
	{
		(count1[one[i]])++;
	}
	for (int i = 0; i < length2; i++)
	{
		(count2[two[i]])++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (count1[i] > count2[i])
		{
			return false;
		}
	}
	return true;
}