#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if(n == 0)
        ultimo = p;
    else
        primeiro->setAnt(p);

    primeiro = p;
    n = n + 1;
}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n = n - 1;

        if(n == 0)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
    }
    else
        cout << "ERRO: lista vazia" << endl;
}
void ListaDupla::removeOcorrencias(int val)
{
    if(n!=0)
    {
        NoDuplo *aux=primeiro;
        while(aux!=NULL)
        {
            if(primeiro->getInfo()==val)
            {
                removeInicio();
                aux=primeiro;
            }
            else
            {
                NoDuplo *p=aux;
                aux=aux->getProx();
                if(p->getInfo()==val)
                {
                    if(p->getProx()==NULL || p->getAnt()==NULL)
                    {
                        if(p->getProx()==NULL)
                        {
                            (p->getAnt())->setProx(NULL);
                        }
                        else if(p->getAnt()==NULL)
                        {
                            (p->getProx())->setAnt(NULL);
                        }
                        else
                        {
                            primeiro=NULL;
                            ultimo=NULL;
                        }
                    }
                    else
                    {
                        (p->getAnt())->setProx(p->getProx());
                        (p->getProx())->setAnt(p->getAnt());

                    }
                    delete p;
                    n--;
                }
            }
        }
    }
    else
    {
        cout<<"nn a nos"<<endl;
    }
}
void ListaDupla::imprime()
{
    NoDuplo*p=primeiro;
    while(p!=NULL)
    {
        cout<<p->getInfo()<<" ";
        p=p->getProx();
    }
    cout<<endl;
}
void ListaDupla::concatena(ListaDupla *l2)
{
    if(l2->getn()!=0)
    {
        NoDuplo*aux=l2->primeiro;
        ultimo->setProx(l2->primeiro);
        aux->setAnt(ultimo);
        ultimo=l2->ultimo;
        n=n+l2->n;
        l2->n=0;
        l2->primeiro=NULL;
        l2->ultimo=NULL;
    }
}
int ListaDupla::getn()
{
    return n;
}
void ListaDupla::insereFinal(int val)
{
    NoDuplo *p=new NoDuplo();
    p->setInfo(val);
    p->setAnt(ultimo);
    p->setProx(NULL);
    if(n!=0)
    {
        ultimo->setProx(p);
    }
    else
    {
        primeiro=p;
    }
    ultimo=p;
    n++;
}
ListaDupla* ListaDupla::partir(int x)
{
    ListaDupla *l2=new ListaDupla();
    if(primeiro!=0)
    {
        NoDuplo *p=primeiro;
        while()
        }

