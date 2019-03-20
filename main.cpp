/*
 * main.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Block.h"

using namespace std;

int main(void){
	
	const string BLOCK_0   = "block0.txt";
	const string BLOCK_00  = "block00.txt";
	const string BLOCK_000 = "block000.txt";

	ifstream ifs(BLOCK_000);
	if (ifs.is_open()){
		/* le block0 a deja ete cree */
		cout << BLOCK_000 << " existe deja" << endl;
		//TODO recuperer les donnees du fichier et les verifier
	}else{
		cout << "*** Creation du block0 ***" << endl;
		Block b0;
	}	
	ifs.close();


	cout << "*** Creation du block1 ***" << endl;
	cout << "Entrer une chaine a sauvegarder : " << endl;
	string newData; 
	getline(cin,newData);
	cout << "Voulez vous sauvegarder : " << newData << " [oui|non]" << endl;
	string reponse;
	getline(cin,reponse);
	if (reponse == "oui" || reponse == "OUI" || reponse == "o" || reponse == "O") {
		cout << "vous avez repondu ... OUI" << endl;

		string index;
		string timestamp;
		string previousHash;
		string data;
		string currentHash;

		ifstream ifs(BLOCK_000);
		if (ifs.is_open()){
			getline(ifs,index);
			getline(ifs,timestamp);
			getline(ifs,data);
			getline(ifs,previousHash);
			getline(ifs,currentHash);

		cout << "index        du block 0 ==> " << index << endl;
		cout << "timestamp    du block 0 ==> " << timestamp << endl;
		cout << "data         du block 0 ==> " << data << endl;
		cout << "previousHash du block 0 ==> " << previousHash << endl;
		cout << "currentHash  du block 0 ==> " << currentHash << endl;

		}else{ cout << "File fail "<< endl; }
		ifs.close();	
	
		Block b1(1,newData,currentHash);
		b1.toString();

	}else{
		cout << "vous avez repondu ... NON" << endl;
	}




//	Block block(0,"ma premiere data");
	

//	cout << endl;
//	cout << "block 0" << endl;
//	cout << "******* " << endl;
//	block.toString();



	return 0;
}
