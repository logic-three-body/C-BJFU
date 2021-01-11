#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool cmp(string& a, string& b) {
	return a > b; //按字典序从小到大排列 
}
int main()
{
	vector<string>v;
	string s;
	int n;
	cin >> n;
	//string s[n];
	
	for (int i = 0; i < n; i++)
	{
	cin >> s;
	sort(s.begin(), s.end());
	v.push_back(s);
	//v.insert(v.begin(), s);
	}
	//sort(v.begin(),v.end(), cmp);
	sort(v.begin(), v.end(), greater<string>());
	

	for (int i = 0; i < v.size(); i++)
	{
		
		if (i == v.size() - 1)
			cout << v[i];
		else
			cout << v[i] << endl;
		
	}
	
	return 0;
}