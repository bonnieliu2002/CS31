/* Name: Bonnie Liu
   ID: 005300989
   Class: CS 31 Discussion 1F
   Project 4: Array of Sunshine
   Date: 11/4/2019 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
void swap(string a[], int i, int j);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);
int rotateRight(string a[], int n, int pos);
void printArray(string a[], int n);

int main()
{	

	string empty[1] = { "" };


	string a1[5] = { "1", "2", "3", "4" };

	assert(appendToAll(a1, 3, "?") == 3 && a1[0] == "1?" && a1[1] == "2?" && a1[2] == "3?" && a1[3] == "4");

	assert(appendToAll(a1, 0, "?") == 0 && a1[0] == "1?" && a1[1] == "2?" && a1[2] == "3?" && a1[3] == "4");

	assert(appendToAll(a1, -1, "?") == -1 && a1[0] == "1?" && a1[1] == "2?" && a1[2] == "3?" && a1[3] == "4");

	assert(appendToAll(a1, 4, "") == 4 && a1[0] == "1?" && a1[1] == "2?" && a1[2] == "3?" && a1[3] == "4");

	assert(appendToAll(empty, 1, "") == 1 && empty[0] == "");


	string l1[4] = { "1", "2", "3", "4" };

	string l2[5] = { "Test", "1, 2", "abc", "tEST", "abc" };

	assert(lookup(l1, 3, "3") == 2);

	assert(lookup(l1, -1, "3") == -1);

	assert(lookup(l1, 0, "3") == -1);

	assert(lookup(l1, 4, "5") == -1);

	assert(lookup(l2, 5, "test") == -1);

	assert(lookup(l2, 5, "tEST") == 3);

	assert(lookup(l2, 5, "abc") == 2);

	assert(lookup(empty, 1, "") == 0);


	string p1[4] = { "1", "2", "3", "4" };

	string p2[5] = { "Test", "test", "c", "test", "b" };

	assert(positionOfMax(p1, 4) == 3);

	assert(positionOfMax(p1, 0) == -1);

	assert(positionOfMax(p1, -43) == -1);

	assert(positionOfMax(l1, 4) == 3);

	assert(positionOfMax(p2, 5) == 1);

	assert(positionOfMax(p2, 3) == 1);

	assert(positionOfMax(p2, 1) == 0);

	// assert(positionOfMax(empty, 1) == 0);

	string r1[4] = { "1", "2", "3", "4" };

	assert(rotateLeft(r1, 4, 1) == 1 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 0, -1) == -1 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 1, -1) == -1 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 4, 4) == -1 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 1, 0) == 0 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 3, 2) == 2 && r1[0] == "1" && r1[1] == "3" && r1[2] == "4" && r1[3] == "2");

	assert(rotateLeft(r1, 4, 0) == 0 && r1[0] == "3" && r1[1] == "4" && r1[2] == "2" && r1[3] == "1");

	assert(rotateLeft(r1, 4, 4) == -1 && r1[0] == "3" && r1[1] == "4" && r1[2] == "2" && r1[3] == "1");

	assert(rotateLeft(empty, 1, 0) == 0 && empty[0] == "");


	string c1[9] = { "1", "1", "2", "1", "4", "3", "3", "3", "111234" };

	assert(countRuns(c1, 4) == 3);

	assert(countRuns(c1, 9) == 6);

	assert(countRuns(empty, 1) == 1);

	assert(countRuns(r1, 3) == 3);


	string f1[4] = { "1", "2", "3", "4" };

	string f2[5] = { "1", "2", "3", "4", "5" };

	assert(flip(f1, 3) == 3 && f1[0] == "3" && f1[1] == "2" && f1[2] == "1" && f1[3] == "4");

	assert(flip(f1, 4) == 4 && f1[0] == "4" && f1[1] == "1" && f1[2] == "2" && f1[3] == "3");

	assert(flip(f1, 0) == 0 && f1[0] == "4" && f1[1] == "1" && f1[2] == "2" && f1[3] == "3");

	assert(flip(f2, 5) == 5 && f2[0] == "5" && f2[1] == "4" && f2[2] == "3" && f2[3] == "2" && f2[4] == "1");

	assert(flip(f2, 4) == 4 && f2[0] == "2" && f2[1] == "3" && f2[2] == "4" && f2[3] == "5" && f2[4] == "1");

	assert(flip(empty, 1) == 1 && empty[0] == "");


	string d1[4] = { "1", "2", "3", "4" };

	string d2[2] = { "1", "2" };

	string d3[5] = { "2", "4", "1", "2", "3" };

	assert(differ(d1, 3, d1, 3) == 3);

	assert(differ(d1, -332, d1, 3) == -1);

	assert(differ(d1, 0, d1, 0) == 0);

	assert(differ(d1, 0, d1, -22) == -1);

	assert(differ(d1, 1, d2, 2) == 1);

	assert(differ(d2, 2, d1, 4) == 2);

	assert(differ(d1, 4, d2, 2) == 2);

	assert(differ(d3, 5, d1, 4) == 0);

	assert(differ(empty, 1, empty, 0) == 0);


	string s1[7] = { "1", "2", "3", "4" , "4", "2", "5" };

	string s2[2] = { "4", "2" };

	string s3[3] = { "3", "4", "4" };

	assert(subsequence(s1, 7, s2, 0) == 0);

	assert(subsequence(s1, 7, s2, 1) == 3);

	assert(subsequence(s1, 7, s2, 2) == 4);

	assert(subsequence(s1, 2, s3, 3) == -1);

	assert(subsequence(s1, 4, s2, 2) == -1);

	assert(subsequence(s1, 5, s2, 2) == -1);

	assert(subsequence(s1, 7, s3, 3) == 2);

	assert(subsequence(s1, 4, s3, 3) == -1);

	assert(subsequence(empty, 1, empty, 1) == 0);

	assert(subsequence(empty, 1, empty, 0) == 0);


	string la1[7] = { "1", "2", "2", "3", "4", "5", "4" };

	string la2[3] = { "2", "2", "1" };

	string la3[2] = { "test", "4" };

	assert(lookupAny(la1, 7, la2, 3) == 0);

	assert(lookupAny(la1, 7, la2, 2) == 1);

	assert(lookupAny(la1, 7, la2, 0) == -1);

	assert(lookupAny(la1, 1, la2, 2) == -1);

	assert(lookupAny(la1, 7, la3, 2) == 4);

	assert(lookupAny(la1, 7, la3, 1) == -1);

	assert(lookupAny(la1, 4, la3, 2) == -1);

	assert(lookupAny(empty, 1, empty, 0) == -1);


	string se1[4] = { "1", "2", "3", "4" };

	assert(separate(se1, 4, "5") == 4 && se1[0] < "5" && se1[1] < "5" && se1[2] < "5" && se1[3] < "5");

	string se2[4] = { "1", "2", "3", "4" };

	assert(separate(se2, 4, "22") == 2 && se2[0] < "22" && se2[1] < "22" && se2[2] > "22" && se2[3] > "22");

	string se3[3] = { "1", "2", "3" };

	assert(separate(se3, 3, "2") == 1 && se3[0] < "2" && se3[1] >= "2" && se3[2] >= "2");

	string se4[8] = { "1", "test", "TeSt", "3", "a", "b", "4", "4test" };

	assert(separate(se4, 8, "4") == 2 && se4[0] < "4" && se4[1] < "4" && se4[2] >= "4" && se4[3] >= "4");

	string se5[8] = { "1", "test", "TeSt", "3", "a", "b", "4", "4test" };

	assert(separate(se5, 8, "separator") == 7 && se5[0] < "separator" && se5[1] < "separator" && se5[6] < "separator" && se5[7] >= "separator");

	assert(separate(empty, 1, "") == 0);

	assert(separate(empty, 0, "eeee") == 0);

	assert(separate(empty, -59, "eeee") == -1);

	cout << "All tests succeeded!" << endl;
	/*
	string g[4] = { "mick", "marie", "lindsey", "nancy" };
	assert(appendToAll(g, 0, "?") == 0 && g[0] == "mick" && g[3] == "nancy");
	assert(appendToAll(g, 2, "?") == 2 && g[0] == "mick?" && g[3] == "nancy");
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "mick??" && g[3] == "nancy?");

	string h[6] = { "donald", "lindsey", "mike", "adam", "nancy", "donald" };
	assert(lookup(h, 6, "lindsey") == 1);
	assert(lookup(h, 2, "adam") == -1);
	assert(lookup(h, 6, "andy") == -1);
	assert(lookup(h, 0, "lindsey") == -1);
	assert(lookup(h, 6, "donald") == 0);

	string j[4] = { "marie", "rudy", "fiona", "adam" };
	assert(positionOfMax(j, 4) == 1);
	string i[5] = { "marie", "rudy", "rudy", "fiona", "adam" };
	assert(positionOfMax(i, 5) == 1);
	assert(positionOfMax(i, 0) == -1);

	string k[4] = { "donald", "lindsey", "mike", "adam" };
	assert(rotateLeft(k, 4, 1) == 1 && k[1] == "mike" && k[3] == "lindsey");
	assert(rotateLeft(k, 0, 1) == -1 && k[1] == "mike" && k[3] == "lindsey");

	string l[6] = { "marie", "marie", "rudy", "fiona", "adam", "adam" };
	assert(countRuns(l, 6) == 4);
	string m[4] = { "marie", "rudy", "fiona", "adam" };
	assert(countRuns(m, 4) == 4);
	string n[1] = { "marie" };
	assert(countRuns(n, 1) == 1);
	//string o[0] = {};
	//assert(countRuns(o, 0) == 0);

	string folks[7] = { "adam", "", "fiona", "mike", "rudy", "nancy", "donald" };
	assert(flip(folks, 5) == 5 && folks[0] == "rudy" && folks[2] == "fiona");
	string folk[7] = { "adam", "", "fiona", "mike", "rudy", "nancy", "donald" };
	assert(flip(folk, 4) == 4 && folk[0] == "mike" && folk[2] == "");
	assert(flip(folk, 0) == 0 && folk[0] == "mike" && folk[2] == "");

	string p[7] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey" };
	string q[4] = { "mick", "marie", "lindsey", "nancy" };
	assert(differ(p, 4, q, 4) == 2);
	assert(differ(p, 4, q, 1) == 1);
	assert(differ(p, 4, q, 0) == 0);

	string r[11] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey", "fiona", "rudy", "", "gordon" };
	string s[4] = { "fiona", "rudy", "", "gordon" };
	string t[2] = { "hello", "world" };
	assert(subsequence(r, 7, s, 4) == 2);
	assert(subsequence(r, 11, s, 4) == 2);
	assert(subsequence(r, 7, t, 2) == -1);
	assert(subsequence(r, 7, t, 0) == 0);

	string v[3] = { "lindsey", "fiona", "mike" };
	string w[3] = { "hello", "world", "CS" };
	assert(lookupAny(p, 7, v, 3) == 2);
	assert(lookupAny(p, 7, w, 3) == -1);
	assert(lookupAny(p, 7, w, 0) == -1);

	string x[7] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey" };
	assert(separate(x, 7, "lindsey") == 3);
	string y[7] = { "mick", "mick", "fiona", "rudy", "fiona", "gordon", "lindsey" };
	assert(separate(y, 7, "fiona") == 0);
	string z[7] = { "mick", "mick", "fiona", "rudy", "fiona", "gordon", "lindsey" };
	assert(separate(z, 7, "hello") == 3);
	string aa[7] = { "mick", "mick", "fiona", "rudy", "fiona", "gordon", "lindsey" };
	assert(separate(aa, 7, "zebra") == 7);
	string ab[7] = { "mick", "mick", "fiona", "rudy", "fiona", "gordon", "lindsey" };
	assert(separate(ab, 7, "apple") == 0);
	string ac[7] = { "mick", "mick", "fiona", "rudy", "fiona", "gordon", "lindsey" };
	assert(separate(ac, 7, "rudy") == 6);

	cout << "All tests succeeded" << endl;
	
	*/
	
	
	
	/*string h[7] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey" };
	string g[4] = { "mick", "marie", "lindsey", "nancy" };
	string e[4] = { "fiona", "rudy", "", "gordon" };
	string d[5] = { "marie", "marie", "marie", "rudy", "rudy" };
	string f[3] = { "lindsey", "fiona", "mike" };
	string empty[2] = { "", "" };
	string a[6] = { "angelina", "andy", "argentina", "accomplice", "boston", "arthur" };
	assert(appendToAll(h, -4, "brandon") == -1); // bad argument: negative array size
	assert(appendToAll(h, 0, "demarcus") == 0); // n is 0
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "mick?" && g[3] == "nancy?");
	// checks if appendToAll works properly for other cases
	assert(lookup(e, -2, "fiona") == -1); // bad argument: negative array size
	assert(lookup(e, 4, "Fiona") == -1); // “Fiona” is not an element of array e
	assert(lookup(e, 4, "fiona") == 0); // “fiona” is the first element of the array e
	assert(lookup(e, 4, "gordon") == 3); // “gordon” is the 4th element of the array e
	assert(lookup(e, 4, "") == 2); // “” is the 3rd element of the array e
	assert(positionOfMax(d, -3) == -1); // bad argument: negative array size
	assert(positionOfMax(d, 0) == -1); // no interesting elements to examine
	assert(positionOfMax(d, 5) == 3);
	// 3 is the smallest position of the string that is >= every string in the array
	assert(positionOfMax(empty, 2) == -1); // no interesting elements in array
	assert(rotateLeft(a, -2, 1) == -1); // bad argument: negative array size
	assert(rotateLeft(a, 0, 3) == -1); // bad argument: array with no elements of interest
	assert(rotateLeft(a, 5, 8) == -1); // bad argument: position is greater than number of elements in array
	assert(rotateLeft(a, 6, -4) == -1); // bad argument: position is less than 0
	assert(rotateLeft(h, 7, 6) == 6 && h[6] == "lindsey" && h[0] == "mick"); // doesn’t change array
	assert(rotateLeft(h, 7, 0) == 0 && h[0] == "marie" && h[6] == "mick" && h[3] == "");
	// checks if rotateLeft works properly for other cases
	assert(countRuns(d, -7) == -1); // bad argument: position is less than 0
	assert(countRuns(d, 0) == 0); // no runs because empty array
	assert(countRuns(d, 5) == 2); // consecutive runs for 2 different strings
	assert(countRuns(a, 6) == 6); // just another example
	assert(flip(h, -5) == -1); // bad argument: negative array size
	assert(flip(h, 0) == 0); // empty array, so returns size of array, which is 0
	assert(flip(e, 4) == 4 && e[0] == "gordon" && e[2] == "rudy"); // flip array with an even-numbered size
	assert(flip(d, 5) == 5 && d[0] == "rudy" && d[4] == "marie"); // flip array with an odd-numbered size
	assert(differ(a, -4, d, 2) == -1); // bad argument: negative array size
	assert(differ(a, 2, d, -2) == -1); // bad argument: negative array size
	string folks[7] = { "adam", "", "fiona", "mike", "rudy", "nancy", "donald" };
	string group[6] = { "adam", "", "fiona", "donald", "mike", "rudy" };
	assert(differ(folks, 7, group, 6) == 3); // returns position where the arrays have different elements
	assert(differ(folks, 2, group, 3) == 2); // one array runs out of elements first, so return size of that array
	assert(differ(folks, 7, a, 4) == 0); // arrays have different first element
	assert(subsequence(a, -4, d, 2) == -1); // bad argument: negative array size
	assert(subsequence(a, 4, d, -2) == -1); // bad argument: negative array size
	assert(subsequence(a, 4, d, 0) == 0); // sequence of 0 elements is subsequence of any sequence starting at position 0
	assert(subsequence(a, 1, d, 2) == -1); // d cannot be a subsequence of a if d has more elements than a
	string names[10] = { "gordon", "marie", "nancy", "mick", "adam", "lindsey" };
	string names1[10] = { "marie", "nancy", "mick" };
	assert(subsequence(names, 6, names1, 3) == 1); // subsequence function returns first position where names1 is subsequence of names
	string names2[10] = { "gordon", "mick" };
	assert(subsequence(names, 5, names2, 2) == -1); // names2 is not a subsequence of names, so returns -1
	assert(lookupAny(a, -4, d, 2) == -1); // bad argument: negative array size
	assert(lookupAny(a, 4, d, -2) == -1); // bad argument: negative array size
	string set1[10] = { "donald", "adam", "mick", "marie" };
	assert(lookupAny(names, 6, set1, 4) == 1); // "marie" is found in names at position 1, so returns 1
	string set2[10] = { "rudy", "fiona" };
	assert(lookupAny(names, 6, set2, 2) == -1); // "rudy" and "fiona" do not appear in the array names at all, so return -1
	assert(separate(a, -2, "hi") == -1); // bad argument: negative array size
	string persons[6] = { "donald", "lindsey", "marie", "rudy", "fiona", "adam" };
	assert(separate(persons, 6, "gordon") == 3); // elements before position 3 are now less than "gordon" while elements after 3 are greater than "gordon"
	string persons2[4] = { "marie", "nancy", "lindsey", "mike" };
	assert(separate(persons2, 4, "mike") == 2);  // elements before position 2 are now less than "mike" while elements after 2 are greater than "mike"
	assert(separate(persons, 6, "zoo") == 6); // no elements are >= "zoo", so return array size
	
	cout << "All tests succeeded" << endl;
	*/
}

