#include "header.h"

Chain::Chain()
{
	vector<Transaction> Genesis;

	for (int i = 0; i < 100; i++)
	{
		Genesis.push_back(Transaction());
		Genesis[i].SetTransaction(1, "Genesis", "Genesis");
	}

	Chain_.emplace_back(Block(1, Genesis));
	Difficulty_ = 2;
}

void Chain::AddBlock(Block New)
{
	New.prev_ = GetLastBlock().GetHash();
	Chain_.push_back(New);
}

Block Chain::GetLastBlock() const
{
	return Chain_.back();
}
