#include "stdafx.h"
#include "AVL_tree.h"
#include <iostream>
using namespace std;


Nod::Nod()
{
	info = 0;
	st = dr = NULL;
}

Nod::Nod(const Nod &n1)
{
	info = n1.info;
	st = n1.st;
	dr = n1.dr;
}

Nod::~Nod()
{
	info = 0;
	st = dr = NULL;
}

void Nod::operator=(Nod *n1)
{
	info = n1->info;
	st = n1->st;
	dr = n1->dr;
}

istream& operator>>(istream& o, Nod &n)
{
	o >> n.info;
	return o;
}

ostream& operator<<(ostream& a, Nod &n)
{
	cout << n.info << " ";
	return a;
}



Nod_AVL::Nod_AVL()
{
	info = echilibru = inaltime = 0;
	sta = dre = NULL;
}

Nod_AVL::Nod_AVL(const Nod_AVL &n1)
{
	info = n1.info;
	echilibru = n1.echilibru;
	inaltime = n1.inaltime;
	sta = n1.sta;
	dre = n1.dre;
}

Nod_AVL::~Nod_AVL()
{
	info = echilibru = inaltime = 0;
	sta = dre = NULL;
}

void Nod_AVL::operator=(Nod_AVL *n1)
{
	info = n1->info;
	echilibru = n1->echilibru;
	inaltime = n1->inaltime;
	sta = n1->sta;
	dre = n1->dre;
}

istream& operator>>(istream& o, Nod_AVL &n)
{
	o >> n.info;
	return o;
}

ostream& operator<<(ostream& a, Nod_AVL &n)
{
	cout << n.info << " ";
	return a;
}

void Nod_AVL::afisare()
{
	cout << echilibru << " ";
}



Arbore::Arbore()
{
	nr_noduri = 0;
}

Arbore::Arbore(const Arbore &a1)
{
	nr_noduri = a1.nr_noduri;
}

Arbore::~Arbore()
{
	nr_noduri = 0;
}

void Arbore::operator=(Arbore a1)
{
	nr_noduri = a1.nr_noduri;
}

istream& operator>>(istream& o, Arbore &arb)
{
	o >> arb.nr_noduri;
	return o;
}

ostream& operator<<(ostream& a, Arbore &arb)
{
	cout << arb.nr_noduri << " ";
	return a;
}



ABC::ABC()
{
	rad = NULL;
}

Nod* ABC::copy_ABC(Nod* root)
{
	if (root == NULL)
		return root;

	Nod *temp = new Nod;
	temp->info = root->info;
	temp->st = root->st;
	temp->dr = root->dr;
	copy_ABC(root->st);
	copy_ABC(root->dr);
	return temp;
}

ABC::ABC(const ABC &a1)
{
	nr_noduri = a1.nr_noduri;
	rad = copy_ABC(a1.rad);
}

Nod* ABC::insert(Nod* root, int info)
{
	if (root == NULL)
	{
		Nod *temp = new Nod;
		temp->info = info;
		temp->st = temp->dr = NULL;
		return temp;
	}

	if (info < root->info)
		root->st = insert(root->st, info);
	if (info > root->info)
		root->dr = insert(root->dr, info);

	return root;
}

void ABC::inorder(Nod* root)
{
	if (root != NULL)
	{
		if(root->st != NULL)
		    inorder(root->st);
		cout << root->info << " ";
		if(root->dr != NULL)
		    inorder(root->dr);
	}
}

void ABC::destruct(Nod* x)
{
	Nod *a, *b;
	a = NULL;
	b = NULL;
	if(x->st != NULL)
	a = x->st;
	if(x->dr != NULL)
	b = x->dr;

	delete x;
	if(a != NULL)
		destruct(a);
	if(b != NULL)
		destruct(b);
}

ABC::~ABC()
{
	destruct(rad);
}

void ABC::operator =(ABC a1)
{
	nr_noduri = a1.nr_noduri;
	rad = copy_ABC(a1.rad);
}

istream& operator >>(istream& o, ABC &arbb)
{
	o >> arbb.nr_noduri;
	int x;
	for (int i = 0; i < arbb.nr_noduri; i++)
	{
		o >> x;
		//cout << x;
		arbb.rad=arbb.insert(arbb.rad, x);
	}
	return o;
}

