#include "board.hpp"

#include<iostream>
// #include<memory>
#include<random>
#include<utility>
#include<set>
#include "utilities.hpp"
#include "exceptions.hpp"
// #include<vector>

using namespace std;

//  BOARD_PRINTER_METHODS
std::pair<int,int> _BoardPrinter::titleBar(int width){	//Considering sufficient width, to be able to play the game

	 #ifdef __linux__
	 	system("clear");
	 #elif _WIN32
	 	system("cls")
	 #endif

	cout<<std::endl;
	customUtil::align_text_center(width, "Welcome to \"Ludo-The Game\"");
	cout<<'\n';
	while (width--) cout<<'=';
}

std::pair<int,int> _BoardPrinter::titleBar(){

	return titleBar( customUtil::getTerminalDimen().first );
}

void _BoardPrinter::type1(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	string content;

	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';

		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
		for (size_t i = 0; i < (boxlen+1)*6 - 1; i++)
			std::cout<<'\\';

		std::cout<<'|';

		for (size_t i = 0; i < 3; i++){
			if( ! customUtil::align_text_center(boxlen, board[nrow][6+i].content) ){
				errorScreen("Window smaller than is minimum required!");
			}
			std::cout<<'|';
		}

		for (size_t i = 0; i < (boxlen+1)*6 - 1; i++)	std::cout<<'\\';
		std::cout<<"|\n";
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3-1; i++) std::cout<<'-';

	std::cout<<'|';
	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<"|\n";
	//Inter-Row Line end
}

void _BoardPrinter::type2(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';

		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
		for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
		customUtil::align_text_center(boxlen+2, board[nrow][1].get_box_content());
		for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
		customUtil::align_text_center(boxlen+2, board[nrow][4].get_box_content());
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
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3-1; i++) std::cout<<'-';

	std::cout<<'|';
	for (size_t i = 0; i < boxlen; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < (boxlen)*2 + 1; i++)	std::cout<<'\\';
	for (size_t i = 0; i < boxlen+2; i++) std::cout<<'-';
	for (size_t i = 0; i < boxlen; i++) std::cout<<'\\';
	std::cout<<"|\n";
	//Inter-Row Line end

}

void _BoardPrinter::type3(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
		
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<'|';


		for (size_t i = 0; i < 3; i++){
			customUtil::align_text_center(boxlen, board[nrow][6+i].get_box_content());
			std::cout<<'|';
		}

		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<"|\n";
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3-1; i++) std::cout<<'-';

	std::cout<<'|';
	for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
	std::cout<<"|\n";
	//Inter-Row Line end
}

void _BoardPrinter::type4(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
		
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<'|';


		for (size_t i = 0; i < 3; i++){
			customUtil::align_text_center(boxlen, board[nrow][6+i].get_box_content());
			std::cout<<'|';
		}

		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<"|\n";
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'-';

	for (size_t i = 0; i < (boxlen+1)*3-1+2; i++) std::cout<<'-';

	for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'-';
	std::cout<<"|\n";
	//Inter-Row Line end
}

void _BoardPrinter::type5(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
				
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
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
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3 -1; i++) std::cout<<' ';	
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
	std::cout<<'|';
	std::cout<<'\n';
	//Inter-Row Line end
}

void _BoardPrinter::type6(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
				
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
			customUtil::align_text_center(boxlen, board[nrow][0].get_box_content());
			std::cout<<'|';
		for (size_t i = 1; i < 6; i++){
			customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
			std::cout<<' ';
		}

		for (size_t i = 0; i < (boxlen+1)*3 -1; i++) std::cout<<' ';	
		std::cout<<'|';

		for (size_t i = 9; i < 12; i++){
			customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
			std::cout<<' ';
		}
		for (size_t i = 12; i < 14; i++){
			customUtil::align_text_center(boxlen, board[nrow][i].get_box_content());
			std::cout<<'|';
		}
		cout<<'\n';

	}
	//Actual-Row End
	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*3 -1; i++) std::cout<<' ';	
	std::cout<<'|';

	for (size_t i = 0; i < (boxlen+1)*6-1; i++) std::cout<<'-';
	std::cout<<'|';
	std::cout<<'\n';
	//Inter-Row Line end	
}

