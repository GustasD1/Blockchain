#ifndef HEADER
#define HEADER

//libraries

#include <cstdint>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include "sha256.h"


//namespace

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
//classes

class Transaction
{
public:
	Transaction();

	void SetTransaction(int amount, string from, string to);

	int GetAmount() const
	{
		return amount_;
	}

	string GetFrom() const
	{
		return from_;
	}

	string GetTo() const
	{
		return to_;
	}

	string GetID() const
	{
		return ID_;
	}


private:

	string ID_;
	string from_;
	string to_;
	int amount_;
};

class Block
{
public:
	string prev_;

	Block(uint32_t IndexIn, vector<Transaction> &DataIn);

	string GetHash();

	int64_t GetNonce() const
	{
		return Nonce_;
	}

	void MineBlock(uint32_t Difficulty);
	time_t getTime() {
		return Time_;
	}


private:
	uint32_t Index_;
	int64_t Nonce_;
	vector<Transaction> Data_;
	string Hash_;
	time_t Time_;
	string merkle_;
	string CalculateHash() const;

	void CreateMerkel();

};

class Chain
{
public:
	Chain();

	void AddBlock(Block New);

	uint32_t GetDiff() const
	{
		return Difficulty_;
	}

private:
	uint32_t Difficulty_;
	vector<Block> Chain_;

	Block GetLastBlock() const;
};

class User
{
public:
	User();

	void irasymas(std::istringstream& skaitymas);

	string GetName() const
	{
		return name_;
	}
	string GetKey() const
	{
		return public_key;
	}

	int GetBling() const
	{
		return bling_;
	}

	void SetBling(int temp)
	{
		bling_ = temp;
	}

private:

	string name_;
	string surname_;
	string public_key;
	int bling_;

};

//functions

string Convertion(char[]);
void skaitymas(vector <User> &Users);
void Trans(User x, User y, int amount, vector <Transaction>& AllTrans);
void kurimas(vector <User>& vartotojai, vector <Transaction>& Visos);
void atrinkimas(vector <Transaction>& Visos, vector <Transaction>& Atrinktos, vector <User>& vartotojai);
void BlokoKurimas(vector<Transaction>& Visos, vector<User>& vartotojai, Chain& Blocky, uint32_t& index, bool& found, size_t& MaxNonce, int i);
#endif
