#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
int max(int arr[], int size)
{
	int ind = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[ind] < arr[i])
		{
			ind = i;
		}
	}
	return ind;
}

int batting(int ind)
{
	if (ind >= 0 && ind < 5)
	{
		int probability = rand() % 10;
		if (probability == 9)
		{
			return -1;
		}
		else
		{
			int add = rand() % 7;
			return add;
		}
	}
	else
	{
		int probabality = rand() % 2;
		if (probabality == 0)
		{
			return -1;
		}
		else if (probabality == 1)
		{
			int add = rand() % 7;
			return add;
		}
	}
}

bool isWide()
{
	int probability = (rand() % 10) + 1;
	if (probability == 10)
	{
		return true;
	}
	return false;
}

bool isNoBall()
{
	int probability = (rand() % 10) + 1;
	if (probability == 10)
	{
		return true;
	}
	return false;
}

double getRunRate(int r, int b)
{
	if (r == 0)
	{
		return 0.0;
	}
	double rr = (double(r) / b) * 6;
	return rr;
}

double getEcon(int r, int o, int b)
{
	if (r == 0)
	{
		return 0.0;
	}
	int balls = (o * 6) + b;
	double econ = (double(r) / balls) * 6;
	return econ;
}

double getStrikeRate(int r, int b)
{
	if (r == 0)
	{
		return 0.0;
	}
	double sk = (double(r) / b) * 100;
	return sk;
}

int numberOfWickets(bool out[])
{
	int count = 0;
	for (int i = 0; i < 11; i++)
	{
		if (out[i])
		{
			count++;
		}
	}
	return count;
}

void bowlingBoard(string names[], int o[], int bb[], int rg[], int w[], int m[], int ov, int wd[], int nb[])
{
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << left << setw(40) << "BOWLING" << left << setw(7) << "O" << left << setw(7) << "M" << left << setw(7) << "R" << left << setw(7) << "W" << left << setw(8) << "ECON" << left << setw(7) << "WD" << left << setw(7) << "NB" << endl;
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	if (ov < 5)
	{
		for (int i = 0; i < ov + 1; i++)
		{
			cout << left << setw(40) << names[11 - i] << o[i] << "." << left << setw(5) << bb[i] << left << setw(7) << m[i] << left << setw(7) << rg[i] << left << setw(7) << w[i] << left << setw(8) << fixed << showpoint << setprecision(2) << getEcon(rg[i], o[i], bb[i]) << left << setw(7) << wd[i] << left << setw(7) << nb[i] << endl;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			cout << left << setw(40) << names[11 - i] << o[i] << "." << left << setw(5) << bb[i] << left << setw(7) << m[i] << left << setw(7) << rg[i] << left << setw(7) << w[i] << left << setw(8) << fixed << showpoint << setprecision(2) << getEcon(rg[i], o[i], bb[i]) << left << setw(7) << wd[i] << left << setw(7) << nb[i] << endl;
		}
	}
}

void battingBoard(string names[], bool out[], int rs[], int bf[], int f[], int s[], int w, int on, int off)
{
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << left << setw(60) << "BATTING" << left << setw(5) << "R" << left << setw(5) << "B" << left << setw(5) << "4s" << left << setw(7) << "6s" << "SR" << endl;
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	if (w >= 0 && w < 10)
	{
		for (int i = 0; i < w + 2; i++)
		{
			if (i == on)
			{
				string temp = names[i + 1] + '*';
				cout << left << setw(40) << temp << left << setw(20) << "Not Out" << left << setw(5) << rs[i] << left << setw(5) << bf[i] << left << setw(5) << f[i] << left << setw(7) << s[i] << fixed << showpoint << setprecision(2) << getStrikeRate(rs[i], bf[i]) << endl;
			}
			else
			{
				if (out[i] == 1)
				{
					cout << left << setw(40) << names[i + 1] << left << setw(20) << "Out" << left << setw(5) << rs[i] << left << setw(5) << bf[i] << left << setw(5) << f[i] << left << setw(7) << s[i] << fixed << showpoint << setprecision(2) << getStrikeRate(rs[i], bf[i]) << endl;
				}
				else
				{
					cout << left << setw(40) << names[i + 1] << left << setw(20) << "Not Out" << left << setw(5) << rs[i] << left << setw(5) << bf[i] << left << setw(5) << f[i] << left << setw(7) << s[i] << fixed << showpoint << setprecision(2) << getStrikeRate(rs[i], bf[i]) << endl;
				}
			}
		}
	}
	else if (w == 10)
	{
		for (int i = 0; i < 11; i++)
		{
			if (out[i])
			{
				cout << left << setw(40) << names[i + 1] << left << setw(20) << "Out" << left << setw(5) << rs[i] << left << setw(5) << bf[i] << left << setw(5) << f[i] << left << setw(7) << s[i] << fixed << showpoint << setprecision(2) << getStrikeRate(rs[i], bf[i]) << endl;
			}
			else
			{
				string temp = names[i + 1] + '*';
				cout << left << setw(40) << temp << left << setw(20) << "Not Out" << left << setw(5) << rs[i] << left << setw(5) << bf[i] << left << setw(5) << f[i] << left << setw(7) << s[i] << fixed << showpoint << setprecision(2) << getStrikeRate(rs[i], bf[i]) << endl;
			}
		}
	}
}