void _BoardPrinter::type7(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
				
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
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
	}
	//Actual-Row End
	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
    boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  |";
	for (size_t i = 0; i < (boxlen+1)*15-1; i++) std::cout<<'-';
	std::cout<<"|\n";
	//Inter-Row Line end	
}

void _BoardPrinter::type8(int boxlen, int nrow,const std::array<std::array<ludo_box,15>,15>& board, rowLockStatus ){
	//Actual-Row Start
	for(size_t j=0; j<boxlen; ++j, boxlen/=2){	//@brief The outermost loop manages row-wise printing
		std::cout<<'|';
				
		boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<'|';


		for (size_t i = 0; i < 3; i++){
			customUtil::align_text_center(boxlen, board[nrow][6+i].get_box_content());
			std::cout<<'|';
		}

		for (size_t i = 0; i < (boxlen+1)*6-1; i++)	std::cout<<'\\';
		std::cout<<"|\n";
	}
	//Actual-Row End

	//Inter-Row line Start
    customUtil::place_center(customUtil::getTerminalDimen().first - 15*(2*boxlen+1) +3 -4);
	boxlen *= 2;	//A quick move to use 'row length' 2 times the boxlen('column length')...IT WILL BE RESET AT END OF EACH LOOP 
	std::cout<<"  ";
	for (size_t i = 0; i < (boxlen+1)*15+1; i++)	std::cout<<'-';
	std::cout<<'\n';
	//Inter-Row Line end
}
//  BOARD_PRINTER_METHODS END

//GAME_CLASS_DEFINTIONS START
void game::player_move(vector<int> &consq_moves){
	//TODO
}

bool game::moveGoti(std::shared_ptr<ludo_goti> the_goti, unsigned int dist){
	std::pair<int,int> increment_coord={0,0};	//[NOTE] - Can store these in the ludo_box class itself, besides the corner specification
	std::pair<int,int> updated_coords = the_goti->curr_coords;

	unsigned int org_dist = dist;	//! Used to return whether move possible or not
	/*TODO - 
		Checking if move possible or not
		Checking at each loop, whether it is at stop, to update gotiStatus
		Checking at each loop, whether the coord is in home_turn, (to make algorithm better, check if dist remaining <= 6, if not return false straightaway)
	*/

	direction turnDirection;

	cout<<"[DEBUG] Removing from ["<<the_goti->curr_coords.first<<"]["<<the_goti->curr_coords.second<<"]"<<endl;

	while(dist--){

		increment_coord = {0,0};
		turnDirection = _ludo_coords.turnAtCorner(updated_coords, _ludo_coords.outer_corners);	//For Outer Corners
		if(turnDirection != NO_TURN){	//ie. a turn will happen to go to next box

			the_goti->curr_direction = turnDirection;
			if(turnDirection == NORTH){
				increment_coord = {-1,0};
			}
			else if(turnDirection == EAST){
				increment_coord = {0,1};
			}
			else if(turnDirection == WEST){
				increment_coord = {0,-1};
			}
			else if(turnDirection == SOUTH){
				increment_coord = {1,0};
			}
		}
		else{
			turnDirection = _ludo_coords.turnAtCorner(updated_coords, _ludo_coords.inner_turns); //For Inner Turns
			if (turnDirection != NO_TURN)
			{
				the_goti->curr_direction = turnDirection;
				if(turnDirection == NORTH){
					increment_coord = {-1,1};
				}
				else if(turnDirection == EAST){
					increment_coord = {1,1};
				}
				else if(turnDirection == WEST){
					increment_coord = {-1,-1};
				}
				else if(turnDirection == SOUTH){
					increment_coord = {1,-1};
				}
			}
			else{
				//Checking for Home_Turns
				if( updated_coords == _ludo_coords.home_turns[the_goti->gotiColour].first )
				{
					turnDirection = _ludo_coords.home_turns[the_goti->gotiColour].second;
					the_goti->curr_direction = turnDirection;
				}

				//ie. needs to 'go straight' on its current path
				if(the_goti->get_curr_direction() == NORTH){
					increment_coord = {-1,0};
				}
				else if(the_goti->get_curr_direction() == EAST){
					increment_coord = {0,1};
				}
				else if(the_goti->get_curr_direction() == WEST){
					increment_coord = {0,-1};
				}
				else if(the_goti->get_curr_direction() == SOUTH){
					increment_coord = {1,0};
				}
			}
		}
		updated_coords.first += increment_coord.first;
		updated_coords.second += increment_coord.second;
	}

	getBoardBox(the_goti->curr_coords).removeGoti( the_goti );	//Reaches here only if move possible

	the_goti->curr_coords = updated_coords;
	cout<<"[DEBUG] Adding to ["<<the_goti->curr_coords.first<<"]["<<the_goti->curr_coords.second<<"]"<<endl;
	// cout<<"Difference of ["<<<<"]["<<<<"]"<<endl;
	getBoardBox(the_goti->curr_coords).appendGoti( the_goti );

}

