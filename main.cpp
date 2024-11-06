#include <iostream>
#include <vector>
#include <cctype>
#include "nsUtil.h"

using namespace std;
using namespace nsUtil;


string & ToLower (string & Str){
    for (size_t i (0); i<Str.size(); ++i)
        Str[i] = tolower(Str[i]);
    return Str;
}

vector<string> & ToLower(vector<string> & VString){
    for (size_t i (0); i<VString.size(); ++i)
        VString[i] = ToLower(VString[i]);
    return VString;
}

string & ToUpper (string & Str){
    for (size_t i (0); i<Str.size(); ++i)
        Str[i] = toupper(Str[i]);
    return Str;
}

vector <string> & ToUpper (vector <string> & VString){
    for (size_t i (0); i<VString.size(); ++i)
        VString[i] = ToUpper(VString[i]);
    return VString;
}


vector <string> & Swap (vector <string> & VString, const unsigned & PosBeg, const unsigned & PosEnd){
    string temp = VString[PosBeg];
    VString[PosBeg]=VString[PosEnd];
    VString[PosEnd]=temp;
    return VString;
}


vector <string> & Delete (vector <string> & VString, const unsigned & PosBeg){
    for (unsigned i(PosBeg); i < VString.size(); ++i)
        VString[i] = VString[i+1];

    VString.resize(VString.size()-1);
    return VString;
}


vector <string> & Insert (vector <string> & VString, const unsigned & PosBeg, const string & Line){
    VString.resize(VString.size()+1);
    for (unsigned i(VString.size()-1); i >=PosBeg+1; i--){
        VString[i] = VString[i-1];
    }
    VString[PosBeg]=Line;
    return VString;
}

vector <string>& Move (vector <string> & VString, const unsigned & PosBeg, const unsigned & PosEnd){
    string chaine = VString[PosBeg];
    VString.erase(VString.begin()+PosBeg);
    VString.insert(VString.begin()+PosEnd, chaine);
    return VString;
}


string & TrimLeft (string & Str){
    size_t i (0);
    while (isspace(Str[i])){
        ++i;
    }
    cout << i << endl;;
    return i;
}

void AfficherTab (vector<string> VString){
    for (size_t i (0); i<VString.size(); ++i)
        cout << VString[i] << endl;
}


//argc nombre argument dans le terminal,  argv liste des arguments
int main(int argc, char *argv[])
{
    // for (int i (0); i < argc; ++i)
    //     cout << argv[i] << endl;
    // if (4 != argc){
    //     cout << argc;
    //     cerr << "utilisation : "
    //          << argv[0]
    //          << " + nom d'un fichier "
    //          << endl;
    //     exit(1);
    // }
    string cheminVersFichier = string(argv[1]);
    vector<string> vFichier = FileToVectString(cheminVersFichier);
    //vFichier[2] = ToLower(vFichier[2]);

    if (string(argv[2])=="min"){
        if (string (argv[3])=="tout"){
            vFichier=ToLower(vFichier);
        }
        else {
            size_t numLigne = stoull (argv[3]);
            vFichier[numLigne]=ToLower(vFichier[numLigne]);
        }
    }

    else if (string(argv[2])=="maj"){
        if (string (argv[3])=="tout"){
            vFichier=ToUpper(vFichier);
        }
        else {
            size_t numLigne = stoull (argv[3]);
            vFichier[numLigne]=ToUpper(vFichier[numLigne]);
        }
    }

    else if (string (argv[2])=="swa"){
        vFichier=Swap(vFichier,stoul( argv[3]),stoul(argv[4]));
    }


    else if (string (argv[2])=="del"){
        vFichier=Delete(vFichier, stoul(argv[3]));
    }

    else if (string(argv[2])=="ins"){
        vFichier=Insert(vFichier, stoul(argv[3]),string(argv[4]));
    }

    else if (string(argv[2])=="mov"){
        vFichier=Move(vFichier, stoul(argv[3]),stoul(argv[4]));
    }

    EditVStringV3(vFichier);
    // cout << string(70,'-') << endl;
    // AfficherTab(vFichier);
    return 0;
}