int getTotalScore(int rs[], int wd[], int nb[])
{
	int score = 0;
	for (int i = 0; i < 11; i++)
	{
		score += rs[i];
	}
	for (int i = 0; i < 5; i++)
	{
		score += wd[i];
		score += nb[i];
	}
	return score;
}

double oversBowled(int o[], int b[])
{
	int ov = 0, bl = 0;
	for (int i = 0; i < 5; i++)
	{
		ov += o[i];
		bl += b[i];
	}
	double overs = ov + double(bl) / 10;
	return overs;
}

int getBalls(int o[], int bb[])
{
	int balls = 0;
	for (int i = 0; i < 5; i++)
	{
		balls += bb[i];
	}
	for (int i = 0; i < 5; i++)
	{
		balls += (6 * o[i]);
	}
	return balls;
}

void batterScoreCard(string name, int r, int b)
{
	cout << name << " is OUT!!" << "\t" << r << "/" << b << "  (SR: " << fixed << showpoint << setprecision(2) << getStrikeRate(r,b) << ")" << endl;
}

void fallOfWickets(string names[], int scor[], double ovrs[], int wiks)
{
	cout << "Fall of wickets: ";
	int count = 0;
	for (int i = 0; i < wiks; i++)
	{
		if (i == wiks - 1)
		{
			cout << i + 1 << "-" << scor[i] << " (" << names[i] << ", " << fixed << showpoint << setprecision(1) << ovrs[i] << " ov)";
		}
		else
		{
			cout << i + 1 << "-" << scor[i] << " (" << names[i] << ", " << fixed << showpoint << setprecision(1) << ovrs[i] << " ov), ";
		}
		count++;
		if (count == 2)
		{
			count = 0;
			cout << endl;
		}
	}
	cout << endl;
}

void drawScoreCard(string t1[], string t2[], int rs[], int rg[], int bf[], int bb[], int w[], int o[], int f[], int s[], bool out[], int m[], int on, int off, int wk, int ov, int wd[], int nb[], int wikSc[], double wikOv[], string playerWik[])
{
	battingBoard(t1, out, rs, bf, f, s, wk, on, off);
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	int ts = getTotalScore(rs,wd,nb);
	double overs = oversBowled(o, bb);
	int balls = getBalls(o, bb);
	double rr = getRunRate(ts, balls);
	cout << left << setw(40) << "TOTAL" << fixed << showpoint << setprecision(1) << overs << " Ov (RR: " << fixed << showpoint << setprecision(2) << rr << ")" << right << setw(20) << ts << endl;
	for (int i = 1; i <= 88; i++)
	{
		cout << "-";
	}
	cout << endl;
	if (wk < 9)
	{
		int count = 0;
		cout << "Did not bat: ";
		if (on>off)
		{
			for (int i = on + 1; i < 11; i++)
			{
				if (i == 10)
				{
					cout << t1[i + 1];
				}
				else
				{
					cout << t1[i + 1] << ", ";
				}
				count++;
				if (count > 4)
				{
					count = 0;
					cout << endl;
				}
			}
		}
		else
		{
			for (int i = off + 1; i < 11; i++)
			{
				if (i == 10)
				{
					cout << t1[i + 1];
				}
				else
				{
					cout << t1[i + 1] << ", ";
				}
				count++;
				if (count > 4)
				{
					count = 0;
					cout << endl;
				}
			}
		}
		cout << endl;
	}
	if (wk > 0)
	{
		for (int i = 1; i <= 88; i++)
		{
			cout << "-";
		}
		cout << endl;
		fallOfWickets(playerWik, wikSc, wikOv, wk);
	}
	bowlingBoard(t2, o, bb, rg, w, m, ov, wd, nb);
}