bool game::attack(std::shared_ptr<ludo_goti> to_be_removed, std::weak_ptr<ludo_goti>& attacker,const std::pair<int,int>& coords){
	if(getBoardBox(coords).isPresent(*(to_be_removed)) && getBoardBox(coords).isPresent(*(attacker.lock()))){
		getBoardBox(coords).removeGoti(to_be_removed);
		
		auto iter = std::find(movingGotis[to_be_removed->gotiColour].begin(), movingGotis[to_be_removed->gotiColour].end(), to_be_removed);
		auto emptyLockBox = std::find_if(lockedPositions[to_be_removed->gotiColour].begin(), lockedPositions[to_be_removed->gotiColour].end(), [](std::reference_wrapper<ludo_box> &box){
			if(box.get().isEmpty() == 0)	return true;
			else return false;
		});

		emptyLockBox->get().appendGoti( to_be_removed );
		movingGotis[to_be_removed->gotiColour].erase(iter);
		add_to_lockedGoti(to_be_removed);
	}
	else return false;	//nothing changed
}

ludo_box& game::getBoardBox(const std::pair<int,int>& coords){
	return board[ coords.first ][ coords.second ];
}

bool game::unlockGoti(const colours gotiColour){
	if (gotiColour == UnknownColour)
	{
		cerr<<"unlockGoti() request made for Unknown Colour"<<endl;
		return false;
	}
	else if(movingGotis[gotiColour].size() >= goti_per_user){
		cerr<<"Goti request makes the number of ludo_goti of "<<stringify(gotiColour)<<" more than "<<goti_per_user<<endl;
		return false;
	}
	else{

		//First std::find_if gives us the raw reference of box
		auto box_iter = std::find_if(lockedPositions[gotiColour].begin(), lockedPositions[gotiColour].end(), [&](auto &lockedBox){
			return lockedBox.get().numGotis[gotiColour] > 0;
		});
				
		if( box_iter == lockedPositions[gotiColour].end()){	//no locked goti present
			return false;
		}

		auto goti = box_iter->get().inBoxGotis.back();	//Causing the SEG_Fault
		box_iter->get().removeGoti(goti);

		goti->curr_coords = _ludo_coords.start_coords[gotiColour];
		goti->curr_direction = _ludo_coords.start_dir[gotiColour];

		getBoardBox( goti->curr_coords ).appendGoti( goti );
		movingGotis[gotiColour].push_back( goti );
		--numlockedGotis[gotiColour];

		return true;
	}
}

bool game::add_to_lockedGoti(std::shared_ptr<ludo_goti> goti_to_lock){

	goti_to_lock->curr_coords = {0,0};
	goti_to_lock->curr_direction = NO_TURN;	

	auto emptyBox = std::find_if(lockedPositions[goti_to_lock->gotiColour].begin(), lockedPositions[goti_to_lock->gotiColour].end(), [](std::reference_wrapper<ludo_box>& box){
		return box.get().isEmpty();
	});
	emptyBox->get().appendGoti(goti_to_lock);

}

