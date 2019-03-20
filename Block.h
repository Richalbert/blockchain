/*
 * Block.h
 *
 *  Created on: 18 mars 2019
 *      Author: richard
 *
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {

	private:
		int  m_index;			
		std::string m_timestamp;
		std::string m_data;	
		std::string m_hashOfPreviousBlock;
		std::string m_hashOfCurrentBlock;		

	public:
		// constructor
		Block();		// pour le block_0
		Block(int index,	// pour tout nouveau block
		      std::string data,
		      std::string hashOfPreviousBlock
	        );

		// copy constructor
		Block(Block const & blockAcopier);

		// destructor
		~Block();

		// getter 
		int getIndex();		
		std::string getTimestamp();
		std::string getHashOfPreviousBlock();
		std::string getData();
		std::string getHashOfCurrentBlock();

		// setter
		void setIndex(int index); 
		void setTimestamp(std::string timestamp);
		void setHashOfPreviousBlock(std::string hashOfPreviousBlock);
		void setData(std::string data);
//		void setHashOfCurrentBlock(std::string hashOfCurrentBlock);

		// surchage d operateur
		friend bool operator==(Block const &a, Block const &b);

		void toString();

		// methodes de copie de du block dans un fichier


};


		

#endif
