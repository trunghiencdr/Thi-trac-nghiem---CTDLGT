#pragma once
#include "Diem.h"
#include "XuLiChuoi.h"
#include "math.h"

char truongSuaSV[][20]= {"SUA TT SINH VIEN", "Ma sv:", "Ho:", "Ten:", "Phai:", "Password:", "SUA"};
char truongThemSV[][20]= {"THEM SINH VIEN", "Ma sv:", "Ho:", "Ten:", "Phai:", "Password:", "THEM"};
char *cnSV = "F2:Them  F3:Sua  F4:Xoa";
// ctdl sinh vien-dslk don
struct sinhvien
{
    char password[8];
    char MASV[11];
    char HO[51];
    char TEN[11];
    char PHAI[5];
    int TrangThaiThi;
    PTRD Firstdiem;

};
struct nodesv
{
    sinhvien info;
    nodesv *next;
};
typedef nodesv *PTRSV;
// khai bao ham
int inTTSV(int x, int y, PTRSV sv, char *maMH);
int xoaSinhVien(PTRSV &first, char *maSV);
void selectionSort(PTRSV &First);
void dslkSangMangSV(PTRSV firstSV, sinhvien *&sv);
void bubbleSort(sinhvien *a, int n);
PTRSV searchStudent(PTRSV First, char *masv);
int demSinhVien(PTRSV First);
sinhvien newSinhVien( char *maSV, char *ho, char *ten, char *phai, char *password);
void insertLast(PTRSV &FirstSinhVien, sinhvien x);
int checkMonThi(PTRSV sv, char* maMH);
int timKiemMangSV(sinhvien ds[], int n, char *maSV);
void inBangSV(int vtThongTin[], int y, sinhvien ds[], char *maLop, int n, int vitriHL, int oToiDa);
void diChuyenBangSV(int vtThongTin[], int y, sinhvien dssv[], int n, int &vitriHT,int oToiDa,int trangThai);
int sua1SinhVien( PTRSV &sv);  // kiem tra ma sv bi trung va neu thi roi thi khong sua duoc vi thi roi la chac chan dung du lieu roi
void swap(sinhvien &a, sinhvien &b);
char *makeString(sinhvien sv);
void insertOrder(PTRSV &First, sinhvien sv);
void inDiem(int soCauDung, int soCauThi, float &diem);
void moveOut(sinhvien *&dssv, int &soLuongSV,  int i);

void themDSSV(sinhvien *&dssv, int &soLuongSV, sinhvien sv, int &vitriSV);
void capNhatDSSV(sinhvien *&dssv, int soLuongSV, int &vitriSV);
int xoaDSSV(sinhvien *&dssv, int &soLuongSV, int &vitriSV);
void moveOut(sinhvien *&dssv, int &soLuongSV,  int i)
{
    
    for(int j = soLuongSV; j > i; --j)
    {
        dssv[j] = dssv[j-1];
    }
    ++soLuongSV;
}


void themDSSV(sinhvien *&dssv, int &soLuongSV, sinhvien sv, int &vitriSV)
{
    int i;
    for (i = 0; i < soLuongSV; ++i)
    {
        if(stricmp(makeString(sv), makeString(dssv[i])) < 0)
        {
            moveOut(dssv, soLuongSV, i);
           	dssv[i] = sv;// them vao sau ma lop vua lon hon
            vitriSV=i;
            break;
        }
    }
    if(i == soLuongSV)		//Cuoi danh sach , khong co ma lop nao lon hon class
    {
        dssv[soLuongSV] = sv;
        vitriSV=soLuongSV;
        ++soLuongSV;
    }
}
void capNhatDSSV(sinhvien *&dssv, int soLuongSV, int &vitriSV)
{
    sinhvien temp=dssv[vitriSV];
    xoaDSSV(dssv, soLuongSV, vitriSV);
    themDSSV(dssv, soLuongSV, temp, vitriSV);
}


int xoaDSSV(sinhvien *&a, int &n, int &vitri)
{
    if(n<=0) return 0;
    if(vitri<0)// xoa dau
        vitri=0;
    if(vitri>=n) // xoacuoi
        vitri=n-1;
    for(int i=vitri; i<n-1; i++)
        a[i]=a[i+1];
    if(vitri==n-1) vitri--;
    n--;
    return 1;

}
void inDiem(int soCauDung, int soCauThi, float &diem)
{
    Normal();
    xoaKhungThi();
    anConTro();
    diem = ((10*1.0/soCauThi)*soCauDung);
    diem = roundf(diem * 100) / 100;
    veKhung(70, 7, 30, 8);
    gotoxy(83, 9);
    cout << "DIEM";
    gotoxy(84, 10);
    cout << setprecision(3) << diem;
    gotoxy(80,11);
    cout << "So Cau Dung";
    gotoxy(83,12);
    cout << soCauDung << "/" << soCauThi;
    gotoxy(39,20);

}