int appendToAll(string a[], int n, string value)
{
	// returns -1 if a negative array size is passed
	if (n < 0)
	{
		return -1;
	}
	// adds string value to all items in array a
	for (int i = 0; i < n; i++)
	{
		a[i] += value;
	}
	return n;
}

int lookup(const string a[], int n, string target)
{
	// returns -1 if a negative array size is passed
	if (n < 0)
	{
		return -1;
	}
	// looks for target in array a and returns index of where the target first appears
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target)
		{
			return i;
		}
	}
	return -1;
}

int positionOfMax(const string a[], int n)
{
	// returns -1 if a negative array size is passed or if array size is 0
	if (n <= 0)
	{
		return -1;
	}
	// checks if array a has interesting elements
	bool hasInterestingElements = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != "")
		{
			hasInterestingElements = true;
		}
	}
	// if there are interesting elements, find string with greatest value
	if (hasInterestingElements)
	{
		int k = 0;
		string temp = a[0];
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= a[k] && a[i] > temp)
			{
				k = i;
				temp = a[k];
			}
		}
		return k;
	}
	// if there are no interesting elements, return -1
	else
	{
		return -1;
	}
}

int rotateLeft(string a[], int n, int pos)
{
	// returns -1 if a negative array size is passed or if position is out of bounds
	if (n <= 0 || pos >= n || pos < 0)
	{
		return -1;
	}
	// store original value of a at position pos in a temporary string
	string temp = a[pos];
	// shift every array element after pos to the left
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	// set the last value of the array to original value of a at position pos
	a[n - 1] = temp;
	return pos;
}

