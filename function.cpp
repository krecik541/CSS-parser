#include"function.h"

using namespace std;

//blok* p = nullptr;

selector_list* fun_naw_otw(bool& selektor, bool& atrybut, selector_list* sel, char* r)
{
	selektor = false;
	atrybut = true;
	return sel->append(&(sel), r);
}

lista* fun_naw_zam(lista* head, lista* tail, bool& wartosc, bool& selektor, bool& atrybut, blok *x, char* r, char* v)
{
    if (x == nullptr)
        return tail;
    wartosc = false;
    selektor = true;
    atrybut = false;
    if (v != nullptr)
    {
        x->atrybuty = x->atrybuty->append(&(x->atrybuty), v, r);
        v = nullptr;
    }
    tail = addElement(tail, x);//zapisanie bloku w tablicy
    /*list* tmp_head = head;
    int i = 0;
   while (tmp_head != nullptr)
    {
        for (int i = 0; i < T; i++)
        {
            if (tmp_head->tab[i] != nullptr)
                wypisz_blok(*(tmp_head->tab[i]));
        }
        tmp_head = tmp_head->next;
        i++;
    }
    cout << i;*/
    return tail;
}

void fun_naw_dwukr(bool& wartosc, bool& atrybut, char** r, char** v)
{
    wartosc = true;
    atrybut = false;
    swap(*v, *r);
}

atrybuty_list* sred(bool& wartosc, bool& atrybut, atrybuty_list* atrybuty, char* r, char** v)
{
    wartosc = false;
    atrybut = true;
    atrybuty = atrybuty->append(&(atrybuty), *v, r);
    *v = nullptr;
    return atrybuty;
}

int fun_znak_zap(lista* head)
{
    int i = 0;
    while (head != nullptr)
    {
        i += head->zajetych;
        head = head->next;
    }
    return i;
}

int str_to_int(char* t, int& i)
{
    int wyn = 0;
    while (t[i] != ',' && t[i] != '\0' && t[i] != ' ')
    {
        wyn = wyn*10 + t[i] - (int)'0';
        i++;
    }
    return wyn;
}

void czytaj_str(char* t, int& i, char** q)
{
    char* x;
    int licz = 0, j = i+1, k = i;
    if (t[i] == '?')
    {
        x = new char[2];
        x[0] = '?';
        x[1] = '\0';
    }
    {
        while (t[j] != ',' && t[j] != '\0' /* && t[j] != ' '*/)
            j++;
        if (t[j] == ',' && t[j + 1] == ' ')
        {
            char* x = nullptr;
            swap(x, *q);
            delete[]x;
            return;
        }
        x = new char[j - i + 1];
        for (; i < j; i++)
        {
            x[i - k] = t[i];
        }
        x[j - k] = '\0';
    }
    swap(x, *q);
    delete[]x;
}

blok* znajdzBlok(lista* head, int numer)
{
    int i = 0, j;
    while (head != nullptr)
    {
        if (i + head->zajetych >= numer)
        {
            for (j = 0; j < T; j++)
            {
                if (head->tab[j] != nullptr)
                    i++;
                if (i == numer)
                {
                    //p = head->tab[j];
                    //wypisz_blok(*(head->tab[j]));
                    return head->tab[j];
                }
            }
            znajdzBlok(head->next, numer-i);
            break;
        }
        i += head->zajetych;
        head = head->next;
    }
    return nullptr;
}

void i_S_j(lista* head, int i1, int i2)
{
    blok* blok_head = znajdzBlok(head, i1);
    if (blok_head == nullptr)
    {
        //blok_head = p;
        //p = nullptr;
        return;
    }
        //return;
    char* wyn = blok_head->selektory->jtySelektor(blok_head->selektory, i2);
    if (wyn == nullptr)
        return;
    cout << i1 << ",S," << i2 << " == " << wyn << endl;
}

void i_S_znakZap(lista* head, int numer)
{
    int wyn = -1;
    blok* blok_head = znajdzBlok(head, numer);
    if (blok_head == nullptr)
    {
        //blok_head = p;
        //p = nullptr;
        return;
    }
        //return;
    wyn = blok_head->selektory->liczEle(blok_head->selektory);
    if (wyn == -1)
        return;
    cout << numer << ",S,? == " << wyn << endl;
}

void i_A_znakZap(lista* head, int numer)
{
    int wyn = -1;
    blok* blok_head = znajdzBlok(head, numer);
    //wypisz_blok(*blok_head);
    if (blok_head == nullptr)
    {
        //blok_head = p;
        //p = nullptr;
        return;
    }
        //return ;
    wyn = blok_head->atrybuty->liczEle(blok_head->atrybuty);
    if (wyn == -1)
        return;
    cout << numer << ",A,? == " << wyn << endl;
}