void insertOrder(PTRSV &First, sinhvien sv)
{
    PTRSV after, before, p;
    p = new nodesv;
    p->info = sv;
    for(after = First; after != NULL && stricmp(makeString(after->info), makeString(sv)) < 0; before = after, after = after->next); // dung before luu node after r after cap nhat lai
    if(after == First)
    {
        p->next = First;
        First = p;
    }
    else
    {
        p->next = after;
        before->next = p;
    }
}
int inTTSV(int x, int y, PTRSV sv, char *maMH)
{
    gotoxy(x, y);
    cout << sv->info.MASV;
    gotoxy(x, wherey()+1);
    cout << sv->info.HO;
    gotoxy(wherex()+1, wherey());
    cout << sv->info.TEN;

    gotoxy(x, wherey()+1);
    cout << maMH;
    gotoxy(x, wherey()+1);
    cout << "Diem: " << sv->info.Firstdiem->info.mark;
}

char *makeString(sinhvien sv);
int xoaSinhVien(PTRSV &first, char *maSV)
{
    PTRSV p=first,q;
    if(first==NULL) return 0;
    if(stricmp(first->info.MASV,maSV)==0) // co 1 nut duy nhat
    {
        p=first;
        first=p->next;
        delete p;
        return 1;
    }
    for(p=first; p->next!=NULL && stricmp(p->next->info.MASV, maSV)!=0; p=p->next); // lay nut truoc nut bang ma sv
    if(p->next!=NULL)  // masv==masv
    {
        q=p->next; // dung q de chua node can delete
        p->next=q->next;
        delete q;
        return 1;
    }
    return 0;

}
void bubbleSort(sinhvien *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(stricmp(makeString(a[i]), makeString(a[j]))>0)
                swap(a[i],a[j]);
        }
    }
}
void selectionSort(PTRSV &First)
{
    if(First==NULL) return ;
    PTRSV p, q, pmin;
    sinhvien min;
    for(p = First; p->next != NULL; p = p->next)
    {
        min = p->info;
        pmin = p;
        for(q = p->next; q != NULL; q = q->next)
        {
            if(stricmp(makeString(q->info), makeString(min)) < 0)
            {
                // cap nhat lai gia tri min va vi tri pmin
                min = q->info;
                pmin = q;
            }
        }
        // hoan doi  pmin vs p
        pmin->info = p->info;
        p->info = min;
    }
}
void dslkSangMangSV(PTRSV firstSV, sinhvien *&sv)
{
    int i=0;
    for(PTRSV p=firstSV; p!=NULL; p=p->next)
    {
        sv[i]=p->info;
        i++;
    }
}
int demSinhVien(PTRSV First)
{
    PTRSV p;
    int i = 0;
    if(First == NULL)
    {
        return 0;
    }
    for(p = First; p != NULL; p = p->next, ++i);
    return i;
}
PTRSV searchStudent(PTRSV First, char *masv)
{
    for(PTRSV p = First; p != NULL; p = p->next)
        if(stricmp(p->info.MASV, masv) == 0)	return p;
    return NULL;
}