void game::takeIntro(){
	std::pair<int,int> tmpDimen(0,0);
	tmpDimen = customUtil::getTerminalDimen();

	customUtil::place_v_center("[NOTICE] Please ensure window is at least 62*31");
	cout<<endl;

	do{
		tmpDimen = customUtil::getTerminalDimen();

	}while( tmpDimen.first < 62 || tmpDimen.second < 31 );

	_BoardPrinter::titleBar(tmpDimen.first);

	customUtil::place_v_center(tmpDimen.second - 7, "");
	customUtil::align_text_center(tmpDimen.first, "Enter names of the Players (Leave empty if not playing) : ");
	
	string playerName;
	player p=Player1;
	colours colour;
	
	colour = colourOrder[0];	
	
	while(p <= Player4){
		
		customUtil::place_center(tmpDimen.first, string("Player") + customUtil::intTostring(p) + string(" - "));		
		getline(cin, playerName, '\n');		
		if(customUtil::trimString(playerName) != ""){
			activePlayerMap.insert({{ p, { customUtil::trimString(playerName), colour} }});
		}

		p = player(p+1);
		colour = colours(colour+1);
		//NOTE - lambda_next(p) can't be used here,since after P4, it becomes P1, ie. int(1), while the above makes is (5), thus helping us go out of loop
	}

	//Setting the board, on basis of given players
	for (auto &&player : activePlayerMap)
	{
		auto gotiColour = player.second.second;
		for(auto&& lockedBox : lockedPositions[gotiColour]){
			lockedBox.get().appendGoti(std::shared_ptr<ludo_goti>(new ludo_goti(gotiColour, getEmptyLocks(gotiColour))));
			lockedBox.get().box_type = _boxLOCK;
		}
		coloursMap.insert({player.second.second, player.first});
		numfinishedGotis.insert({player.second.second, 0});
	}

	for (auto &&stop : _ludo_coords.stops)
	{
		getBoardBox(stop).content = 'X';
	}

	cout<<endl<<"\nPress Enter to go to the board...";
	cin.get();
}

bool game::isPlayerPlaying(player p){
	return activePlayerMap.find(p) != activePlayerMap.end();
}

int game::rolldie(player ID){
	/*BUG - return dist(mt); isn't returning 1
		Out of 500 runs, the observation was : 
			1 - 0%
			2 - 14%
			3 - 15%
			4 - 15%
			5 - 20%
			6 - 18%   */
	return Die::dist[ ID-1 ] (Die::mt[ID-1] );
}

