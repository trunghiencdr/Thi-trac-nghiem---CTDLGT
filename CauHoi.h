#pragma once
#include "DoHoaManHinh.h"
#include "XuLiChuoi.h"
#include "DongHo.h"
#include <string.h>
#include "fstream"
#define MAXID 200
using namespace std;
int soLuongID;
int *danhSachID;
char truongCauHoi[][20]= {"THEM CAU HOI","Noi dung:", "A:", "B:", "C:", "D:", "Dap an:", "ADD"};
char truongSuaCH[][20]= {"SUA CAU HOI","Noi dung:", "A:", "B:", "C:", "D:", "Dap an:", "SUA"};
const char* fileID="Data\\danhSachID.txt";
const char* FileCauHoi = "Data\\CauHoi.txt";
//===============================================================================================================================================================
struct cauhoi
{
    int trangThai;
    char maMH[11];
    string noidung;
    string A;
    string B;
    string C;
    string D;
    char dapan;

};
struct nodecauhoi
{
    int key;
    cauhoi info;
    nodecauhoi *left;
    nodecauhoi *right;
    int height;
};
typedef nodecauhoi *PTRQ;
//===============================================================================================================
cauhoi cauHoiMoi(char *maMh, string noidung, string a, string b, string c, string d, char dapAn);
void stoc2(string a[], int n, char *b[]);
int max(int a, int b);
int height(PTRQ N);
int max(int a, int b);
PTRQ newNode(int key, cauhoi a);
PTRQ rightRotate(PTRQ y);
PTRQ leftRotate(PTRQ x);
int getBalance(PTRQ N);
PTRQ  insert(PTRQ &node, int key, cauhoi a);
PTRQ minValueNode(PTRQ node);
PTRQ deleteNode(PTRQ &root, int key);
void preOrder(PTRQ root);
int layID(int *a, int &n);
void stoc(string s, char *c);
int *randomCauHoi(int *dsCauHoi,int soCauHoi, int soCauThi);
void inTTCH(PTRQ root, int id);
void ctos(char *c, string &s);
void ctos2(char *c[], int n, string *s);
int demCauHoi2(PTRQ root, char *maMH);
void bubbleSort(int *&a, int n);
int xoaMangID(int *a, int &n, int &vitri);
int them1CauHoi(PTRQ &root, char *maMH, int *&dsID, int &soCH, int &vitriID);
int countNode(PTRQ root);
void layDSCauHoi(PTRQ root, int *&dsCauHoi, char* maMH, int soCauHoi);
PTRQ search(PTRQ root, int id);
int sua1CauHoi(PTRQ &p);
int nhapThongTinThi(int x, int y, PTRQ root, char *maMh, int &soCauThi, int &thoiGian);
int demSoCauHoi(PTRQ root, char *maMH);
void inNoiDung(string s, int max);// max la so ki tu toi da in ra
int inDanhSachCH(PTRQ &root, int dsID[], char *maMH, int &soCauHoi, int &idCH);
int timKiemMangID(int *a, int n, int x);
void inBangCH(PTRQ root, int vtThongTin[], char *maMH, int y, int dsID[], int n, int vitriHL, int oToiDa);// n la so cau hoi
void diChuyenBangCH(PTRQ root, int vtThongTin[], int y, int dsID[], int n, int &vitriHT,int oToiDa,int trangThai);
PTRQ search(PTRQ root, int id);
void inString(string s, int dai);
void showdapan(int dapan[],int SoCauHoi);
int timNoiDungCH(PTRQ root, int *dsID, int &soCauHoi, char *noiDung);
int* docFileID( int &n);
void ghiFileID(int *a, int n);
void SaveCauHoi(PTRQ root);
//==============================================================================================================================================
int height(PTRQ N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
PTRQ newNode(int key, cauhoi a)
{
    PTRQ node = new nodecauhoi();
    node->key = key;
    node->info=a;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
    // added at leaf
    return(node);
}

// neu lech trai trai thi xoay phai lay nut bi lech lam tam de xoay- y
PTRQ rightRotate(PTRQ y)
{
    PTRQ x = y->left; // bien tam luu dia chi cua nut con trai va con phai cua con trai
    PTRQ T2 = x->right;

    // dich chuyen cac nut lay y lam nut de xoay
    x->right = y;
    y->left = T2;

    // cap nhat lai chieu cao cua x va y
    // =max 2 cay con + 1
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // tra ve nut goc moi la x 
    return x;
}

// lech phai phai thi xoay trai lay nut lech lam tam xoay-x
PTRQ leftRotate(PTRQ x)
{
	// bien tam luu dia chi node tam thoi
    PTRQ y = x->right;
    PTRQ T2 = y->left;

    // xoay trai -> nut con phai y lam goc
    y->left = x;
    x->right = T2;

    // cap nhat lai chieu cao
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // tra ve nut goc moi
    return y;
}

// kiem tra do lech cua node , cay con trai so voi con phai
int getBalance(PTRQ N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

PTRQ  insert(PTRQ &node, int key, cauhoi a)
{
    // them node moi vao cay nhu cay bts
    if (node == NULL)
        return(newNode(key, a));

    if (key < node->key)
        node->left = insert(node->left, key, a);
    else if (key > node->key)
        node->right = insert(node->right, key, a);
    else // key bang key thi khong them 
        return node;

    // cap nhat do cao cua  nut cha hien tai 
    node->height = 1 + max(height(node->left),
                           height(node->right));

    //3.Kiem tra tai moi node cha khi ket thuc de qui xem node vua them co lam lech khong
    int balance = getBalance(node);

    // thuc hien xoay cay de cay can bang neu bi lech
    // co 4 truong hop bi lech

    // lech trai trai
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // lech phai phai
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // lech trai phai
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // lech phai trai
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // tra ve dia chi cua node (khong bi lech)
    return node;
}

/* Cho mot cau tim kiem nhi phan khong trong,
tra ve nut co gia tri khoa toi thieu tim thay 
trong cay do. Luu ý rang toan bo cay khong can tim kiem. */
PTRQ minValueNode(PTRQ node)
{
    PTRQ current = node;

    /* tim la ngoai cung ben trai */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Xoa nut khoi cay avl */
PTRQ deleteNode(PTRQ &root, int key)
{

    // BUOC 1: THUC HIEN XOA CAY BST
    if (root == NULL)
        return root;

    /* Neu khoa can xoa nho hon khoa goc, thi
    no nam o cay con ben trai*/
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    /* Neu khoa can xoa lon hon khoa goc, thi
    no nam o cay con ben phai*/
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    /*Neu khoa giong voi khoa goc, thi day
    la nut can xoa*/
    else
    {
        // nut chi co 1 con hoac khong co con
        if( (root->left == NULL) ||
                (root->right == NULL) )
        {
            PTRQ temp = root->left ? // root ->left !=NULL
                        root->left :
                        root->right;

            // Khong co con
            if (temp == NULL)
            {
//            	temp->info=root->info;
                temp = root;
                root = NULL;
            }
            else // co 1 con
            {
//            	root->info=temp->info;
                *root=*temp;
            }
            // Sao chep noi dung cua cay con
            free(temp);
        }
        else
        {
            /* Nut co 2 con: lay nut the mang (nho nhat
            trong cay con ben phai)*/
            PTRQ temp = minValueNode(root->right);

            /* Sao chep su lieu cua nut the mang*/
            root->key = temp->key;
            root->info=temp->info;
            // Xoa nut the mang
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    // Neu cau chi co 1 nut thi tra ve
    if (root == NULL)
        return root;

    // BUOC 2: CAP NHAT CHIEU CAO CUA NUT HIEN TAI
    root->height = 1 + max(height(root->left),
                           height(root->right));

    /* BUOC 3: Kiem tra tai moi node cha khi ket thuc 
	de qui xem node vua them co lam lech khong*/
    int balance = getBalance(root);

    // thuc hien xoay cay de cay can bang neu bi lech
    // co 4 truong hop bi lech

    // lech trai trai
    if (balance > 1 &&
            getBalance(root->left) >= 0)
        return rightRotate(root);

    // lech trai phai
    if (balance > 1 &&
            getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // lech phai phai
    if (balance < -1 &&
            getBalance(root->right) <= 0)
        return leftRotate(root);

    // lech phai trai
    if (balance < -1 &&
            getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


int layID(int *a, int &n)
{
    n--;
    return a[n];
}
void diChuyenBangCH(PTRQ root, int vtThongTin[], int y, int dsID[], int n, int &vitriHT,int oToiDa,int trangThai)
{
    int chon=vitriHT%oToiDa;
    PTRQ p = search(root, dsID[vitriHT]);
    Normal2(vtThongTin[0]-3,y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << dsID[vitriHT];
    gotoxy(vtThongTin[1], y+chon);
    cout << p->info.trangThai;
    gotoxy(vtThongTin[2], y+chon);
    inNoiDung(p->info.noidung, 35);
    if(trangThai==Up)
    {
        vitriHT--;
        chon--;
    }
    if(trangThai==Down)
    {
        if(vitriHT < n-1)
        {
            vitriHT++;
            chon++;
        }
    }
    p=search(root, dsID[vitriHT]);
    HighLight2(vtThongTin[0]-3, y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << dsID[vitriHT];
    gotoxy(vtThongTin[1], y+chon);
    cout << p->info.trangThai;
    gotoxy(vtThongTin[2], y+chon);
    inNoiDung(p->info.noidung, 35);

}
void SaveCauHoi(PTRQ root)
{
    PTRQ Stack[STACKSIZE];
    PTRQ p=root;
    int maxnode = countNode(root);
    int sp=-1;	// Khoi tao Stack rong
    ofstream ofs;
    ofs.open(FileCauHoi, ios_base::out);
    if(ofs.fail())
    {
        BaoLoi(xTB, yTB, "data danh sach cau hoi bi hong!");
        return;
    }
    ofs << maxnode << endl;
    do
    {
        while(p != NULL)
        {
            Stack[++sp]= p;
            p = p->left;
        }
        if (sp != -1)
        {
            p = Stack[sp--];
            ofs << p->key <<",";
            ofs << p->info.trangThai << endl;
            ofs << p->info.maMH << endl;
            ofs << p->info.noidung << endl;
            ofs << "A. " << p->info.A << endl;
            ofs << "B. " << p->info.B << endl;
            ofs << "C. " << p->info.C << endl;
            ofs << "D. " << p->info.D << endl;
            ofs << p->info.dapan << endl;
            p = p->right;
        }
        else
            break;
    }
    while(1);
    ofs.close();
}

int *randomCauHoi(int *dsCauHoi,int soCauHoi, int soCauThi)
{
    srand(time(NULL));
    int *dethi = new int[soCauThi];
    int a, i, x;
    for(i = 0; i < soCauThi; ++i)
    {
        a = rand() % soCauHoi;
        dethi[i] = dsCauHoi[a];
        x = dsCauHoi[a];
        dsCauHoi[a] = dsCauHoi[soCauHoi - 1];
        dsCauHoi[soCauHoi--] = x;
    }
    return dethi;
}
int* docFileID( int &n)
{
    FILE *f;
    int x, i=0;
    f=fopen(fileID,"rb");
    fread(&n, sizeof(int), 1, f);
    int *a= new int[n];
    while(fread (&x, sizeof (int), 1, f)!=0)
    {
        a[i++]=x;
    }

    fclose(f);
    return a;
}
void ghiFileID(int *a, int n)
{
    FILE *f;
    f=fopen(fileID,"wb");
    fwrite(&n, sizeof(int), 1, f);
    for(int i=0; i<n; i++)
    {
        fwrite(&a[i], sizeof(int), 1, f);
    }
    fclose(f);
}
int timNoiDungCH(PTRQ root, int *dsID,int &soCauHoi, char *noiDung)
{
    PTRQ p;
    char *temp=new char[200];
    for(int i=0; i<soCauHoi; i++)
    {
        p=search(root, dsID[i]);
        stoc(p->info.noidung, temp);
        if(timChuoiCon(temp, noiDung)==-1) // khong tim thay thi xoa
        {
            xoaMangID(dsID, soCauHoi, i);
            i--;
        }
    }
    if(soCauHoi==0) return -1;
    else return 1;
}
int nhapThongTinThi(int x, int y, PTRQ root, char *maMH, int &soCauThi, int &thoiGian)
{
    Normal();
    int cotTextField = x+15;
    int soKhung = 3;
    int dai=30, rong = 2;
    veKhung(x,y, dai+25, 23);
    y=y+2;
    // ve Khung nhap
    gotoxy(95,y+1);
    cout << "THONG TIN BAI THI";
    // ve Khung nhap
    int pos[3];
    bool kt[2];
    char *text[2];
    for(int i=0; i<soKhung-1; i++)
    {
        text[i] = new char[100];
        strcpy(text[i], "");
    }
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=false;
    }
    char labelSV[][20]= {"So cau hoi:", "Thoi gian:","THI"};
    veKhungTextField(cotTextField, y, dai, rong, pos, soKhung,labelSV);
    gotoxy(cotTextField+dai+1, pos[1]);
    cout << "Phut";
    char kytu;
    int vitri=0;
    int dichuyen;
    int trangThai=0;
    while(true)
    {
        switch(vitri)
        {
        case 0:// nhap so cau hoi
        {
            hienConTro();
            int soCauHoi=demSoCauHoi(root, maMH);
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            dichuyen=nhapChuoiSo(cotTextField+1, pos[vitri], dai-1, text[vitri],9);
            Normal();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            // kiem tra xem ma da co chua neu co roi thi thong bao da co roi

            if(atoi(text[vitri]) > soCauHoi)
            {
                xoaHang(cotTextField, pos[vitri]-2,25);
                gotoxy(cotTextField, pos[vitri]-2);
                textcolor(160);
                cout << "Con thieu " << atoi(text[vitri])-soCauHoi << " cau hoi";
                kt[vitri]=false;
                Normal();
            }
            else
            {
                xoaHang(cotTextField, pos[vitri]-2,25);
                kt[vitri]=true;
            }
            break;
        }
        case 1:// nhap ten
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiSo(cotTextField+1, pos[vitri], dai-1, text[vitri],9);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            break;
        }
        case 2: // add
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+6,pos[vitri]-1,7,1);
            Normal();
            do
            {
                char c=getch();
                if(c==ENTER)
                {
                    if(ktTextField(kt,soKhung-1)==false)
                    {
                        BaoLoi(xTB, 5, "Thong tin nhap khong chinh xac!");
                        dichuyen=Down;
                        break;
                    }
                    else
                    {
                        soCauThi=atoi(text[0]);
                        thoiGian=atoi(text[1]);
                        return 1;
                    }
                }
                if(c==Up)
                {
                    dichuyen=Up;
                    break;
                }
                if(c==Down)
                {
                    dichuyen=Down;
                    break;
                }
            }
            while(true);
            veKhungNho(cotTextField+6,pos[vitri]-1,7,1);
            hienConTro();
        }
        }
        if(dichuyen==ESC) return ESC;
        if(dichuyen ==Up)
        {
            if(vitri==0) vitri=soKhung-1;
            else vitri--;
        }
        if(dichuyen ==Down)
        {
            if(vitri==soKhung-1) vitri=0;
            else vitri++;
        }

    }
    for(int i=0; i<5; i++)
    {
        delete [] text[i];
    }
    delete []text;
}
void showdapan(int dapan[],int SoCauHoi)
{
    int x=2,y=15;
    for(int i=0; i<SoCauHoi; i++)
    {
        x=4;
        x=x + 8 * (i/20);
        y=14 + (i% 20);
        Normal();
        gotoxy(2,13);
        cout<<"DAP AN DA CHON";
        gotoxy(x-1, y);
        if(dapan[i]==4)
        {
            textcolor(240);
            printf("%5s", " ");
            gotoxy(x,y);
            cout<<i+1<<".";
            cout << "?";
        }
        else
        {
            HighLight();
            printf("%5s", " ");
            gotoxy(x,y);
            cout<<i+1<<".";
            cout << doiChon(dapan[i]);
        }
    }
}
void inString(string s, int dai)
{
    if(s.length()<dai-1) cout << s;
    else
    {
        for(int i=s.length()-dai+1; i < s.length(); i++)
        {
            cout << s[i];
        }
    }
}
int countNode(PTRQ root)
{
    PTRQ Stack[STACKSIZE];
    PTRQ p=root;
    int i = 0;
    int sp=-1;	// Khoi tao Stack rong
    do
    {
        while(p != NULL)
        {
            Stack[++sp]= p;
            p = p->left;
        }
        if (sp != -1)
        {
            p = Stack[sp--];
            ++i;
            p = p->right;
        }
        else
            break;
    }
    while(1);
    return i;
}
cauhoi cauHoiMoi(char *maMH, string noidung, string a, string b, string c, string d, char dapAn)
{
    cauhoi temp;
    strcpy(temp.maMH, maMH);
    temp.noidung=noidung;
    temp.A=a;
    temp.B=b;
    temp.C=c;
    temp.D=d;
    temp.dapan=dapAn;
    temp.trangThai=0;
    return temp;
}


void bubbleSort(int *&a, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
}
void stoc2(string a[], int n, char *b[])
{
    for(int i=0; i<n; i++)
    {
        stoc(a[i], b[i]);
    }
}
void ctos2(char *c[],int n, string *s)
{
    for(int i=0; i<n; i++)
    {
        string temp(c[i]);
        s[i]=temp;
    }
}
int xoaMangID(int *a, int &n, int &vitri)
{
    if(n<=0) return 0;
    if(vitri<0)// xoa dau
        vitri=0;
    if(vitri>=n) // xoacuoi
        vitri=n-1;
    for(int i=vitri; i<n-1; i++)
        a[i]=a[i+1];
    if(vitri==n-1 && n!=1) vitri--;
    n--;
    return 1;
}
void ctos(char *c, string &s)
{
    int i = 0;
    while(i < strlen(c))
    {
        s += c[i];
        ++i;
    }
    s[i]='\n';
}
void stoc(string s, char *c)
{

    for(int i = 0; i < s.length(); i++)
    {
        c[i] = s[i];
    }
    c[s.length()] = '\0';
}

int timKiemMangID(int *a, int n, int x)
{
    for(int i=0; i<n; i++)
        if(a[i]==x) return i;
    return -1;
}
int nodeHeight(PTRQ p)
{
    if(p == NULL)
        return 0;
    return max(nodeHeight(p->left), nodeHeight(p->right)) + 1;
}
void inNoiDung(string s, int max)
{
    int i=0;
    for( i=0; i<s.length() && i < max-3; i++)
    {
        cout << s[i];
    }
    if(s.length()>max-3) cout << "...";
}

int sua1CauHoi(PTRQ &p)
{
    int cotTextField = 35, y=yLamViec+1;
    int soKhung = 7;
    int dai=55, rong = 2;
    // ve Khung nhap
    int pos[soKhung];
    bool kt[soKhung-1];
    char **text = new char*[soKhung-2];
    for(int i=0; i<soKhung-2; i++)
    {
        text[i] = new char[201];
        strcpy(text[i], "");
    }
    stoc(p->info.noidung, text[0]);// noi dung
    stoc(p->info.A,text[1]);// a
    stoc(p->info.B,text[2]);// b
    stoc(p->info.C,text[3]);// c
    stoc(p->info.D,text[4]);//d
    char dapAn=p->info.dapan;
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=true;
    }
    khungNhapCauHoi(cotTextField, y, dai, rong, pos, soKhung,truongSuaCH);
    anConTro();
    gotoxy(cotTextField+1, pos[0]);
    inString(text[0], dai-1);
    gotoxy(cotTextField+1, pos[1]);
    inString(text[1], dai-1);
    gotoxy(cotTextField+1, pos[2]);
    inString(text[2], dai-1);
    gotoxy(cotTextField+1, pos[3]);
    inString(text[3], dai-1);
    gotoxy(cotTextField+1, pos[4]);
    inString(text[4], dai-1);
    gotoxy(cotTextField+1, pos[5]);
    cout << "<<  " << dapAn << "  >>";
    hienConTro();
    char kytu;
    int vitri=0;
    int dichuyen;
    while(true)
    {
        switch(vitri)
        {
        case 0:// noi dung
        case 1:// a
        case 2:// b
        case 3:// c
        case 4: // d
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiDB(cotTextField+1, pos[vitri], dai-1, text[vitri], 200);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            //if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            if(strcmp(text[vitri],"")!=0)
            {
                kt[vitri]=true;
                if(vitri==2||vitri==3||vitri==4)
                {
                    for(int m=1; m<vitri; m++)
                    {
                        if(strcmp(text[vitri],text[m])!=0)
                        {
                            kt[vitri]=true;
                        }
                        else
                        {
                            kt[vitri]=false;
                            break;
                        }
                    }
                }
            }
            else kt[vitri]=false;
            break;
            break;
        }
        case 5: // chon dap an
        {
            anConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=chonDapAn(cotTextField+1, pos[vitri], dai-1, dapAn);
            hienConTro();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            kt[vitri]=true;
            break;
        }
        case 6: // sua
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+23,pos[vitri]-1,6,1);
            Normal();
            do
            {
                char c=getch();
                if(c==ENTER)
                {
                    if(ktTextField(kt,soKhung-1)==false)
                    {
                        BaoLoi(xTB, yTB, "Sua cau hoi that bai!");
                        dichuyen=Down;
                        break;
                    }
                    else
                    {
                        string temp[5];
                        ctos2(text, 5, temp);
                        p->info.noidung=temp[0];
                        p->info.A=temp[1];
                        p->info.B=temp[2];
                        p->info.C=temp[3];
                        p->info.D=temp[4];
                        BaoLoi(xTB, yTB, "Sua cau hoi thanh cong");
                        return 1;
                    }
                }
                if(c==Up)
                {
                    dichuyen=Up;
                    break;
                }
                if(c==Down)
                {
                    dichuyen=Down;
                    break;
                }
            }
            while(true);
            veKhungNho(cotTextField+23,pos[vitri]-1,6,1);
            hienConTro();
        }
        }

        if(dichuyen==ESC) return ESC;
        if(dichuyen ==Up)
        {
            if(vitri==0) vitri=soKhung-1;
            else vitri--;
        }
        if(dichuyen ==Down)
        {
            if(vitri==soKhung-1) vitri=0;
            else vitri++;
        }
    }
}
void inBangCH(PTRQ root, int vtThongTin[], char *maMH, int y,  int *dsID, int n, int vitriHL, int oToiDa)
{

    if(n==0 || vitriHL >= n) return;
    PTRQ p;
    int trangHienTai=vitriHL/oToiDa;
    int chon=vitriHL%oToiDa;
    int soTrang;
    if(n%oToiDa==0)	soTrang=n/oToiDa-1;
    else soTrang=n/oToiDa;
    xoaKhungLamViec();
    viethoa(maMH);
    veBangLop(vtThongTin[0]-3,y-4,oToiDa);
    gotoxy(vtThongTin[0]+20, y-5) ;
    cout << "DANH SACH CAU HOI MON " << maMH;
    gotoxy(vtThongTin[0], y-3);
    cout << "ID";
    gotoxy(vtThongTin[1], y-3);
    cout << "Da thi";
    gotoxy(vtThongTin[2]+20, y-3);
    cout << "Noi dung";
    gotoxy(vtThongTin[0], wherey()+2);
    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<n; i++)
    {
        p=search(root, dsID[i]);
        gotoxy(vtThongTin[0], wherey()+1);
        cout << dsID[i];
        gotoxy(vtThongTin[1], wherey());
        cout << p->info.trangThai;
        gotoxy(vtThongTin[2], wherey());
        inNoiDung(p->info.noidung, 35);
    }
    // b2: highlight lop o hang thu y tuc la 0
    p=search(root, dsID[vitriHL]);
    HighLight2(vtThongTin[0]-3, y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << dsID[vitriHL];
    gotoxy(vtThongTin[1], y+chon);
    cout << p->info.trangThai;
    gotoxy(vtThongTin[2], y+chon);
    inNoiDung(p->info.noidung, 35);
    ThongBaoTrang(trangHienTai+1, soTrang+1);
}
int inDanhSachCH(PTRQ &root, char*maMH, int &soCauHoi, int *&dsID, int &vitriMang)
{

    Normal();
    int oToiDa = 20;
    int chon=0;
    int pos[3];
    pos[0]=xLamViec+23;
    pos[1]=pos[0]+16;
    pos[2]=pos[1]+13;
    int y=yLamViec+6;
    inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0) kytu = getch();
        switch (kytu)
        {
        case F1:
        {
            char noiDung[21]="";
            while(true)
            {

                // search ID de tim dau hoi

                int timKiem=khungTimKiem(xTB, yTB-1, noiDung, 30, 10, "Nhap cum tu");
                if(timKiem==Down) // ==ENTER
                {
                    soCauHoi=demSoCauHoi(root, maMH);
                    dsID=new int[soCauHoi];
					layDSCauHoi(root,  dsID, maMH, soCauHoi);
                    if(timNoiDungCH(root, dsID, soCauHoi, noiDung)==-1)
                    {
                        xoaThongBao();
                        BaoLoi(xTB, yTB, "Khong tim thay cau hoi");

                    }
                    else
                    {
                    	
                    	bubbleSort(dsID, soCauHoi);
                        vitriMang=0;
                        inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                        break;
                    }
                    delete []dsID;
                }
                if(timKiem==ESC) break;
            }


            xoaThongBao();
            break;
        }
        case F3: // sua cau hoi
        {
            PTRQ p=search(root, dsID[vitriMang]);
            if(p->info.trangThai==1)
            {
                BaoLoi(xTB, yTB, "Cau hoi nay thi roi khong sua duoc");
                break;
            }
            else
            {
                xoaKhungLamViec();
                gotoxy(55, yLamViec+1);
                cout << "MON " << maMH;
                hienConTro();
                int checkSuaSV = sua1CauHoi(p);
                xoaKhungLamViec();
                inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                break;
            }

        }



        case F4:  // xoa cau hoi
        {
            PTRQ p=search(root, dsID[vitriMang]);
            if(p->info.trangThai==1)
            {
                BaoLoi(xTB, yTB, "Cau hoi nay da thi roi khong xoa duoc");
                break;
            }
            else
            {
                int xn=xacNhan(xTB, yTB, "Ban co chac muon xoa cau hoi nay khong?(y/n):");
                if(xn==ESC) break;
                if(xn==YES)
                {
                    xoaThongBao();
                    root=deleteNode(root, dsID[vitriMang]);
                    xoaMangID(dsID, soCauHoi, vitriMang);
                    xoaKhungLamViec();
                    inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                    if(soCauHoi==0)
                    {
                        soCauHoi=demSoCauHoi(root, maMH);
                        if(soCauHoi==0)
                        {

                            BaoLoi(xTB, yTB, "Danh sach rong!");

                            xoaKhungLamViec();
                            return ESC;
                        }
                        else
                        {
                            inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                        }
                    }
                    break;
                }
                if(xn==NO)
                {
                    xoaThongBao();
                    break;
                }
            }

        }
        case F2:
            return F2;
        case F5:
        {
            int xn=xacNhan(xTB, yTB, "Thay doi trang thai thi cua cau hoi ve 0? ");
            if(xn==YES)
            {
                PTRQ p=search(root, dsID[vitriMang]);
                p->info.trangThai=0;
            }
            inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
            break;
        }
        case LEFT:
        {

            if(soCauHoi<=oToiDa) break; // neu chi co 1 trang thi khoi left or right
            else
            {

                int tempVt=(vitriMang/oToiDa)*oToiDa;
                if(tempVt < oToiDa) break;
                else
                {
                    vitriMang=tempVt-oToiDa;
                    chon=0;
                    inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                }
                break;
            }

        }
        case RIGHT:
        {

            if(soCauHoi<=oToiDa) break;
            else
            {
                int tempVt=(vitriMang/oToiDa)*oToiDa; // lay vi tri dau tien vd 45 se ve 40 dung temp vi tranh thay doi vitriMang
                if(tempVt > soCauHoi-oToiDa) break; // kiem tra neu khong right duoc nua thi break
                else
                {
                    vitriMang=tempVt+oToiDa; // neu left duoc thi ta tru chon oToiDa de lui
                    inBangCH(root, pos, maMH, y, dsID, soCauHoi, vitriMang, oToiDa);
                    chon=0;
                }
                break;
            }
        }
        case Up :
            if (vitriMang%oToiDa > 0) // lay hang
            {
                diChuyenBangCH(root, pos, y, dsID, soCauHoi, vitriMang,oToiDa, Up);

            }
            break;
        case Down :
            if (vitriMang%oToiDa  < oToiDa-1 && vitriMang < soCauHoi-1)// lay hang
            {
                diChuyenBangCH(root, pos, y, dsID, soCauHoi, vitriMang,oToiDa, Down);
            }
            break;
        case ESC:
            return ESC;
        case ENTER:
            return ENTER;

        }  // end switch
    }
    while (1);

}

