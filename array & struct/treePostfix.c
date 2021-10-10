#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node tree;
struct node{
    tree*kiri;
    tree*kanan;
    char data;
};

typedef struct{
    tree*data[50];
    int count;
}stack;

void insert();
tree*pop(stack*);
int derajat(char);
int kosong(stack*);
int penuh(stack*);
void inisialisasi(stack*);
void preorder(tree*);
void inorder(tree*);
void boking(char);
void push(tree*,stack*);
void postorder(tree*);
tree*p,*temp;
tree*bantuan;
stack operat,operan;

int main()
{
    int pilihan, i;
    char notasi[50];
    inisialisasi(&operan);
    inisialisasi(&operat);

    puts("PRAKTIKUM TREE ARITMATIKA 14.2\n");
    printf("Masukkan notasi inputan : ");
    gets(notasi);

    for(i = 0;i < strlen(notasi);i++){
        fflush(stdin);
        boking(notasi[i]);
        bantuan = p;

        if(notasi[i]== '('){
            push(bantuan, &operat);
        }
        else if(notasi[i] == ')'){
            temp = pop(&operat);
            temp->kanan = pop(&operan);
            temp->kiri = pop(&operan);
            push(temp, &operan);
            pop(&operat);
        }
        else if(notasi[i]=='*'||notasi[i]=='^'||notasi[i]=='/'||notasi[i]=='+'||notasi[i]=='-'){
            push(bantuan, &operat);
        }
        else if((notasi[i]>='A'&&notasi[i]<='Z')||(notasi[i]>='0'&&notasi[i]<='9')){
            push(bantuan, &operan);
        }
        else
            puts("Notasi inputan salah gan");
    }
    while((!kosong(&operan))&&(!kosong(&operat))){
        temp = pop(&operat);
        temp->kanan = pop(&operan);
        temp->kiri = pop(&operan);
    }

    do{
        puts("\nMENU TREE");
        puts("1. Preorder");
        puts("2. Postorder");
        puts("3. Inorder");
        puts("4. Exit");
        printf("masukkan pilihan anda : ");
        scanf("%d", &pilihan);
        fflush(stdin);

        if(pilihan == 1){
            puts("Hasil Preorder : ");
            preorder(temp);
            printf("\n");
        }
        else if(pilihan == 2){
            puts("Hasil Postorder : ");
            postorder(temp);
            printf("\n");
        }
        else if(pilihan == 3){
            puts("Hasil Inorder : ");
            inorder(temp);
            printf("\n");
        }
        else if(pilihan == 4){
            puts("Arigatou gonzaimasu");
            exit(0);
        }
        else{
            puts("Masukkan menu salah");
        }
    }while(1);
}

void boking(char input){
    p = (tree*)malloc(sizeof(tree));
    if(p == NULL){
        puts("Alokasi gagal, maaf");
        exit(0);
    }
    else{
        p->data = input;
        p->kiri = NULL;
        p->kanan = NULL;
    }
}

void push(tree*x, stack*s){
    if(penuh(s)){
        puts("Stack penuh, data tidak dapat disimpan");
    }else{
        s->data[s->count] = x;
        s->count++;
    }
}

tree*pop(stack*s){
    tree*temp;

    if(kosong(s)){
        puts("Saat ini Stack Kosong, tidak dapat mengambil data.");
    }else{
        s->count--;
        temp = s->data[s->count];
        return(temp);
    }
}

void inisialisasi(stack*s){
    s->count = 0;
}

int kosong(stack*s){
    if(s->count==0)
        return(1);
    else
        return(0);
}

int penuh(stack*s){
    if(s->count==50)
        return(1);
    else
        return(0);
}

int derajat(char masuk){
    if(masuk == '^')
        return 4;
    else if(masuk== '*'||masuk=='/')
        return 3;
    else if(masuk=='+'||masuk=='-')
        return 2;
    else if(masuk=='(')
        return 1;
    else
        return 0;
}

void preorder(tree*node){
	if(node!=NULL){
		printf("%c ",node->data);
		preorder(node->kiri);
		preorder(node->kanan);
	}
}

void inorder(tree *node){
	if(node!=NULL){
		inorder(node -> kiri);
        printf("%c ",node -> data);
		inorder(node -> kanan);
	}
}

void postorder(tree *node){
	if(node!=NULL){
		postorder(node -> kiri);
		postorder(node -> kanan);
		printf("%c ",node -> data);
	}
}
