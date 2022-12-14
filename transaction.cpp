#include "header.h"

Transaction::Transaction()
{
	from_ = "";
	to_ = "";
	amount_ = 0;
}

void Transaction::SetTransaction(int amount, string from, string to)
{
	from_ = from;
	to_ = to;
	amount_ = amount;

	stringstream ss;
	ss << from << to << amount;

	ID_ = sha256(ss.str());

}

void Trans(User x, User y, int amount, vector<Transaction>& AllTrans)
{
	int size = AllTrans.size();
	AllTrans.push_back(Transaction());
	AllTrans[size].SetTransaction(amount, x.GetKey(), y.GetKey());
}
