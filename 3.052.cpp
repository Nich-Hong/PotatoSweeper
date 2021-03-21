// Nicholas, Owen, Zach, Nikhil
//May 2019
/* program is used in order to display the minesweeper grid. This program will loop over and over again until the player flags
all 10 bombs correctly. This page will use various functions in order to find bombs arouind coordinate. Also
the program reads in and out into various text files so data ins not lost*/
#include <iostream>//call libraries
#include <string>
#include <fstream> 
#include <sstream>
//declare the function
void hit( int a, int b,std:: string arr[][11], std:: string w, std:: string bomb[][11], int o[], int p[], int&counter); //function for hit
void hit2 (std:: string arr[][11], int a, int b, int counter, std:: string bomb[][11], int o[], int p[], std:: string w); //function of hit 2
void upgrid(std:: string arr[][11]); // function for upgrid
void flower(std:: string bomb[][11], int o[],int p[]); //function for potato
void num(int o[], int p[], std:: string bomb[][11], std:: string arr[][11]); //function for num
void num2(int o[], int p[], std:: string bomb[][11]); //function for num2
void win(std:: string arr[][11], std:: string bomb[][11], int o[], int p[], bool &no); //function for win
void win2(bool&no, int&count); //function for win 2
void message(int a, int b, std:: string arr[][11]); //function for message
void count1 (int&counter); //function for bomb counters
int main()
{
    //declare variables
	int  a=0, b=0, o[11], p[11], count = 0, counter=10; //set counter = 10 and count = 0
	std:: string bomb[11][11]; // declare bomb array
	std::string returnString = "Error";
	std:: string w, w2, w3;
	char c, d, e; //c, d ,e holds one characters
	std:: string arr[11][11]; //declare 2d array
	bool no=false; //set bool no = false
	//calls Doctype HTML
	//display title and it is CSS class properties, font size, letter spacing, and boxes for tables
	std::cout << "Content-type: text/html\n\n" << std::endl;
	std:: cout << "<style> table, td, tr { border: 1px black solid;} td{font-size:30px; width: 25px; padding-left: 10px;}";
	std:: cout << " .centered { display: flex; flex-direction:column; align-items: center;}";
	std:: cout << " input[type=radio] {border: 10px;width:30px;height: 30px;}";
	std:: cout << " button[type=submit] {width:30px;height: 2em;margin-right: 5px;}";
	std:: cout << " body{background-color: #A8A5FD; background-image: url(\"https://i.imgur.com/rJi4Gh4.jpg\") ;background-repeat: no-repeat;}";
	std:: cout << "h1{text-align:center}</style></head>";
	std:: cout << "<body>"<< std:: endl	;
	std::string data =getenv ("QUERY_STRING");
	std::istringstream inputSS(data); char temp; //temp only holds on character
	//The address which when we hit result
	if (inputSS >> temp >> temp>>c>>temp>>temp>>temp>>d>>e){
				    //taking the address and set it into a declared variable
					w=c;
					w2=d;w3=e;
					//convert string to integer 
					a=stoi(w2);b=stoi(w3);
			
				bool good = false; //set bool good = false
				flower(bomb, o, p); // calls function flower
				//count3(counter);
			   
				for (int i =0; i<10; i++){//for statement to compare to the bomb array
					
					if(p[i]==b&&o[i]==a){ //If statement to check the bool
						good=true;
					}
				}
				
				if(!good||w=="y"){ //if statement if the user didnt hit the bomb
					
					hit(a, b, arr, w, bomb, o, p, counter); //calls hit function
					
					
					
					
					win(arr, bomb, o , p , no); //calls win function
					win2(no, count); //calls win2 function
						if(count!=10){// if statement to keep check of the bombs
							 
							std:: cout << "<form action=\"/cgi-bin/3.052.cgi\">"; //File CGI
							//if counter is no 10 than flag and sweep button will be here
							std::cout << "<div style=\"text-align:center ;font-size:30px;padding-bottom:20px;\"><label><input type=\"radio\" name=\"g\" value=\"x\" checked>Sweep</label>";
							std::cout << "<label style=\"padding-left: 80px ; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"y\" >Flag</label></div>";
							
							 hit2(arr, a, b, counter, bomb, o, p, w); //calls hit 2 function
							 count1(counter);// calls count 1 function
							  std:: cout << "</form>"; //end form
							message(a, b, arr);// calls message function
							
							
						}
						else { //else statement if you win the game, it would show the answer key
							std:: cout << "<h1>Nice Job! You can now safely plant new potatoes.</h1>";
										std:: cout << "<div class=\"centered\"><table><tr>";
								for (int i = 1; i<10; i++){
									  std:: cout << "<td>"<<i<<"</td>";
							  }
							  std:: cout << "</tr><tr>";
								for(int i=1; i< 10; i++){
										for(int j=1;j<10; j++){
											if(bomb[i][j]=="a"){
												std:: cout << "<td style=\"color:green\">"<<bomb[i][j] << "</td>"; //a = bomb which is green
												}
												else if(bomb[i][j]=="?"){
													std:: cout << "<td style=\"color:red\">"<<bomb[i][j] << "</td>";// ? Are when the user goes over 10 counters
												}
												else if(bomb[i][j]=="+"){
													std:: cout << "<td style=\"brown\">"<<bomb[i][j] << "</td>";//+ = no bomb around which is brown
												}
												else{
													std:: cout << "<td style=\"color:blue\">"<<bomb[i][j] << "</td>";//numbers which is blue
												}
										}
										std:: cout << "<td>"<<i<<"</tr>"; //cout i
									}
						std:: cout << "</table></div>";
							std:: cout << "<form action =\"/cgi-bin/3.053.cgi\">";//cgi file
							std:: cout << "<h1>Would you like to play again</h1>";//loop to see if they want to play
							std::cout << "<div style=\"padding-left: 80px; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"x\" checked>Yes</div>";//yes or no button
							std::cout << "<divs style=\"padding-left: 80px; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"y\" >No</div>";
							std:: cout << "<div style=\"padding-left: 80px; padding-top:10px;\"><input type=\"submit\" value=\"Submit\"></div></form>";//submit button
						}
						upgrid(arr); //calls function upgrid
				}
				else if(good){//if you step on the bomb
					std:: cout << "<div class=\"centered\"><table><tr>";
					for (int i = 1; i<10; i++){
						  std:: cout << "<td>"<<i<<"</td>"; //cout the table
				  }
				  //shows the answer of the game
				  std:: cout << "</tr><tr>";
					for(int i=1; i< 10; i++){
							for(int j=1;j<10; j++){
								if(bomb[i][j]=="a"){
									std:: cout << "<td style=\"color:green\">"<<bomb[i][j] << "</td>"; //a is bomb which is green
									}
									else if(bomb[i][j]=="?"){
										std:: cout << "<td style=\"color:red\">"<<bomb[i][j] << "</td>";// ? is when user goes over counter
									}
									else if(bomb[i][j]=="+"){
										std:: cout << "<td style=\"brown\">"<<bomb[i][j] << "</td>"; // + is when there arent bomb around which is brown
									}
									else{
										std:: cout << "<td style=\"color:blue\">"<<bomb[i][j] << "</td>";//numbers around the bomb which is blue
									}
							}
							std:: cout << "<td>"<<i<<"</tr>";//cout the answer key
						}
						std:: cout << "</table></div>";
					std:: cout << "<H1>AHHHH! You dug up a potato!</h1>";//message you digged up a bomb
					std:: cout << "<form action =\"/cgi-bin/3.053.cgi\">";//file cgi
							std:: cout << "<h1>Would you like to play again</h1>";//loop to see if the user wants to play again
							std::cout << "<div style=\"padding-left: 80px; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"x\" checked>Yes</div>";//yes no button
							std::cout << "<div style=\"padding-left: 80px; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"z\" >No</div>";
							std:: cout << "<div style=\"padding-left: 80px; padding-top:10px;\"><input type=\"submit\" value=\"Submit\"></div></form>";//submit button
				}
				
				
			}
			
			
			
		
	
	return 0; // the end of the game
}
	
