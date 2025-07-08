#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct mahasiswa{
	int nim[100];
	string nama[100];
	float nilaiUTS[100];
	float nilaiUAS[100];
	float ratarata[100];
	int data;
};

int jumlahdata=0;

void buatdata(){
	int data;
	ofstream file("data.txt",ios::app);
	if(!file){
		cout<<"gagal membuka file"<<endl;
		return;
	}
	mahasiswa c;
	cout<<endl;
	cout<<"masukan banyak data yang ingin di simpan :";
	cin>>c.data;
	
	for(int a=1; a<=data; a++){
		cout<<"================================="<<endl;
		cout<<"masukan nama ke-"<<a<<" : ";
		cin.ignore();
	    getline(cin,c.nama[a]);
		cout<<"masukan nim ke-"<<a<<" : ";
		cin>>c.nim[a];
		cout<<"masukan nilai UTS ke-"<<a<<" : ";
		cin>>c.nilaiUTS[a];
		cout<<"masukan nim UAS-"<<a<<" : ";
		cin>>c.nilaiUAS[a];
		cout<<"rata rata nilai ke-"<<a<<" : ";
		c.ratarata[a]=(c.nilaiUAS[a]+c.nilaiUTS[a])/2;
		cout<<c.ratarata[a];
		cout<<endl;
		cout<<"=================================="<<endl;
		jumlahdata++;
		
	}
	
	
	file << c.nim <<","<<c.nama<<","<<c.nilaiUTS<<","<<c.nilaiUAS<<endl;
	file.close();
	cout<<"data berhasil ditambahkan \n";
	}

void urutkanterkecil(){
	mahasiswa c;
	int temp;
	for(int i=0; i<=jumlahdata-1; i++){
		for(int j=0; j<=jumlahdata-i-1; j++){
			if(c.ratarata[j]>c.ratarata[j+1]){
				temp = c.ratarata[j];
				c.ratarata[j] = c.ratarata[j+1];
				c.ratarata[j+1] = temp;
			}
		}
	}
	
	for(int u=0; u<=jumlahdata; u++){
		cout<<c.ratarata[u];
	}
	
}

void urutkanterbesar(){
	mahasiswa c;
	int temp;
	for(int i=0; i<=jumlahdata-1; i++){
		for(int j=0; j<=jumlahdata-i-1; j++){
			if(c.ratarata[j]<c.ratarata[j+1]){
				temp = c.ratarata[j];
				c.ratarata[j] = c.ratarata[j+1];
				c.ratarata[j+1] = temp;
			}
		}
	}
	
	for(int u=0; u<=jumlahdata; u++){
		cout<<c.ratarata[u];
	}
	
}

void bacadata(){
	ifstream file("data.txt");
	if(!file){
		cout<<"file tidak ditemukan \n";
		return ;}
	
	string nama;
	int nim;
	float nilaiUAS, nilaiUTS, ratarata;
	
		cout<<"====LIHAT DATA===="<<endl;
		cout<<"nama :"<<nama<<endl;
		cout<<"nim :"<<nim<<endl;
		cout<<"nilai UAS :"<<nilaiUAS;
		cout<<"nilai UTS :"<<nilaiUTS;
		cout<<"rata rata :"<<ratarata;
	
	file.close();
}

void ubahdata(){
	ifstream file("data.txt");
	ofstream temp("temp.txt");
	
	if(!file || !temp){
		cout<<"gagal membuka file\n";
		return ;
	}
	string tujuannim, namabaru;
	cout<<"masukan id yang ingin di edit :";
	cin>>tujuannim;
	cout<<"masukan nama baru :";
	cin.ignore();
	getline(cin,namabaru);
	
	string line;
	bool found = false;
	while(getline(file, line)){
		stringstream ss(line);
		string nim, nama;
		getline(ss, nim ,',');
		getline(ss, nama);
		
		if(nim == tujuannim){
			temp << nim <<","<< namabaru <<endl;
			found = true;
		}else {
			temp<<nim<<","<<nama<<endl;
		}
	}
	file.close();
	temp.close();
	
	remove("data.txt");
	rename("temp.txt","data.txt");
	
	if(found)
	cout<<"Data berhasil di update.\n";
	else
	cout<<"ID tidak ditemukan.\n";
}

void menu(){
	cout<<"\n=====MENU======\n";
	cout<<"1.tambah data"<<endl;
	cout<<"2.lihat data"<<endl;
	cout<<"3.edit data"<<endl;
	cout<<"4.mengurutkan rata rata terkecil"<<endl;
	cout<<"5.mengurutkan rata rata terbesar"<<endl;
	cout<<"0.keluar"<<endl;
	cout<<"pilih :";
	
}

int main(){
	int pilihan;
	
	do{
	menu();
	cin>>pilihan;
	switch(pilihan){
		case 1: buatdata(); break;
		case 2: bacadata(); break;
		case 3: ubahdata(); break;
		case 4: urutkanterkecil();break;
		case 5: urutkanterbesar();break;
		case 0: cout<<"keluar\n"; break;
		default: cout<<"pilihan tidak valid\n";
		
	}
}while(pilihan != 0);
return 0;
}
