#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;


int main() {
 
	ifstream plik("ciągi.txt");
	string wiersz;

	vector <string> list;
	vector <string> duplikaty;
	vector <string> jedynki;
	int count0;
	int count1;
	int count1_in_line;
	int maxDlugosc;
	int maxDlugosc_index;
	bool same_jedynki = true;
	int maxInt = 0;

	//odczytaj plik, zapisz
	for(int i=0; getline(plik, wiersz); i++)
		list.push_back(wiersz);

	
	for(int i=0; i<list.size(); i++){

		//Sprawdzi, czy są co najmniej dwa takie same ciągi
		for(int j=i; j<list.size(); j++)//                |
			if(list[i] == list[j] && i != j)//              |
				duplikaty.push_back(list[i]);//_______________|
//                        ___________________________________________________
		//Iterowanie po bitach                                                   |
		int len = list[i].length();//                                            |
		char char_array[len+1]; 							//deklaracja listy znaków          |
		strcpy(char_array, list[i].c_str());  //inicjacja listy znaków           |
//                                                                           |
					//Obliczy ilość 1 i 0 w całym pliku                                |
		for(int j=0; j<len; j++)//							|                                |
			if(char_array[j] == '0') count0++;//	|                                |
			else count1++;//______________________|                                |
//                                                                           |
		//Znajdzie ciąg, w którym jest najwięcej znaków 1                        |
		for(int j=0; j<len; j++)//                      |                        |
			if(char_array[j] == '1') count1_in_line++;//  |                        |
		//                                              |                        |
		if(count1_in_line > maxDlugosc){//              |                        |
			maxDlugosc = count1_in_line;//					 	 	  |                        |
			maxDlugosc_index = i;//										 	  |                        |
		}//																						  |                        |
    //																						  |                        |
		count1_in_line = 0;//___________________________|                        |
//                                                                           |
//		                                                                       |
		//Wypisze wszystkie ciągi składające się wyłącznie ze znaków 1           |
		for(int j=0; j<len; j++)//																	 |           |
			if(char_array[j] == '0')//																 |           | 
				same_jedynki = false;//																	 |           |
		//																													 |           |
		if(same_jedynki) jedynki.push_back(list[i]);//							 |           |
		same_jedynki = true;//_______________________________________|           |
		//		                                                                   |
		//_______________________________________________________________________|

		//Jaką największą liczbę dziesiętną zapisano w pliku
		try{	//																					 |
		int liczba = stoi(list[i], 0, 2);//								 |
		if(liczba > maxInt) maxInt = liczba;//						 |
		}catch(...){}//____________________________________|
	}
			
	

		



	cout << "Wyświetli zawartość pliku ciągi.txt, po myślniku" << endl;
		for(int i=0; i<list.size(); i++)
			cout << "- " << list[i] << endl;

	cout << endl << "Obliczy ilość 1 i 0 w całym pliku" << endl;
		cout << "0: " << count0 << endl;
		cout << "1: " << count1 << endl;

	cout << endl << "Znajdzie ciąg, w którym jest najwięcej znaków 1" << endl;
		cout << list[maxDlugosc_index] << endl;

	cout << endl << "Sprawdzi, czy są co najmniej dwa takie same ciągi" << endl;
		if(duplikaty.size() == 0) cout << "\tNie" << endl;
		else for(int i=0; i<duplikaty.size(); i++)
			cout << "+ " << duplikaty[i] << endl;

	cout << endl << "Wypisze wszystkie ciągi składające się wyłącznie ze znaków 1" << endl;
		for(int i=0; i<jedynki.size(); i++)
			cout << "+ " << jedynki[i] << endl;

	cout << endl << "Jaką największą liczbę dziesiętną zapisano w pliku" << endl;
		cout << "Największa " << maxInt << endl;
		
	  
return 0;
}


