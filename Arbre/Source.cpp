#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#include<queue>

class BST {
	struct Membre {
	public:
		int _valeur;
		Membre* gauche, * droit;
		Membre(int val) { _valeur = val; gauche = droit = nullptr; }
	}*racine = nullptr;
	bool Contient(Membre* mem, int cle)const {
		if (!mem) { return false; }
		if (cle == mem->_valeur) { return true; }
		if (cle < mem->_valeur) { return Contient(mem->gauche, cle); }
		else { return Contient(mem->droit, cle); }
	}
	bool Insere(Membre*& mem, int cle) {
		if (!racine) { racine = new Membre(cle); return true; }
		if (cle == mem->_valeur) { return false; }
		if (cle < mem->_valeur) {
			if (mem->gauche) {
				return Insere(mem->gauche, cle);
			}
			else { mem->gauche = new Membre(cle); return true; }
		}
		else {
			if (mem->droit) {
				return Insere(mem->droit, cle);
			}
			else { mem->droit = new Membre(cle); return true; }
		}
	}
	void Dev(Membre* mem, int niveau)const {
		if (!mem) { return; }
		Dev(mem->gauche, niveau + 1);


		for (int i = 0; i < niveau; ++i)std::cout << ".";

		//if(mem->gauche&&mem->droit)
		std::cout << mem->_valeur << '\n';

		Dev(mem->droit, niveau + 1);
	}
	void Detruire(Membre* mem) {
		if (!mem) { return; }
		Detruire(mem->gauche);
		Detruire(mem->droit);
		delete mem;
	}
public:
	bool Contient(int cle)const { return Contient(racine, cle); }

	bool Insere(int val) {
		return Insere(racine, val);
	}
	void Dev()const {
		Dev(racine, 0);
	}
	~BST() { Detruire(racine); }
};

int main() {

	setlocale(LC_ALL, "Ru");

	BST bst;
	/*bst.Insere(7);
	bst.Insere(3);
	bst.Insere(2);
	bst.Insere(1);
	bst.Insere(9);
	bst.Insere(5);
	bst.Insere(4);
	bst.Insere(6);
	bst.Insere(8);
	bst.Dev();
	*/

	std::string s;
	while (std::cin >> s) {
		if (s == "cherche") {
			int cle;
			std::cin >> cle;
			std::cout << (bst.Contient(cle) ? "Oui\n" : "Non\n");
		}
		else if (s == "ajouter") {
			int cle;
			std::cin >> cle;
			std::cout << (bst.Insere(cle) ? "fait\n" : "deja");
		}
		else {
			bst.Dev();
		}
	}




	return 0;

}