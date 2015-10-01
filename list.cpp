#include <iostream>
#include "list.h"
using namespace std;

address allocate (infotype x)
{
    address P;

    P=new element_list;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocate (address &P)
{
    delete P;
}

void create_list (list &L)
{
    first(L)=NULL;
    last(L)=NULL;
}

void insert_first (list &L, address P)
{
    if (first(L)!=NULL and last(L)!=NULL)
    {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        first(L)=P;
    }
    else
    {
        first(L)=P;
        next(P)=first(L);
        prev(P)=first(L);
        last(L)=P;
    }
}

void insert_after (list &L, address P, address Prec)
{
    prev(P)=Prec;
    next(P)=next(Prec);
    prev(next(Prec))=P;
    next(Prec)=P;
}

void delete_last (list &L, address &P)
{
    P=last(L);
    if (first(L)!=last(L))
    {
        last(L)=prev(last(L));
        next(P)=NULL;
        prev(P)=NULL;
        prev(first(L))=last(L);
        next(last(L))=first(L);
    }
    else
    {
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
        last(L)=NULL;
    }
    deallocate(P);
}

void sorting (list &L, int temp1)
{
    address P;
    infotype temp;

    P=first(L);
    for (int i=1; i<=temp1-1; i++)
    {
        P=first(L);
        for (int j=1 ; j<=(temp1-i); j++)
        {
            if (info(P).name > info(next(P)).name)
            {
                temp=info(next(P));
                info(next(P))=info(P);
                info(P)=temp;
                P=next(P);
            }
            else
            {
                P=next(P);
            }

        }
    }
}
