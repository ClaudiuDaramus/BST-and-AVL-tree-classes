// Tema12_AVL_Gr144v2_DaramusClaudiu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "AVL_tree.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream f("data.in");
	ABC q;
	Arbore_AVL qe;
	
	f >> q;
	cout << q;
	cout << endl;
	ifstream g("data.in");
	g >> qe;
	cout << qe;

	/*Arbore_AVL *pa;
	Arbore *p, qa;
	cout << endl;
	p = &qe;
	p->nr_nod;

	f >> qa;
	pa = &qa;
	pa->nr_nod;*/
	return 0;
}
