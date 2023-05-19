#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nod
{
    int n;
    struct nod *urm;
}nod;

nod *addlast(nod *rad,int x)
{
    nod *q=(nod*)malloc(sizeof(nod));
    q->n=x;
    q->urm=NULL;
    if (rad==NULL) rad=q;
    else
    {
        nod *t=rad;
        while (t->urm!=NULL) t=t->urm;
        t->urm=q;
    }
    return rad;
}

nod *addfirst(nod *rad,int x)
{
    nod *q=(nod*)malloc(sizeof(nod));
    q->n=x;
    q->urm=rad;
    rad=q;
    return rad;
}

nod *erasefirst(nod *rad)
{
    nod *t=rad;
    rad=rad->urm;
    free(t);
    return rad;
}

nod *erase(nod *rad,int x)
{
    nod *q=rad;
    while (q->urm->n!=x && q->urm!=NULL) q=q->urm;
    nod *t=q->urm;
    q->urm=t->urm;
    free(t);
    return rad;
}

void see(nod *rad)
{
    nod *t=rad;
    while (t!=NULL)
    {
        printf("%d\n",t->n);
        t=t->urm;
    }
}

int main()
{
    int tip=0,x=0;
    nod *rad=NULL;

    while(true)
    {
        printf("0. Exit\n");
        printf("1. Add last\n");
        printf("2. Add first\n");
        printf("3. Erase first\n");
        printf("4. Erase\n");
        printf("5. Display list\n");
        scanf("%d",&tip);

        switch(tip)
        {
        case 0:
            return 0;
        case 1:
            scanf("%d",&x);
            rad=addlast(rad,x);
            break;
        case 2:
            scanf("%d",&x);
            rad=addfirst(rad,x);
            break;
        case 3:
            rad=erasefirst(rad);
            break;
        case 4:
            scanf("%d",x);
            rad=erase(rad,x);
            break;
        case 5:
            see(rad);
            break;
        }
    }
}



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nod{
    char *ide;
    struct nod* urm;
}nod;

nod *r1=NULL,*r2=NULL,*ri=NULL,*rr=NULL,*rs=NULL;

nod *adauga(nod *lista, nod*aux)
{
    nod *q1,*q2;
    for (q1=q2=lista;q1!=NULL && strcmp(q1->ide,aux->ide)<0;q2=q1,q1=q1->urm);
    if (q1!=NULL && strcmp(q1->ide,aux->ide)==0)
    {
        free(aux->ide);
        free(aux);
        return lista;
    }
    if (q1==q2)   // adaugare in capul listei
    {
        aux->urm=lista;
        lista=aux;
    }
    else // se adauga dupa primul nod
    {
        q2->urm=aux;
        aux->urm=q1;
    }
    return lista;
}

nod *read(char *lista,char NumeFisier[])
{
    FILE *f;
    nod *aux;
    char id[30];
    if ((f=fopen(NumeFisier,"rt"))==NULL)
    {
        printf("fisierul nu a fost gasit");
        return lista;
    }
    while (!feof(f))
    {
        fscanf(f,"%s",id);
        aux=(nod*)malloc(sizeof(nod));
        aux->ide=(char*)malloc(strlen(id)+1);
        strcpy(aux->ide,id);
        lista=adauga(lista,aux);
    }
    fclose(f);
    return lista;
}

nod *inter(nod *lista)
{
    nod *p=r1,*q=r2,*aux;
    while (p!=NULL)
    {
        q=r2;
        while (q!=NULL)
        {
            if (strcmp(q->ide,p->ide)==0)
            {
                aux=(nod*)malloc(sizeof(nod));
                aux->ide=(char*)malloc(strlen(q->ide)+1);
                strcpy(aux->ide,q->ide);
                lista=adauga(lista,aux);
            }
            q=q->urm;
        }
        p=p->urm;
    }
    return lista;
}

nod *reun(nod *lista)
{
    nod *p=r1, *q=r2,*aux;
    while (p!=NULL)
    {
        aux=(nod*)malloc(sizeof(nod));
        aux->ide=(char*)malloc(strlen(p->ide)+1);
        strcpy(aux->ide,p->ide);
        lista=adauga(lista,aux);
        p=p->urm;
    }
    while (q!=NULL)
    {
        p=r1;
        while (p!=NULL)
        {
            if (strcmp(q->ide,p->ide)!=0)
            {
                aux=(nod*)malloc(sizeof(nod));
                aux->ide=(char*)malloc(strlen(q->ide)+1);
                strcpy(aux->ide,q->ide);
                lista=adauga(lista,aux);
            }
            p=p->urm;
        }
        q=q->urm;
    }
    return lista;
}

nod *scad(nod *lista)
{
    int ok;
    nod *p=r1,*q=r2,*aux;
    while (p!=NULL)
    {
        ok=0;
        q=r2;
        while (q!=NULL)
        {
            if (strcmp(q->ide,p->ide)==0)
            {
                ok=1;
                break;
            }
            q=q->urm;
        }
        if (ok==0)
        {
            aux=(nod*)malloc(sizeof(nod));
            aux->ide=(char*)malloc(strlen(p->ide)+1);
            strcpy(aux->ide,p->ide);
            lista=adauga(lista,aux);
        }
        p=p->urm;
    }
    return lista;
}

nod *erase(nod *rad,char s[])
{
    nod *q=rad;
    while (strcmp(q->urm->ide,s)!=0 && q->urm!=NULL) q=q->urm;
    nod *t=q->urm;
    q->urm=t->urm;
    free(t);
    return rad;
}

void see(nod *lista)
{
    nod *q=lista;
    while (q!=NULL)
    {
        printf("%s ",q->ide);
        q=q->urm;
    }
    printf("\n");
}

int main(void)
{
    r1=read(r1,"input.in");
    r2=read(r2,"input.out");
    see(r1);
    see(r2);
    ri=inter(ri);
    see(ri);
    rr=reun(rr);
    see(rr);
    rr=erase(rr,"doi");
    see(rr);
    rs=scad(rs);
    see(rs);
}
