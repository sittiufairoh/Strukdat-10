/*
Program		: exercise-02
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Circular Queue Linked List
Tanggal		: 8 Mei 2019
*/

#include <iostream>
using namespace std;

struct QueueList{
	char info;
	QueueList* next;
};

struct Queue{
	QueueList *head;
	QueueList *tail;
};

typedef QueueList* pointer;
typedef pointer List;
Queue Q;

void createQueue(Queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}

void createList(pointer &pBaru){
	pBaru=new QueueList;
	cout << "Masukkan huruf: "<<endl; cin>>pBaru->info;
	pBaru->next=NULL;
}

void push(Queue &Q, pointer &pBaru){
	if(Q.head==NULL){
		Q.head=pBaru;
		Q.tail=pBaru;
	}else{
		Q.tail->next=pBaru;
		Q.tail=pBaru;
	}
}

void pop(Queue &Q, pointer pHapus){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		pointer pHapus;
		pHapus=Q.head;
		Q.head=Q.head->next;
		pHapus->next=NULL;
	}
}

void print(Queue Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		pointer pBantu=Q.head;
		cout<<endl<<"Q = [";
		while(pBantu!=NULL){
			cout<<pBantu->info;
			if(pBantu->next!=NULL){
				cout<<", ";
			}
			pBantu=pBantu->next;
		}
		cout<<"]"<<endl;
	}
}

int main(){
	Queue Q;
	pointer p, pHapus;
	char pil;
	int menu;
	
	createQueue(Q);

	do{
		system("cls");
		cout << "\nCircular Queue Linked List \n1. Push\n2. Pop\n3. Print\nMasukkan pilihan : ";
		cin >> menu;
		switch(menu)
		{
			case 1: createList(p);
					push(Q,p); 
					break;
			case 2: pop(Q,pHapus); 
					break;
			case 3: print(Q);
					break;
			default: cout << "Wrong Option.\n"; 
					 break;
		}
		cout << "Again? (Y/N) "; cin >> pil;
	} while (pil=='Y' || pil=='y');
}