void skipOversFirstInnings(int n, string t1[], int tO, int& ts, int& ov, int &b, int& a, int& wk, int& curBl, int& on, int& off, bool& maden, int rs[], int rg[], int bf[], int bb[], int w[], int o[], int f[], int s[], bool out[], int m[], int wd[], int nb[], int wikAtScor[], double wikAtOv[], string wikOfPlayers[])
{
	if (n <= ov)
	{
		cout << "You entered the wrong number\n";
		return;
	}
	if (n>tO)
	{
		n = tO;
	}
	int skip = ov + (n - ov) - 1;
	while (ov < skip && wk < 10)
	{
		if (isWide())
		{
			if (wd[curBl] < 6)
			{
				wd[curBl]++;
				ts++;
				rg[curBl]++;
			}
			continue;
		}
		if (isNoBall())
		{
			if (nb[curBl] < 6)
			{
				nb[curBl]++;
				ts++;
				rg[curBl]++;
			}
			continue;
		}
		int scor = batting(on);
		bf[on]++;
		if (scor == -1)
		{
			bb[curBl]++;
			wk++;
			w[curBl]++;
			out[on] = 1;
			wikAtScor[a] = ts;
			wikAtOv[a] = oversBowled(o, bb);
			wikOfPlayers[a] = t1[on + 1];
			a++;
			if (wk == 10)
			{
				break;
			}
			if (on>off)
			{
				on++;
			}
			else
			{
				on = off + 1;
			}
		}
		else
		{
			bb[curBl]++;
			if (scor > 0)
			{
				maden = false;
			}
			if (scor == 6)
			{
				s[on]++;
			}
			else if (scor == 4)
			{
				f[on]++;
			}
			ts += scor;
			rs[on] += scor;
			rg[curBl] += scor;
			if (scor % 2 == 1)
			{
				int temp = on;
				on = off;
				off = temp;
			}
		}
		b++;
		if (b == 6)
		{
			if (maden)
			{
				m[curBl]++;
			}
			o[curBl]++;
			bb[curBl] = 0;
			if (curBl == 4)
			{
				curBl = 0;
			}
			else
			{
				curBl++;
			}
			ov++;
			b = 0;
			maden = true;
			int temp = on;
			on = off;
			off = temp;
		}
	}
}

void skipOversSecondInnings(int n, int target, string t1[], int tO, int& ts, int& ov, int &b, int& a, int& wk, int& curBl, int& on, int& off, bool& maden, int rs[], int rg[], int bf[], int bb[], int w[], int o[], int f[], int s[], bool out[], int m[], int wd[], int nb[], int wikAtScor[], double wikAtOv[], string wikOfPlayers[])
{
	if (n <= ov)
	{
		cout << "You entered the wrong number\n";
		return;
	}
	if (n>tO)
	{
		n = tO;
	}
	int skip = ov + (n - ov) - 1;
	while (ts<target && ov < skip && wk < 10)
	{
		if (isWide())
		{
			if (wd[curBl] < 6)
			{
				wd[curBl]++;
				ts++;
				rg[curBl]++;
			}
			continue;
		}
		if (isNoBall())
		{
			if (nb[curBl] < 6)
			{
				nb[curBl]++;
				ts++;
				rg[curBl]++;
			}
			continue;
		}
		int scor = batting(on);
		bf[on]++;
		if (scor == -1)
		{
			bb[curBl]++;
			wk++;
			w[curBl]++;
			out[on] = 1;
			wikAtScor[a] = ts;
			wikAtOv[a] = oversBowled(o, bb);
			wikOfPlayers[a] = t1[on + 1];
			a++;
			if (wk == 10)
			{
				break;
			}
			if (on>off)
			{
				on++;
			}
			else
			{
				on = off + 1;
			}
		}
		else
		{
			bb[curBl]++;
			if (scor > 0)
			{
				maden = false;
			}
			if (scor == 6)
			{
				s[on]++;
			}
			else if (scor == 4)
			{
				f[on]++;
			}
			ts += scor;
			rs[on] += scor;
			rg[curBl] += scor;
			if (scor % 2 == 1)
			{
				int temp = on;
				on = off;
				off = temp;
			}
		}
		b++;
		if (b == 6)
		{
			if (maden)
			{
				m[curBl]++;
			}
			o[curBl]++;
			bb[curBl] = 0;
			if (curBl == 4)
			{
				curBl = 0;
			}
			else
			{
				curBl++;
			}
			ov++;
			b = 0;
			maden = true;
			int temp = on;
			on = off;
			off = temp;
		}
	}
}

