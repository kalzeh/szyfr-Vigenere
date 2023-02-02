/** @file */

#ifndef functionsH
#define functionsH


#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

/** Definicja typu Text
*   Jest to typ, ktorego uzywam do wpisywania tekstu - vector stringow
*/
typedef std::vector<std::string> Text;

/** Funkcja ReadText sluzy do odczytania textu z pliku
*   @param fileName - nazwa pliku, z ktorego odczytujemy tekst
*   @return vector stringow (typ text) z odczytanym tekstem
*/
Text ReadText(const std::string& fileName);

/** Funkcja ReadWords sluzy do odczytania textu z pliku (do seta)
*   @param fileName - nazwa pliku, z ktorego odczytujemy tekst
*   @return set stringow (typ text) z odczytanym tekstem
*/
std::set<std::string> ReadWords(const std::string & fileName);

/** Funkcja ReadKey sluzy do odczytania klucza z pliku
*   @param fileName - nazwa pliku, z ktorego odczytujemy klucz
*   @return string z odczytanym kluczem ( z pominieciem spacji)
*/
std::string ReadKey(const std::string& fileName);

/** Funkcja writeText sluzy wypisania tekstu (glownie roboczo)
*   @param text - tekst, ktory chcemy wypisac
*   @return nic nie zwraca
*/
void writeText(const Text & text);

/** Funkcja writeKey sluzy wypisania klucza (glownie roboczo)
*   @param key - klucz, ktory chcemy wypisac
*   @return nic nie zwraca
*/
void writeKey(const std::string &key);

/** Funkcja textUpper sluzy do zmiany wszystkich liter tekstu na wielkie litery
*   @param text - tekst, ktory chcemy zmienic na wielkie litery
*   @return typ Text tekstu wielkimi literami
*/
Text textUpper(Text & text);

/** Funkcja strUpper sluzy do zmiany wszystkich liter stringa na wielkie litery
*   @param str - string, ktory chcemy zmienic na wielkie litery
*   @return typ string tekstu wielkimi literami
*/
std::string strUpper(std::string& str);

/** Funkcja cipher sluzy do kodowania i dekodowania wiadomosci
*   @param encrypted - tekst, ktory chcemy zaszyfrowac lub odszyfrowac
*   @param key - klucz do zaszyfrowania / odszyrowania
*   @return typ Text odszyfrowanej/zaszyfrowanej wiadomosci
*/
Text cipher(Text& encrypted, std::string & key);

/** Funkcja changeKey sluzy do "odwrocenia" klucza w celu deszyfracji (zgodnie ze wzroem: K2(i) = [26 minus K(i)] mod 26, gdzie K(i) to kolejne litery slowa kluczowego, numerowane A=0, B=1 itd., a K2(i) to kolejne litery hasla "odwroconego". 26 oznacza liczbe liter alfabetu lacinskiego.
*   @param key - klucz do "odwrocenia"
*   @return typ string "odwroconego klucza
*/
std::string changeKey(std::string & key);

/** Funkcja WriteError sluzy do wypisania bledu, jezeli sa zle podane przelaczniki
*   @param nic nie pobiera
*   @return nic nie zwraca
*/
void WriteError();

/** Funkcja SaveToFile sluzy do zapisania tekstu po szfyracji/deszyfracji do pliku
*   @param TextToFile - tekst do zapisania w pliku
*   @param fileName - nazwa pliku, do ktorego zapisujemy tekst
*   @return nic nie zwraca
*/
void SaveToFile(const Text TextToFile, const std::string& fileName);

/** Funkcja CheckKey sluzy do sprawdzenie czy wygenerowany klucz jest poprawny
*   @param key - klucz do sprawdzenia
*   @return zwraca true jezeli tak, a false jezeli nie
*/
bool CheckKey(std::string key);

/** Funkcja CheckKey sluzy do wygenerowania klucza brute forcem
*   @param nie przyjmuje parametro
*   @return nie zwraca nic
*/
void BreakCode(std::string &key);

#endif