int sua1SinhVien( PTRSV &sv)  // kiem tra ma sv bi trung va neu thi roi thi khong sua duoc vi thi roi la chac chan dung du lieu roi
{
    sinhvien x;
    int cotTextField = 50, y=yLamViec+1;
    int soKhung = 6;
    int dai=25, rong = 2;
    // ve Khung nhap
    int pos[soKhung];
    int len[soKhung-1];
    bool kt[soKhung-1];
    char text[5][51];
    char tempMaSV[11];
    strcpy(text[0],sv->info.MASV);
    strcpy(text[1],sv->info.HO);
    strcpy(text[2],sv->info.TEN);
    strcpy(text[3],sv->info.PHAI);
    strcpy(text[4],sv->info.password);
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=true;
    }
    kt[0]=true;
    khungSuaSinhVien(text, cotTextField, y, dai, rong, pos, soKhung,truongSuaSV);
    char kytu;
    int vitri=1;
    int dichuyen;
    int trangThai=1;
    while(true)
    {
        switch(vitri)
        {

        case 1:// nhap ho
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri], 50);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            break;
        }
        case 2://Nhap ten
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri], 10);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            break;
        }
        case 3:// lua chon nam or nu
        {
            anConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=chonPhai(cotTextField+1, pos[vitri], dai-1, text[vitri]);
            hienConTro();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            break;
        }
        case 4: // nhap dang password
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapPassword(cotTextField+1, pos[vitri], dai-1, text[vitri], trangThai, 6);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            break;
        }
        case 5: // add
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+((dai-strlen(truongSuaSV[soKhung]))/2)-1,pos[vitri]-1,strlen(truongSuaSV[soKhung])+2,1);
            Normal();
            do
            {
                char c=getch();
                if(c==ENTER)
                {
                    if(ktTextField(kt,soKhung-1)==false)
                    {
                        int i=1;
                        for(; i<soKhung-1 && kt[i]!=false; i++);
                        switch(i)
                        {
                        case 1:
                            BaoLoi(xTB, yTB, "Ho sinh vien khong hop le!");
                            break;
                        case 2:
                            BaoLoi(xTB, yTB, "Ten sinh vien khong hop le!");
                            break;
                        case 4:
                            BaoLoi(xTB, yTB, "Password sinh vien khong hop le!");
                            break;

                        }
                        vitri=i-1;
                        dichuyen=Down;
                        break;
                    }
                    else
                    {
                        strcpy(sv->info.HO, text[1]);
                        strcpy(sv->info.TEN, text[2]);
                        strcpy(sv->info.PHAI, text[3]);
                        strcpy(sv->info.password, text[4]);
                        BaoLoi(xTB, yTB, "Sua sinh vien thanh cong");
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
            veKhungNho(cotTextField+((dai-strlen(truongSuaSV[soKhung]))/2)-1,pos[5]-1,strlen(truongSuaSV[soKhung])+2,1);
            hienConTro();
        }
        }

        if(dichuyen==ESC) return ESC;
        if(dichuyen ==Up)
        {
            if(vitri==1) vitri=soKhung;
            else vitri--;
        }
        if(dichuyen ==Down)
        {
            if(vitri==soKhung) vitri=1;
            else vitri++;
        }
    }
}


char *makeString(sinhvien sv)
{
    // so sanh ten truoc neu = ss ho roi toi mssv
    char *info = new char[61];
    strcpy(info, sv.TEN);
    strcat(info, sv.HO);
    strcat(info, sv.MASV);
    return info;
}



void swap(sinhvien &a, sinhvien &b)
{
    sinhvien temp=a;
    a=b;
    b=temp;

}



