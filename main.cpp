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
	for(int i=0; getline(plik, wiersz); i++){
		list.push_back(wiersz);
		//Wyświetli zawartość pliku ciągi.txt, po myślniku
		cout << "- " << wiersz << endl;
                        
		//	iterowanie jednego wiersza                                              
		int len = wiersz.length();
		char char_array[len+1]; 							//deklaracja listy znaków          
		strcpy(char_array, wiersz.c_str());  //inicjacja listy znaków                                                                                                                                              
		for(int j=0; j<len; j++){                                        
			                          //ilość 0 i 1                                                    ciągi składające się ze znaków 1	
			if(char_array[j] == '0'){		count0++;                                                           same_jedynki = false;                  }
																//                ciąg, w którym jest najwięcej znaków 1  
			if(char_array[j] == '1'){   count1++;          count1_in_line++;                      } 
			
		}//for - iterowanie jednego wiersza

		                                          //Znajdzie ciąg, w którym jest najwięcej znaków 1
		                                             if(count1_in_line > maxDlugosc){
			                                          		maxDlugosc = count1_in_line;
			                                              maxDlugosc_index = i;
		                                             }
	                                               	count1_in_line = 0;  

																																																//Sprawdzi, czy są co najmniej dwa takie same ciągi
																																																for(int j=0; j<list.size(); j++)
																																																	if(wiersz == list[j] && i != j)
																																																		duplikaty.push_back(wiersz);

		//Wypisze wszystkie ciągi składające się wyłącznie ze znaków 1           
		if(same_jedynki) jedynki.push_back(wiersz);//							            
		same_jedynki = true;

		//Jaką największą liczbę dziesiętną zapisano w pliku
		try{																				
		int liczba = stoi(wiersz, 0, 2);							 
		if(liczba > maxInt) maxInt = liczba;						 
		}catch(...){}
	}

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


