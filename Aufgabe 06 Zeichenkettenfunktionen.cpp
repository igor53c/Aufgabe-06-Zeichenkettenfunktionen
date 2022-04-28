// Aufgabe 06 Zeichenkettenfunktionen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 * 1.	Schreiben sie eine Funktion 'digitCount', die eine Zeichenkette
 *		übergeben bekommt und als 'int'-Wert zurückliefert, wie viel Ziffern
 *		darin enthalten sind.
 *
 *      Beispiel: abcde123fgh4ijk...		Ergebnis: 4
 *
 * 2.	Schreiben sie eine Funktion 'stringReverse' die eine Zeichenkette übergeben
 *	bekommt, und eine neue Zeichenkette zurückliefert in der die Zeichen
 *      in umgekehrter Reihenfolge enthalten sind.
 *
 *      Beispiel: 'umdrehen'			Ergebnis: 'neherdmu'
 *
 * 3.   Schreiben sie eine Funktion 'toLower', die als Rückgabewert eine neue Zeichenkette
 *      zurückliefert in der alle Großbuchstaben einer übergebenen Zeichenkette
 *      in Kleinschreibung konvertiert wurden (ohne Umlaute).
 *
 * 4.   Schreiben sie eine Funktion 'toUpper' die als Rückgabewert eine neue Zeichenkette
 *      zurückliefert, die der alle Kleinbuchstaben einer übergebenen Zeichenkette
 *      in Großschreibung konvertiert wurden (ohne Umlaute).
 *
 * 5.   Schreiben Sie eine Funktion 'lTrim' die als Rückgabewert eine neue Zeichenkette zurückliefert
 *      in der alle führenden Leerzeichen entfernt wurden.
 *
 *		Beispiel: '    C++ ist toll   '	Ergebnis: 'C++ ist toll   '
 *
 * 6.   Schreiben Sie eine Funktion 'rTrim' die als Rückgabewert eine neue Zeichenkette zurückliefert
 *      in der alle abschliessenden Leerzeichen entfernt wurden.
 *
 *		Beispiel: '   C++ ist toll    '		Ergebnis: '   C++ ist toll'
 *
 * 7.   Schreiben Sie eine Funktion 'trim' die als Rückgabewert eine neue Zeichenkette zurückliefert
 *      in der alle führenden und alle abschliessenden Leerzeichen entfernt wurden.
 *
 *	Beispiel: '    C++ ist toll    '	Ergebnis: 'C++ ist toll'
 *
 * 8.   Erweitern sie die Trim-Funktionen (lTrim, rTrim, trim) soweit, dass sie nicht nur Leerzeichen,
 *      sondern auch jedes andere Zeichen aus der Zeichenkette entfernen können.
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::locale;
using std::string;
using std::cin;

char ENTFERNUNGSZEICHEN = ' ';

int digitCount(string);
string stringReverse(string);
string toLower(string);
string toUpper(string);
string lTrim(string, char = ENTFERNUNGSZEICHEN);
string rTrim(string, char = ENTFERNUNGSZEICHEN);
string trim(string, char = ENTFERNUNGSZEICHEN);
bool istNeuerText();

int main()
{
	locale::global(locale("German_germany"));

	do 
	{
		string text;

		cout << endl << "Geben Sie den Text ein: ";
		getline(cin, text);

		cout << endl << "digitCount: " << digitCount(text) << endl;
		cout << endl << "stringReverse: '" << stringReverse(text) << "'" << endl;
		cout << endl << "toLower: '" << toLower(text) << "'" << endl;
		cout << endl << "toUpper: '" << toUpper(text) << "'" << endl;
		cout << endl << "lTrim: '" << lTrim(text) << "'" << endl;
		cout << endl << "rTrim: '" << rTrim(text) << "'" << endl;
		cout << endl << "trim: '" << trim(text) << "'" << endl;

	} while (istNeuerText());

	return EXIT_SUCCESS;
}

int digitCount(string text)
{
	int retValue = 0;

	for (char letter : text)
		if (letter >= '0' && letter <= '9')
			retValue++;

	return retValue;
}

string stringReverse(string text)
{
	string retValue;

	for (int i = text.length() - 1; i >= 0; i--)
		retValue += text[i];

	return retValue;
}

string toLower(string text)
{
	for (char& letter : text)
		letter = tolower(letter);

	return text;
}

string toUpper(string text)
{
	for (char& letter : text)
		letter = toupper(letter);

	return text;
}

string lTrim(string text, char letter)
{
	for (int i = 0; i < text.length(); i++)
		if (text[i] != letter)
			return text.substr(i);
		
	return {};
}

string rTrim(string text, char letter)
{
	for (int i = text.length() - 1; i >= 0; i--)
		if (text[i] != letter)
			return text.substr(0, i + 1);
		
	return {};
}

string trim(string text, char letter)
{
	return rTrim(lTrim(text, letter), letter);
}

bool istNeuerText()
{
	string weiter;

	cout << endl << "Neuer Text? (J | N) : ";

	cin >> weiter;

	if (weiter.length() != 1 || (weiter[0] != 'J' && weiter[0] != 'j'))
		return false;

	cin.ignore();

	system("cls");

	return true;
}