void i_A_n(lista* head, int numer, char* n)
{
    char* wyn = nullptr;
    blok* blok_head = znajdzBlok(head, numer);
    if (blok_head == nullptr)
        return;
    wyn = blok_head->atrybuty->znajdzWartosc(blok_head->atrybuty, n);
    if (wyn == nullptr)
        return;
    cout << numer << ",A," << n << " == " << wyn << endl;
}

lista* i_D_gwiazdka(lista* head, int numer)
{
    lista* tmp = head;
    int i = 0, j;
    while (head != nullptr)
    {
        if (i + head->zajetych >= numer)
        {
            for (j = 0; j < T; j++)
            {
                if (head->tab[j] != nullptr)
                    i++;
                if (i == numer)
                {
                    head->zajetych--;
                    //czyszczenie(head->tab[j]);
                    head->tab[j] = nullptr;
                    head = remove(tmp, head);
                    cout << numer << ",D,* == deleted\n";
                    return tmp;
                }
            }
            head = remove(tmp, head);
            i_D_gwiazdka(head, numer-i);
            break;
        }
        i += head->zajetych;
        head = head->next;
    }
    return tmp;
}

lista* i_D_n(lista* head, int numer, char* n)
{
    lista* tmp = head;
    int i = 0, j;
    while (head != nullptr)
    {
        if (i + head->zajetych >= numer)
        {
            for (j = 0; j < T; j++)
            {
                if (head->tab[j] != nullptr)
                    i++;
                if (i == numer)
                {
                    bool b = false, corr = false;
                    head->tab[j]->atrybuty = head->tab[j]->atrybuty->pop_name(head->tab[j]->atrybuty, n, b, corr);
                    if (b == true)
                    {
                        cout << numer << ",D," << n << " == deleted\n";
                        head->zajetych--;
                        head = remove(tmp, head);
                        head->tab[j] = nullptr;
                    }
                    if (corr == true)
                        cout << numer << ",D," << n << " == deleted\n";
                    return tmp;
                }
            }
            break;
        }
        i += head->zajetych;
        head = head->next;
    }
    return tmp;
}

void n_A_znakZap(lista* head, char* c1)
{
    int i = 0;
    while (head != nullptr)
    {
        for (int j = 0; j < T; j++)
        {
            if (head->tab[j] != nullptr)
            {
                i += head->tab[j]->atrybuty->iloscWystapien(head->tab[j]->atrybuty, c1);
            }
        }
        head = head->next;
    }
    cout << c1 << ",A,? == " << i << endl;
}

void z_S_znakZap(lista* head, char* c1)
{
    int i = 0;
    while (head != nullptr)
    {
        for (int j = 0; j < T; j++)
        {
            if (head->tab[j] != nullptr)
            {
                i += head->tab[j]->selektory->iloscWystapien(head->tab[j]->selektory, c1);
            }
        }
        head = head->next;
    }
    cout << c1 << ",S,? == " << i << endl;
}

void z_E_n(lista* tail, char* sel, char* atr)
{
    while (tail != nullptr)
    {
        for (int i = T-1; i >= 0; i--)
        {
            if (tail->tab[i] != nullptr)
            {
                if (tail->tab[i]->selektory->iloscWystapien(tail->tab[i]->selektory, sel) == 1)
                {
                    char* wyn = tail->tab[i]->atrybuty->znajdzWartosc(tail->tab[i]->atrybuty, atr);
                    if (wyn != nullptr)
                    {
                        cout << sel << ",E," << atr << " == " << wyn << endl;
                        return;
                    }
                }
            }
        }
        tail = tail->prev;
    }
    if (tail == nullptr)
        return;
}

char* makeString(int i, int& poczatek, int& prawa, char* t, bool& napis)
{
    int size = i - poczatek - prawa + 1;
    char* r = new char[size];
    //cout << size << " " << i << " " << poczatek << " " << prawa << endl;
    for (int j = poczatek; j < i - prawa; j++)
    {
        int z = j-poczatek;
        r[j - poczatek] = t[j];
    }
    r[size - 1] = '\0';
    prawa = 0;
    poczatek = i + 1;
    napis = false;
    //cout << "*" << r << "*\n";
    return r;
}

int rzeczywistaLista(lista* head)
{
    int licz = 0, l=0;
    while (head != nullptr)
    {
        for (int i = 0; i < T; i++)
            if (head->tab[i] != nullptr)
                l++;
        head = head->next;
    }
    return l;
}