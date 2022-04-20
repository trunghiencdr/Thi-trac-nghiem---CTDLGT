#pragma once
#include "CauHoi.h"
#define MAXID 200
using namespace std;
struct monHoc
{
    char maMH[11];
    char tenMH[51];
};
// khai bao ham

void dieuChinhMonHoc(PTRQ &root, monHoc *ds[], int &n);
int inDanhSachMH(int x, int y, monHoc *ds[],int n, int &vitriMang);
int searchmaMH(monHoc *dsMH[],int n, char *maMH);
int searchtenMH(monHoc *dsMH[],int n, char *tenMH);
int them1MonHoc(monHoc *dsMH[],int &soLuongMH, int &vitriMH);
int xoa1MonHoc(monHoc *dsMH[], int &soLuongMH, int &vitriMH);
int sua1MonHoc(monHoc *dsMH[], int &soLuongMH, int &vitriMH);
void themMonHoc(monHoc *dsMH[],int &soLuongMH);
void initialize(monHoc *dsMH[], int n);
void themDSMH(monHoc *dsMH[], int &soLuongMH, monHoc MH, int &vitriMH);
void capNhatDSMH(monHoc *dsMH[], int soLuongMH, int &vitriMH);
void moveOut(monHoc *dsMH[], int &soLuongMH,  int i);
int xoa1MonHoc(monHoc *a[], int &n, int &vitri);
void moveOut(monHoc *dsMH[], int &soLuongMH,  int i)
{
    for(int j = soLuongMH; j > i; --j)
    {
        *(dsMH[j]) = *(dsMH[j-1]);
    }
    ++soLuongMH;
}


void themDSMH(monHoc *dsMH[], int &soLuongMH, monHoc MH, int &vitriMH)
{
    int i;
    for (i = 0; i < soLuongMH; ++i)
    {
        if(stricmp(MH.tenMH, dsMH[i]->tenMH) < 0)
        {
            moveOut(dsMH, soLuongMH, i);
            *(dsMH[i]) = MH;// them vao sau ma lop vua lon hon
            vitriMH=i;
            break;
        }
    }
    if(i == soLuongMH)		//Cuoi danh sach , khong co ma lop nao lon hon class
    {
        *(dsMH[soLuongMH]) = MH;
        vitriMH=soLuongMH;
        soLuongMH++;
    }
}
void capNhatDSMH(monHoc *dsMH[], int soLuongMH, int &vitriMH)
{
    monHoc temp=*(dsMH[vitriMH]);
    xoa1MonHoc(dsMH, soLuongMH, vitriMH);
    themDSMH(dsMH, soLuongMH, temp, vitriMH);
}


int xoa1MonHoc(monHoc *a[], int &n, int &vitri)
{
    if(n<=0) return 0;
    if(vitri<0)// xoa dau
        vitri=0;
    if(vitri>=n) // xoacuoi
        vitri=n-1;
    for(int i=vitri; i<n-1; i++)
        *(a[i])=*(a[i+1]);
    if(vitri==n-1) vitri--;
    n--;
    return 1;

}