void firstInnings(int tO, int& ts, string t1[], string t2[], int rs[], int rg[], int bf[], int bb[], int w[], int o[], int f[], int s[], bool out[], int m[], int wd[], int nb[], int wikAtScor[], double wikAtOv[], string wikOfPlayers[], int& onn1, int& off1)
{
	cout << t1[0] << " INNINGS (" << tO << " overs maximum)" << endl;
	int onStrike = 0, offStrike = 1;
	int wickets = 0;
	int overs = 0;
	int balls = 0;
	int currentBowler = 0;
	int a = 0;
	bool maden = true;
	drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd , nb, wikAtScor, wikAtOv, wikOfPlayers);
	char c;
	cout << "Do you want to skip overs?\nPress Y if yes: ";
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		int n;
		cout << "Enter the over you want to jump to: ";
		cin >> n;
		skipOversFirstInnings(n, t1, tO, ts, overs, balls, a, wickets, currentBowler, onStrike, offStrike, maden, rs, rg, bf, bb, w, o, f, s, out, m, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
		cin.ignore();
		cout << "Press Enter to continue . . . ";
		cin.get();
	}
	system("cls");
	while (overs < tO && wickets < 10)
	{
		if (isWide())
		{
			if (wd[currentBowler] < 6)
			{
				wd[currentBowler]++;
				ts++;
				rg[currentBowler]++;
			}
			continue;
		}
		if (isNoBall())
		{
			if (nb[currentBowler] < 6)
			{
				nb[currentBowler]++;
				ts++;
				rg[currentBowler]++;
			}
			continue;
		}
		int scor = batting(onStrike);
		bf[onStrike]++;
		if (scor == -1)
		{
			system("cls");
			cout << "WICKET!!" << endl;
			batterScoreCard(t1[onStrike + 1], rs[onStrike], bf[onStrike]);
			cin.ignore();
			cout << "Press enter to continue . . . ";
			cin.get();
			system("cls");
			bb[currentBowler]++;
			wickets++;
			w[currentBowler]++;
			out[onStrike] = 1;
			wikAtScor[a] = ts;
			wikAtOv[a] = oversBowled(o, bb);
			wikOfPlayers[a] = t1[onStrike + 1];
			a++;
			if (wickets == 10)
			{
				break;
			}
			if (onStrike>offStrike)
			{
				onStrike++;
			}
			else
			{
				onStrike = offStrike + 1;
			}
		}
		else
		{
			bb[currentBowler]++;
			if (scor > 0)
			{
				maden = false;
			}
			if (scor == 6)
			{
				s[onStrike]++;
			}
			else if (scor == 4)
			{
				f[onStrike]++;
			}
			ts += scor;
			rs[onStrike] += scor;
			rg[currentBowler] += scor;
			if (scor % 2 == 1)
			{
				int temp = onStrike;
				onStrike = offStrike;
				offStrike = temp;
			}
		}
		balls++;
		if (balls == 6)
		{
			if (maden)
			{
				m[currentBowler]++;
			}
			o[currentBowler]++;
			bb[currentBowler] = 0;
			if (currentBowler == 4)
			{
				currentBowler = 0;
			}
			else
			{
				currentBowler++;
			}
			overs++;
			balls = 0;
			maden = true;
			int temp = onStrike;
			onStrike = offStrike;
			offStrike = temp;
		}
		if (overs == tO)
		{
			break;
		}
		cout << t1[0] << " INNINGS (" << tO << " overs maximum)" << endl;
		drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
		if (overs < tO - 1)
		{
			char c;
			cout << "Do you want to skip overs?\nPress Y if yes: ";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				int n;
				cout << "Enter the over you want to jump to: ";
				cin >> n;
				skipOversFirstInnings(n, t1, tO, ts, overs, balls, a, wickets, currentBowler, onStrike, offStrike, maden, rs, rg, bf, bb, w, o, f, s, out, m, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
				cin.ignore();
				cout << "Press Enter to continue . . . ";
				cin.get();
			}
		}
		else
		{
			cout << "Press Enter to continue . . . ";
			cin.get();
		}
		system("cls");
	}
	onn1 = onStrike;
	off1 = offStrike;
	cout << t1[0] << " INNINGS (" << tO << " overs maximum)" << endl;
	drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
	cout << "Press Enter to start 2nd innings . . . ";
	cin.get();
	system("cls");
}

