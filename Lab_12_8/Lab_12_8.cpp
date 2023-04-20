#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next;
    Elem* prev;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    Elem* T = L;
    if (L != NULL)
    {
        while (T->next != L)
            T = T->next;
        T->next = tmp;
        tmp->prev = T;
    }
    else
        L = tmp;
    L->prev = tmp;
    tmp->next = L;
}

void print(Elem* L)
{
    Elem* F = L;
    do 
    {
        cout << L->info << "  ";
        L = L->next;
    } while (L != F);
    cout << endl;
}

void neighbor(Elem* L)
{
    Elem* F = L; bool found = false; int pos = 0, n = 0;
    do 
    {
        if (L->prev->info == L->next->info)
        {
            cout << "Equal neighbors found near position " << pos << " (" << L->info << ") : " << L->next->info << endl;
            found = true;
            n++;
        }
        pos++;
        L = L->next;
    } while (L != F);
    if (found)
        cout << "Number of equal neighbors : " << n << endl;
    else
        cout << "No equal neighbors were found" << endl;
}

void delmin(Elem*& L)
{
    Elem* F = L; Info min = L->info; bool first;
    while (L->next != F)
    {
        L = L->next;
        if (L->info < min)
            min = L->info;
    }
    L = F;
    do
    {
        first = false;
        if (L->info == min)
        {
            if (L == F)
            {
                first = true;
                F = F->next;
            }
            Elem* next = L->next;
            Elem* prev = L->prev;
            delete L;
            next->prev = prev;
            prev->next = next;
            L = next;
        }
        else
            L = L->next;
    } while (L != F || first);
    L = F;
}

int main()
{
    Elem* L = NULL; int imax, value;
    cout << "Enter the amount of values : ";
    cin >> imax;
    for (int i = 0; i < imax; i++)
    {
        cout << "Enter the value : ";
        cin >> value;
        insert(L, value);
    }
    print(L);
    neighbor(L);
    delmin(L);
    print(L);
}