void inTTCH(PTRQ root, int id)
{
    xoaChucNang();
    xoaKhungDeThi();
    int sodapan = 4;
    veKhungDeThi();
    PTRQ p = search(root,id);
    char dapAnDung = p->info.dapan;
    string DapAn[4] ;
    DapAn[0]=p->info.A;
    DapAn[1]=p->info.B;
    DapAn[2]=p->info.C;
    DapAn[3]=p->info.D;
    int posy[4];

    gotoxy(xCTDT+3, yCTDT+3);
    cout << "Noi dung:" << p->info.noidung;
    gotoxy(xCTDT+3, wherey()+2);
    for (int i=0; i < sodapan ; i++)
    {
        posy[i]=wherey()+1;
        gotoxy(xCTDT+5, posy[i]);
        cout << doiChon(i) << ". " ;
        inNoiDung(DapAn[i],70);
    }
    textcolor(10);
    gotoxy(xCTDT+5, posy[doiChon2(dapAnDung)]);
    cout << dapAnDung << ". ";
    inNoiDung(DapAn[doiChon2(dapAnDung)], 70);
    Normal();

}
int them1CauHoi(PTRQ &root, char *maMH, int *&dsID, int &soCH, int &vitriID)
{
    danhSachID=docFileID(soLuongID);
    int cotTextField = 35, y=yLamViec+1;
    int soKhung = 7;
    int dai=55, rong = 2;

    // ve Khung nhap

    int pos[soKhung];
    bool kt[soKhung-1];
    char **text= new char*[soKhung-2];
    for(int i=0; i<soKhung-2; i++)
    {
        text[i] = new char[201];
        strcpy(text[i], "");
    }
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=false;
    }
    char dapAn='A';
    khungNhapCauHoi(cotTextField, y, dai, rong, pos, soKhung,truongCauHoi);
    char kytu;
    int vitri=0;
    int dichuyen;
    while(true)
    {
        switch(vitri)
        {
        case 0:// nhap noi dung
        case 1:// nhap dap an A
        case 2:// nhap  dap an B
        case 3://nhap dap an C
        case 4:// nhap dap an D
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            hienConTro();
            dichuyen=nhapChuoiDB(cotTextField+1, pos[vitri], dai-1, text[vitri],200);
            //if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            if(strcmp(text[vitri],"")!=0)
            {
                kt[vitri]=true;
                if(vitri==2||vitri==3||vitri==4)
                {
                    for(int m=1; m<vitri; m++)
                    {
                        if(strcmp(text[vitri],text[m])!=0)
                        {
                            kt[vitri]=true;
                        }
                        else
                        {
                            kt[vitri]=false;
                            break;
                        }
                    }
                }
            }
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            break;
        }
        case 5: // chon dap an dung
        {
            anConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=chonDapAn(cotTextField+1, pos[vitri], dai-1, dapAn);
            hienConTro();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            kt[vitri]=true;
            break;
        }
        case 6: // add
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+23,pos[vitri]-1,6,1);
            Normal();
            do
            {
                char c=getch();
                if(c==ENTER)
                {
                    if(ktTextField(kt,soKhung-1)==false)
                    {
                        BaoLoi(xTB, yTB, "Them cau hoi that bai!");
                        dichuyen=Down;
                        break;
                    }
                    else// khac rong
                    {
                        int co=0;
                        for(int i=1; i<soKhung-3; i++)
                        {
                            for(int j=i+1; j<soKhung-2; j++)
                            {
                                if(stricmp(text[i], text[j])==0)
                                {
                                    Normal();
                                    anConTro();
                                    int x1 = wherex(), y1 = wherey();
                                    gotoxy(xTB, yTB);
                                    cout<<"Dap an " << doiChon(i-1) << " va " << doiChon(j-1) << " trung nhau!";
                                    Sleep(1000);
                                    xoaThongBao();
                                    gotoxy(x1, y1 );
                                    co=1;
                                    break;
                                }
                            }
                            if(co==1) break;
                        }
                        if(co==1) break;
                        // lay id gan vao va them vao root
                        string a[5];
                        ctos2(text, 5, a);
                        cauhoi temp=cauHoiMoi(maMH, a[0], a[1], a[2], a[3], a[4],dapAn);
                        int id=layID(danhSachID, soLuongID);
                        root=insert(root, id, temp);
                        dsID[soCH++]=id;
                        bubbleSort(dsID, soCH);
                        vitriID=timKiemMangID(dsID, soCH, id);
                        BaoLoi(xTB, yTB, "Them cau hoi thanh cong");
                        if(soCH==MAXID){
						
                			BaoLoi(xTB, yTB, "Toi da 200 cau hoi 1 mon. Khong them duoc nua!");
                			ghiFileID(danhSachID, soLuongID);
        					for(int i=0; i<soKhung-2; i++)
    						{
       			 				delete [] text[i];
    						}
    
    						delete []text;
   			 				delete []danhSachID;
							return ESC;
						}
                        dichuyen=Down;
                        for(int i=0; i<soKhung-2; i++)
                        {
                            xoaHang(cotTextField+1, pos[i], dai-1);
                            strcpy(text[i], "");
                        }
                        break;
                    }
                }
                if(c==Up)
                {
                    dichuyen=Up;
                    break;
                }
                if(c==Down)
                {
                    dichuyen=Down;
                    break;
                }
            }
            while(true);
            veKhungNho(cotTextField+23,pos[vitri]-1,6,1);
            hienConTro();
        }

        }
        if(dichuyen==ESC) {
        	ghiFileID(danhSachID, soLuongID);
        	for(int i=0; i<soKhung-2; i++)
    			{
       			 delete [] text[i];
    			}
    
    			delete []text;
   			 	delete []danhSachID;
			return ESC;
		}
        if(dichuyen ==Up)
        {
            if(vitri==0) vitri=soKhung-1;
            else vitri--;
        }
        if(dichuyen ==Down)
        {
            if(vitri==soKhung-1) vitri=0;
            else vitri++;
        }

    }
    

}



