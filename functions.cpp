/** @file */
#include "functions.h"

typedef std::vector<std::string> Text;

void WriteError(){
    std::cout<<"\n\n!!!!ERROR!!!!\n\n";
    std::cout<<"Program sluzy do:\n";
    std::cout<<"Program uruchamiany jest z linii polecen z wykorzystaniem nastepujacych przelacznikow\n (kolejnosc przelacznikow jest dowolna):\n\n";
    std::cout<<"  *Szyfrowania plikow w szyfrze vinegre'a:\n\n";
    std::cout<<"    --en flaga szyfrowania\n";
    std::cout<<"    -i [nazwa_pliku] - plik tekstowy wejsciowy jawny\n";
    std::cout<<"    -o [nazwa_pliku] - plik tekstowy wyjsciowy zaszyfrowany\n";
    std::cout<<"    -k [nazwa_pliku] - plik tekstowy z kluczem\n\n";
    std::cout<<"  *Deszyfrowania pliki tekstowe zaszyfrowane metoda Vigenere'a:\n\n";
    std::cout<<"    --de flaga odszyfrowania\n";
    std::cout<<"    -i [nazwa_pliku] - plik tekstowy wejsciowy zaszyfrowany\n";
    std::cout<<"    -o [nazwa_pliku] - plik tekstowy wyjsciowy jawny\n";
    std::cout<<"    -k [nazwa_pliku] - plik tekstowy z kluczem\n\n";
    std::cout<<"  *Lamie pliki tekstowe zaszyfrowane metoda Vigenere'a (tylko w jezyku angielskim):\n\n";
    std::cout<<"    --br flaga lamania szyfru\n";
    std::cout<<"    -i [nazwa_pliku] - plik tekstowy wejsciowy zaszyfrowany\n";
    std::cout<<"    -o [nazwa_pliku] - plik tekstowy wyjsciowy jawny\n";
}

Text ReadText(const std::string& fileName){
    Text text;
    std::ifstream file(fileName);
    if(file){
        std::string line;
        while(std::getline(file, line)){
            std::stringstream ss(line);
            std::string temp;
            while(ss>>temp){
                text.push_back(temp);
            }
        }
        file.close();
    }else{
        std::cout<<"nie ma takiego pliku";
        WriteError();
    }
    return text;
}

std::set<std::string> ReadWords(const std::string & fileName){
    std::set<std::string> text;
    std::ifstream file(fileName);
    if(file){
        std::string line;
        while(std::getline(file, line)){
            std::stringstream ss(line);
            std::string temp;
            while(ss>>temp){
                for(auto &el:temp){
                    el = toupper(el);
                }

                text.insert(temp);
            }
        }
        file.close();
    }
    return text;
}

std::string ReadKey(const std::string& fileName){
    std::string key;
    std::ifstream file(fileName);
    if(file){
        std::string line;
        while(std::getline(file, line)){
            std::stringstream ss(line);
            std::string temp;
            while(ss>>temp){
                key+=temp;
            }
        }
        file.close();
    }
    return key;
}

void writeText(const Text & text){
    for(const auto & el: text){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
}

void writeKey(const std::string &key){
    for(const auto & el:key){
        std::cout<<el;
    }
    std::cout<<std::endl;
}

Text textUpper(Text & text){
    for(auto & el: text){
        for(auto & el1 : el){
           el1 = toupper(el1);
        }
    }
    return text;
}

std::string strUpper(std::string& str){
    for(auto & el : str){
           el = toupper(el);
        }
    return str;
}

Text cipher(Text& encrypted, std::string & key){
    Text decrypted;
    while(!encrypted.empty()){
        std::string wordE = encrypted[0];
        std::string wordD;
        for(const auto &el:wordE){
            char lE = el;
            char lK = key[0];
            char lD = (((lE +lK)-130)%26)+65;
            wordD.push_back(lD);
            key.erase(key.begin());
            key.push_back(lK);
        }
        decrypted.push_back(wordD);
        encrypted.erase(encrypted.begin());
    }
    return decrypted;
}

std::string changeKey(std::string & key){
    for(auto & el :  key){
        el = ((26-(el-65))%26)+65;
    }
    return key;
}

void SaveToFile(const Text TextToFile, const std::string& fileName){
    std::ofstream file(fileName);
    for(const auto& el: TextToFile){
        file<<el<<" ";
    }
    file.close();
}

bool CheckKey(std::string key){

    std::set<std::string> wordList = ReadWords("words_lite.txt"); //map albo set

    Text decrypted = ReadText("xd.txt");
    decrypted = textUpper(decrypted);

    key = changeKey(key);

    Text encrypted = cipher(decrypted, key);

    for(auto & el : encrypted){
        if(wordList.find(el)==wordList.end()){
           return false;
        }
    }

    return true;
}

void BreakCode(std::string &key){
    for(char c='A'; c<='Z'; c++){
        key.push_back(c);
        if(CheckKey(key)) return;
        if(key.length()<=3) BreakCode(key);
        key.pop_back();
    }
}
