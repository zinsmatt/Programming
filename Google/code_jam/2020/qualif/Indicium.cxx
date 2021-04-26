// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl;

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cout << *it << " "; \
    } \
    cout << std::endl;

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()


template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

vector<int> binary2(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		res.push_back(x % 2);
		x >>= 1;
	}
	return res;
}



class Choice
{
public:
	Choice(int n) :
		tab(vector<bool>(n, true)), nb_free(n) {
	}

	vector<bool> tab;
	int nb_free;

	bool is_free(int i) const { return tab[i]; }
	int get_nb_free() const { return nb_free; }

	void set_free(int i) { 
		if (!tab[i]) {
			tab[i] = true;
			nb_free++;
		}
	}
	void set_occ(int i) {
		if (tab[i]) {
	 		tab[i] = false;
	 		nb_free--;
		}
	}

	void print() const {
		cout << "choice: ";
		for (auto b: tab)
			cout << b << " " ;
		cout << "\n";
	}

	int size() const { return tab.size(); }

	int get_next(int i) const {
		while (i < tab.size())
		{
			if (tab[i])
				return i;
			++i;
		}
		return -1;
	}

	Choice intersection(const Choice& ch)
	{
		int n = this->size();
		Choice res(n);
		F(i, n)
		{
			if (tab[i] && ch.is_free(i))
				res.set_free(i);
			else
				res.set_occ(i);
		}
		return res;
	}


};

class Case
{
public:
	Case(Choice* ch_row, Choice* ch_col) :
		row(ch_row), col(ch_col)
	{}


	int get_value() const { return value; }
	bool get_modifiable() const { return modifiable; }
	bool is_empty() const { return value == -1; }
	void set_modifiable(bool b) { modifiable = b; }
	Choice get_choice() const { return row->intersection(*col); }
	void remove() {
		if (value != -1)
		{
			row->set_free(value);
			col->set_free(value);
			value = -1;
		}
	}

	bool set_value(int x)
	{
		if (!modifiable)
			return false;
		if (row->is_free(x) && col->is_free(x))
		{
			//cout << "bforef remove  " << std::endl;
			if (value != -1)
				remove();
			row->set_occ(x);
			col->set_occ(x);
			value = x;
			return true;
		}
		return false;
	}

	int value = -1;
	bool modifiable = true;

	Choice* row;
	Choice* col;


};

class Table
{

public:
	Table(int nn) : n(nn)
	{
		rows.resize(n, Choice(n));
		cols.resize(n, Choice(n));

		F(i, n)
		{
			vector<Case> row_cases;
			F(j, n)
			{
				row_cases.emplace_back(&rows[i], &cols[j]);
			}
			cases.push_back(row_cases);
		}

		/*F(i, n)
		{
			vector<Choice> row_choices;
			F(j, n)
			{
				row_choices.push_back(Choice(n));
			}
			choices.push_back(row_choices);
		}*/
	}

	bool get_modifiable(int i, int j) const {
		return cases[i][j].get_modifiable();
	}
	Choice get_choice(int i, int j) const {
		return cases[i][j].get_choice();
	}
	int get_value(int i, int j) const {
		return cases[i][j].get_value();
	}
	bool set_value(int i, int j, int x) {
		return cases[i][j].set_value(x);
	}
	void remove(int i, int j) {
		cases[i][j].remove();
	}


	int n;
	vector<vector<Case>> cases;
	vector<Choice> rows;
	vector<Choice> cols;


	//vector<vector<Choice>> choices;
	std::queue<int> emptys;

	int get_row(int idx) const {
		return idx / n;
	}
	int get_col(int idx) const {
		return idx % n;
	}
	int get_id(int i, int j) const {
		return i * n + j;
	}


	bool get_modifiable(int id) const {
		return get_modifiable(get_row(id), get_col(id));
	}
	Choice get_choice(int id) const {
		return get_choice(get_row(id), get_col(id));
	}
	int get_value(int id) const {
		return get_value(get_row(id), get_col(id));
	}
	bool set_value(int id, int x) {
		return set_value(get_row(id), get_col(id), x);
	}
	void remove(int id) {
		remove(get_row(id), get_col(id));
	}

	bool set_initial(int i, int j, int x) {
		cases[i][j].set_value(x);
		cases[i][j].set_modifiable(false);
		return true;
	}


	int get_first_empty()
	{
		F(i, n)
		{
			F(j, n)
			{
				if (cases[i][j].is_empty())
				{
					return get_id(i, j);
				}
			}
		}
		return -1;
	}
	/*void init_empty_cases()
	{
		F(i, n)
		{
			F(j, n)
			{
				if (cases[i][j].is_empty())
				{
					emptys.push(get_id(i, j));
				}
			}
		}
	}*/

	void print() const {
		cout << "Table:\n";
		F(i, n)
		{
			F(j, n)
			{
				cout << cases[i][j].get_value() << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void print_sol() const 
	{
		F(i, n)
		{
			F(j, n)
			{
				cout << cases[i][j].get_value() + 1 << " ";
			}
			cout << "\n";
		}
	}
};

class Solver
{

public:
	Solver(Table t):
		table(t)
	{
		hist.push(table.get_first_empty());
	}

	bool step()
	{
		if (hist.size() == 0)
			return false;

		int cur = hist.top();
		int v = 0;
		if (table.get_value(cur) == -1)
			v = table.get_choice(cur).get_next(0);
		else
			v = table.get_choice(cur).get_next(table.get_value(cur));
		if (v == -1)
		{
			table.remove(cur);
			hist.pop();
		}
		else
		{
			table.set_value(cur, v);
			int next_empty = table.get_first_empty();
			if (next_empty == -1)
			{
				return false;;
			}
			else
			{
				hist.push(table.get_first_empty());
			}
		}
		//cout << "Step : " << std::endl;
		//table.print();
		//cout << hist.size() << std::endl;
		return true;
	}

	bool solve()
	{
		while(step())
		{ }
		return table.get_first_empty() == -1;
	}

	int get_case() {
		return hist.top();
	}

	void print_sol() const {
		table.print_sol();
	}


	std::stack<int> hist;
	Table table;
};


vector<int> repr(int x, int n, int& sum)
{
	sum = 0;
	vector<int> res(n, 0);
	int i= 0;
	while (x > 0)
	{
		res[i++] = x % n;
		sum += x % n;
		x /= n;
	}
	return res;
}

int main()
{

	ll tt;
	cin >> tt;
	F(tti, tt)
	{

		int n, k;
		cin >> n >> k;
		k -= n;
		/*Table t(n);
		cout << "losc " << std::endl;
		t.set_initial(0, 0, 0);
		t.set_initial(1, 1, 1);

		cout << "init done " << std::endl;
		t.print();


		Solver solver(t);
		if (solver.solve())
		{
			solver.print_sol();
		}
		else{
			cout << "impossible" << std::endl;
		}*/
		bool ok = false;
		F(i, pow(n, n))
		{
			int s = 0;
			//cout << "i = " << i << "\n";
			auto diag = repr(i, n, s);
			if (s == k)
			{
				//VPRINT("diag ", diag)
				Table t(n);
				F(j, n) {
					t.set_initial(j, j, diag[j]);
				}
				Solver solver(t);
				if (solver.solve())
				{
					cout << "Case #" << tti+1 <<": POSSIBLE\n";
					solver.print_sol();
					ok = true;
					break;
				}
			}
		}
		if (!ok)
		{
			cout << "Case #" << tti+1 <<": IMPOSSIBLE\n";
		}
	}


	
    return 0;
}
