#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	fstream plik("hasla.txt", ios::in);
	fstream wynik("passwords.txt", ios::out);
	string haslo;
	char znaki[3] {'#', '$', '*'};
	
	if(plik.good() && wynik.good())
	{
		while(!plik.eof())
		{
			plik >> haslo;
			
			if(haslo.length() >= 8)
			{
				for(int i = 0; i <= haslo.length() - 1; i++)
				{
					for(int k = 0; k < 3; k++)
					{
						if(haslo[i] == znaki[k])
						{
							wynik << haslo << endl;
							haslo = " ";
						}
					}
				}
			}	
		}	
		
		plik.close();
		wynik.close();
	} 
	
	return 0;
}
