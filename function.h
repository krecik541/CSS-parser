#pragma once
#include<iostream>
#include"atrybuty_list.h"
#include"blok.h"
#include"selector_list.h"

selector_list* fun_naw_otw(bool& selektor, bool& atrybut, selector_list* sel, char* r);

lista* fun_naw_zam(lista*head, lista* tail, bool& wartosc, bool& selektor, bool& atrybut, blok *x, char* r, char* v);

void fun_naw_dwukr(bool& wartosc, bool& atrybut, char** r, char** v);

atrybuty_list* sred(bool& wartosc, bool& atrybut, atrybuty_list* atrybuty, char* r, char** v);

int fun_znak_zap(lista* head);

int str_to_int(char* t, int& i);

void czytaj_str(char* t, int& i, char** q);

blok* znajdzBlok(lista* head, int numer);

void i_S_znakZap(lista* head, int numer);

void i_A_znakZap(lista* head, int numer);

void i_A_n(lista* head, int numer, char*n);

lista* i_D_gwiazdka(lista* head, int numer);

lista* i_D_n(lista* head, int numer, char* n);

void n_A_znakZap(lista* head, char* c1);

void z_S_znakZap(lista* head, char* c1);

void i_S_j(lista* head, int i1, int i2);

void z_E_n(lista* tail, char* sel, char* atr);

char* makeString(int i, int& poczatek, int& prawa, char* t, bool& napis);

int rzeczywistaLista(lista* head);