void initialize(monHoc *dsMH[], int n)
{
    for(int i=0; i<n; i++)
    {
        dsMH[i] = new monHoc;
    }
}
void show(monHoc *dsMH[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "ma mh:" << dsMH[i]->maMH << endl;
        cout << "ten mh:" << dsMH[i]->tenMH << endl;
    }
}
void add(monHoc *dsMH[], int &n, monHoc x)
{
    strcpy(dsMH[n-1]->maMH,x.maMH);
    strcpy(dsMH[n-1]->tenMH,x.tenMH);
    n++;
}
int inDanhSachMH(int x, int y, monHoc *ds[],int n, int &vitriMang)
{


    int x1=x+23;
    int x2=x1+12;
    int x3=x2+17;
    int oToiDa = 20;
    int trangHienTai=vitriMang/oToiDa;
    int chon=vitriMang%oToiDa;
    // b1: in ra so lop < 10 theo trang
    int soTrang;
    if(n%10==0)	soTrang=n/oToiDa-1;
    else soTrang=n/oToiDa;
    Normal();
    veBangLop(x1-3,y-4,oToiDa);

    gotoxy(x+50, y-5) ;
    cout << "DANH SACH MON HOC";
    gotoxy(x1, y-3);
    cout << "STT";
    gotoxy(x2, y-3);
    cout << "Ma mon hoc";
    gotoxy(x3, y-3);
    cout << "Ten mon hoc";
    gotoxy(x1, wherey()+2);
    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<n; i++)
    {
        gotoxy(x1, wherey()+1);
        cout << i+1;
        gotoxy(x2, wherey());
        cout << ds[i]->maMH;
        gotoxy(x3, wherey());
        cout << ds[i]->tenMH;
    }
    // b2: highlight lop dua vao vi tri mang

    HighLight2(x1-3, y+chon);
    gotoxy(x1, y+chon);
    cout << vitriMang+1;
    gotoxy(x2, y+chon);
    cout << ds[vitriMang]->maMH;
    gotoxy(x3, y+chon);
    cout << ds[vitriMang]->tenMH;
    ThongBaoTrang(trangHienTai+1, soTrang+1);


    // b2: highlight lop dau tien
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0) kytu = getch();
        switch (kytu)
        {
        case F1:
        {
            // search bang ma
            char maMH[11]="";
            while(1)
            {

                int timKiem=khungTimKiem(xTB, yTB-1, maMH, 30, 10, "Nhap ma MH");
                if(timKiem==Down) // ==ENTER
                {
                    vitriMang=searchmaMH(ds, n, maMH);
                    if(vitriMang==-1)
                    {
                        xoaThongBao();
                        BaoLoi(xTB, yTB, "Khong tim thay mon hoc");

                    }
                    else
                    {
                        //xoaKhungLamViec();
                        XoaKhung(x1-3, y-4, 75, oToiDa+3);
                        xoaThongBao();
                        return F1;
                    }
                }
                if(timKiem==ESC) break;
            }
            xoaThongBao();
            break;
        }
        case F2:
            return F2;
        case F3:
            vitriMang=chon+trangHienTai*oToiDa;
            return F3;
        case F4:
            vitriMang=chon+trangHienTai*oToiDa;
            return F4;
        case LEFT:
        {
            if(soTrang>0)
            {
                chon=0;
                if(trangHienTai > 0 )
                {
                    xoaKhungLamViec();
                    trangHienTai--;
                    Normal();
                    veBangLop(x1-3,y-4,oToiDa);
                    gotoxy(x+50, y-5) ;
                    cout << "DANH SACH MON HOC";
                    gotoxy(x1, y-3);
                    cout << "STT";
                    gotoxy(x2, y-3);
                    cout << "Ma mon hoc";
                    gotoxy(x3, y-3);
                    cout << "Ten mon hoc";
                    gotoxy(x1, wherey()+2);
                    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<n; i++)
                    {
                        gotoxy(x1, wherey()+1);
                        cout << i+1;
                        gotoxy(x2, wherey());
                        cout << ds[i]->maMH;
                        gotoxy(x3, wherey());
                        cout << ds[i]->tenMH;
                    }
                    // b2: highlight lop dau tien

                    HighLight2(x1-3, y);
                    gotoxy(x1, y);
                    cout << trangHienTai*oToiDa+1;
                    gotoxy(x2, y);
                    cout << ds[trangHienTai*oToiDa]->maMH;
                    gotoxy(x3, y);
                    cout  << ds[trangHienTai*oToiDa]->tenMH;

                    ThongBaoTrang(trangHienTai+1, soTrang+1);
                }
                break;
            }
        }
        case RIGHT:
        {
            if(soTrang>0)
            {
                chon=0;
                if(trangHienTai < soTrang )
                {
                    xoaKhungLamViec();
                    trangHienTai++;
                    veBangLop(x1-3,y-4,oToiDa);
                    gotoxy(x+50, y-5) ;
                    cout << "DANH SACH MON HOC";
                    gotoxy(x1, y-3);
                    cout << "STT";
                    gotoxy(x2, y-3);
                    cout << "Ma Lop";
                    gotoxy(x3, y-3);
                    cout << "Ten Lop";
                    gotoxy(x1, wherey()+2);
                    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<n; i++)
                    {
                        gotoxy(x1, wherey()+1);
                        cout << i+1;
                        gotoxy(x2, wherey());
                        cout << ds[i]->maMH;
                        gotoxy(x3, wherey());
                        cout << ds[i]->tenMH;
                    }
                    // b2: highlight lop dau tien

                    HighLight2(x1-3, y);
                    gotoxy(x1, y);
                    cout << trangHienTai*oToiDa+1;
                    gotoxy(x2, y);
                    cout << ds[trangHienTai*oToiDa]->maMH;
                    gotoxy(x3, y);
                    cout << ds[trangHienTai*oToiDa]->tenMH;
                    ThongBaoTrang(trangHienTai+1, soTrang+1);
                }
            }
            break;
        }
        case Up :
            if (chon  > 0 && n>0)
            {
                int vitri=trangHienTai*oToiDa;
                Normal2(x1-3,y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds[chon+vitri]->maMH;
                gotoxy(x3, y+chon);
                cout << ds[chon+vitri]->tenMH;
                chon --;
                HighLight2(x1-3, y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds[chon+vitri]->maMH;
                gotoxy(x3, y+chon);
                cout << ds[chon+vitri]->tenMH;
            }
            break;
        case Down :
            if (chon  < oToiDa-1 && n>0)
            {
                int vitri=trangHienTai*oToiDa;
                Normal2(x1-3,y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds[chon+vitri]->maMH;
                gotoxy(x3, y+chon);
                cout << ds[chon+vitri]->tenMH;
                if((chon+vitri)<(n-1))
                {
                    chon ++;
                }
                HighLight2(x1-3, y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds[chon+vitri]->maMH;
                gotoxy(x3, y+chon);
                cout << ds[chon+vitri]->tenMH;


            }

            break;
        case ESC:
            return ESC;
        case 13:
            vitriMang=chon+trangHienTai*oToiDa;
            return ENTER;

        }  // end switch
    }
    while (1);
}
int them1MonHoc(monHoc *dsMH[],int &soLuongMH, int &vitriMang)
{
    int cotTextField = 50, y=yLamViec+1;
    int soKhung = 3;
    int dai=25, rong = 2;
    veKhung(35, y, 50, 23);

    // ve Khung nhap
    gotoxy(55,y+2);
    cout << "THEM MON HOC";
    // ve Khung nhap

    int pos[3];
    bool kt[2];
    char *text[2];
    for(int i=0; i<2; i++)
    {
        text[i] = new char[100];
        strcpy(text[i], "");
    }
    for(int i=0; i<2; i++)
    {
        kt[i]=false;
    }
    char labelSV[][20]= {"Ma MH:", "Ten MH:", "THEM"};
    veKhungTextField(cotTextField, y+4, dai, rong, pos, soKhung,labelSV);
    char kytu;
    int vitri=0;
    int dichuyen;
    while(true)
    {
        switch(vitri)
        {
        case 0:// nhap ma sinh vien khong cach
        {
            hienConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            dichuyen=nhapChuoiKC(cotTextField+1, pos[vitri], dai-1, text[vitri],10);
            Normal();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            // kiem tra xem ma da co chua neu co roi thi thong bao da co roi

            if(searchmaMH(dsMH, soLuongMH, text[vitri])==-1)
            {
                strcpy(dsMH[soLuongMH]->maMH,text[vitri]);
                xoaHang(cotTextField, pos[vitri]-2,25);
                kt[vitri]=true;
            }
            else
            {
                kt[vitri]=false;
                gotoxy(cotTextField, pos[vitri]-2);
                textcolor(160);
                cout << "Ma mon hoc da ton tai";
                Normal();
            }
            break;
        }
        case 1:// nhap ho
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri],50);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            
            if(searchtenMH(dsMH, soLuongMH, text[vitri])==-1)
            {
                strcpy(dsMH[soLuongMH]->tenMH,text[vitri]);
                xoaHang(cotTextField, pos[vitri]-5,25);
                kt[vitri]=true;
            }
            else
            {
                kt[vitri]=false;
                gotoxy(cotTextField, pos[vitri]-5);
                textcolor(160);
                cout << "Ten mon hoc da ton tai";
                Normal();
            }
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
                        int i=0;
                        for(; i<soKhung-1 && kt[i]!=false; i++);
                        switch(i)
                        {
                        case 0:
                            BaoLoi(xTB, yTB, "Ma mon hoc khong hop le!");
                            break;
                        case 1:
                            BaoLoi(xTB, yTB, "Ten mon hoc khong hop le!");
                            break;
                        }
                        vitri=i-1;
                        dichuyen=Down;
                        break;
                    }
                    else
                    {
                        monHoc temp;
                        strcpy(temp.maMH, text[0]);
                        strcpy(temp.tenMH, text[1]);
                        themDSMH(dsMH, soLuongMH, temp, vitriMang);
                        BaoLoi(xTB, yTB, "Them mon hoc thanh cong!");
                        dichuyen=Down;
                        for(int i=0; i<soKhung-1; i++)
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
int searchmaMH(monHoc *dsMH[],int n, char *maMH)
{
    for(int i = 0; i<n; i++)
        if(stricmp(dsMH[i]->maMH, maMH) == 0)
        {
            return i;
        }
    return -1;
}
int searchtenMH(monHoc *dsMH[],int n, char *tenMH)
{
    for(int i = 0; i<n; i++)
        if(stricmp(dsMH[i]->tenMH, tenMH) == 0)
        {
            return i;
        }
    return -1;
}
int sua1MonHoc(monHoc *dsMH[],int &soLuongMH, int &vitriMH)
{
    int cotTextField = 50, y=yLamViec+1;
    int soKhung = 3;
    int dai=25, rong = 2;
    veKhung(35, y, 50, 23);

    // ve Khung nhap
    gotoxy(55,y+2);
    cout << "SUA MON HOC";
    // ve Khung nhap

    int pos[3];
    bool kt[2];
    char *text[2];
    for(int i=0; i<2; i++)
    {
        text[i] = new char[100];
    }
    strcpy(text[0], dsMH[vitriMH]->maMH);
    strcpy(text[1], dsMH[vitriMH]->tenMH);
    kt[1]=true;
    kt[0]=true;
    char labelSV[][20]= {"Ma MH:", "Ten MH:", "SUA"};
    veKhungTextField(cotTextField, y+4, dai, rong, pos, soKhung,labelSV);
    gotoxy(cotTextField+1, pos[0]);
    cout << text[0];
    gotoxy(cotTextField+1, pos[1]);
    string temp(text[1]);
    Normal();
    hienConTro();
    inString(temp, dai-1);
    char kytu;
    int vitri=1;
    int dichuyen;
    while(true)
    {
        switch(vitri)
        {

        case 1:// ten mon hoc
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri],50);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(searchtenMH(dsMH, soLuongMH, text[vitri])==-1)
            {
                strcpy(dsMH[soLuongMH]->tenMH,text[vitri]);
                xoaHang(cotTextField, pos[vitri]-5,25);
                kt[vitri]=true;
            }
            else
            {
                kt[vitri]=false;
                gotoxy(cotTextField, pos[vitri]-5);
                textcolor(160);
                cout << "Ten mon hoc da ton tai";
                Normal();
            }
            break;
        }

        case 2: // sua
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
                        BaoLoi(xTB, yTB, "Sua mon hoc that bai!");
                        dichuyen=Down;
                        break;
                    }
                    else
                    {

                        strcpy(dsMH[vitriMH]->maMH, text[0]);
                        strcpy(dsMH[vitriMH]->tenMH, text[1]);
                        capNhatDSMH(dsMH,  soLuongMH, vitriMH);
                        BaoLoi(xTB, yTB, "Sua mon hoc thanh cong");
                        dichuyen=Down;
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
            if(vitri==1) vitri=soKhung-1;
            else vitri--;
        }
        if(dichuyen ==Down)
        {
            if(vitri==soKhung-1) vitri=1;
            else vitri++;
        }

    }
    for(int i=0; i<2; i++)
    {
        delete [] text[i];
    }
    delete []text;
}

