#include"lista.h"
#include"blok.h"
#include<iostream>

using namespace std;

/*list* push_begin(list* head, int zajetych)
{
	list* tmp = new list;
	tmp->zajetych = zajetych;
	tmp->tab = new blok[T];
	tmp->next = head;
	tmp->prev = nullptr;
	if (head != NULL)
	{
		head->prev = tmp;
	}
	return tmp;
}
*/

lista* lista::push_end(lista* tail)
{
	lista* tmp = new lista;
	tmp->prev = tail;
	tmp->next = nullptr;
	tmp->tab = new blok*[T];
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

lista* lista::last(lista* head)
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

lista* lista::addElement(lista* tail, blok* k)
{
	if (tail == nullptr || tail->zajetych == T)
	{
		tail = push_end(tail);
	}
	for (int i = 0; i < T; i++)
	{
		if (tail->tab[i] == nullptr)
		{
			tail->tab[i] = k;
			tail->zajetych++;
			return tail;
		}
	}
	return tail;
}