void secondInnings(int tO, int& ts, int target, string t1[], string t2[], int rs[], int rg[], int bf[], int bb[], int w[], int o[], int f[], int s[], bool out[], int m[], int wd[], int nb[], int wikAtScor[], double wikAtOv[], string wikOfPlayers[], int& onn2, int& off2)
{
	cout << t1[0] << " INNINGS (Target: " << target << " runs from " << tO << " overs)";
	cout << "  Remaining Score: " << target - ts << "\t    RRR: " << fixed << showpoint << setprecision(2) << getRunRate(target, tO * 6) << endl;
	int onStrike = 0, offStrike = 1;
	int wickets = 0;
	int overs = 0;
	int balls = 0;
	int currentBowler = 0;
	int a = 0;
	bool maden = true;
	drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
	char c;
	cout << "Do you want to skip overs?\nPress Y if yes: ";
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		int n;
		cout << "Enter the over you want to jump to: ";
		cin >> n;
		skipOversSecondInnings(n, target, t1, tO, ts, overs, balls, a, wickets, currentBowler, onStrike, offStrike, maden, rs, rg, bf, bb, w, o, f, s, out, m, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
		cin.ignore();
		cout << "Press Enter to continue . . . ";
		cin.get();
	}
	system("cls");
	while (ts < target && overs < tO && wickets < 10)
	{
		if (isWide())
		{
			if (wd[currentBowler] < 6)
			{
				wd[currentBowler]++;
				ts++;
				rg[currentBowler]++;
			}
			continue;
		}
		if (isNoBall())
		{
			if (nb[currentBowler] < 6)
			{
				nb[currentBowler]++;
				ts++;
				rg[currentBowler]++;
			}
			continue;
		}
		int scor = batting(onStrike);
		bf[onStrike]++;
		if (scor == -1)
		{
			system("cls");
			cout << "WICKET!!" << endl;
			batterScoreCard(t1[onStrike + 1], rs[onStrike], bf[onStrike]);
			cin.ignore();
			cout << "Press enter to continue . . . ";
			cin.get();
			system("cls");
			bb[currentBowler]++;
			wickets++;
			w[currentBowler]++;
			out[onStrike] = 1;
			wikAtScor[a] = ts;
			wikAtOv[a] = oversBowled(o, bb);
			wikOfPlayers[a] = t1[onStrike + 1];
			a++;
			if (wickets == 10)
			{
				break;
			}
			if (onStrike>offStrike)
			{
				onStrike++;
			}
			else
			{
				onStrike = offStrike + 1;
			}
		}
		else
		{
			bb[currentBowler]++;
			if (scor > 0)
			{
				maden = false;
			}
			if (scor == 6)
			{
				s[onStrike]++;
			}
			else if (scor == 4)
			{
				f[onStrike]++;
			}
			ts += scor;
			rs[onStrike] += scor;
			rg[currentBowler] += scor;
			if (scor % 2 == 1)
			{
				int temp = onStrike;
				onStrike = offStrike;
				offStrike = temp;
			}
		}
		balls++;
		if (balls == 6)
		{
			if (maden)
			{
				m[currentBowler]++;
			}
			o[currentBowler]++;
			bb[currentBowler] = 0;
			if (currentBowler == 4)
			{
				currentBowler = 0;
			}
			else
			{
				currentBowler++;
			}
			overs++;
			balls = 0;
			maden = true;
			int temp = onStrike;
			onStrike = offStrike;
			offStrike = temp;
		}
		if (overs == tO || ts>=target )
		{
			break;
		}
		int ov = tO - overs;
		int bls = (ov*6) - balls;
		cout << t1[0] << " INNINGS (Target: " << target << " runs from " << tO << " overs)";
		cout << "  Remaining Score: " << target - ts << "\t    RRR: " << fixed << showpoint << setprecision(2) << getRunRate(target - ts, bls) << endl;
		drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
		if (overs < tO - 1)
		{
			char c;
			cout << "Do you want to skip overs?\nPress Y if yes: ";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				int n;
				cout << "Enter the over you want to jump to: ";
				cin >> n;
				skipOversSecondInnings(n, target, t1, tO, ts, overs, balls, a, wickets, currentBowler, onStrike, offStrike, maden, rs, rg, bf, bb, w, o, f, s, out, m, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
				cin.ignore();
				cout << "Press Enter to continue . . . ";
				cin.get();
			}
		}
		else
		{
			cout << "Press Enter to continue . . . ";
			cin.get();
		}
		system("cls");
	}
	onn2 = onStrike;
	off2 = offStrike;
	cout << t1[0] << " INNINGS (Target: " << target << " runs from " << tO << " overs)" << endl;
	drawScoreCard(t1, t2, rs, rg, bf, bb, w, o, f, s, out, m, onStrike, offStrike, wickets, overs, wd, nb, wikAtScor, wikAtOv, wikOfPlayers);
	cout << "Press Enter to see match result . . . ";
	cin.get();
	system("cls");
}

