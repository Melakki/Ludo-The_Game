#pragma once

#include <iostream>
#include <array>
#include "ludo_box.h"
#include "utilities.hpp"

class _BoardPrinter{ //! @info Only for use by updateDisplay() & takeIntro()
private:
	/*@note Also clears the screen, so that the titlebar is at top
	  @returns Terminalstd::pair<int,int> as pair<int,int>*/

	//Common data that will be used
	const std::vector<std::vector<ludo_box>> &board;

	static void titleBar(int width);
	static void titleBar(); /*@brief Simply just calls titleBar with (terminalDimen().first)*/
	static void errorScreen(std::string errMsg);
    static void finishedScreen(void);
    	/*FUTURE - It can be modified to show who's the 1st and who's the 4th, BUT FOR NOW I WILL NOT IMPLEMENT IT HERE, SINCE I HAVE FURTHER PENDING PLANS FOR GUI*/

    void row_type1(int nrow);
    void row_type2(int nrow);
    void row_type3(int nrow);
    void row_type4(int nrow);

    void inter_type1();
    void inter_type2();
    void inter_type3();
    void inter_type4();
    void inter_type5();

    void refresh_Dimensions();

    friend class game;

public:
	unsigned int boxlen;
	int termWidth;
	explicit _BoardPrinter( const std::vector<std::vector<ludo_box>>& );	//! Links to the board
	_BoardPrinter() = delete;

};

//Defintions Start
_BoardPrinter::_BoardPrinter( const std::vector<std::vector<ludo_box>>& boardToLink ) : board(boardToLink){
	boxlen = 0;
	termWidth = customUtil::getTerminalDimen().first;
}

void _BoardPrinter::refresh_Dimensions(){
	termWidth = customUtil::getTerminalDimen().first;
}

//	DEFINITIONS	start//
void _BoardPrinter::errorScreen(std::string errMsg){
	titleBar();
	std::pair<int,int> termDimen = customUtil::getTerminalDimen();
	std::cout<<'\n';

	for(int i=0; i<(termDimen.second-3)/2; ++i)	std::cout<<'\n';
	customUtil::align_text_center(customUtil::getTerminalDimen().first, errMsg);	
	for(int i=0; i<termDimen.second - (termDimen.second-3)/2; ++i)	std::cout<<'\n';
}

void _BoardPrinter::finishedScreen(){
	titleBar();
	std::pair<int,int> termDimen = customUtil::getTerminalDimen();
	std::cout<<'\n';

	for(int i=0; i<(termDimen.second-3)/2; ++i)	std::cout<<'\n';
	customUtil::align_text_center(customUtil::getTerminalDimen().first, "Khelne ke liye Dhanyawaad :D ");	
	for(int i=0; i<termDimen.second - (termDimen.second-3)/2; ++i)	std::cout<<'\n';
	// std::cin.get();	//DEBUG ONLY, UNCOMMENT LATER
}

void _BoardPrinter::titleBar(int width){	//Considering sufficient width, to be able to play the game

	 // #ifdef __linux__
	 // 	system("clear");
	 // #elif _WIN32
	 // 	system("cls")
	 // #endif

	std::cout<<std::endl;
	customUtil::align_text_center(width, "NAMASTE from \"Ludo - The Game\" :D");
	std::cout<<'\n';
	while (width--) std::cout<<'=';
}

void _BoardPrinter::titleBar(){

	return titleBar( customUtil::getTerminalDimen().first );
}

void _BoardPrinter::row_type1(int nrow){
	//Actual-Row Start
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*6 - 1; i++)
		std::cout<<'\\';

	std::cout<<'|';

	for (size_t i = 0; i < 3; i++){
		customUtil::align_text_center(boxlen, board[nrow][6+i].content);
		std::cout<<'|';
	}

	for (size_t i = 0; i < (boxlen+1)*6 - 1; i++)	std::cout<<'\\';
	std::cout<<"|\n";
	//Actual-Row End
}

void _BoardPrinter::row_type2(int nrow){
	//!Explanatory comments in _BoardPrinter::row_type1
	std::cout<<'|';

	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';	
	customUtil::align_text_center(boxlen+2, board[nrow][1].content);
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	customUtil::align_text_center(boxlen+2, board[nrow][4].content);
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<'|';

	for (size_t i = 0; i < 3; i++){
		customUtil::align_text_center(boxlen, board[nrow][6+i].get_box_content());
		std::cout<<'|';
	}

	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
	customUtil::align_text_center(boxlen+2, board[nrow][10].get_box_content());
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	customUtil::align_text_center(boxlen+2, board[nrow][13].get_box_content());
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<"|\n";
	//Actual-Row End
}


void _BoardPrinter::row_type3(int nrow){
	//!Explanatory comments in _BoardPrinter::row_type1
	//Actual-Row Start
	std::cout<<'|';
	for (size_t i = 0; i < 6; i++){
		customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
		std::cout<<'|';
	}

	for (size_t i = 0; i < (boxlen+1)*3 -1; i++) std::cout<<' ';	
	std::cout<<'|';

	for (size_t i = 9; i < 15; i++){
		customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
		std::cout<<'|';
	}
	std::cout<<'\n';
	//Actual-Row End
}