void diChuyenBangSV(int vtThongTin[], int y, sinhvien dssv[], int n, int &vitriHT,int oToiDa,int trangThai)
{
    // neu o cuoi con down thi k lam nua;
    int chon=vitriHT%oToiDa;
    NormalSV(vtThongTin[0]-1,y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << vitriHT+1;
    gotoxy(vtThongTin[1], y+chon);
    cout << dssv[vitriHT].MASV;
    gotoxy(vtThongTin[2], y+chon);
    cout << dssv[vitriHT].HO;
    gotoxy(vtThongTin[3], y+chon);
    cout << dssv[vitriHT].TEN;
    gotoxy(vtThongTin[4], y+chon);
    cout << dssv[vitriHT].PHAI;
    gotoxy(vtThongTin[5], y+chon);
    cout << dssv[vitriHT].password;
    gotoxy(vtThongTin[6], y+chon);
    cout << dssv[vitriHT].TrangThaiThi;
    if(trangThai==Up)
    {
        vitriHT--;
        chon--;
    }
    if(trangThai==Down)
    {

        vitriHT++;
        chon++;

    }
    HighLightSV(vtThongTin[0]-1, y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << vitriHT+1;
    gotoxy(vtThongTin[1], y+chon);
    cout << dssv[vitriHT].MASV;
    gotoxy(vtThongTin[2], y+chon);
    cout << dssv[vitriHT].HO;
    gotoxy(vtThongTin[3], y+chon);
    cout << dssv[vitriHT].TEN;
    gotoxy(vtThongTin[4], y+chon);
    cout << dssv[vitriHT].PHAI;
    gotoxy(vtThongTin[5], y+chon);
    cout << dssv[vitriHT].password;
    gotoxy(vtThongTin[6], y+chon);
    cout << dssv[vitriHT].TrangThaiThi;

}
void inBangSV(int vtThongTin[], int y, sinhvien ds[], char *maLop, int n, int vitriHL, int oToiDa)
{
    if(n==0 || vitriHL >= n) return;
    int trangHienTai=vitriHL/oToiDa;
    int chon=vitriHL-(trangHienTai*oToiDa);
    int soTrang;
    if(n%oToiDa==0)	soTrang=n/oToiDa-1;
    else soTrang=n/oToiDa;
    xoaKhungLamViec();
    gotoxy(xLamViec+40, yLamViec+1);
    cout << "DANH SACH SINH VIEN LOP " << maLop;
    veBangSinhVien(vtThongTin[0]-2,y-4, oToiDa);
    gotoxy(vtThongTin[0], y-3);
    cout << "STT";
    gotoxy(vtThongTin[1]+1, y-3);
    cout << "Ma SV";
    gotoxy(vtThongTin[2]+10, y-3);
    cout << "Ho SV";
    gotoxy(vtThongTin[3]+1, y-3);
    cout << "Ten SV";
    gotoxy(vtThongTin[4], y-3);
    cout << "Phai";
    gotoxy(vtThongTin[5], y-3);
    cout << "Password";
    gotoxy(vtThongTin[6]-2, y-3);
    cout << "Mon thi";
    gotoxy(vtThongTin[0], wherey()+2);
    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<n; i++)
    {
        gotoxy(vtThongTin[0], wherey()+1);
        cout << i+1;
        gotoxy(vtThongTin[1], wherey());
        cout << ds[i].MASV;
        gotoxy(vtThongTin[2], wherey());
        cout << ds[i].HO;
        gotoxy(vtThongTin[3], wherey());
        cout << ds[i].TEN;
        gotoxy(vtThongTin[4], wherey());
        cout << ds[i].PHAI;
        gotoxy(vtThongTin[5], wherey());
        cout << ds[i].password;
        gotoxy(vtThongTin[6], wherey());
        cout << ds[i].TrangThaiThi;
    }
    // b2: highlight lop o hang thu y tuc la 0
    HighLightSV(vtThongTin[0]-1, y+chon);
    gotoxy(vtThongTin[0], y+chon);
    cout << vitriHL+1;
    gotoxy(vtThongTin[1], y+chon);
    cout << ds[vitriHL].MASV;
    gotoxy(vtThongTin[2], y+chon);
    cout << ds[vitriHL].HO;
    gotoxy(vtThongTin[3], y+chon);
    cout << ds[vitriHL].TEN;
    gotoxy(vtThongTin[4], y+chon);
    cout << ds[vitriHL].PHAI;
    gotoxy(vtThongTin[5], y+chon);
    cout << ds[vitriHL].password;
    gotoxy(vtThongTin[6], y+chon);
    cout << ds[vitriHL].TrangThaiThi;
    ThongBaoTrang(trangHienTai+1, soTrang+1);



}
int timKiemMangSV(sinhvien ds[], int n, char *maSV)
{
    int i=0;
    for(; i<n-1 && stricmp(ds[i].MASV, maSV)!=0; i++);
    if(i<n) return i;
    else return -1;
}
// dinh nghia ham


// dinh nghia cac ham

void insertLast(PTRSV &FirstSinhVien, sinhvien x)
{
    PTRSV p=new nodesv;
    p->info=x;
    p->next=NULL;
    if(FirstSinhVien==NULL) FirstSinhVien=p;
    else
    {
        PTRSV Last=FirstSinhVien;
        for(; Last->next!=NULL; Last=Last->next);
        Last->next=p;
    }
}

sinhvien newSinhVien(char *maSV, char *ho, char *ten, char *phai, char *password)
{
    sinhvien x;
    x.Firstdiem=NULL;
    x.TrangThaiThi=0;
    strcpy(x.MASV, maSV);
    strcpy(x.HO, ho);
    strcpy(x.TEN, ten);
    strcpy(x.PHAI, phai);
    strcpy(x.password, password);
    return x;
}
// bang 0 la chua thi bang 1 la thi roi
int checkMonThi(PTRSV sv, char* maMH)
{
    if(sv->info.TrangThaiThi==0) return 0;
    for(PTRD p = sv->info.Firstdiem; p!=NULL; p=p->next)
    {
        if(stricmp(p->info.maMH, maMH)==0) return 1;
    }
    return 0;
}


