/** @file */
#include "functions.h"

//dopisaæ wnioski do sprawozdania

int main(int argc, char* argv[]){
    std::string flag;

    //sprawdzamy, czy wgl jest wystarczajaco argumentow do lamania (jak nie to do reszty tez jest za malo)
    if(argc<6){
        WriteError();
        return 0;
    }

    //szukamy flagi, jezeli uzytkownik wpisal wiecej niz jedna flage to wywalamy error
    for(int i = 0 ; i< argc; i++){
        std::string s=argv[i];
        if(!s.rfind("--")){
            if(flag.length() != 0){
                WriteError();
                return 0;
            }else{
                flag = s;
            }
        }
    }

    std::string output;
    std::string input;
    std::string keyF;

    if(flag == "--en"){
        if(argc<8){
            WriteError();
            return 0;
        }
        for(int i=1;i<argc;i++){
                std::string val = argv[i];
            if(val=="-o"){
                output = argv[i+1];
            }else if(val=="-i"){
                input = argv[i+1];
            }else if(val=="-k"){
                keyF = argv[i+1];
            }
        }

        //jezeli ktorys z przelacznikow byl bledny
        if(output == "" || input == "" || keyF == ""){
            WriteError();
            return 0;
        }

        //odczytujemy tekst do zaszyfrowania z pliku, a nastepnie go zmieniamy na wielkie litery i wypisujemy
        Text encrypted = ReadText(input);
        encrypted = textUpper(encrypted);
        std::cout<<"Tekst jawny: ";
        writeText(encrypted);

        //odczytujemy klucz z pliku, a nastepnie go zmieniamy na wielkie litery i wypisujemy
        std::string key = ReadKey(keyF);
        std::cout<<"Klucz: ";
        key = strUpper(key);
        writeKey(key);

        //szyfrujemy
        Text decrypted = cipher(encrypted, key);

        //Wypisujemy zaszyfrowany plik, a nastepnie zapisujemy go do pliku
        std::cout<<"Tekst zaszyfrowany: ";
        writeText(decrypted);
        SaveToFile(decrypted, output);


    }else if(flag == "--de"){

        if(argc<8){
            WriteError();
            return 0;
        }
        for(int i=1;i<argc;i++){
                std::string val = argv[i];
            if(val=="-o"){
                output = argv[i+1];
            }else if(val=="-i"){
                input = argv[i+1];
            }else if(val=="-k"){
                keyF = argv[i+1];
            }
        }

        //jezeli ktorys z przelacznikow byl bledny
        if(output == "" || input == "" || keyF == ""){
            WriteError();
            return 0;
        }

        //odczytujemy tekst do odszyfrowaniaz pliku, a nastepnie go zmieniamy na wielkie litery i wypisujemy
        Text decrypted = ReadText(input);
        decrypted = textUpper(decrypted);
        std::cout<<"Tekst zaszyfrowany: ";
        writeText(decrypted);

        //odczytujemy klucz z pliku, a nastepnie go zmieniamy na wielkie litery, "odwracamy" go i wypisujemy
        std::string key = ReadKey(keyF);
        std::cout<<"Klucz: ";
        key = strUpper(key);
        key = changeKey(key);
        writeKey(key);

        //szyfrujemy
        Text encrypted = cipher(decrypted, key);

        //Wypisujemy odszyfrowany plik, a nastepnie zapisujemy go do pliku
        std::cout<<"Tekst odszyfrowany: ";
        writeText(encrypted);
        SaveToFile(encrypted, output);


    }else if(flag == "--br"){

        if(argc<6){
            WriteError();
            return 0;
        }
        for(int i=1;i<argc;i++){
                std::string val = argv[i];
            if(val=="-o"){
                output = argv[i+1];
            }else if(val=="-i"){
                input = argv[i+1];
            }
        }

        //jezeli ktorys z przelacznikow byl bledny
        if(output == "" || input == ""){
            WriteError();
            return 0;
        }
        //pobieramy plik do zaszyfrowania
        Text decrypted = ReadText(input);
        decrypted = textUpper(decrypted);
        std::cout<<"Tekst zaszyfrowany: ";
        writeText(decrypted);
        SaveToFile(decrypted,"xd.txt");

        //lamiemy kod
        std::string key;
        BreakCode(key);
        std::cout<<"Klucz: "<<key<<"\n";
        key = changeKey(key);
        Text encrypted = cipher(decrypted, key);

        //zapisujemy do plik i wypisujemy zlamany tekst
        std::cout<<"Tekst jawany: ";
        writeText(encrypted);
        SaveToFile(encrypted, output);

    }else{
        WriteError();
        return 0;
    }






    return 0;
}