//NOTE FOR SELF - The downward direction is x+ve axis(row), and towards left is y+ve axis(column)
void game::updateDisplay(player currplayer){
	int boxlen = 0;
	std::pair<int,int> tmpDimen(0,0);

	do{	
		tmpDimen = customUtil::getTerminalDimen();
		boxlen = (min(tmpDimen.first,tmpDimen.second) - 16)/15;

	}while( min(tmpDimen.first,tmpDimen.second) < 16 || max(tmpDimen.first,tmpDimen.second) < 31 );

	_BoardPrinter::titleBar(tmpDimen.first);

    customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4 );
	cout<<"  ";
	for (size_t i = 0; i < 10; i++){
		cout<<"  "<<i;
	}
	for (size_t i = 10; i < 15; i++){
		cout<<' '<<i;
	}
	cout<<"\n  ";
    customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4 );
	for (size_t i = 0; i <(2*boxlen+1)*15 + 1; i++)
	{
		cout<<'-';
	}
	cout<<"\n";

	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<0<<' '; _BoardPrinter::type1(boxlen,0,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<1<<' '; _BoardPrinter::type2(boxlen,1,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<2<<' '; _BoardPrinter::type3(boxlen,2,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<3<<' '; _BoardPrinter::type1(boxlen,3,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<4<<' '; _BoardPrinter::type2(boxlen,4,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<5<<' '; _BoardPrinter::type4(boxlen,5,board);

	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<6<<' '; _BoardPrinter::type5(boxlen,6,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<7<<' '; _BoardPrinter::type6(boxlen,7,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<8<<' '; _BoardPrinter::type7(boxlen,8,board);

	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<9<<' '; _BoardPrinter::type1(boxlen,9,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<10; _BoardPrinter::type2(boxlen,10,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<11; _BoardPrinter::type3(boxlen,11,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<12; _BoardPrinter::type1(boxlen,12,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<13; _BoardPrinter::type2(boxlen,13,board);
	customUtil::place_center(tmpDimen.first - 15*(2*boxlen+1) +3 -4); cout<<14; _BoardPrinter::type8(boxlen,14,board);
	
	cout<<"\n";
	customUtil::align_text_center(activePlayerMap[currplayer].first);
	cout<<"\n";
	for(int i=0; i<tmpDimen.first; ++i) cout<<'-';
	cout<<'\n';

}

std::pair<int,int> game::getEmptyLocks(colours gotiColour){
	for (auto &&lockedBox : lockedPositions[gotiColour])
	{
		if(lockedBox.get().isEmpty()){
			return lockedBox.get().coords;
		}
	}
	return {0,0};
}

void _BoardPrinter::errorScreen(string errMsg){
	std::pair<int,int> termDimen = titleBar();
	cout<<'\n';

	for(int i; i<(termDimen.second-3)/2; ++i)	cout<<'\n';
	customUtil::align_text_center(termDimen.first, errMsg);
	for(int i; i<termDimen.second - (termDimen.second-3)/2; ++i)	cout<<'\n';
}

bool game::InitGame(short playerConsent){	//1 for reset, 2 is with previous playerMap

	if(playerConsent !=1 && playerConsent !=2){
		return false;
	}
	else{
		goti_per_user = 4;

		for (auto &&row : board)
		{
			for (auto &&box : row)
			{
				box.content.clear();
				box.inBoxGotis.clear();
				for (auto &&num_goti : box.numGotis)
				{
					num_goti.second = 0;
				}
			}
		}

		if( playerConsent == 1 ){	//not changed, in case it is 2
			activePlayerMap.clear();
			coloursMap.clear();

			takeIntro();
		}

		//coloursMap and activePlayerMap initialised by takeIntro()		
	}

	++number_of_GameRuns;

	return true;
}

void game::automate_play(){

	auto lambda_next = [&](){
		std::vector<player> tmpVec;
		for (auto &&i : activePlayerMap)
		{
			tmpVec.push_back(i.first);
		}
		size_t pos = std::find(tmpVec.begin(), tmpVec.end(), currentPlayer) - tmpVec.begin();
		if( pos+1 < tmpVec.size() ){
			currentPlayer = tmpVec[ pos+1 ];
		}
		else currentPlayer = tmpVec[0];
		currentGotiColour = activePlayerMap[currentPlayer].second;
	};

	currentGotiColour = colourOrder[0];
	currentPlayer = coloursMap[currentGotiColour];

	std::vector<unsigned short> dieNumbers;
	std::pair<int,int> currentCoord = _ludo_coords.start_coords[ currentGotiColour ];

	while (true){
		
		updateDisplay(currentPlayer);
		cout<<"\nPress Enter to roll the die...";

		unsigned short currentRoll, enteredRoll;
		unsigned short choice_num;

		do{
			currentRoll = rolldie(currentPlayer);
			dieNumbers.push_back(currentRoll);
		}while( currentRoll == 6 );

		cout<<"\nRoll Output - ";
		for (auto &&outNum : dieNumbers)
		{
			cout<<outNum<<' ';
		}

		auto lambda_isSIXinRoll = [&](){
			for (auto &&i : dieNumbers)
			{
				if(i == 6)
					return true;
			}
			return false;
		};

		if( movingGotis[currentGotiColour].empty() && !lambda_isSIXinRoll() ){	//No movable goti, so continue to next player
			cout<<"\nNo movable goti, for the moves"<<endl;
			
			customUtil::pause(1);

			lambda_next();
			dieNumbers.clear();
			continue;
		}

		while( !dieNumbers.empty() ){
			updateDisplay(coloursMap[currentGotiColour]);
			unsigned short counter = 1;
			std::cout<<"\nChose from these gotis : ";
			if( lambda_isSIXinRoll() && numlockedGotis[currentGotiColour]!=0 )
			{
				cout<<"\n0. Unlock New Goti (type 0 and 6 for this)\n\n";
				for (auto &&goti_ptr : movingGotis[currentGotiColour])	//Iterating through vector of goti pointers
				{
					cout<<counter<<". ["<<goti_ptr->curr_coords.first<<"]["<<goti_ptr->curr_coords.first<<"]\n";
					++counter;
				}				
				unlockGoti(currentGotiColour);
			}
			for (auto &&goti_ptr : movingGotis[currentGotiColour])	//Iterating through vector of goti pointers
			{
				cout<<counter<<". ["<<goti_ptr->curr_coords.first<<"]["<<goti_ptr->curr_coords.first<<"]\n";
				++counter;
			}
			cout<<"\nRoll Output - ";
			for (auto &&outNum : dieNumbers)
			{
				cout<<outNum<<' ';
			}
			cout<<"\nEnter GotiNumber and dieNumber : ";
			choice_num = 1;
			enteredRoll = dieNumbers[0];

			if(true){
				if(choice_num != 0){
					if(moveGoti(movingGotis[currentGotiColour][choice_num-1], enteredRoll)){
						continue;
					}
					dieNumbers.erase(std::find(dieNumbers.begin(), dieNumbers.end(), enteredRoll));
				}
				else{
					unlockGoti(currentGotiColour);
					dieNumbers.erase(std::find(dieNumbers.begin(), dieNumbers.end(), 6));
				}
            }			
           	else continue;
		}
		customUtil::pause(1);
		lambda_next();
	}
}

void game::play(bool boolVal){
	if( !boolVal ){
		return;
	}
	else{

		auto lambda_next = [&](){
			std::vector<player> tmpVec;
			for (auto &&i : activePlayerMap)
			{
				tmpVec.push_back(i.first);
			}
			size_t pos = std::find(tmpVec.begin(), tmpVec.end(), currentPlayer) - tmpVec.begin();
			if( pos+1 < tmpVec.size() ){
				currentPlayer = tmpVec[ pos+1 ];
			}
			else currentPlayer = tmpVec[0];
			currentGotiColour = activePlayerMap[currentPlayer].second;
		};

		currentGotiColour = colourOrder[0];
		currentPlayer = coloursMap[currentGotiColour];

		std::vector<unsigned short> dieNumbers;
		std::pair<int,int> currentCoord = _ludo_coords.start_coords[ currentGotiColour ];

		while (true){
			
            cout<<"[DEBUG] Going to print for Player:"<<currentPlayer<<" Colour:"<<activePlayerMap[coloursMap[currentGotiColour]].second;
				updateDisplay(currentPlayer);
			cout<<"\nPress Enter to roll the die...";
			cin.get();

			unsigned short currentRoll, enteredRoll;
			unsigned short choice_num;

			do{
				currentRoll = rolldie(currentPlayer);
				dieNumbers.push_back(currentRoll);
			}while( currentRoll == 6 );

			cout<<"\nRoll Output - ";
			for (auto &&outNum : dieNumbers)
			{
				cout<<outNum<<' ';
			}

			//TODO - Remove cases of triple sixes
			//TODO - Modify code such that instead of checking if enteredRoll is in dieNumbers, check whether it's a sum of elements or not

			auto lambda_isSIXinRoll = [&](){
				for (auto &&i : dieNumbers)
				{
					if(i == 6)
						return true;
				}
				return false;
			};

			if( movingGotis[currentGotiColour].empty() && !lambda_isSIXinRoll() ){	//No movable goti, so continue to next player
				cout<<"\nNo movable goti, for the moves"<<endl;
				
				customUtil::pause(1);

				lambda_next();
				dieNumbers.clear();
				continue;
			}

			while( !dieNumbers.empty() ){
    			updateDisplay(coloursMap[currentGotiColour]);
				unsigned short counter = 1;
				std::cout<<"\nChose from these gotis : ";
				if( lambda_isSIXinRoll() ) cout<<"\n0. Unlock New Goti (type 0 and 6 for this)\n\n";
				for (auto &&goti_ptr : movingGotis[currentGotiColour])	//Iterating through vector of goti pointers
				{
					cout<<counter<<". ["<<goti_ptr->curr_coords.first<<"]["<<goti_ptr->curr_coords.first<<"]\n";
					++counter;
				}
				cout<<"\nRoll Output - ";
				for (auto &&outNum : dieNumbers)
				{
					cout<<outNum<<' ';
				}
				cout<<"\nEnter GotiNumber and dieNumber : ";
				cin>>choice_num>>enteredRoll;

				if(
					std::find(dieNumbers.begin(), dieNumbers.end(), enteredRoll)!=dieNumbers.end()
							&& (choice_num>=0 && choice_num <= counter)	//Verifies Entered values are valid
				){
					if(choice_num != 0){
						if(moveGoti(movingGotis[currentGotiColour][choice_num-1], enteredRoll)){
							continue;
						}
						dieNumbers.erase(std::find(dieNumbers.begin(), dieNumbers.end(), enteredRoll));
					}
					else if( lambda_isSIXinRoll() ){
						unlockGoti(currentGotiColour);
						dieNumbers.erase(std::find(dieNumbers.begin(), dieNumbers.end(), 6));
					}
					else continue;
				}
				else{
					cout<<"Invalid Choice... Try again"<<endl;
					continue;
				}
			}
			lambda_next();
		}
	}
}

game::game() : colourOrder({ColourLAAL, ColourNEELA, ColourPEELA, ColourHARA}){
	number_of_GameRuns = 0;
	min_boxlen = 1;
	goti_per_user = 4;

	unsigned short i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			board[i][j].coords = {i,j};
		}
	}

	//Marking the LockRooms and the HomePath
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			board[i][j].box_type = _boxUNUSABLE;
			board[7][j].box_type = _boxHOMEPATH;
			board[7][14-j].box_type = _boxHOMEPATH;
		}
		board[i][7].box_type = _boxHOMEPATH;
		board[14-i][7].box_type = _boxHOMEPATH;
	}
	board[0][7].box_type = board[14][7].box_type = _boxNORMAL;
	board[7][0].box_type = board[7][14].box_type = _boxNORMAL;
	for (i = 9; i < 15; i++)	for (j = 0; j < 6; j++)	board[i][j].box_type = _boxUNUSABLE;
	for (i = 9; i < 15; i++)	for (j = 9; j < 15; j++)	board[i][j].box_type = _boxUNUSABLE;
	for (i = 0; i < 6; i++)	for (j = 9; j < 15; j++)	board[i][j].box_type = _boxUNUSABLE;
	
	//Marking the HomeArea
	for (i = 6; i < 9; i++)	for (j = 6; j < 9; j++)	board[i][j].box_type = _boxUNUSABLE;

	//NOTE - activePlayerMap and playerMap is initialized in takeIntro()

	colourOrder = { ColourLAAL, ColourHARA, ColourPEELA, ColourNEELA };

	//Storing references in order, starting from the starting positon of that colour, then anti-clockwise
	lockedPositions = {
		{ ColourLAAL, { ref(board[13][4]), ref(board[13][1]), ref(board[10][1]), ref(board[10][4]) } },
		{ ColourHARA, { ref(board[4][1]), ref(board[1][1]), ref(board[1][4]), ref(board[4][4]) } },
		{ ColourPEELA, { ref(board[1][10]), ref(board[1][13]), ref(board[4][13]), ref(board[4][10]) } },
		{ ColourNEELA, { ref(board[10][13]), ref(board[13][13]), ref(board[13][10]), ref(board[10][10]) } }
	};

	coloursMap = {
		{ ColourLAAL, Player1},
		{ ColourHARA, Player1},
		{ ColourPEELA, Player3},
		{ ColourNEELA, Player4}
	};

	currentPlayer = Player1;
	currentGotiColour = ColourLAAL;
	number_of_GameRuns = 0;

	for (auto &&stop : _ludo_coords.stops)
	{
		getBoardBox(stop).content = 'X';
	}

}

game::~game(){}

//GAME_CLASS_DEFINTIONS END

//  LEARNT|+QUESTIONS  //
/*[LEARNT] - Nesting functions (ie. function declaration inside function) is not supported by standards in C/C++
				 But, gcc supports it as a 'non-standard' extension
				 BUT, in C++ mode, it's not allowed, 'Local Functions' aren't supported
				 BUT, FROM C++11, IT IS SUPPORTED, using LAMDAs {Imp. - Lambdas have a semicolon at end}*/
/*LAMBDAs - 1. Have a ';' at end
			2. '[]' is the "capture clause", also called 'lambda-introducer'
			3. parameter list '()' is optional
			4. These are the parts:
					[] () mutable throw() -> int {//body//}
					 |  |   |        |       |    
		capture clause  |  optional  |  trailing-return-type(optional)
					parameters   exception specification(optional)
*/
		//QUestion - Why didnt this lambda work?
	// }while ( (tmpDimen.getKey() < 31 || tmpDimen.getVal() < 31) ? true : []{	//Lamda Function (used to declare this 'local' function)
	// 	cerr<<"INSUFFICIENT HEIGHT/WIDTH FOR DISPLAY!"<<endl;
	// 	return false;
	// } );