#pragma once
#include<iostream>
#include"selector_list.h"
#include"atrybuty_list.h"
#define T 8
using namespace std;

struct blok {
	selector_list* selektory = nullptr;
	atrybuty_list* atrybuty = nullptr;
};

void wypisz_blok(blok x);

void czyszczenie(blok* x);

struct lista {
	int zajetych = NULL;
	blok** tab = nullptr;
	lista* next = nullptr;
	lista* prev = nullptr;
};

lista* push_end(lista* tail);
lista* remove(lista* head, lista*del);
lista* last(lista* head);
lista* addElement(lista* tail, blok* k);
void wypisz_lista(lista* head);
void czyszczenie_lista(lista* head);