//function definations 
void hit( int a, int b,std:: string arr[][11], std:: string w, std:: string bomb[][11], int o[], int p[], int&counter){
	
					
	char ch;
	std:: ifstream in("/home/debian/CS102/lab_3/3.051.txt");//it takes the first txt file and input it here.
	std:: ofstream out("/home/debian/CS102/lab_3/3.052.txt");//takes the data collected from this function and output it to txt file 2.
	
	while(in.get(ch)){ //gets information from the first txt file
		
	    for(int i= 1; i< 10; i++){
				while(!isspace(ch)){//check if there is space and delete the spaces
					for(int j =1; j<10; j++){
					//std:: cout << j << i;
					
						if(a==i&&b==j){//check the user's coordinates 
							if(w=="x"){//if user chose sweep
								
									num(o, p, bomb, arr);// calls function num
									
								
							}
							else if (w=="y"){//if user chose flag
								
								arr[i][j]="F";//prints out "F for flag"
								
							}
						}
						
						else{// anything else that isnt user's coordinates
							arr[i][j]=ch; //ch = "X"
						}
						out << arr[i][j]; // cout array
						in.get(ch);//information from first txt
						}
					
					out << std:: endl;// end line
					}
				in.get(ch);// information from first txt
		
		}
		
	   }
	
				
	  

}
void hit2 (std:: string arr[][11], int a, int b, int counter, std:: string bomb[][11], int o[], int p[], std:: string w){

	char ch; //declare ch as one character
	
	
	
	std:: ofstream out("/home/debian/CS102/lab_3/3.054.txt");//it takes the forth txt file and input it here.
	std:: ifstream in("/home/debian/CS102/lab_3/3.052.txt");//outputs it into second txt file
	std:: cout << "<div class=\"centered\"><table><tr>";//center the table
	for (int i = 1; i<10; i++){
          std:: cout << "<td>"<<i<<"</td>";
  }
  std:: cout << "</tr><tr>";

	while(in.get(ch)){//gets the information in the forth txt file
	for(int i= 1; i< 10; i++){
				while(!isspace(ch)){//check to see if there is space.
					for(int j =1; j<10; j++){
					//std:: cout << a << b;
					
						if(a==i&&b==j){//check the user's coordinates 
							
							if(w=="x"){// if the user chose sweep
								
									num(o, p, bomb, arr);//call function num
								
						
							}
							else if (w=="y"){// if the user chose flag
								if(counter>=0)arr[i][j]="F"; //prints out F on the coordinates
								else arr[i][j]="?";//anything else its just ?
							}
						}
						
						else{
							arr[i][j]=ch; //ch = "X" everything will be hidden
						}
						out << arr[i][j];// cout the array
						
						in.get(ch);//grabs the information from forth txt.
							if(arr[i][j]=="F"){ //set the color for Flagging to green
							std:: cout << "<td style=\"color:green\"><button type=\"submit\" name=\"a\" value="<<i<<j<<">F</button></td> ";
							}
							else if(arr[i][j]=="?"){//set ? to red
								std:: cout << "<td style=\"color:red\"><button type=\"submit\" name=\"a\" value="<<i<<j<<">?</button></td>";
							}
							else if(arr[i][j]=="x"){//set x to black
								std:: cout << "<td style=\"black\"><button type=\"submit\" name=\"a\" value="<<i<<j<<">x</button></td>";
							}
							else if(arr[i][j]=="+"){//set + to brown
								std:: cout << "<td style=\"brown\">"<<arr[i][j] << "</td>";
							}
							else{//set the numbers to blue
								std:: cout << "<td style=\"color:blue\">"<<arr[i][j] << "</td>";
							}
						}
					
					out << std:: endl;//end line
					 std:: cout << "<td>"<<i<<"</tr>";//cout table i
					
					}
				in.get(ch);//grabs information from forth file
		
				}
				
	   }
		
	std:: cout << "</table></div>";//end table
}