void dieuChinhMonHoc(PTRQ &root, monHoc *ds[], int &n)
{
    int vitriMH=0;
    char c;
    int soCH,idCH, vitriID=0;
    int *dsID;
    while(1) //
    {
//        ktDanhSachMH:
        xoaChucNang();
        xoaKhungLamViec();
        if(n==0)
        {
            phimChucNang("F2-Them mon hoc");
            BaoLoi(xTB, yTB, "Danh sach lop rong!");
            while(true)
            {
                c=getch();
                if(c==0)
                {
                    c=getch();
                    if(c==F2) // them lop neu ds rong
                    {
                        xoaChucNang();
                        them1MonHoc(ds, n, vitriMH);
                        xoaThongBao();
                        break;
                    }
                }
                if(c==ESC)
                {
                    xoaKhungLamViec();
                    xoaChucNang();
                    return;
                }
            }
        }
        else // danh sach mon hoc > 0
        {
            anConTro();
            xoaKhungLamViec();
            phimChucNang("F2-Them   F3-Sua   F4-Xoa");
            int checkMH = inDanhSachMH(xLamViec, yLamViec+6, ds, n, vitriMH);
            if(checkMH==ESC)
            {
                xoaChucNang();
                xoaKhungLamViec();
                return;
            }
            if(checkMH==F2)
            {
                xoaChucNang();
                xoaKhungLamViec();
                them1MonHoc(ds, n, vitriMH);

            }
            if(checkMH==F3)
            {
                xoaChucNang();
                xoaKhungLamViec();
                sua1MonHoc(ds,  n, vitriMH);
            }
            if(checkMH==F4) // xoa mon hoc
            {
                soCH=demSoCauHoi(root, ds[vitriMH]->maMH);
                if(soCH>0)
                {
                    BaoLoi(xTB, yTB, "Mon hoc nay da co cau hoi khong xoa duoc");
                }
                else
                {
                    int xn=xacNhan(xTB, yTB, "Ban co chac muon xoa cau hoi nay khong?(y/n):");
                    if(xn==YES)
                    {
                        xoaThongBao();
                        xoa1MonHoc(ds, n, vitriMH);
                    }

                }

            }
            if(checkMH==ENTER)
            {
                vitriID=0;


inCauHoi:
                xoaKhungLamViec();
                soCH=demSoCauHoi(root, ds[vitriMH]->maMH);
                if(soCH==0)
                {
                    phimChucNang("F2-Them cau hoi");
                    BaoLoi(xTB, yTB, "Danh sach cau hoi rong!");
                    while(true)
                    {
                        c=getch();
                        if(c==0)
                        {
                            c=getch();
                            if(c==F2) // them lop neu ds rong
                            {
                                xoaChucNang();
                                gotoxy(55, yLamViec+1);
                                cout << "MON " << ds[vitriMH]->maMH;
                                them1CauHoi(root, ds[vitriMH]->maMH, dsID, soCH, vitriID);
                                xoaThongBao();
                                goto inCauHoi;
                            }
                        }
                        if(c==ESC)
                        {
                            xoaKhungLamViec();
                            xoaChucNang();
                            break;
                        }
                    }
                }
                else // co cau hoi
                {
                    anConTro();
					dsID=new int[MAXID];
                    layDSCauHoi(root, dsID, ds[vitriMH]->maMH, soCH);
                    bubbleSort(dsID, soCH);
ktDanhSachCH2:
                    phimChucNang("F2-Them   F3-Sua   F4-Xoa   F5-Chua thi");
                    int checkCH = inDanhSachCH(root, ds[vitriMH]->maMH, soCH,dsID, vitriID);
                    if(checkCH== ESC)// cau hoi rong or tro ra ds mh
                    {
                        xoaKhungLamViec();
                    }
                    if(checkCH==F2)  // them cau hoi
                    {
                        xoaChucNang();
                        xoaKhungLamViec();
                        gotoxy(55, yLamViec+1);
                        cout << "MON " << ds[vitriMH]->maMH;
                        if(soCH==MAXID) {
                        	BaoLoi(xTB, yTB, "Toi da 200 cau hoi cho 1 mon. Khong the them nua!");
						}
						else
                        them1CauHoi(root, ds[vitriMH]->maMH, dsID, soCH, vitriID);
                        goto ktDanhSachCH2;
                    }

                    if(checkCH==ENTER)
                    {
                        xoaChucNang();
                        xoaKhungLamViec();
                        idCH=dsID[vitriID];
                        inTTCH(root, idCH);
                        while(true)
                        {

                            c=getch();
                            if(c==-32 || c==0)
                            {
                                c=getch();
                                switch(c)
                                {
                                case LEFT:
                                    if(vitriID==0) vitriID=soCH-1;
                                    else vitriID--;
                                    idCH=dsID[vitriID];
                                    inTTCH(root, idCH);
                                    break;
                                case RIGHT:
                                    if(vitriID==soCH-1) vitriID=0;
                                    else vitriID++;
                                    idCH=dsID[vitriID];
                                    inTTCH(root, idCH);
                                    break;

                                }
                            }
                            if(c==ESC) // thoat xem chi tiet cau hoi
                            {
                                goto ktDanhSachCH2;
                            }

                        }

                    }

                }


                // luu vi tri de ti quay lai


            }
        }

    }
    delete []dsID;
}
