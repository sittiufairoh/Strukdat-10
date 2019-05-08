/*
Program		: exercise-01
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Circular Queue Array
Tanggal		: 8 Mei 2019
*/

#include <iostream>
using namespace std;

const int maxE = 5;

struct Queue{
	char data[maxE];
	int head;
	int tail;
};

void createQueue(Queue& Q){
    Q.head = -1;
    Q.tail = -1;
}

void push(Queue &Q){
    if(Q.head==-1){
		Q.head++, Q.tail++;
		cin>>Q.data[Q.head];
	}else{
		if(Q.tail<maxE-1){
			Q.tail++; cin>>Q.data[Q.tail];
		}else{
			if(Q.head==0){
				cout<<"Antrian Penuh!"<<endl;
			}else{
				Q.tail=0; cin>>Q.data[Q.tail];
        	}
	    }
    }
}

void pop(Queue& Q){
	if(Q.tail==-1){
		cout<<"Antrian kosong"<<endl;
	}
	else if(Q.head==Q.tail){
		Q.head=-1;
		Q.tail=-1;
	}
	else{
		if(Q.head<maxE-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}

void print(Queue& Q){
	if(Q.head==-1){
		cout<<"Antrian Kosong."<<endl;
	}
	else{
		int i=Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head>Q.tail){
			while(i<maxE){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				} i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}

int main(){
    Queue Q;
	int pil, n;
	char lagi;
	
	cout << "Masukkan banyak data : "; cin >> n;
	cout << "Input Nama(1 HURUF) : "<<endl;
	for(int i = 0; i < n; i++){
		push(Q);
	}
	
	do{
		cout << "\nCircular Queue Array \n1. Push\n2. Pop\n3. Print\nMasukkan pilihan : "; cin >> pil;
		switch(pil){
			case 1:
				push(Q);
				break;
			case 2:
				pop(Q);
				break;
			case 3:
				print(Q);
		}
		cout << "Kembali ke menu (Y/N) : "; cin >> lagi;
	} while(lagi == 'Y' || lagi == 'y');
	
	
	return 0;
}
