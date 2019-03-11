#pragma once
#include <iostream>
using namespace std;


class Nod
{
protected:
	int info;
private:
	Nod * st, *dr;
public:
	Nod();
	Nod(const Nod& n1);
	~Nod();
	void operator=(Nod *n1);
	friend istream& operator>>(istream& o, Nod &n);
	friend ostream& operator<<(ostream& a, Nod &n);
	friend class ABC;
};


class Nod_AVL : public Nod
{
	Nod_AVL *sta, *dre;
protected:
	int echilibru, inaltime;
public:
	Nod_AVL();
	Nod_AVL(const Nod_AVL &n1);
	~Nod_AVL();
	void operator=(Nod_AVL *n1);
	friend istream& operator>>(istream& o, Nod_AVL &n);
	friend ostream& operator<<(ostream& a, Nod_AVL &n);
	void afisare();
	friend class Arbore_AVL;
};


class Arbore
{
protected:
	int nr_noduri;
public:
	Arbore();
	Arbore(const Arbore &a1);
	~Arbore();
	void operator=(Arbore a1);
	friend istream& operator>>(istream& o, Arbore &arb);
	friend ostream& operator<<(ostream& a, Arbore &arb);
	virtual void ech() {}
	virtual void nr_nod()
	{
		cout << "Arborele are" << nr_noduri << " noduri " << endl;
	}
};


class ABC : public Arbore
{
	Nod *rad;
public:
	ABC();
	ABC(const ABC &a1);
	~ABC();
	void destruct(Nod* x);
	Nod* copy_ABC(Nod *root);
	void operator=(ABC a1);
	friend istream& operator>>(istream& o, ABC &arbb);
	friend ostream& operator<<(ostream& a, ABC &arbb);
	Nod* insert(Nod *root, int info);
	void inorder(Nod *root);
};


class Arbore_AVL : public Arbore
{
	Nod_AVL *rad;
public:
	Arbore_AVL();
	Arbore_AVL(const Arbore_AVL &a1);
	~Arbore_AVL();
	Nod_AVL* copy_AVL(Nod_AVL *root);
	void operator=(Arbore_AVL a1);
	Nod_AVL* insert(Nod_AVL* N1, int info);
	friend istream& operator>>(istream& o, Arbore_AVL &arbe);
	friend ostream& operator<<(ostream& a, Arbore_AVL &arbe);
	void ech();
	void nr_nod();
	void preorder(Nod_AVL *root);
	int static max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	int height(Nod_AVL *N);
	Nod_AVL* dreRotate(Nod_AVL *y);
	Nod_AVL* staRotate(Nod_AVL *x);
	int getBalance(Nod_AVL *N);
};