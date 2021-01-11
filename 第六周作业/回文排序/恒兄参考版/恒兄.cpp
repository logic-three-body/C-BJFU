#include"iostream"
#include"string"
using namespace std;
bool back(string s);
void print(string* S, int num);
int main()
{
	int num;
	cin >> num;
	int i, j;
	string *S = new string[num];
	string* S2 = new string[num];
	for (i = 0; i < num; i++)
		cin >> S[i];
	for (i = 0, j = 0; i < num; i++)
	{
		if (back(S[i])) {
			S2[j] = S[i];
		//	cout << S2[j] << endl;
			j++;
			
		}
	}
	print(S2, j);
}

bool back(string s)
{
	int i;
	int mid = s.length() / 2;
	for (i = 0; i <= mid; i++)
	{
		if (s[i] != s[s.length() - i - 1])return false;
	}
	return true;
}
void print(string* S, int num)
{
	int i, j;
	string temp;
	for (i = 0; i < num - 1; i++)
	{
		for (j = num - 1; j > i; j--)
		{
			if (S[j].length() < S[j - 1].length()) {
				temp = S[j];
				S[j] = S[j - 1];
				S[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		cout << S[i] << endl;
	}
}