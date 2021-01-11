#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class TableTennisPlayer {

private:

	string firstname;

	string lastname;

	bool hasTable;

public:

	TableTennisPlayer(const string &, const string &, bool);

	string FirstName() const;

	string LastName() const;

	bool HasTable() const;

};

TableTennisPlayer::TableTennisPlayer(const string & a, const string & b, bool c):firstname(a),lastname(b),hasTable(c)
{

}

string TableTennisPlayer::FirstName() const
{
	return firstname;
}

string TableTennisPlayer::LastName() const
{
	return lastname;
}

bool TableTennisPlayer::HasTable() const
{
	return hasTable;
}

class RatedPlayer :public TableTennisPlayer
{
private:
	int rates;
public:
	RatedPlayer(int num,const string & a, const string & b, bool c);
	int Rating();
};

RatedPlayer::RatedPlayer(int num, const string & a, const string & b, bool c):rates(num),TableTennisPlayer(a,b,c)
{
}

int RatedPlayer::Rating()
{
	return rates;
}

int main() {

	string firstname, lastname;

	bool hasTable;

	int rating;

	char flag;

	while (cin >> flag) {

		if (flag == 'T') {

			cin >> firstname >> lastname >> hasTable;

			TableTennisPlayer tp(firstname, lastname, hasTable);

			if (tp.HasTable())

				cout << tp.FirstName() << " " << tp.LastName() << " has a table.\n";

			else

				cout << tp.FirstName() << " " << tp.LastName() << " hasn't a table.\n";

		}
		else if (flag == 'R') {

			cin >> firstname >> lastname >> hasTable >> rating;

			RatedPlayer rp(rating, firstname, lastname, hasTable);

			if (rp.HasTable())

				cout << rp.FirstName() << " " << rp.LastName() << " has a table. The rating is " << rp.Rating() << ".\n";

			else

				cout << rp.FirstName() << " " << rp.LastName() << " hasn't a table. The rating is " << rp.Rating() << ".\n";

		}

	}

	return 0;

}
