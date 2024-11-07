#include <iostream>
#include <vector>

using namespace std;

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}



void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}




struct participant {
    string nom;
    string prenom;
    vector<int> classement;
};

int main()
{
    vector <string> vGlacePref;
    for (unsigned i (0); i < 4; ++i)
        vGlacePref.push_back(litUneString());

    affichVectString (vGlacePref);

    // participant test{"yo","bidule",{5,4}};
    // cout << test.nom << endl;

    return 0;
}
