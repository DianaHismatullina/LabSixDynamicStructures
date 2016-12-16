// Lab_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Laptop 
{
	char company[128]; 
	char operating_system[64]; 
	int kernels;
	int memory;
	int price;
};

struct List 
{
	Laptop laptop; 
	List *pNext; 
};

void addFirst(List *& pF,  List* p) 
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF) 
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;
}

bool add(List *&pF, List * pZad, List *p)
{
	if (pZad == pF) 
	{
		p->pNext = pF;
		pF = p;
		return true;
	}
	List *pPred = pF; 
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; 
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p) 
{
	if (pF == 0) return 0;
	if (pF == p) 
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF; 
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; 
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); 
}
 
int main()
{
	List *pF = 0; 
	List *p;

	char Next; 
	do
	{
		p = (List *)malloc(sizeof(List));
		fflush(stdin); gets_s(p->laptop.company, 127);
		printf_s("\nCompany: ");
		fflush(stdin); gets_s(p->laptop.company, 127);
		printf_s("Operating system: ");
		fflush(stdin); gets_s(p->laptop.operating_system, 63);
		printf("Kernels = ");
		fflush(stdin); scanf_s("%d", &p->laptop.kernels);
		printf("Memory = ");
		fflush(stdin); scanf_s("%d", &p->laptop.memory);
		printf("Price = ");
		fflush(stdin); scanf_s("%d", &p->laptop.price);

		addFirst(pF, p); 
		printf("For continue press Y else press N ");
		Next = _getche(); 
	} while (Next == 'Y' || Next == 'y');

	printf("\nList:");
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s \n%s \nKernels = %4d \nMemory = %4d \nPrice = %4d \n", pi->laptop.company, pi->laptop.operating_system, pi->laptop.kernels, pi->laptop.memory, pi->laptop.price);

	int k = 1;
	while (k)
	{
		k = 0;
		for (List *pi = pF; pi; pi = pi->pNext)
		{
			for (List *pj = pi->pNext; pj; pj = pj->pNext)
				if (pj->laptop.price < pi->laptop.price)
				{
					del(pF, pj);
					add(pF, pi, pj);
					k = k + 1;
				}
		}
	}

	printf("\nThe sorted list:");
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s \n%s \nKernels = %4d \nMemory = %4d \nPrice = %4d \n", pi->laptop.company, pi->laptop.operating_system, pi->laptop.kernels, pi->laptop.memory, pi->laptop.price);

	system("pause");
	return 0;
}
