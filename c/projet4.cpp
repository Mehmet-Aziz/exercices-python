#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tache
{
    string nom;
    string description;
    int priorite;
    bool etat;           // false = à faire, true = terminée
    string date;         // on passe à string pour simplifier l'entrée JJ/MM/AAAA
};

// ✅ Corrigé : meilleure saisie des données
void remplir(tache &t)
{
    cout << "Nom de la tâche : ";
    cin.ignore();
    getline(cin, t.nom); // On accepte les espaces

    cout << "Description : ";
    getline(cin, t.description);

    cout << "Priorité (1-5) : ";
    cin >> t.priorite;

    cout << "État (0 = à faire, 1 = terminée) : ";
    cin >> t.etat;

    cout << "Date limite (JJ/MM/AAAA) : ";
    cin.ignore();
    getline(cin, t.date); // plus simple à lire
}

// ✅ Corrigé : reçoit une tâche et l'affiche clairement
void affiche(const tache &t)
{
    cout << "\n--- Tâche ---" << endl;
    cout << "Nom         : " << t.nom << endl;
    cout << "Description : " << t.description << endl;
    cout << "Priorité    : " << t.priorite << endl;
    cout << "État        : " << (t.etat ? "Terminée" : "À faire") << endl;
    cout << "Date        : " << t.date << endl;
}

// ✅ Corrigé : passe le vecteur en paramètre + bon choix
void terminer(vector<tache> &taches)
{
    int choix;
    cout << "1. Par indice\n2. Par nom\nChoix : ";
    cin >> choix;

    if (choix == 1)
    {
        int index;
        cout << "Indice de la tâche : ";
        cin >> index;

        if (index >= 0 && index < taches.size())
        {
            taches[index].etat = true;
            cout << "✅ Tâche marquée comme terminée !" << endl;
        }
        else
        {
            cout << "❌ Indice invalide." << endl;
        }
    }
    else if (choix == 2)
    {
        string titre;
        cin.ignore();
        cout << "Nom exact de la tâche : ";
        getline(cin, titre);

        bool trouve = false;
        for (auto &t : taches)
        {
            if (t.nom == titre)
            {
                t.etat = true;
                cout << "✅ Tâche marquée comme terminée !" << endl;
                trouve = true;
                break;
            }
        }

        if (!trouve)
        {
            cout << "❌ Tâche non trouvée." << endl;
        }
    }
    else
    {
        cout << "❌ Choix invalide." << endl;
    }
}

// ✅ Corrigé : suppression sécurisée par index
void supprimer_tache(vector<tache> &liste, int index)
{
    if (index < 0 || index >= liste.size())
    {
        cout << "❌ Index invalide. Aucun élément supprimé." << endl;
        return;
    }

    liste.erase(liste.begin() + index);
    cout << "✅ Tâche supprimée avec succès !" << endl;
}

// ✅ Corrigé : bon format + filtre clair
void filtrer_a_faire(const vector<tache> &taches)
{
    cout << "\n📋 Tâches à faire :" << endl;
    for (const auto &t : taches)
    {
        if (!t.etat)
        {
            cout << "- " << t.nom << " (priorité " << t.priorite << ")" << endl;
        }
    }
}

int main()
{
    vector<tache> liste;
    int choix;
    bool fin = false;

    cout << "=== Gestionnaire de Tâches ===\n";

    do
    {
        cout << "\nMenu :\n";
        cout << "1. Ajouter une tâche\n";
        cout << "2. Afficher toutes les tâches\n";
        cout << "3. Marquer une tâche comme terminée\n";
        cout << "4. Supprimer une tâche\n";
        cout << "5. Afficher tâches à faire\n";
        cout << "6. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
        {
            tache temp;
            remplir(temp);
            liste.push_back(temp);
            break;
        }
        case 2:
            for (const auto &t : liste)
                affiche(t);
            break;

        case 3:
            terminer(liste);
            break;

        case 4:
        {
            int index;
            cout << "Indice de la tâche à supprimer : ";
            cin >> index;
            supprimer_tache(liste, index);
            break;
        }

        case 5:
            filtrer_a_faire(liste);
            break;

        case 6:
            fin = true;
            break;

        default:
            cout << "❌ Choix invalide." << endl;
        }

    } while (!fin);

    cout << "👋 Merci d’avoir utilisé la To-Do List." << endl;
    return 0;
}
