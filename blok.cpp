#include"blok.h"
#include<iostream>

using namespace std;

void wypisz_blok(blok x)
{
	x.selektory->wypisz(x.selektory);
	x.atrybuty->wypisz(x.atrybuty);
}

void czyszczenie(blok* x)
{
    x->atrybuty->czyszczenie(x->atrybuty);
    x->selektory->czyszczenie(x->selektory);
}


lista* push_end(lista* tail)
{
	lista* tmp = new lista;
	tmp->prev = tail;
	tmp->next = nullptr;
	tmp->tab = new blok * [T];
	for (int i = 0; i < T; i++)
		tmp->tab[i] = nullptr;
	tmp->zajetych = 0;
	if (tail == nullptr)
	{
		return tmp;
	}
	tail->next = tmp;
	return tmp;
}

lista* last(lista* head)
{
	if (head == nullptr)
		return nullptr;
	lista* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	return tmp;
}

lista* addElement(lista* tail, blok* k)
{
	if (tail == nullptr || tail->zajetych == T)
	{
		tail = push_end(tail);
	}
	for (int i = T-1; i > 0; i--)
	{
		if (tail->tab[i-1] != nullptr)
		{
			tail->tab[i] = k;
			tail->zajetych++;
			return tail;
		}
	}
	tail->tab[0] = k;
	tail->zajetych++;
	return tail;
}

void wypisz_lista(lista* head)
{
	while (head != nullptr)
	{
		for (int i = 0; i < T; i++)
		{
			if (head->tab[i] != nullptr)
				wypisz_blok(*(head->tab[i]));
		}
		head = head->next;
	}
}

void czyszczenie_lista(lista* head)
{
	while (head != nullptr)
	{
		for (int i = 0; i < T; i++)
		{
			if (head->tab[i] != nullptr)
				czyszczenie((head->tab[i]));
		}
		head = head->next;
	}
}

lista* remove(lista* head, lista* del)
{
	int i = 0;
	for (; i < T; i++)
		if (del->tab[i] != nullptr)
			break;
	if (i != T)
		return head;
	if (del == nullptr)
		return head;
	if (del->next != nullptr)
		del->next->prev = del->prev;
	if (del->prev == nullptr)
	{
		return del->next;
	}
	del->prev->next = del->next;
	return head;
}