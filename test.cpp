#include <iostream>
#include <vector>
#include <EasyAssert.h>
#include <cassert>

using namespace std;

void genererTab (vector<int> & tab,
                const size_t &taille,
                const int & min,
                const int & max){
    tab.resize(taille);
    for (int & val : tab)
        val = min + rand ()%(max-min);
}

void afficherTab (const vector<int> & tab){
    for (const int & val : tab)
        cout << val << ' ';
    cout << endl;
}

int supprimerElem (vector<int> & tab, const size_t & pos){
    int val = tab[pos];
    for (unsigned i(pos); i < tab.size(); i++)
        tab[i] = tab[i+1];
    tab.resize(tab.size()-1);
    return val;
}

void insererElem (vector<int> & tab, const size_t & pos,
                 const int & val){
    tab.resize(tab.size()+1);
    for (unsigned i(tab.size()-1); i>=pos+1; i--){
        tab[i] = tab[i-1];

    }
    tab[pos]=val;
}

void deplacerElem (vector<int> & tab,
                  const size_t & posInit,
                  const size_t & posFin){
    int nbr = supprimerElem(tab,posInit);
    insererElem(tab,posFin,nbr);
}

void monDeplacerElem (vector<int> & tab,
                     const size_t & posInit,
                     const size_t & posFin){
    int val = tab[posInit];
    tab.erase(tab.begin()+posInit);
    tab.insert(tab.begin()+posFin, val);
}

void protocoleSupprimerAvecEasyAssert (const size_t & tailleTab,
                                      const unsigned & nbTab){
    if (tailleTab > 26 || nbTab > 2){
        cerr << "paramètres trops grands pour EASY_ASSERT" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        //on le génère
        vector<int> tabInitial;
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //on l'appele avec la première copie pour supprimer la case courante
            supprimerElem(tabCourant1, j);
            //on fait appel à la même fonction du C++ avec la seconde copie
            tabCourant2.erase(tabCourant2.begin()+j);
            //on compare les resultats
            EASY_ASSERT (tabCourant1 == tabCourant2);
        }
    }
}

void protocoleInsererAvecEasyAssert (const size_t & tailleTab,
                                    const unsigned & nbTab){
    if (tailleTab > 26 || nbTab > 2){
        cerr << "paramètres trops grands pour EASY_ASSERT" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        vector<int> tabInitial;
        //on le génère
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //on l'appele avec la première copie pour inserer -1 dans la case courante
            insererElem(tabCourant1, j, -1);
            //on fait appel à la même fonction du C++ avec la seconde copie
            tabCourant2.insert(tabCourant2.begin()+j, -1);
            //on compare les resultats
            EASY_ASSERT (tabCourant1 == tabCourant2);
        }
    }
}

void protocoleDeplacerAvecEasyAssert (const size_t & tailleTab,
                                     const unsigned & nbTab){
    if (tailleTab > 26 || nbTab > 2){
        cerr << "paramètres trops grands pour EASY_ASSERT" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        vector<int> tabInitial;
        //on le génère
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice j du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //pour chaque autre indice k du tableau (k != j)
            for (size_t k (0); k < tabInitial.size(); ++k){
                if (k == j) continue;
                //on appelle notre fonction pour deplacer l'element entre les positions j et k
                deplacerElem(tabCourant1, j, k);
                //on appelle notre fonction pour deplacer l'element entre les positions j et k,
                //mais en utilisant les fonctions du C++
                monDeplacerElem(tabCourant2, j, k);
                EASY_ASSERT (tabCourant1 == tabCourant2);
            }
        }
    }
}

void protocoleSupprimerAvecAssert (const size_t & tailleTab,
                                      const unsigned & nbTab){
    if (tailleTab < 1000 || nbTab < 10){
        cerr << "paramètres trops petits pour assert" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        //on le génère
        vector<int> tabInitial;
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //on l'appel avec la première copie pour supprimer la case courante
            supprimerElem(tabCourant1, j);
            //on fait appel à la même fonction du C++ avec la seconde copie
            tabCourant2.erase(tabCourant2.begin()+j);
            //on compare les resultats
            assert (tabCourant1 == tabCourant2);
        }
    }
    cout << "tous les tests finis !" << endl;
}

void protocoleInsererAvecAssert (const size_t & tailleTab,
                                    const unsigned & nbTab){
    if (tailleTab < 1000 || nbTab < 10){
        cerr << "paramètres trops petits pour assert" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        vector<int> tabInitial;
        //on le génère
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //on l'appele avec la première copie pour inserer -1 dans la case courante
            insererElem(tabCourant1, j, -1);
            //on fait appel à la même fonction du C++ avec la seconde copie
            tabCourant2.insert(tabCourant2.begin()+j, -1);
            //on compare les resultats
            assert (tabCourant1 == tabCourant2);
        }
    }
    cout << "tous les tests finis !" << endl;
}

void protocoleDeplacerAvecAssert (const size_t & tailleTab,
                                     const unsigned & nbTab){
    if (tailleTab < 1000 || nbTab < 10){
        cerr << "paramètres trops petits pour assert" << endl;
        return;
    }
    //pour chaque tableau
    for (unsigned i (0); i < nbTab; ++i){
        vector<int> tabInitial;
        //on le génère
        genererTab(tabInitial, tailleTab, 0, tabInitial.size() + 10);
        //pour chaque indice j du tableau
        for (size_t j (0); j < tabInitial.size(); ++j){
            //on crée 2 copies du tableau originel
            vector<int> tabCourant1 (tabInitial), tabCourant2 (tabInitial);
            //pour chaque autre indice k du tableau (k != j)
            for (size_t k (0); k < tabInitial.size(); ++k){
                if (k == j) continue;
                //on appelle notre fonction pour deplacer l'element entre les positions j et k
                deplacerElem(tabCourant1, j, k);
                //on appelle notre fonction pour deplacer l'element entre les positions j et k,
                //mais en utilisant les fonctions du C++
                monDeplacerElem(tabCourant2, j, k);
                assert (tabCourant1 == tabCourant2);
            }
        }
    }
    cout << "tous les tests finis !" << endl;
}

int main (){
    //srand(time(nullptr));
    vector<int> tab;
    genererTab(tab, 10, 0, 20);
    afficherTab(tab);
    int val = supprimerElem (tab, 5);
    afficherTab(tab);
    insererElem(tab, 0, -1);
    afficherTab(tab);
    deplacerElem(tab, 0, 9);
    afficherTab(tab);
    return 0;
}

// int main(int argc, char**argv)
// {
//     if (3 != argc){
//         cerr << "utilisation : " << argv[0] << '\n'
//              << "1er argument : taille des tableaux \n"
//              << "2nd argument : nombre de tableaux"
//              <<endl;
//         return 1;
//     }
//     size_t tailleTab (stoull (argv[1]));
//     unsigned nbTab (stoul (argv[2]));
//     //    protocoleSupprimerAvecEasyAssert (tailleTab, nbTab);
//     //    protocoleInsererAvecEasyAssert (tailleTab, nbTab);
//     //    protocoleDeplacerAvecEasyAssert (tailleTab, nbTab);
//         protocoleSupprimerAvecAssert (tailleTab, nbTab);
//     //    protocoleInsererAvecAssert (tailleTab, nbTab);
//     //    protocoleDeplacerAvecAssert (tailleTab, nbTab);
//     return 0;
// }