ostream& operator <<(ostream& a, ABC &arbb)
{
	a << arbb.nr_noduri << endl;
	arbb.inorder(arbb.rad);
	return a;
}



Arbore_AVL::Arbore_AVL()
{
	rad = NULL;
}

Nod_AVL* Arbore_AVL::copy_AVL(Nod_AVL *root)
{
	if (root == NULL)
		return root;

	Nod_AVL *temp = new Nod_AVL;
	temp->info = root->info;
	temp->echilibru = root->echilibru;
	temp->inaltime = root->inaltime;
	temp->sta = copy_AVL(root->sta);
	temp->dre = copy_AVL(root->dre);
	return temp;
}

Arbore_AVL::Arbore_AVL(const Arbore_AVL &a1)
{
	nr_noduri = a1.nr_noduri;
	*rad = copy_AVL(a1.rad);
}

void Arbore_AVL::preorder(Nod_AVL *root)
{
	if (root != NULL)
	{
		cout << root->info << " ";
		preorder(root->sta);
		preorder(root->dre);
	}
}

Arbore_AVL::~Arbore_AVL()
{
	delete rad;
}

void Arbore_AVL::operator=(Arbore_AVL a1)
{
	nr_noduri = a1.nr_noduri;
	rad = copy_AVL(a1.rad);
}

istream& operator>>(istream& o, Arbore_AVL &arbe)
{
	o >> arbe.nr_noduri;
	int x;
	for (int i = 0; i < arbe.nr_noduri; i++)
	{
		o >> x;
		arbe.rad = arbe.insert(arbe.rad, x);
	}
	return o;
}

ostream& operator<<(ostream& a, Arbore_AVL &arbe)
{
	cout << arbe.nr_noduri << endl;
	arbe.preorder(arbe.rad);
	return a;
}

void Arbore_AVL::ech()
{
	for (int i = 0; i < nr_noduri; i++)
		rad[i].afisare();
}

void Arbore_AVL::nr_nod()
{
	cout << "Arborele_AVL are" << nr_noduri << " noduri ";
}

int Arbore_AVL::height(Nod_AVL *N)
{
	if (N == NULL)
		return 0;
	return N->inaltime;
}

Nod_AVL *Arbore_AVL::dreRotate(Nod_AVL *y)
{
	Nod_AVL *x = y->sta;
	Nod_AVL *T2 = x->dre;

	x->dre = y;
	y->sta = T2;

	y->inaltime = max(height(y->sta), height(y->dre)) + 1;
	x->inaltime = max(height(x->sta), height(x->dre)) + 1;

	return x;
}

Nod_AVL *Arbore_AVL::staRotate(Nod_AVL *x)
{
	Nod_AVL *y = x->dre;
	Nod_AVL *T2 = y->sta;

	y->sta = x;
	x->dre = T2;

	x->inaltime = max(height(x->sta), height(x->dre)) + 1;
	y->inaltime = max(height(y->sta), height(y->dre)) + 1;

	return y;
}

int Arbore_AVL::getBalance(Nod_AVL *N)
{
	if (N == NULL)
		return 0;
	return height(N->sta) - height(N->dre);
}

Nod_AVL* Arbore_AVL::insert(Nod_AVL* N1, int info)
{
	if (N1 == NULL)
	{
		Nod_AVL* temp = new Nod_AVL;
		temp->info = info;
		temp->sta = temp->dre = NULL;
		temp->inaltime = 1;
		temp->echilibru = 0;
		return(temp);
	}

	if (info < N1->info)
		N1->sta = insert(N1->sta, info);
	else if (info > N1->info)
		N1->dre = insert(N1->dre, info);
	else
		return N1;

	N1->inaltime = 1 + max(height(N1->sta), height(N1->dre));
	N1->echilibru = getBalance(N1);

	if (N1->echilibru > 1 && info < N1->sta->info)
		return dreRotate(N1);

	if (N1->echilibru < -1 && info > N1->dre->info)
		return staRotate(N1);

	if (N1->echilibru > 1 && info > N1->sta->info)
	{
		N1->sta = staRotate(N1->sta);
		return dreRotate(N1);
	}

	if (N1->echilibru < -1 && info < N1->dre->info)
	{
		N1->dre = dreRotate(N1->dre);
		return staRotate(N1);
	}
	return N1;
}