#include <bits/stdc++.h>

using namespace std;

struct Nut{
	int Info;
	Nut *Left, *Right;
};
Nut *T;

int m = INT_MAX;
int Min(Nut *T){
	if(T != NULL){
		m = min(T->Info,m);
		Min(T->Left);
		Min(T->Right);
	}
	return m;
}

int M = INT_MAX;
int Max(Nut *T){
	if(T != NULL){
		M = max(T->Info,M);
		Max(T->Left);
		Max(T->Right);
	}
	return M;
}

int LaCayNPTK(Nut *T){
	if (T == NULL || T->Left == NULL && T->Right == NULL)
		return 1;
	if (T->Left == NULL)
		return (T->Info <= Min(T->Right) && LaCayNPTK(T->Right));
	else if (T->Right == NULL)
		return (T->Info > Max(T->Left) && LaCayNPTK(T->Left));
	else
		return (T->Info <= Min(T->Right) && T->Info > Max(T->Left) 
				   && LaCayNPTK(T->Left) && LaCayNPTK(T->Right));		
}

int SoNutLa(Nut *T){
	if (T == NULL) return 0;
	else if (T->Left == NULL && T->Right == NULL)
		return 1;
	if (T->Left != NULL || T->Right != NULL)		
		return 1 + SoNutLa(T->Left) + SoNutLa(T->Right);
}

int ChieuCao(Nut *T){
	if (T == NULL) return 0;
	else if (T->Left == NULL && T->Right == NULL)
		return 1;
	else return 1 + max(ChieuCao(T->Left),ChieuCao(T->Right));
}

int main(){
	
	return 0;
}