void upgrid(std:: string arr[][11]){
	
	char ch;//declare ch as one character
	std:: ofstream out("/home/debian/CS102/lab_3/3.051.txt");//it takes the first txt file and input it here.
	std:: ifstream in("/home/debian/CS102/lab_3/3.054.txt");//output the collected data from this function to forth txt file.
	while(in.get(ch)){//grabs information from first txt file
	    for(int i= 0; i< 11; i++){
	        while(!isspace(ch)){//check if there is space
				for(int j = 0; j<11; j++){//makes a grid
					arr[i][j]=ch;// makes it so that everything in the 2d array is "X"
					out << arr[i][j];//cout array
					in.get(ch);//grabs information from txt 1
				}
	        }
	        in.get(ch);//grabs information from txt 1
	        out << std:: endl;//end line
	   }
	}
}
	
void flower(std:: string bomb[][11], int o[],int p[]){
	std:: string x, y, z; //declare strings
	
	int a=0; //set a = 0
	for(int i=1; i< 10; i++){//nested for the coordinates of the bomb array
        for(int j=1;j<10; j++){
            bomb[i][j]="+";//sets bomb[i][j] = "+"
        }
    }
	std:: ifstream in("/home/debian/CS102/lab_3/3.05f.txt");//grabs the file from txtfile flower that contains the bombs.
	char ch;
	
		while(in>>x){//while ifstream in can input to x
				
				y=x.substr(0,1); //uses substr to take the numbers in flower txt
				z=x.substr(1,1);
				o[a]= stoi(y); //convert y and z to integer
				p[a]=stoi(z);
				bomb[o[a]][p[a]]="a";//now it sets the bomb into its coordinates
				a++; // a + 1
			   }
	num2(o, p, bomb);// calls function num 2
	
}
void num(int o[], int p[], std:: string bomb[][11], std:: string arr[][11]){
    //this function that creates the number around the bombs
	for(int i = 0; i < 11; i++){//nested for loop to check the amount of bombs
        if(i>0&&i<10){
            for (int j=0; j<11; j++){
                if(j>0&&j<10){
					
                         int u = 0;// u is the number around the bombs
                         bool nextpos=false;//set bool to false
                         for (int l = 0; l < 10; l++){
                        if(     o[l]-1==i&&p[l]==j||
                                o[l]-1==i&&p[l]-1==j||
                                o[l]+1==i&&p[l]==j||
                                o[l]+1==i&&p[l]-1==j||
                                o[l]==i&&p[l]-1==j||
                                o[l]==i&&p[l]+1==j||
                                o[l]+1==i&&p[l]+1==j||
                                o[l]-1==i&&p[l]+1==j
                                ){
                                    nextpos=true;//if o[1]and p[1] matches the condition then bool will be true
                                    break;// break so no loop
                                }
                                
						}
						if(nextpos){//when bool became true
						//those if statement check the tiles around the bombs, if there is more bombs around there 3 by 3 then u will + 1
							if(i-1!=-1&&j-1!=-1&&j+1!=11&&i+1!=11){
											
											if(bomb[i-1][j-1]=="a"){// [i][j] is u and it checks diagonally up down and sideways to see if there is a bomb
												u++;
											}
											if(bomb[i-1][j]=="a"){
												u++;
											}
											if(bomb[i-1][j+1]=="a"){
												u++;
											}
											if(bomb[i][j-1]=="a"){
												u++;
											}
											if(bomb[i][j+1]=="a"){
												u++;
											}
											if(bomb[i+1][j-1]=="a"){
												u++;
											}
											if(bomb[i+1][j]=="a"){
												u++;
											}
											if(bomb[i+1][j+1]=="a"){
												u++;
											}
											
									 }
									arr[i][j]=std:: to_string(u);//if there is bombs, it will set the grid with numbers around "a" which is the bomb
								}
								else arr[i][j]="+"; //if there isnt any bombs arr[i][j]= "+"
						}
					
					}
				}
			}
		}