void _BoardPrinter::row_type4(int nrow){
	//!Explanatory comments in _BoardPrinter::row_type1
	//Actual-Row Start
	std::cout<<'|';
		
	customUtil::align_text_center(boxlen, board[nrow][0].get_box_content());
	std::cout<<'|';
	for (size_t i = 1; i < 5; i++){
		customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
		std::cout<<' ';
	}
	customUtil::align_text_center(boxlen, board[nrow][5].get_box_content());
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3 -1; i+)) std::cout<<' ';	
	std::cout<|'\';

Ifor �sy�e_t i = 9;�i`< 13; i++){
		customUtil::align_textWcenter(boxlen, board[nrow][i].get_box_content());
	qtd::cout<<' ';
	}
for (size_t i = 13; i < 15;!i++)�
		customU4il::align_text_center(boxleo� board[nrow][h_.get_box_content(	)?
		std::cout<<'|';
)�
	std::cout<<'\n';
	//Actual-Row End
}

void _BoardPrinper::inter_type1(){
		/-Inter-Row line Start
    customUtil::place_cen4er(termUidth - 15"(boxlenk1) +3`-4);
	std::cout<<"( |";	for ,size_t I = 0; i = boxlef;!i++)	std:*cout<<'\\';
	for �si:e_t i ? 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t"i = 0; i < (boxlen)j2�+ 1; i++)	ctd:�cout<<'\\';
	For$(size_t0i = 0; i < boxle�+2; �+#) std:�cout<<'-';	for (s�ze_t i = 0; i < box�en; i++) {td::coqt<<'\\';
)stD:�#out<<'|';

	for(int j=0; b<33 ++j){
I	for (shze_t i = 8; i <0(boxlen); i++) std::cout<'-'?
        3td::cout<'|';
	}

for((size_t i = 0;(i < box|en; k++)	std*:cout<<'\\'?	for (size_t i = 0; i�<(boxlen+2; i++) std::cout<<'-'3
	for (size_t i = 0;�i < (boxlan)*2 ) �; i++)std::cout<<'\\';
	for ({ire_t i = 0; i < boxlen+2;!i)+)�std>:cout<<'-';
	for"(size_t i = 0; i < roxlen; i++) std::cout<<'\\';
	std::cout<<"|\n"?
		//Intep-Rgw Line end
}

void _BoardPrinter::inter_type2(){
		//Inter-Row line Start
�   customUtil::pldce_center(termWi`th - 15*(boznen+1- +3 -�);
	std::cout<<"  |";
	for (size_t i = 0 i < bnxlen; i++)	std::cout<<'\�';
	for (sixe_t i = 0; i < boxlen+2; i++) ctd::cout8<'-';
	for (si{e[t i = 0; i < *boxlen)*2 # 1+ i++)	std::cout,<'|\#;
	for (size_t i = 0; i < boxLen+2; i++) std:�cout<<'-';
	fOr0(size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	st`::cout<<'|';

	for (siz`_t i = 0;$i < (boxlen); a+/) 3td::cout<<'-';
   `std::kout<<'|';	for (iize_u i0� 0; i < (boxlen); )+++ std:cout<<' ;
    std:3cout<<'|';
	for hsize_t i = 0; i < (box�en); i++) std::cnut<<'-7;
   "std::cout<<&|';

	for (size_t i�= 4; i < boxlen{ i#+)	std::cout<4'\\';
	fop (size_t i = �; i < boxlen+2; k++) std::cout4<'-';
	for (sizeWt i = 2; i < (boxlen)*2 ) 1; i+))	std::cout<='\\';
	for (size_t i = 0; i < joxme.+2; hk+) st�;:cout<<'-';
	for (size_t i = 0; i < boxL�n; i++) std::cut<<'\\';
	std::co}t<<"|\n";
		//Inter-�ow Line end
}
void _BOardPrinter::inter_typm3(({
		//I~ter-Rms line Staru
    customUtil::place_center(tezmWidth - 15*(boxlen+1)�+3 -4){
	std::cout<<"  |";
	for (size_t i = 8; i < ,boxlen+p)*6-1; i++)	std>:co}t<'Y\';
	std::cout<>'|';

	fo� (size_t i = 0; i < boxlen); i++) sTd::coqt|<'-';
 b" std::cout,<'|'
	for (size[ti = 0;0i < (bo�len); ik+) std::cout<<'(';
   0std::cout<<'|�;
	for (skze_t h 9 0; i <"(�oxlen); i+) s4l::gmut<<'-';
	std::cout<'|';

)for (size_t i!= 0; i <`(box|en+1)*6-1; a+;)	std::co�t<<'\\g;
	std::cout<<"|\n";
		//Inter,Row Lmne Ent
}

void _BoardPrinte2:;inter_type4(){
		/'Inter-Row line Start
    custmUtil::place_ceNter(termWidth - 15+(foxlen+1) +3 -4);
std::cout<<" �|";
	for (�ize_t i = 0; i < (boXlen+1)*15-1; i++)std::ckut<<'m';
	s|d:2cut<<"|\�"?
		/;Ynter-Row Line end
}

void _BoardPrinter::inter_typ%5(){
		//Inter-Row l�ne Start
    customUtil::place_center(termWidth - 15*(boxlen+1) +3 -4);
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
    std::cout<<'|';
	for (size_t i = 0; i < (boxlen+1)*3-1; i++) std::cout<<' ';
    std::cout<<'|';
	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
    std::cout<<"|\n";
		//Inter-Row Line end
}