int main()
{
	srand(time(0));
	int runsScored1[11] = { 0 };
	int ballsFaced1[11] = { 0 };
	int ballsBowled1[5] = { 0 };
	int runsGiven1[5] = { 0 };
	int wicketsTaken1[5] = { 0 };
	int oversBowled1[5] = { 0 };
	int fours1[11] = { 0 };
	int sixes1[11] = { 0 };
	bool isOut1[11] = { 0 };
	int maiden1[5] = { 0 };
	int wd1[5] = { 0 };
	int nb1[5] = { 0 };
	int wikAtScor1[11] = { 0 };
	double wikAtOv1[11] = { 0.0 };
	string wikOfPlayers1[11];
	int on1, off1;

	int runsScored2[11] = { 0 };
	int ballsFaced2[11] = { 0 };
	int ballsBowled2[5] = { 0 };
	int runsGiven2[5] = { 0 };
	int wicketsTaken2[5] = { 0 };
	int oversBowled2[5] = { 0 };
	int fours2[11] = { 0 };
	int sixes2[11] = { 0 };
	bool isOut2[11] = { 0 };
	int maiden2[5] = { 0 };
	int wd2[5] = { 0 };
	int nb2[5] = { 0 };
	int wikAtScor2[11] = { 0 };
	double wikAtOv2[11] = { 0.0 };
	string wikOfPlayers2[11];
	int on2, off2;
	
	int totalScore[2] = { 0 };
	int tOvers;
	string* team1 = new string[12];
	string* team2 = new string[12];
	cout << "					 **Welcome**					" << endl;
	cout << "Select an option: \n";
	cout << "1. Read overs from the file." << endl;
	cout << "2. Take overs from user." << endl;
	int ch;
	cin >> ch;
	while (!(ch >= 1 && ch <= 2))
	{
		cout << "Please Selecet between 1 and 2: ";
		cin >> ch;
	}
	if (ch == 1)
	{
		fstream f;
		f.open("configuration.txt", ios::in);
		if (!f.is_open())
		{
			cout << "File could not be opened successfully\n";
			exit(0);
		}
		f >> tOvers;
		f.close();
	}
	else
	{
		cout << "Enter the number of overs: ";
		cin >> tOvers;
		while (tOvers <= 0)
		{
			cout << "Enter a correct value!!";
			cin >> tOvers;
		}
	}
	fstream f2("teams.txt", ios::in);
	if (!f2)
	{
		cout << "File could not be opened successfully" << endl;
		exit(0);
	}
	for (int i = 0; i < 12; i++)
	{
		getline(f2, team1[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		getline(f2, team2[i]);
	}
	system("cls");
	cout << "----------------------------------------" << endl;
	cout << team1[0] << "  (TEAM A)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 1; i < 12; i++)
	{
		cout << team1[i] << endl;
	}
	cin.ignore();
	cout << "Press Enter to continue . . . ";
	cin.get();
	system("cls");
	cout << "----------------------------------------" << endl;
	cout << team2[0] << "  (TEAM B)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 1; i < 12; i++)
	{
		cout << team2[i] << endl;
	}
	cout << "Press Enter to continue . . . ";
	cin.get();
	system("cls");
	f2.close();
	
	cout << "Toss\n";
	cout << "Heads or Tails?" << endl;
	cout << right << setw(5) << "1." << right << setw(8) << "Heads" << endl;
	cout << right << setw(5) << "2." << right << setw(8) << "Tails" << endl;
	int ts;
	cout << "Enter your choice: ";
	cin >> ts;
	while (!(ts >= 1 && ts <= 2))
	{
		cout << "Please Selecet between 1 and 2: ";
		cin >> ts;
	}
	bool lose = false;
	int win = 0;
	int t = rand() % 2;
	if (t==0)
	{
		cout << "Congratulations! You won the toss.. Would you like to bat or bowl?\n";
		cout << right << setw(5) << "1." << right << setw(5) << "Bat" << endl;
		cout << right << setw(5) << "2." << right << setw(6) << "Bowl" << endl;
		cin >> win;
		while (!(win >= 1 && win <= 2))
		{
			cout << "Please Selecet between 1 and 2: ";
			cin >> win;
		}
	}
	else if (t==1)
	{
		int c = rand() % 2;
		if (c == 1)
		{
			cout << "Sorry you lost the toss.. The opponent has chosen to bat\n";
			lose = true;
		}
		else
		{
			cout << "Sorry you lost the toss.. The opponent has chosen to bowl\n";
		}
	}
	cin.ignore();
	cout << "Press enter to continue . . . ";
	cin.get();
	system("cls");
	if (!lose && win == 1)
	{
		firstInnings(tOvers, totalScore[0], team1, team2, runsScored1, runsGiven2, ballsFaced1, ballsBowled2, wicketsTaken2, oversBowled2, fours1, sixes1, isOut1, maiden2, wd2, nb2, wikAtScor1, wikAtOv1, wikOfPlayers1, on1, off1);
		int target = totalScore[0] + 1;
		secondInnings(tOvers, totalScore[1], target, team2, team1, runsScored2, runsGiven1, ballsFaced2, ballsBowled1, wicketsTaken1, oversBowled1, fours2, sixes2, isOut2, maiden1, wd1, nb1, wikAtScor2, wikAtOv2, wikOfPlayers2, on2, off2);
		if (totalScore[0] > totalScore[1])
		{
			cout << "\t\t\t\t--------------------WINNER------------------------" << endl;
			cout << "\t\t\t\t" << team1[0] << " won the match by " << totalScore[0] - totalScore[1] << " runs" << endl;
		}
		else if (totalScore[0] < totalScore[1])
		{
			int wks = 0;
			for (int i = 0; i < 5; i++)
			{
				wks += wicketsTaken1[i];
			}
			cout << "\t\t\t\t--------------------WINNER------------------------" << endl;
			cout << "\t\t\t\t" << team2[0] << " won the match by " << 10 - wks << " wickets" << endl;
		}
		else
		{
			cout << "Match Drawn" << endl;
		}
	}
	else
	{
		firstInnings(tOvers, totalScore[1], team2, team1, runsScored2, runsGiven1, ballsFaced2, ballsBowled1, wicketsTaken1, oversBowled1, fours2, sixes2, isOut2, maiden1, wd1, nb1, wikAtScor2, wikAtOv2, wikOfPlayers2, on1, off1);
		int target = totalScore[1] + 1;
		secondInnings(tOvers, totalScore[0], target, team1, team2, runsScored1, runsGiven2, ballsFaced1, ballsBowled2, wicketsTaken2, oversBowled2, fours1, sixes1, isOut1, maiden2, wd2, nb2, wikAtScor1, wikAtOv1, wikOfPlayers1, on2, off2);
		if (totalScore[1] > totalScore[0])
		{
			cout << "\t\t\t\t--------------------WINNER------------------------" << endl;
			cout << "\t\t\t\t" << team2[0] << " won the match by " << totalScore[1] - totalScore[0] << " runs" << endl;
		}
		else if (totalScore[0] > totalScore[1])
		{
			int wks = 0;
			for (int i = 0; i < 5; i++)
			{
				wks += wicketsTaken2[i];
			}
			cout << "\t\t\t\t--------------------WINNER------------------------" << endl;
			cout << "\t\t\t\t" << team1[0] << " won the match by " << 10 - wks << " wickets" << endl;
		}
		else
		{
			cout << "Match Drawn" << endl;
		}
	}
	if (runsScored1[max(runsScored1,11)] >= runsScored2[max(runsScored2,11)])
	{
		cout << "\t\t\t\t---------------Batsman Of the Match---------------" << endl;
		cout << "\t\t\t\t" << team1[max(runsScored1, 11) + 1] << endl;
		cout << "\t\t\t\t--------------------------------------------------" << endl;
	}
	else
	{
		cout << "\t\t\t\t---------------Batsman Of the Match---------------" << endl;
		cout << "\t\t\t\t" << team2[max(runsScored2, 11) + 1] << endl;
		cout << "\t\t\t\t--------------------------------------------------" << endl;
	}
	if (wicketsTaken1[max(wicketsTaken1,5)] >= wicketsTaken2[max(wicketsTaken2,5)])
	{
		cout << "\t\t\t\t---------------Bowler Of the Match----------------" << endl;
		cout << "\t\t\t\t" << team1[11 - max(wicketsTaken1, 5)] << endl;
		cout << "\t\t\t\t--------------------------------------------------" << endl;
	}
	else
	{
		cout << "\t\t\t\t---------------Bowler Of the Match----------------" << endl;
		cout << "\t\t\t\t" << team2[11 - max(wicketsTaken2, 5)] << endl;
		cout << "\t\t\t\t--------------------------------------------------" << endl;
	}
	cout << endl;
	int choce;
	cout << "Press 1 to see the short summary of the match." << endl;
	cout << "Press 2 to see First Innings." << endl;
	cout << "Press 3 to see Second Innings." << endl;
	cout << "Press 4 to save match data on a file." << endl;
	cout << "Press 5 to load a previous match data." << endl;
	cin >> choce;
	while (!(choce >= 1 && choce <= 5))
	{
		cout << "Please select between 1-5: ";
		cin >> choce;
	}
	system("cls");
	if (choce == 5)
	{
		fstream file("matchdata.txt", ios::in);
		if (!file)
		{
			cout << "File could not be opened successfully" << endl;
			exit(0);
		}
		if (file.eof())
		{
			cout << "File is empty..." << endl;
			exit(0);
		}
		string players1[11], players2[11];
		int score1[11], score2[11], ballF1[11], ballF2[11], wiks1[5], wiks2[5];
		double overs1[5], overs2[5], sRate1[11], sRate2[11];
		for (int i = 0; i < 6; i++)
		{
			getline(file, players1[i], ',');
			file >> score1[i];
			file >> ballF1[i];
			file >> sRate1[i];
			file.ignore();
		}
		for (int i = 0; i << 6; i++)
		{
			cout << players1[i] << endl;
		}
		for (int i = 6; i < 11; i++)
		{
			getline(file, players1[i], ',');
			file >> score1[i];
			file >> ballF1[i];
			file >> sRate1[i];
			file >> overs1[10 - i];
			file >> wiks1[10 - i];
			file.ignore();
		}
		for (int i = 0; i < 6; i++)
		{
			getline(file, players2[i], ',');
			file >> score2[i];
			file >> ballF2[i];
			file >> sRate2[i];
			file.ignore();
		}
		for (int i = 6; i < 11; i++)
		{
			getline(file, players2[i], ',');
			file >> score2[i];
			file >> ballF2[i];
			file >> sRate2[i];
			file >> overs2[10 - i];
			file >> wiks2[10 - i];
			file.ignore();
		}
		for (int i = 1; i <= 105; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "TEAM (A)\t\t\tRuns\t\tBalls\t\tSR\t\tOvers\t\tWickets" << endl;
		for (int i = 1; i <= 105; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < 11; i++)
		{
			if (i >= 0 && i < 6)
			{
				cout << left << setw(33) << players1[i] << left << setw(15) << score1[i] << left << setw(15) << ballF1[i] << left << setw(17) << fixed << showpoint << setprecision(2) << sRate1[i] << endl;
			}
			else
			{
				cout << left << setw(33) << players1[i] << left << setw(15) << score1[i] << left << setw(15) << ballF1[i] << left << setw(17) << fixed << showpoint << setprecision(2) << sRate1[i] << left << setw(17) << fixed << showpoint << setprecision(1) << overs1[10 - i] << left << setw(15) << wiks1[10 - i] << endl;
			}
		}
		cout << "Press Enter to continue . . . ";
		cin.ignore();
		cin.get();
		system("cls");
		for (int i = 1; i <= 105; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "TEAM (B)\t\t\tRuns\t\tBalls\t\tSR\t\tOvers\t\tWickets" << endl;
		for (int i = 1; i <= 105; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < 11; i++)
		{
			if (i >= 0 && i < 6)
			{
				cout << left << setw(33) << players2[i] << left << setw(15) << score2[i] << left << setw(15) << ballF2[i] << left << setw(17) << fixed << showpoint << setprecision(2) << sRate2[i] << endl;
			}
			else
			{
				cout << left << setw(33) << players2[i] << left << setw(15) << score2[i] << left << setw(15) << ballF2[i] << left << setw(17) << fixed << showpoint << setprecision(2) << sRate2[i] << left << setw(17) << fixed << showpoint << setprecision(1) << overs2[10 - i] << left << setw(15) << wiks2[10 - i] << endl;
			}
		}
	}
	else if (choce == 1)
	{
		if (!lose && win == 1)
		{
			cout << "\t\t\t\t-----------------SHORT SUMMARY-----------------" << endl;
			cout << "FIRST INNINGS: " << team1[0] << "  " << totalScore[0] << "/" << numberOfWickets(isOut1) << endl;
			cout << "Target: " << totalScore[0] + 1 << endl;
			cout << "SECOND INNINGS: " << team2[0] << "  " << totalScore[1] << "/" << numberOfWickets(isOut2) << endl;
			cout << "Press Enter to continue . . . ";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "\t\t\t\t-----------------SHORT SUMMARY-----------------" << endl;
			cout << "FIRST INNINGS: " << team2[0] << "  " << totalScore[1] << "/" << numberOfWickets(isOut2) << endl;
			cout << "Target: " << totalScore[1] + 1 << endl;
			cout << "SECOND INNINGS: " << team1[0] << "  " << totalScore[0] << "/" << numberOfWickets(isOut1) << endl;
			cout << "Press Enter to continue . . . ";
			cin.ignore();
			cin.get();
		}
	}
	else if (choce == 2)
	{
		cout << "FIRST INNINGS" << endl;
		if (!lose && win == 1)
		{
			drawScoreCard(team1, team2, runsScored1, runsGiven2, ballsFaced1, ballsBowled2, wicketsTaken2, oversBowled2, fours1, sixes1, isOut1, maiden2, on1, off1, numberOfWickets(isOut1), oversBowled(oversBowled2, ballsBowled2), wd2, nb2, wikAtScor1, wikAtOv1, wikOfPlayers1);
		}
		else
		{
			drawScoreCard(team2, team1, runsScored2, runsGiven1, ballsFaced2, ballsBowled1, wicketsTaken1, oversBowled1, fours2, sixes2, isOut2, maiden1, on1, off1, numberOfWickets(isOut2), oversBowled(oversBowled1, ballsBowled1), wd1, nb1, wikAtScor2, wikAtOv2, wikOfPlayers2);
		}
	}
	else if (choce == 3)
	{
		cout << "SECOND INNINGS" << endl;
		if (!lose && win == 1)
		{
			drawScoreCard(team2, team1, runsScored2, runsGiven1, ballsFaced2, ballsBowled1, wicketsTaken1, oversBowled1, fours2, sixes2, isOut2, maiden1, on1, off1, numberOfWickets(isOut2), oversBowled(oversBowled1, ballsBowled1), wd1, nb1, wikAtScor2, wikAtOv2, wikOfPlayers2);
		}
		else
		{
			drawScoreCard(team1, team2, runsScored1, runsGiven2, ballsFaced1, ballsBowled2, wicketsTaken2, oversBowled2, fours1, sixes1, isOut1, maiden2, on1, off1, numberOfWickets(isOut1), oversBowled(oversBowled2, ballsBowled2), wd2, nb2, wikAtScor1, wikAtOv1, wikOfPlayers1);
		}
	}
	else if (choce == 4)
	{
		fstream file("matchdata.txt", ios::out);
		if (!file)
		{
			cout << "File could not be created successfully" << endl;
			exit(0);
		}
		for (int i = 0; i < 6; i++)
		{
			file << team1[i + 1] << "," << runsScored1[i] << " " << ballsFaced1[i] << " " << fixed << showpoint << setprecision(2) << getStrikeRate(runsScored1[i], ballsFaced1[i]) << endl;
		}
		for (int i = 6; i < 11; i++)
		{
			file << team1[i + 1] << "," << runsScored1[i] << " " << ballsFaced1[i] << " " << fixed << showpoint << setprecision(2) << getStrikeRate(runsScored1[i], ballsFaced1[i]) << " " << oversBowled1[10 - i] << "." << ballsBowled1[10 - i] << " " << wicketsTaken1[10 - i] << endl;
		}
		for (int i = 0; i < 6; i++)
		{
			file << team2[i + 1] << "," << runsScored2[i] << " " << ballsFaced2[i] << " " << fixed << showpoint << setprecision(2) << getStrikeRate(runsScored2[i], ballsFaced2[i]) << endl;
		}
		for (int i = 6; i < 11; i++)
		{
			file << team2[i + 1] << "," << runsScored2[i] << " " << ballsFaced2[i] << " " << fixed << showpoint << setprecision(2) << getStrikeRate(runsScored2[i], ballsFaced2[i]) << " " << oversBowled2[10 - i] << "." << ballsBowled2[10 - i] << " " << wicketsTaken2[10 - i] << endl;
		}
		file.close();
	}
	delete[]team1;
	delete[]team2;
	return 0;
}