void win(std:: string arr[][11], std:: string bomb[][11], int o[], int p[], bool &no){

		std:: ofstream out("/home/debian/CS102/lab_3/3.053.txt");//replace txt file 3.053 to this function
		for(int i = 0; i<10; i++){
			if(arr[o[i]][p[i]]=="F"){//if the bombs are "F"
				out << "F"<< std:: endl;; //stream out "F"
			}
		}
	  
   
	  
}
void win2(bool&no, int&count){
	std:: ifstream in("/home/debian/CS102/lab_3/3.053.txt");//grabs information from 3.053 txt file
	//declare string x
	std:: string x;
	while (in>> x){// its holds "F" into x
		count++;//counter plus 1
		//this is too count how many correct bomb locations the user found
	}

}
void message(int a, int b, std:: string arr[][11]){
	//messages as you progress in the game
		if(arr[a][b]=="+"){
				std:: cout << "<h1>Good choice. There are no potatoes near you.</h1>";// gives you hint that there isnt anything bombs
		}
		else if(arr[a][b]=="1"){//check how many bombs are around arr [a][b]
				std:: cout << "<h1> Phew..There is only 1 potatoes near you.</h1>";//one bomb around you
		}
		else if(arr[a][b]=="2"){
			std:: cout << "<h1>Becareful! There are 2 potatoes near you.</h1>";//two bomb around you
		}
		else if(arr[a][b]=="3"){
			std::cout << "<h1>Oh My Goodness! 3 potatoess...3!</h1>";//three bombs around you
		}
		else if(arr[a][b]=="4"){
			std:: cout << "<h1>Wow! There are 4 potatoess near you. Be extra careful.</h1>";//four bombs around you
		}
		else if(arr[a][b]=="5"){
			std:: cout << "<h1>Thats insane. 5 potatoes. It's like they are after you.</h1>";//five bombs around you
		}
		else if(arr[a][b]=="6"){
			std:: cout << "<h1>Yikes!! 6 of them. There are too many!</h1>";// 6 bombs around you
		}
		else if(arr[a][b]=="7"){
			std:: cout << "<h1>Jeepers Scoob! Theres only one safe space around us!</h1>";// there is 7 bombs so you have only 1 save spot
		}
		else if(arr[a][b]=="8"){
			std:: cout << "<h1>We are surrounded! Fall Back!<h1>";// 8 bombs surrounds that one box
		}
		else if(arr[a][b]=="F"){
			std:: cout << "<h1>You have just flagged Row: "<<a << " Col: "<<b <<".</h1>";// flagging the tiles
		}
		else if(arr[a][b]=="?"){
			std:: cout << "<h1>You have just used up all your flags.<br> Please choose a space that you don't think is a flower.</h1>";// you used all the flags
		}
			
}
void count1 (int&counter){//function to display counter and count how many times the user tried to flag
	std:: ifstream in("/home/debian/CS102/lab_3/3.052.txt");//grabs information from txt file 2 
	std:: ofstream out("/home/debian/CS102/lab_3/3.05c.txt");//output it into our counter txt file
	//declare variable
	char ch;std:: string x;
	while(in.get(ch)){//grabs information from txt 2
	    for(int i= 0; i< 11; i++){
	        while(!isspace(ch)){//check if there is any spaces
				for(int j = 0; j<11; j++){
					x=ch;//set ch  as x
					if(x=="F"||x=="?"){//check how many flag they have used
							
							counter--;//display counter minus one, reminds user how many bombs
					}
					out << x;// output x
					in.get(ch);
				}
	        }
	        in.get(ch);
	        out << std:: endl;
	   }
	}
	
	std:: cout << "<h1>Counter: "<<counter<<"</h1>";// display the counters
}
void num2(int o[], int p[], std:: string bomb[][11]){
	for(int i = 0; i < 11; i++){
        if(i>0&&i<10){
            for (int j=0; j<11; j++){
                if(j>0&&j<10){
					
                         int u = 0;//u = the numbers if there is a bomb or not
                         
							if(bomb[i][j]!="a"){//if the coordinates are not a bomb than its u
											//checks around coordinate u and see if there is a bomb
											if(bomb[i-1][j-1]=="a"){
												u++;//if there is a bomb plus 1
											}
											if(bomb[i-1][j]=="a"){
												u++;
											}
											if(bomb[i-1][j+1]=="a"){
												u++;
											}
											if(bomb[i][j-1]=="a"){
												u++;
											}
											if(bomb[i][j+1]=="a"){
												u++;
											}
											if(bomb[i+1][j-1]=="a"){
												u++;
											}
											if(bomb[i+1][j]=="a"){
												u++;
											}
											if(bomb[i+1][j+1]=="a"){
												u++;
											}
											
									if(u>0){
									bomb[i][j]=std:: to_string(u);//array bomb = the number of bomb new by
									}
								}
								
						}
					
					}
				}
			}
}



