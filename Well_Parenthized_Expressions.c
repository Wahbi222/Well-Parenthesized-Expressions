// The TP is divided into 3 parts:
// Well-parented expressions
// Postfixed notation
// Evaluation of a postfixed expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The first thing to do is to define the data structures to be used which are the stacks and the queues

// We define for each structure the necessary functions to manipulate them


//Stack

//Structure's Definition
typedef struct pp{
    int val;
    struct pp *suivant;
} pile;

// Intialisation de la pile
pile* creerpile(){
    return NULL;
}

//Verifyig if the stack is empty
char estvide(pile *p){
    return (p==NULL);
}


//push
pile *empiler(pile *p,int donnee)
{
    pile *p_nouveau;
    if ((p_nouveau=(pile *)malloc (sizeof(pile)))==NULL)
    {printf ("erreur allocation");
    exit(1);
    }
    p_nouveau->val = donnee;
    p_nouveau->suivant = p;
    return p_nouveau;
}

//pop
pile *depiler(pile *p)
{
pile *p_libre;
if(estvide(p))
{ printf ("erreur la pile estvide");
exit(1);
}
p_libre= p;
p = p->suivant;
free(p_libre);
return p;
}


//Getting the head value of the stack
int obtenir_tete (pile*p)
{
if(estvide(p))
{ printf ("erreur lapile est vide");
exit(1);
}
return p->val ;
}


//Queue

//Definition of the element that the queue will contain
typedef struct el
{
int val;
struct el *suiv;
struct el *pre;
} element;

// The queue's structure
typedef struct ff
{
element *debut;
element *fin;
int taille;
} File;

//Enqueue
File * enfiler (File *f, int data)
{
element *z;
z=(element *) malloc (sizeof(element));
z->val=data;
if(estvidefile (f))
{
z->suiv=NULL;
z->pre =NULL;
f->debut= z;
f->fin=z;

}
else
{
z->suiv=f->fin;
z->pre=NULL;
(f->fin)->pre=z;
f->fin=z;
}
f->taille++;
return f ;
}

// Dequeue
File *defiler ( File *f )
{ element *y;
if (f->taille==0)
exit(1);
if (f->taille==1)
{ free(f->debut);
f->debut=NULL;
f->fin=NULL;
f->taille=0; }
else { y=f->debut;
f->debut=y->pre;
( f->debut)->suiv=NULL;
free(y);
f->taille--; }
return f ;
}

//Get the value of the head of the queue
int valeur_tete ( File * f )
{
{
if (f->taille==0)
exit(1);
}
return((f->debut)->val);
}

// Verify if a queue is empty
int estvidefile(File *f)
{
if(f==NULL){
    return 1;
}else{
    if(f->taille == 0)
        return 1;
}
return 0;
}

// This part contains the functions developed to answer the questions of the TP

// Exercise 1: Well-parented expressions

// The concept is to check if an expression is well parenthesized, that is if the number of opening parentheses is equal to
// the number of closing parentheses


int bien_parenthese(char exp[]){
    pile *p = creerpile(); // We will store the parentheses of our expression in a stack
      for ( int i = 0; i<strlen(exp);i++)
	{
        if(exp[i] == '(')
        {
           p=empiler(p,exp[i]); // if the parenthesis is opening, we push it to the stack
        }
        else {
                if (exp[i] == ')' && (!estvide(p)))
            {
                p=depiler(p); // if the parenthesis is closing and the stack is not empty, we pop the stack
            }
	}
	}
    int parenthese; 
	if(estvide(p)) 
        {
       parenthese=1;
	}
	else
	{
	   parenthese=0; 
	}
return parenthese; 
}

// Exercice 2 : Postfixed Notation

// The purpose of this exercise is to transform an infixed expression into a postfixed expression

char* postfixe(char exp[]){
    pile *p = creerpile(); 
    File *f=  (File *)malloc(sizeof(File)); 
    f->debut = NULL;
    f->fin = NULL;
    char *expression =malloc(100); 
    int j=0;
    for(int i =0; i<strlen(exp); i++){
        if((exp[i] <= 'z')&&(exp[i] >= 'a')){
            f = enfiler(f,exp[i]); 
        }else{
            if((exp[i] == '*') || (exp[i] == '+') || (exp[i] == '/') || (exp[i] == '-') || (exp[i]=='^')){
                p = empiler(p, exp[i]); 
            }else{
                if(exp[i] == ')'){ 
                        while(!estvidefile(f)){ 
                            expression[j++] = valeur_tete(f); 
                            f = defiler(f); 
                        }
                        expression[j++] = obtenir_tete(p); 
                        p = depiler(p);
                }
            }
        }
    }
    for(int i=0;i<j;i++){
        printf("%c",expression[i]); 
    }
    return expression; 
}

// Exercise 3 : Evaluation of a postfixed expression

// The purpose of this exercise is to calculate a postfixed expression


int calculer( int op1, int op2, char operateur )
{
if (operateur=='+') 
return op1+op2;
else if (operateur=='-')
return op1-op2;
else if (operateur=='*')
return op1*op2;
else if (operateur=='/')
return op1/op2;
else if (operateur=='^')
return op1^op2;
else{
return printf("Erreur");
}
}


int evaluation_postfixe(char exp[])
{
    pile *p = NULL; 
                    
    int reponse=0; 
    int i=0;
    for (i=0;i<=strlen(exp);i++)

    {
        if(exp[i]>='a' && exp[i]<='z') 
        {
            int valeur;
            printf("Donner une valeur"); 
            scanf("%d",&valeur);
            p=empiler(p,valeur); 

        }
        else
        {  if((exp[i] == '*') || (exp[i] == '+') || (exp[i] == '/') || (exp[i] == '-')) { 
                int x=obtenir_tete(p); 
                p=depiler(p); 
                int y=obtenir_tete(p); 
                p=depiler(p); 
                int z=calculer(x,y,exp[i]); 
                p=empiler(p,z); 
        }
        }

    if (exp[i]=='\0'){ 
    reponse=obtenir_tete(p); 
    } }
    return reponse; 

}

// Main
void main(){
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);n
    int parenthese=bien_parenthese(expression); 
    if(parenthese==1){
        printf("L'expression est bien parenthesee"); 
    }
    else{
        printf("L'expression n'est pas bien parenthesee"); 
    }
    printf("\n");
    char *expression_postfixe = postfixe(expression); 
    printf("\n");
    int reponse=evaluation_postfixe(expression_postfixe);
    printf("%d",reponse);



}

