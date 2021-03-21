// Nicholas Hong, Zachary Chou, Owen Lee , Nikhil Sharma
//CGI Team Project Lab 5 
//.cgi page which is connect to the first html page. 
//displays first grid, gets cooordinates of random bombs, and stores grid and bomb in txt files
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <cctype>

//declare function definitions
void grid(std:: string arr[][11]);
void flower(std:: string bomb[][11], int o[],int p[]);
int main()
{
	char x; //declare character
	std:: string a; //declare variables
	std::string returnString = "Error";//incase if the link has an error
	int p[11], o[11];//2 d arry for grid
	std:: string arr[11][11];// only need 9x9 grid but 11 by 11 for segmentation errors
	std:: string bomb[11][11];//for the potatoes
	std::cout << "Content-type: text/html\n\n" << std::endl;//makes page appear in html
	std:: cout << "<head>";//header and styling grid , background, and font
	std:: cout << "<style> table, td, tr { border: 1px black solid;} td{font-size:30px; width: 25px; padding-left: 10px;}";
	std:: cout << " .centered { display: flex; flex-direction:column; align-items: center;}";
	std:: cout << ".center{display: block;margin-left: auto;margin-right: auto;}";//display
	std:: cout << " input[type=radio] {border: 10px;width:30px;height: 30px;}";
	std:: cout << " button[type=submit] {width:30px;height: 2em;margin-right: 5px;}";
	std:: cout << " body{background-color: #A8A5FD; background-image: url(\"https://i.imgur.com/rJi4Gh4.jpg\") ;background-repeat: no-repeat;}</style></head>";
	std:: cout << "<body>"<< std:: endl	;
	std::string data =getenv ("QUERY_STRING");//gets page url
	std::istringstream inputSS(data); char temp;//processing url and only takes part of it
	//declare temporary characters
	
	
	
	flower(bomb, o, p);//hold coordiante of bomb
	if (inputSS >> temp >> temp>>x){//take url.takes temp value
		a=x;//character to string
		if(a == "Y"){//if user picked yes from html
			
			
			
	
			
   
			std:: cout << "<form action=\"/cgi-bin/3.052.cgi\">";//2nd cgi file for the game
			
			std::cout << "<div style=\"text-align:center ;font-size:30px;padding-bottom:20px;\"><label><input type=\"radio\" name=\"g\" value=\"x\" checked>Sweep</label>";
			//option to sweep 
			std::cout << "<label style=\"padding-left: 80px ; padding-top:10px;\"><input type=\"radio\" name=\"g\" value=\"y\" >Flag</label></div>"; 
			//option to flag spot
			grid(arr);
			std:: cout << "<h1 style=\"text-align:center\">Counter: 10</h1>"; //pseudo counter for the bombs
			
		}
		else if (a =="N"){//if the user says no
			std:: cout << "<h1 style=\"text-align:center;\"> Have a nice day!</h1>";
			//displays funny picture
			std::cout << "<div ><img src=\"https://i.imgur.com/p2Lc9Nv.jpg/\" class=\"center\"></div>";
		}
	}
	//testing functions
	//grid(arr);
	//flower(hit);
	return 0;
}

void grid(std:: string arr[][11]){
	std:: ofstream out;
	out.open("/home/debian/CS102/lab_3/3.051.txt");//directory file
	
	std:: cout << "<div class=\"centered\"><table><tr>";// makes the table
	for (int i = 1; i<10; i++){
          std:: cout << "<td>"<<i<<"</td>";// output the line
  }
  std:: cout << "</tr><tr>";
	for (int i= 0; i< 11; i++){// to keep the grid to 11 x 11
		
		for (int j=0; j<11; j++){
			if(i>0&j>0&&i<10&&j<10){
				arr[i][j] = "x";// rows and column
					out << arr[i][j] ;//ouputs to txt files
					std:: cout << "<td><button type=\"submit\" name=\"a\" value="<<i<<j<<">x</button></td>";
					//click on buttons rather than coordinates
			}
		}
		if(i>0&&i<10){
		out << std:: endl;//oupututs endline  to make grid lookalike
		std:: cout<< "<td>"<<i<<"</tr>";
		}
		
	}
	std:: cout <<"</table></div>";//print out the table
	out.close();
}


void flower( std::string bomb[][11],int o[],int p[]){
	std:: ofstream in("/home/debian/CS102/lab_3/3.05f.txt");//takes the random number flower it input it into a text file.
	
    srand(time(NULL));//for random flowers
    for (int i=0; i<10; i ++ ){//keeps it to 10 bombs and nothing higher
        o[i] = rand() % 9+1;//finds numbers 1 though 9
        p[i]= rand() % 9+1;
        
        for(int j =0; j<i; j++){//to ensure that no 2 coordinates are the same
            while(o[i]==o[j]&&p[i]==p[j]){
                    o[i]=rand() % 9+1;
                    p[i]= rand() % 9+1;
                }
			
        }
        in << o[i]<<p[i]<<std:: endl;// the output of row and column
    }
    in.close();

}




