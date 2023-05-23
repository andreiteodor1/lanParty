#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};
typedef struct Player JUCATOR;

struct lista
{
    int nr_jucatori;
    JUCATOR* x;
    char* numeEchipa;
    float teampoints;
    struct lista* next;
};
typedef struct lista ECHIPA;

struct coad
{
    ECHIPA* valoare;
    struct coad* next;
};
typedef struct coad coada;

struct Q
{
    ECHIPA *front, *rear;
};
typedef struct Q Queue;

Queue* createQueue()
{
    Queue*q;
    q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL)
    {
        return NULL;
        printf("ALLOCATION ERROR \n");
    }
    q->front=q->rear=NULL;
    return q;
}
int isEmptyQueue(Queue* queue)
{
    return(queue->front==NULL);
}

ECHIPA* deQueue(Queue* q)
{
    if(isEmptyQueue(q)) return INT_MIN;
    // printf("queue empty\n");
    //  exit(1);

    ECHIPA *aux, *address;
    address=(ECHIPA*)malloc(sizeof(ECHIPA));
    aux=q->front;
    address=q->front;
    q->front=(q->front)->next;
    free(aux);
    return address;
}

void enQueue(Queue *q, ECHIPA* team)
{
    if(q==NULL || team==NULL)
    {
        printf("null \n");
        exit(1);
    }
    ECHIPA* newNode=(ECHIPA*)malloc(sizeof(ECHIPA));
    newNode=team;
    newNode->next=NULL;
    if(q->rear==NULL) q->rear=newNode;
    else
    {
        (q->rear)->next=newNode;
        q->rear=newNode;
    }
    if(q->front==NULL) q->front=q->rear;
}


struct stiv
{
    ECHIPA* valoare;
    struct stiv* next;
};
typedef struct stiv stiva;

void push(stiva** top, ECHIPA* team)
{
    stiva* newNode=(stiva*)malloc(sizeof(stiva));
    newNode->valoare=team;
    newNode->next=*top;
    *top=newNode;
}
ECHIPA* pop(stiva** top)
{
    //verificare stiva goala
    stiva* temp=(*top);
    ECHIPA* aux=temp->valoare;
    *top=(*top)->next;
    free(temp);
    return aux;

}

int calculPutere (int n_echipe)
{
    int a=2;
    while(a<n_echipe)
    {
        a=a*2;
    }
    a=a/2;
    return a;
}

int calculPunctaj(ECHIPA* team)
{
    int i;
    int punctaj_echipa;
    for(i=0; i<team->nr_jucatori; i++)
    {
        punctaj_echipa=punctaj_echipa+team->x[i].points;
    }
    return punctaj_echipa;
}

void delete_team (ECHIPA** Node)
{
    int j;
    float punctaj_echipa;
    ECHIPA *aux, *p, *aux2;
    aux2=NULL;
    float min=9999;
    for(p=*Node; p!=NULL; p=p->next)
    {
        punctaj_echipa=0;
        for(j=0; j<p->nr_jucatori; j++)
        {
            punctaj_echipa=punctaj_echipa+p->x[j].points;
        }
        p->teampoints=punctaj_echipa;
        if(p->teampoints<min)
            min=p->teampoints;
    }
    for(aux=*Node; aux!=NULL; aux=aux->next)
    {
        if(aux->teampoints==min)
        {
            if(aux==*Node)
            {
                aux2=*Node;
                *Node=(*Node)->next;
                free(aux2);
                return;
            }
            else
            {
                aux2->next=aux->next;
                free(aux);
                return;
            }
        }
        aux2=aux;
    }

}

void createList(ECHIPA** head, FILE*f)
{
    int nr_echipe;
    fscanf(f,"%d", &nr_echipe);
    int i,j,k=0;
    char c;
    for(i=0; i<nr_echipe; i++)
    {

        ECHIPA* newNode;
        newNode=(ECHIPA*)malloc(sizeof(ECHIPA));

        fscanf(f,"%d",&newNode->nr_jucatori);
        fgetc(f);
        char buffer[40];
        fgets(buffer,40,f);
        newNode->numeEchipa=(char*)malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(newNode->numeEchipa,buffer);
        newNode->x=(JUCATOR*)malloc((newNode->nr_jucatori)*sizeof(JUCATOR));
        for(j=0; j<newNode->nr_jucatori; j++)
        {
            fscanf(f,"%s",buffer);
            newNode->x[j].firstName=(char*)malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(newNode->x[j].firstName,buffer);
            fscanf(f,"%s",buffer);
            newNode->x[j].secondName=(char*)malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(newNode->x[j].secondName, buffer);
            fscanf(f,"%d", &newNode->x[j].points);

        }
        newNode->next=*head;
        *head=newNode;

    }
}

int main(int argc, char* argv[])
{
    ECHIPA *head, *headcopy;
    head=NULL;
    int teams,i;
    int nr_teams=0, no_teams;
    int cerinte[5];
    FILE* f;
    FILE* r;
    f=fopen(argv[1], "rt");
    if(f==NULL)
    {
        printf("ERROR f \n");
        exit(1);
    }
    for(i=0; i<5; i++)
    {
        fscanf(f,"%d",&cerinte[i]);
    }
    fclose(f);
    if(cerinte[0]==1)
    {
        f=fopen(argv[2], "rt");
        if(f==NULL)
        {
            printf("ERROR \n");
            exit(1);
        }
        r=fopen(argv[3], "w");
        if(r==NULL)
        {
            printf("ERROR \n");
            exit(1);
        }
        createList(&head,f);
        ECHIPA* headcpy;
        for(headcpy=head; headcpy!=NULL; headcpy=headcpy->next)
        {
            fprintf(r,"%s", headcpy->numeEchipa);
        }
        fclose(f);
        fclose(r);
    }
    if(cerinte[1]==1)
    {
        ECHIPA* aux;
        for(aux=head; aux!=NULL; aux=aux->next)
        {
            nr_teams++;
        }
        no_teams=nr_teams;


        r=fopen(argv[3], "wt");
        if(r==NULL)
        {
            printf("ERROR \n");
            exit(1);
        }
        int b,k;
        b=calculPutere(nr_teams);
        for(k=0; k<(nr_teams-b); k++)
        {
            delete_team(&head);
        }
        for(aux=head; aux!=NULL; aux=aux->next)
        {
            fprintf(r,"%s", aux->numeEchipa);
        }
        fclose(r);
    }



    if(cerinte[2]==1)
    {
        r=fopen(argv[3], "at");
        if(r==NULL)
        {
            printf("ERROR \n");
            exit(1);
        }

        Queue *q;
        q=createQueue();
        for(headcopy=head; headcopy!=NULL; headcopy=headcopy->next)
        {
            enQueue(q,headcopy);
        }

        int contor=0;
        fprintf(r,"--- ROUND NO:%d",contor+1);
        for(i=0; i<no_teams/2; i++)
        {
            ECHIPA *team1,*team2;
            team1=deQueue(q);
            team2=deQueue(q);
            fprintf(r,"%-33s%s%-33s",team1->numeEchipa,"-",team2->numeEchipa);
            contor++;
            printf("%d", contor);
        }

        stiva* stackTop=NULL;
        fclose(r);
    }
    return 0;
}

