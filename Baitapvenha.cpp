#include <bits/stdc++.h>

using namespace std;

struct Nut{
	int info;
	Nut *Left, *Right;
};
Nut *T;
int m1 = 0, m2 = 0;

//Tim chieu cao cua cay
int ChieuCao(Nut *T){
	if (T == NULL) return 0;
	if (T->Left == NULL || T->Right == NULL) return 1;
	return 1 + max(ChieuCao(T->Left), ChieuCao(T->Right));
}

//Bo sung mot phan tu bang X  vao cay T
void BoSung(Nut *&T, int X){
	if (T == NULL){
		Nut *p = new Nut;
		p->info = X;
		p->Left = p->Right = NULL;
		T = p;
	}else if (T->info >= X)
		return BoSung(T->Left,X);
	else	
		return BoSung(T->Right,X);
}
//Xoa tat ca cac nut trong cay
void XoaTatCa(Nut *&T){
	if (T == NULL) return;
	XoaTatCa(T->Left);
	XoaTatCa(T->Right);
	delete T;
}

//Tim gia tri lon nhat cua cay: 
//Cay T la cay nhi phan tim kiem 
// Cay T khong phai la cay nhi phan tim kiem

//Truong hop nay la cay nhi phan tim kiem
int Timmax(Nut *T){
	if (T == NULL) return 0;
	else return Timmax(T->Right);
}

//Truong hop khong phai la cay nhi phan tim kiem
int TimMax(Nut *T){
	if (T == NULL) return 0;
	m1 = max(m1,TimMax(T->Left));
	m2 = max(m2,TimMax(T->Right));
	return max(m1,m2);
}

int TimMin(Nut *T){
	if (T == NULL) return 0;
	m1 = min(m1,TimMin(T->Left));
	m2 = min(m2,TimMin(T->Right));
	return min(m1,m2);
}

//Tim So Nut
int TimSoNut(Nut *T){
	if (T == NULL) 
		return 0;
	if (T->Left != NULL || T->Right != NULL) 
		return 1 + TimSoNut(T->Left) + TimSoNut(T->Right);
}

//Tim dia chi cua nut cha
Nut *TimCha(Nut *T, Nut *p){
	if (T == NULL) return NULL;
	if (T->Left == p || T->Right == p)
		return T;
	Nut *q = TimCha(T->Left,p);
	if (q != NULL)	
		return q; // Tim thay cha thi return;
	//Neu khong tim thay thi tim ben phai
	return TimCha(T->Right,p);	
}

//Tim muc cua nut duoc tro boi p thuoc cay T
int MucCuap(Nut *T, Nut *p){
	Nut *z = TimCha(T,p);
	if (z == NULL)
		return 0; // Khong tim thay dia chi cua p trong danh sach
	Nut *q = TimCha(T->Left,p);
	if (q != NULL)
		return 1 + MucCuap(T->Left,p); 
	else 
		return 1 + MucCuap(T->Right,p);	
}

//Tim dia chi cua mot nut thuoc cay T co gia tri truong Info bang X
//Doi voi cay nhi phan tim kiem
Nut *TimKiem(Nut *T, int X){
	if (T == NULL)
		return NULL;
	if (T->info == X) 
		return T;
	if (T->info > X)
		return TimKiem(T->Left,X);
	else 
		return TimKiem(T->Right,X);		
}

//Cay T khong phai la cay nhi phan tim kiem
Nut *TimKiem1(Nut *T, int X){
	if (T == NULL) return NULL;
	if (T->info == X) return T;
	Nut *p = TimKiem1(T->Left,X);
	if (p != NULL) 
		return p;
	else{
		Nut *q = TimKiem1(T->Right,X);
		return q;
	}	
}
//In ra gia tri truong info theo thu tu giam dan, biet rang T la cay nhi phan tim kiem
void InGiamDan(Nut *T){
	if (T != NULL){
		InGiamDan(T->Right);
		cout << T->info << " ";
		InGiamDan(T->Left);
	}
}

//Sao chep mot nut co gia tri truong bang T
Nut* SaoChep(Nut *T){
	Nut *p = new Nut;
	if (T != NULL){
		p->info  = T->info;
		p->Left  = SaoChep(T->Left);
		p->Right = SaoChep(T->Right);
	}
	return p;
}
//Kiem tra mot cay co phai la cay nhi phan tim kiem hay khong
bool CayNhiPhanTimKiem(Nut *T){
	if (T == NULL)
		return true;
	if (T->Left != NULL && TimMax(T->Left) > T->info)
		return false;
	if (T->Right != NULL && TimMin(T->Right) < T->info)
		return false;
	if (!CayNhiPhanTimKiem(T->Left) && !CayNhiPhanTimKiem(T->Right))
		return true;	
	return false;	
}

//Tim cap cua cay
int CapCuaCay(Nut *T){
	if (T == 0 || T->Left == NULL && T->Right == NULL)
		return 0;
	return max(CapCuaCay(T->Left),CapCuaCay(T->Right));	
}

//Thay the tat ca gia tri truong info dung bang muc cua cay
void ThayThe(Nut *T, int muc){
	if (T != NULL){
		T->info = muc;
		ThayThe(T->Left,muc + 1);
		ThayThe(T->Right,muc + 1);
	}
}
//Dem so nut tren cay T co info bang X
int dem = 0;
int Dem(Nut *T, int X){
	if (T != NULL){
		if (T->info == X) dem++;
		Dem(T->Left,X);
		Dem(T->Right,X);
	}
	return dem;
}

int main(){
	//Code here...

	return 0;
}

