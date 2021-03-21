// Nicholas, Zach, Owen, Nikhil
//May 2019
/*cgi page that is after the game is played. if player presses yes leads to a copy of first html page. If player presses no, they are lead to 
either a goodbye lose page or a goodbye win page*/
#include <iostream>
#include <sstream>

int main()
{
    //declare string
	std:: string a;
	std::string returnString = "Error";//error message
	std::cout << "Content-type: text/html\n\n" << std::endl;//text file
	std:: cout << "<style> .center{display: block;margin-left: auto;margin-right: auto;}";
	std:: cout << ".box{font-size: 10px; border-radius: 10px; padding: 10px 8px;}</style>";//grid
	std::string data =getenv ("QUERY_STRING");
	std::istringstream inputSS(data); char temp;// input for data
	
	if (inputSS >> temp >> temp>>a){//if statement for user input
		if(a=="x"){
			std:: cout << "<head>";
			std:: cout << "<style>body {text-align: center;background-color: #A8A5FD; background-image: url(\"https://i.imgur.com/BWzC3Tc.png\") ;";//background on first page
			std:: cout << "background-repeat: no-repeat;background-position: right bottom} form {display: inline-block;}";
			std:: cout << "p{font-size: 20px;} button{margin: 20px;border-radius: 8px;font-size: 15px;padding: 12px 28px;background-color:white;";
			std:: cout << "border: 2px solid red;}</style>";
				std::cout << "<title>Potato Sweeper</title>";
				
			std:: cout << "</head>";
			std:: cout << "<h1 style=\"text-align:center\"> Potato Sweeper 2.0</h1> ";//name of the game
			std:: cout << "<h2 style=\"text-align:center\"> Nicholas Hong, Owen Lee, Nikhil Sharma, Zach Chou</h2>";//names of group members
			std:: cout <<  "<h3 style=\"text-align:center\">How to play Potato Sweeper</h3>";//Rules to potato sweeper

			std:: cout << "<body>";// rules to how to play game
			std:: cout<<"<div><p >There will be a 9x9 grid with 10 hidden potatoes. You will choose between 81 buttons<br>";
			std:: cout<< "and choose between two radio buttons you can choose from, sweep or flag. Sweeping will check what is hidden underneath the coordinates.<br>";
			std:: cout<<"If you hit a potato,  you lose. If you hit a space and it shows you a number, that indicates how many number of potatoes is near the <br>";
			std:: cout<<"coordinate you had chosen. This may be vertically, horizontally, or diagonally . If the square shows a + sign then there are no <br>";
			std:: cout<<"potatoes near the coordinates. Flagging will not check what is underneath the grid and is used for indicating that the potato is at certain coordinates. <br>";
			std:: cout<<"The objective is to flag all potatoes.</p></div>";
				std:: cout << "<p> Would you like to play?</p>";// option asking user
				std:: cout << "<form action =\"/cgi-bin/3.05.cgi\">";// cgi file for the game
				std:: cout << "<button type=\"submit\" name=\"a\" value=\"Y\"> Yes</button>";//yes button
				std:: cout << "<button type=\"submit\" name=\"a\" value=\"N\"> No</button>";//no button
				std:: cout <<"</form>";
			std:: cout << "</body>";
		}
		else if(a=="y"){
			std:: cout << "<style> body{background-color: #A8A5FD; background-image: url(\"https://i.imgur.com/rJi4Gh4.jpg\") ;background-repeat: no-repeat;}</style>";//picture for second page
			std::cout << "<body>";
			std:: cout << "<div><H1 style=\"text-align:center\">Thank you for playing!</H1></div>";
			std:: cout << "<H1 style=\"text-align:center\">You Are Now Blessed With Good Harvest By This Cool Potato</H1>"; //if you win
			std:: cout << "<img src=\"https://i.imgur.com/oCxCEsO.png\" class=\"center\">";//image for the middle
			std:: cout << "</body>";
		}
		else if(a=="z"){
			std:: cout << "<style> body{background-color: #A8A5FD; background-image: url(\"https://i.imgur.com/IEVf2if.jpg\") ;background-repeat: no-repeat;}</style>";//image for the page if you said no and lose the game
			std:: cout << "<body>";
			std:: cout << "<div><H1 style=\"text-align:center\">Thank you for playing!</H1></div>";//output for the user playing the game
			std:: cout << "<H1 style=\"text-align:center\">...But I Think The Sad Potato Hates You...</H1>";//you lose game 
			std:: cout << "<img src=\"https://i.imgur.com/wExecAc.jpg\" class=\"center\" style=\"margin-top:100px\">";//sad potato image
			std:: cout<< "</body>";
		}
		
	}
	return 0;
}