//========================================


int demSoCauHoi(PTRQ root, char *maMH)
{

    int count=0;
    PTRQ Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    PTRQ p=root;
    while (p!=NULL )
    {
        if(stricmp(p->info.maMH,maMH)==0) count++;  // "xu ly p"

        if (p->right != NULL)
            Stack[++sp]= p->right;
        if (p->left != NULL)
            p=p->left;
        else  if (sp==-1)
            break;
        else		 p=Stack[sp--];
    }
    return count;
}
void layDSCauHoi(PTRQ root, int *&dsCauHoi, char* maMH, int soCauHoi)
{
    
    int i=0;
    PTRQ Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    PTRQ p=root;
    while (p!=NULL )
    {

        if(stricmp(p->info.maMH,maMH)==0)
        {

            dsCauHoi[i++] = p->key;
        }  // "xu ly p"

        if (p->right != NULL)
            Stack[++sp]= p->right;
        if (p->left != NULL)
            p=p->left;
        else  if (sp==-1)
            break;
        else		 p=Stack[sp--];
    }
}


PTRQ search(PTRQ root, int id)
{
    PTRQ p = root;
    while(p != NULL && id!=p->key)
        if(id < p->key)
            p = p->left;
        else
            p = p->right;
    return p;

}

int Xuat1CauHoi(int cot, int dong,PTRQ &root, int id,int &soCauDung, int &chon, int thutu, Timer &timer)
{
    anConTro();
    int *posy = new int[4];
    int color=159;
    int temp=0;
    PTRQ p = search(root,id);
    char dapAnDung = p->info.dapan;
    string DapAn[4] ;
    p->info.trangThai=1;
    DapAn[0]=p->info.A;
    DapAn[1]=p->info.B;
    DapAn[2]=p->info.C;
    DapAn[3]=p->info.D;
    gotoxy(cot,dong);
    cout << "Cau " << thutu+1 <<":"<< p->info.noidung ;
    gotoxy(cot, wherey()+3);
    cot+=2;
    for (int i=0; i < 4 ; i++)
    {
        posy[i] = wherey()+1;
        gotoxy(cot, posy[i]);
        cout << doiChon(i) <<  ". " << DapAn[i] << endl;
    }
    //hightligt dap an ngta dchon
    if(chon!=4)
    {
        textcolor(color);
        gotoxy(cot, posy[chon]);
        cout <<doiChon(chon) <<  ". " << DapAn[chon];
    }
    // highlight dap an A
    HighLight();
    gotoxy(cot, posy[temp]);
    cout << doiChon(temp) <<  ". " <<DapAn[temp];

    char kytu;
    do
    {
        if(kbhit())
        {
            kytu = getch();
            if (kytu == 0) kytu = getch();
            switch (kytu)
            {
            case Up :
                if (temp > 0 )
                {
                    if(temp!=chon)
                    {
                        Normal();
                        gotoxy(cot, posy[temp]);
                        cout << doiChon(temp) << ". " << DapAn[temp];
                    }
                    temp --;
                    HighLight();
                    gotoxy(cot, posy[temp]);
                    cout << doiChon(temp) << ". " << DapAn[temp];
                    if(temp+1==chon)  // sau khi nhan up neu dong o duoi la dap an duoc chon thi highlight lai
                    {
                        textcolor(color);
                        gotoxy(cot,posy[temp+1]);
                        cout << doiChon(temp+1) << ". " << DapAn[temp+1];
                    }
                }
                break;
            case Down :
                if (temp < 3)
                {
                    if(temp!=chon)  // neu la chon thi khoi can normal lai
                    {
                        Normal();
                        gotoxy(cot, posy[temp]);
                        cout << doiChon(temp) << ". " << DapAn[temp];
                    }
                    temp ++;
                    HighLight();
                    gotoxy(cot, posy[temp]);
                    cout << doiChon(temp) << ". " << DapAn[temp];

                    if(temp-1==chon)  // sau khi nhan down neu dong o duoi la dap an duoc chon thi highlight lai
                    {
                        textcolor(color);
                        gotoxy(cot,posy[temp-1]);
                        cout << doiChon(temp-1) << ". "<<DapAn[temp-1];
                    }

                }
                break;
            case LEFT :
                return LEFT;
            case RIGHT:
                return RIGHT;
            case F1:
                return (int)F1;
            case F2:
            {
                Normal();
                int chon, y=8;
                gotoxy(50, y);
                cout << "Van con thoi gian lam bai, ban co chac muon nop bai?";
                int x1=wherex();
                cout<<"YES"<<"    "<<"NO";
                HighLight();
                gotoxy(x1,y);
                cout<<"YES";
                chon=YES;
                while(!timer.timeOut())
                {
                    if(kbhit())
                    {

                        char c=getch();
                        if(c!=-32 && c!=0)
                        {
                            if(c==LEFT)
                            {
                                chon=YES;
                                Normal();
                                gotoxy(x1+7,y);
                                cout << "NO";
                                HighLight();
                                gotoxy(x1,y);
                                cout << "YES";
                            }
                            if(c==RIGHT)
                            {
                                chon=NO;
                                Normal();
                                gotoxy(x1,y);
                                cout << "YES";
                                HighLight();
                                gotoxy(x1+7,y);
                                cout << "NO";
                            }
                            if(c==ENTER)
                            {
                                Normal();
                                xoaThongBao();
                                if(chon==YES)
                                {
                                    xoaKhungThi();
                                    return (int)F2;
                                }
                                if(chon==NO)
                                {
                                    xoaHang(50, y, 70);
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        anConTro();
                        Normal();
                        gotoxy(134,6);
                        cout << timer.getTimeLeft();
                    }
                }
                break;
            }
            case 13:
            {
                chon = temp;
                if(doiChon(chon)==dapAnDung) soCauDung++;
                return RIGHT;
            }
            }  // end switch}
        }
        else  // neu khong an phim thi in ra thoi gian
        {
            anConTro();
            Normal();
            gotoxy(134,6);
            cout << timer.getTimeLeft();
        }


    }
    while (!timer.timeOut());
    delete []posy;
}

void KhoiTaoChon(int *a, int n, int giatri)
{
    for(int i=0; i<n; i++)
    {
        a[i]=giatri;
    }
}

int XuatDeThi(int cot, int dong, PTRQ &root, int *DeThi,  int *chon, int &soCauDung, int SoCauThi, int soPhut)
{
    int id=0,nd;
    KhoiTaoChon(chon,SoCauThi,4);
    int diChuyen=0;
    soCauDung=0;
    Timer timer(soPhut*60);
    gotoxy(125,4);
    cout << "Thoi gian lam bai con lai";
    textcolor(4);
    veKhung(130, 5, 15, 2);
    Normal();
    veKhungNho(cot-1, dong-1, 126, 16);
    while(!timer.timeOut())
    {

        showdapan(chon,SoCauThi);

        XoaKhung(cot, dong, 124, 14);
        diChuyen=Xuat1CauHoi(cot, dong, root, DeThi[id], soCauDung, chon[id], id, timer);
        if(diChuyen==LEFT)
        {
            if(id==0) id=SoCauThi-1;
            else id--;
        }
        if(diChuyen==RIGHT)
        {
            if(id==SoCauThi-1) id=0;
            else id++;
        }
        if(diChuyen ==(int)F2)
        {
            break;
        }


    }
}



