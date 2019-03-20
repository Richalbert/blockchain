/*
 * Block.cpp
 *
 * 		Author 		: Richard
 * 		Version		: 0318-1155
 * 		Description	:
 *
 */

#include "Block.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <stdio.h>


using namespace std;

// constructor
Block::Block():m_index(0),m_data("data du block zero")
{
	cout << "dans le constructeur par defaut (sans parametre)" << endl;

	time_t timer = time(NULL);
        this->m_timestamp.append(ctime(&timer));
        this->m_timestamp.pop_back();   //remove \n



	/* write a file */
	ofstream ofs("block0.txt");
	if (ofs.is_open()){
		ofs << this->getIndex()     << endl;
		ofs << this->getTimestamp() << endl;
		ofs << this->getData()      << endl;
		ofs.close();
	}else{
		cout << "File fail" << endl;
	}

	/* hash the block_0 et 
	 * mise a jour du champ hashOfPrviousBlock  
	 * */
	char  hash[255];
	FILE *pFile = popen("md5sum block0.txt | awk '{print $1}'","r");
	if (pFile !=NULL) {
		while (fgets(hash,sizeof(hash),pFile)){
		//	cout << hash << endl;
			this->m_hashOfPreviousBlock.append(hash);
			this->m_hashOfPreviousBlock.pop_back();
		}
	}else{
		cout << "popen fail" << endl;
	}


	/* write a block_00 
	 * */
	ofstream ofs2("block00.txt");
	if (ofs2.is_open()){
		ofs2 << this->getIndex()               << endl;
		ofs2 << this->getTimestamp()           << endl;
		ofs2 << this->getData()                << endl;
		ofs2 << this->getHashOfPreviousBlock() << endl;
		ofs2.close();
	}else{
		cout << "ofs2 file fail" << endl;
	}


	/* hash the block_00 et 
	 * mise a jour du champ hashOfCurrentBlock  
	 * */
	char  hash[255];
	FILE *pFile = popen("md5sum block00.txt | awk '{print $1}'","r");
	if (pFile !=NULL) {
		while (fgets(hash,sizeof(hash),pFile)){
		//	cout << hash << endl;
			this->m_hashOfCurrentBlock.append(hash);
			this->m_hashOfCurrentBlock.pop_back();
		}
	}else{
		cout << "popen fail" << endl;
	}

	

	this->toString();
}
Block::Block(int index, std::string data, std::string hash):
	m_index(index),
	m_data(data),
	m_hashOfPreviousBlock(hash)
{
	time_t timer = time(NULL);	
	this->m_timestamp.append(ctime(&timer));
	this->m_timestamp.pop_back();	//remove \n

	/* write a file */
	ofstream ofs("block1.txt");
	if (ofs.is_open()){
		ofs << this->getIndex()               << endl;
		ofs << this->getTimestamp()           << endl;
		ofs << this->getData()                << endl;
		ofs << this->getHashOfPreviousBlock() << endl;
		ofs.close();
	}else{
		cout << "File fail" << endl;
	}

	/* hash the block */
	char  hashi[255];
	FILE *pFile = popen("md5sum block1.txt | awk '{print $1}'","r");
	if (pFile !=NULL) {
		while (fgets(hashi,sizeof(hash),pFile)){
		//	cout << hash << endl;
			this->m_hashOfPreviousBlock.append(hashi);
			this->m_hashOfPreviousBlock.pop_back();
		}
	}else{
		cout << "popen fail" << endl;
	}


	/* write a block */
	ofstream ofs2("block11.txt");
	if (ofs2.is_open()){
		ofs2 << this->getIndex()               << endl;
		ofs2 << this->getTimestamp()           << endl;
		ofs2 << this->getData()                << endl;
		ofs2 << this->getHashOfPreviousBlock() << endl;
		ofs2.close();
	}else{
		cout << "ofs2 file fail" << endl;
	}

}

//getter
int Block::getIndex()           { return this->m_index; }
string Block::getTimestamp()    { return this->m_timestamp; }
string Block::getData()		{ return this->m_data; }
string Block::getHashOfPreviousBlock()	{ return this->m_hashOfPreviousBlock; }



// setter
void Block::setIndex(int index)	{ 
	this->m_index=index; 
}
void Block::setTimestamp(std::string timestamp)	{ 
	this->m_timestamp.append(timestamp); 
}
void Block::setData(std::string data) {
	this->m_data.append(data);
}
//void Block::setHashOfPreviousBlock(std::string hashOfPreviousBlock){
//	this->m_hasgOfPreviousBlock.append(hashOfPreviousBlock);
//}

// destructor
Block::~Block()
{

}

void Block::toString() {

	cout << "  m_index     = " << getIndex() << endl;
        cout << "  m_timestamp = " << getTimestamp() << endl;
        cout << "  m_data      = " << getData() << endl;
	cout << "  m_previous  = " << getHashOfPreviousBlock() << endl;
	//cout << "  m_current   = " << getHashOfCurrentBlock() << endl;

}