int countRuns(const string a[], int n)
{
	// returns -1 if a negative array size is passed
	if (n < 0)
	{
		return -1;
	}
	// empty array, so no runs
	if (n == 0)
	{
		return 0;
	}
	int count = 1;
	for (int i = 0; i < n - 1; i++)
	{
		// if two consecutive elements are different, increase count by one
		if (a[i] != a[i + 1])
		{
			count++;
		}
	}
	return count;
}

int flip(string a[], int n)
{
	// returns -1 if a negative array size is passed
	if (n < 0)
	{
		return -1;
	}
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		swap(a, i, j);
		i++;
		j--;
	}
	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	// returns -1 if a negative array size is passed
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}
	// find smaller array size
	int k;
	if (n1 < n2)
	{
		k = n1;
	}
	else
	{
		k = n2;
	}
	// compares elements of the array and returns position where elements are different
	for (int i = 0; i < k; i++)
	{
		if (a1[i] != a2[i])
		{
			return i;
		}
	}
	// elements are all the same up to position k, so return size of smaller array
	return k;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	// returns -1 if a negative array size is passed
	if (n1 < 0 || n2 < 0 || n2 > n1)
	{
		return -1;
	}
	// returns 0 if array size is 0
	if (n2 == 0)
	{
		return 0;
	}
	// check if a2 is in a1
	for (int i = 0; i <= n1 - n2; i++)
	{
		bool isSubsequence = false;
		if (a1[i] == a2[0])
		{
			isSubsequence = true;
			for (int j = 1; j < n2; j++)
			{
				if (a1[i + j] != a2[j])
				{
					isSubsequence = false;
				}
			}
		}
		if (isSubsequence == true)
		{
			return i;
		}
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	// returns -1 if a negative array size is passed
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}
	// checks if each element of a1 is one of the elements in a2
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j])
			{
				return i;
			}
		}
	}
	return -1;
}

int separate(string a[], int n, string separator)
{
	// returns -1 if a negative array size is passed
	if (n < 0)
	{
		return -1;
	}
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		if (a[i] > separator && a[j] < separator)
		{
			swap(a, i, j);
			i++;
			j--;
		}
		else if (a[i] > separator)
		{
			rotateLeft(a, n, i);
			j = j - 2;
		}
		else if (a[j] < separator)
		{
			rotateRight(a, n, j);
			i = i + 2;
		}
		else
		{
			i++;
		}
	}
	// array should be ordered properly; now we traverse loop to find first element where a[i] is >= separator; return that position
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= separator)
		{
			return i;
		}
	}
	return n;
}

int rotateRight(string a[], int n, int pos)
{
	// returns -1 if a negative array size is passed or if position is out of bounds
	if (n < 0 || pos >= n || pos < 0)
	{
		return -1;
	}
	string temp = a[pos];
	for (int i = pos; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = temp;
	return pos;
}

void swap(string a[], int i, int j)
{
	// swaps two values in an array
	string temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void printArray(string a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}