#pragma once
#include "MyLib.h"
#include <iomanip>
#define WHITE 15
#define MAXLOP 100
#define MAXMH 100
#define STACKSIZE 500
using namespace std;
static char menuGV [5][50] =
{
    "1. Dieu chinh danh sach lop va sinh vien     ",
    "2. Dieu chinh danh sach mon hoc va cau hoi   ",
    "3. Xem danh sach diem va cau truc de thi     ",
    "4. Thi trac nghiem                           ",
    "5. Dang xuat va luu file                     "
};


const int xMenuPhu = 60;
const int yMenuPhu = 3;
const int hangThongBao = 39;
const int xMenu = 50;
const int yMenu = 4;
const int xTB = 55;
const int yTB = 12;
const int xLamViec = 2;
const int yLamViec = 14;
const int xCTDT=15;
const int yCTDT=23;
const int daiCTDT=90;
const int rongCTDT=15;
const int xThi = 37;
const int yThi = 3;
const int daiThi = 100;
const int rongThi = 39;
const int daiLamViec = 117;
const int rongLamViec = 27;
const int xCN=2;
const int yCN=11;
const int topLeft = 201;
const int topRight = 187;
const int botLeft = 200;
const int botRight = 188;
const int topLeftNho = 218;
const int topRightNho = 191;
const int botLeftNho = 192;
const int botRightNho = 217;
const int rongMenuPhu = 8;
const int chuDo = 4;
const int mauThongBao = 160;
const int Up = 72;
const int Down = 80;
const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;
const int RIGHT = 77;
const int LEFT = 75;
const char F1 = ';';
const char F2 = '<';
const char F3 = '=';
const char F4 = '>';
const char F5 = '?';
//==============================================================================================================================================
void xoaHang(int x, int y, int dai);
int c_a_r(char td [][50]);
void khungSuaSinhVien(char ttsv[][51], int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20]);
void veKhung(int x, int y, int dai, int rong);
void XoaKhung(int x, int y, int dai, int rong);
void veKhungNho(int x, int y, int dai, int rong);
void vekhungDangNhap(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char truongDangNhap[][20]);
void VeDuongThang_Ngang(int hang, int FirstCot, int LastCot);
void anConTro();
void hienConTro();
void Normal();
void HighLight();
void Normal2();
void HighLight2();
void VeDuongThang_NgangNho(int hang, int FirstCot, int LastCot);
void VeDuongThang_Doc(int cot, int FirstHang, int LastHang);
void VeDT_NgangBang(int hang, int FirstCot, int LastCot);
void VeDuongThang_DocNho(int cot, int FirstHang, int LastHang);
void ThongBaoTrang(int trangHienTai, int soTrang);
void khungNhapCauHoi(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char cauHoi[][20]);
void veBangLop(int x, int y, int toiDa);
void veBangLop(int x, int y, int toiDa);
void HighLightSV(int x, int y);
void NormalSV (int x, int y) ;
void xoaThongBao();
void veKhungDeThi();
void veKhungTTSV();
void xoaDapAn();
int MenuDong(char td [][50], int &choice);
void khungNhapCauHoi(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20]);
int c_a_r(char td [][50])
{
    int i;
    for(i = 0; td[i][0] != NULL; ++i);
    return i;
}
void thongBao(char *s)
{
    Normal();
    gotoxy(xTB, yTB);
    cout << s;

}
void xoaDapAn()
{
    Normal();
    for(int i=13; i<=41; i++)
    {
        gotoxy(2, i);
        cout << "                                  ";
    }
}
void inMuiTen(int x, int y)
{
    Normal();
    gotoxy(x, y);
    cout << "==>";
}
int MenuDong(char td [][50], int &choice)
{
    textcolor(10);
    anConTro();
    Normal();
    int so_item;
    int i;
    so_item = c_a_r(td);
    for ( i=0; i< so_item ; i++)
    {
        gotoxy(xMenu, yMenu +i);
        cout << td[i];
    }
    inMuiTen(xMenu-8, yMenu+choice);
    HighLight();
    gotoxy(xMenu,yMenu+choice);
    cout << td[choice];
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0) kytu = getch();
        switch (kytu)
        {
        case Up :
            if (choice+1 >1)
            {
                xoaHang(xMenu-8, yMenu+choice,8);
                anConTro();
                Normal();
                gotoxy(xMenu,yMenu+choice);
                cout << td[choice];
                choice --;
                inMuiTen(xMenu-8, yMenu+choice);
                HighLight();
                gotoxy(xMenu,yMenu+choice);
                cout << td[choice];
            }
            break;
        case Down :
            if (choice + 1 <so_item)
            {
                xoaHang(xMenu-8, yMenu+choice,8);
                anConTro();
                Normal();
                gotoxy(xMenu,yMenu+choice);
                cout << td[choice];
                choice ++;
                inMuiTen(xMenu-8, yMenu+choice);
                HighLight();
                gotoxy(xMenu,yMenu+choice);
                cout << td[choice];
            }
            break;
        case ENTER:
            return ENTER;
        }  // end switch
    }
    while (1);
}
//void khungSuaCauHoi(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char truongCauHoi[][20]);
void khungNhapCauHoi(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20])
{
    veKhungNho(cotTextField-17, y+1, dai+30, 24);
    gotoxy(cotTextField+20,y+2);
    cout << labelSV[0];
    y=y+5; // khoang cach giua them cau hoi va may cai khung
    for(int i=0; i<soItem-1; i++)
    {
        gotoxy(cotTextField-14,y+1);
        cout << setw(14) << right << labelSV[i+1];
        veKhung(cotTextField, y, dai, rong);
        pos[i]=y+1;
        y+=3;
    }
    veKhungNho(cotTextField+23,y,6,1);
    gotoxy(cotTextField+25,y+1);
    pos[soItem-1]=y+1;
    cout << labelSV[soItem];
}
void veKhungDeThi()
{
    veKhungNho(xCTDT, yCTDT, daiCTDT, rongCTDT);
    gotoxy(xCTDT-3, yCTDT+rongCTDT/2);
    cout << "<<";
    gotoxy(xCTDT+daiCTDT+2,yCTDT+rongCTDT/2);
    cout << ">>";
}
void xoaKhungDeThi()
{
    XoaKhung(xCTDT+1, yCTDT+1, daiCTDT-1, rongCTDT-1);
}
void xoaChucNang()
{
    xoaHang(2, yTB, 55);
}
void phimChucNang2()
{

    Normal();
    gotoxy(5, 4);
    cout << "ESC-Quay lai";
    gotoxy(5, 5);
    cout << "ENTER-Chon";
    gotoxy(5, 6);
    cout << "UP-Len";
    gotoxy(5, 7);
    cout << "DOWN-Xuong";
    gotoxy(5, 8);
    cout << "F1-Tim kiem";

}

void xoaThongBao()
{
    anConTro();
    for(int i=yTB-1; i<yTB+2; i++)
    {
        gotoxy(xTB-10, i);
        cout << "                                                                               ";
    }
}


void phimChucNang(char *s)
{
    Normal();
    xoaChucNang();
    gotoxy(2, yTB);
    cout << s;
}
void NormalSV (int x, int y)
{
    SetColor(WHITE);
    SetBGColor(0);
    gotoxy(x-1,y);
    putchar(179);
    printf("%4s"," ");
    putchar(179);
    printf("%14s"," ");
    putchar(179);
    printf("%34s"," ");
    putchar(179);
    printf("%14s"," ");
    putchar(179);
    printf("%5s"," ");
    putchar(179);
    printf("%9s"," ");
    putchar(179);
    printf("%13s"," ");
    putchar(179);
}
void HighLightSV(int x, int y)
{
    SetColor(15);
    SetBGColor(1);
    gotoxy(x-1, y);
    putchar(179);
    printf("%4s"," ");
    putchar(179);
    printf("%14s"," ");
    putchar(179);
    printf("%34s"," ");
    putchar(179);
    printf("%14s"," ");
    putchar(179);
    printf("%5s"," ");
    putchar(179);
    printf("%9s"," ");
    putchar(179);
    printf("%13s"," ");
    putchar(179);
}

void veBangLop(int x, int y, int toiDa)
{
    anConTro();
    Normal();
    int ngang=75;
    veKhungNho(x, y, ngang, toiDa+3);
    VeDuongThang_NgangNho(y+3, x+1, x+ngang-1);
    VeDuongThang_DocNho(x+10, y+1, y+toiDa+3);
    VeDuongThang_DocNho(x+30, y+1, y+toiDa+3);

}
void veBangSinhVien(int x, int y, int toiDa)
{
    anConTro();
    Normal();
    int ngang=100;
    veKhungNho(x, y, ngang, toiDa+3);
    VeDuongThang_NgangNho(y+3, x+1, x+ngang-1);
    VeDuongThang_DocNho(x+5, y+1, y+toiDa+3); // stt
    VeDuongThang_DocNho(x+5+15, y+1, y+toiDa+3); // ma sv
    VeDuongThang_DocNho(x+20+35, y+1, y+toiDa+3);// ho
    VeDuongThang_DocNho(x+55+15, y+1, y+toiDa+3);//ten va trangthaithi
    VeDuongThang_DocNho(x+70+6, y+1, y+toiDa+3);// phai
    VeDuongThang_DocNho(x+76+10, y+1, y+toiDa+3);// password
//	VeDuongThang_DocNho(x+55+15, y+1, y+toiDa+3);

}
void veKhungDangNhap(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char truongDangNhap[][20])
{
    veKhung(cotTextField-20, y-3, 55, 15);
    for(int i=0; i<soItem-1; i++)
    {
        gotoxy(cotTextField-14,y+1);
        cout << setw(14) << right << truongDangNhap[i];
        veKhung(cotTextField, y, dai, rong);
//		 xoaHang(cotTextField+1, y+1, dai-1);
        pos[i]=y+1;
        y+=3;
    }
    veKhungNho(cotTextField+2,y+1,12,1);
    gotoxy(cotTextField+4,y+2);
    pos[soItem-1]=y+2;
    cout << "DANG NHAP";
}

void Normal ()
{
    SetColor(WHITE);
    SetBGColor(0);
}
void ThongBaoTrang(int trangHienTai, int soTrang)
{
    Normal();
    gotoxy(xLamViec+daiLamViec-15, yLamViec+rongLamViec);
    cout << "Trang " << trangHienTai << "/" << soTrang;
}

void Normal2 (int x, int y)
{
    Normal();
    gotoxy(x,y);
    putchar(179);
    printf("%9s"," ");
    putchar(179);
    printf("%19s"," ");
    putchar(179);
    printf("%44s"," ");
    putchar(179);;
}
void anConTro()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void hienConTro()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HighLight ()
{
    SetColor(15);
    SetBGColor(1);
}
void HighLight2(int x, int y)
{
    HighLight();
    gotoxy(x, y);
    putchar(179);
    printf("%9s"," ");
    putchar(179);
    printf("%19s"," ");
    putchar(179);
    printf("%44s"," ");
    putchar(179);

}
void xoaHang(int x, int y, int dai)
{
    anConTro();
    gotoxy(x, y);
    textcolor(0);
    cout << setw(dai) << "";
    Normal();
    hienConTro();
}
void VeDuongThang_Ngang(int hang, int FirstCot, int LastCot)
{

    while(FirstCot<=LastCot)
    {
        gotoxy(FirstCot++,hang);
        //cout << "_";
        putchar(205);
    }
}
void VeDuongThang_NgangNho(int hang, int FirstCot, int LastCot)
{

    while(FirstCot<=LastCot)
    {
        gotoxy(FirstCot++,hang);
        //cout << "_";
        putchar(196);//-
    }
}
//------------------------
void VeDuongThang_Doc(int cot, int FirstHang, int LastHang)
{

    while(FirstHang<=LastHang)
    {
        gotoxy(cot,FirstHang++);
        //cout << "|";
        putchar(186);
    }
}
void VeDuongThang_DocNho(int cot, int FirstHang, int LastHang)
{

    while(FirstHang<=LastHang)
    {
        gotoxy(cot,FirstHang++);
        //cout << "|";
        putchar(179);
    }
}
void VeKhung()
{
    clrscr();
    resizeConsole(1000,900);
    textcolor(10);
    gotoxy(70,2);
    cout<<"MENU CHUC NANG";
    gotoxy(5,2);
    cout<<"HUONG DAN";
    phimChucNang2();

    veKhung(1,1,25,8);
    veKhung(28,1,100,8);
    veKhung(1, 10, 127,35);

}
void VeKhungThi()
{
    clrscr();
    //khung to nhat
    resizeConsole(1500,1000);
    VeDuongThang_Ngang(1,2,168);//top
    VeDuongThang_Ngang(42,2,168);//mh_lamviec
    VeDuongThang_Doc(1,2,41);//left
    VeDuongThang_Doc(169,2,41);	//right
    //4 goc
    gotoxy(1,1);//topleft
    putchar(201);
    gotoxy(169,1);//topright
    putchar(187);
    gotoxy(1,42);//botleft
    putchar(200);
    gotoxy(169,42);//botright
    putchar(188);
    //khung thong tin thi sinh
    VeDuongThang_Doc(36,2,11);
    VeDuongThang_Ngang(12,2,35);
//	gotoxy(36,13);
    putchar(188);
    //khungshowdapan
    VeDuongThang_Doc(36,12,41);
}

void XoaKhung(int x, int y, int dai, int rong)
{
    anConTro();
    textcolor(0);
//	HighLight();
    for(int i=y; i<=(rong+y); i++)
    {
        gotoxy(x,i);
        cout << setw(dai) << "";
    }
    Normal();
}
void xoaKhungLamViec()
{
    Normal();
    anConTro();
    for(int i=yLamViec; i<=yLamViec+rongLamViec; i++)
    {
        gotoxy(xLamViec, i);
        cout << "                                                                                                                     ";
    }
}
void xoaKhungThi()
{

    Normal();
    for(int i=yThi; i<yThi+rongThi; i++)
    {
        gotoxy(xThi, i);
        cout << "                                                                                                                                    ";
    }
}
void xoaCauHoi()
{
    XoaKhung(2, 6, 117, 20);
}
void veKhung(int x, int y, int ngang, int doc)
{

    int firstNgang = x+1;
    int endNgang = x+ngang-1;
    int firstDoc = y+1;
    int endDoc = y + doc - 1;
    VeDuongThang_Ngang(y, firstNgang, endNgang);
    VeDuongThang_Ngang(endDoc + 1, firstNgang, endNgang);
    VeDuongThang_Doc(x, firstDoc, endDoc);
    VeDuongThang_Doc(endNgang + 1, firstDoc, endDoc);
    // 4 goc;
    gotoxy(x,y);
    putchar(topLeft);
    gotoxy(endNgang+1, y);
    putchar(topRight);
    gotoxy(x, endDoc + 1);
    putchar(botLeft);
    gotoxy(endNgang+1, endDoc + 1);
    putchar(botRight);

}
void veKhungNho(int x, int y, int ngang, int doc)
{

    int firstNgang = x+1;
    int endNgang = x+ngang-1;
    int firstDoc = y+1;
    int endDoc = y + doc;
    VeDuongThang_NgangNho(y, firstNgang, endNgang);
    VeDuongThang_NgangNho(endDoc + 1, firstNgang, endNgang);
    VeDuongThang_DocNho(x, firstDoc, endDoc);
    VeDuongThang_DocNho(endNgang + 1, firstDoc, endDoc);

    gotoxy(x,y);
    putchar(topLeftNho);
    gotoxy(endNgang+1, y);
    putchar(topRightNho);
    gotoxy(x, endDoc + 1);
    putchar(botLeftNho);
    gotoxy(endNgang+1, endDoc + 1);
    putchar(botRightNho);

}
void veKhungDiem()
{
    VeDuongThang_Ngang(5, 50, 60);
    VeDuongThang_Ngang(10, 50, 60);
    VeDuongThang_Doc(48, 6, 9);
    VeDuongThang_Doc(62, 6, 9);
    gotoxy(49, 5);
    putchar(topLeft);
    gotoxy(61, 5);
    putchar(topRight);
}
void khungThemSinhVien(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20])
{
    Normal();
    veKhungNho(cotTextField-15, y+1, dai+30, 24);
    gotoxy(cotTextField+((dai-strlen(labelSV[0]))/2),y+2);
    cout << labelSV[0];
    y=y+6;
    for(int i=0; i<soItem-1; i++)
    {
        gotoxy(cotTextField-14,y+1);
        cout << setw(14) << right << labelSV[i+1];
        veKhung(cotTextField, y, dai, rong);
        pos[i]=y+1;
        y+=3;
    }
    veKhungNho(cotTextField+((dai-strlen(labelSV[soItem]))/2)-1,y,strlen(labelSV[soItem])+2,1);
    gotoxy(cotTextField+((dai-strlen(labelSV[soItem]))/2),y+1);
    pos[soItem-1]=y+1;
    cout << labelSV[soItem];
}

void inTextField(char *s, int x, int y, int dai)
{
    gotoxy(x, y);
    cout << s;
}
void khungSuaSinhVien(char ttsv[][51], int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20])
{
    Normal();
    veKhungNho(cotTextField-15, y+1, dai+30, 24);
    gotoxy(cotTextField+((dai-strlen(labelSV[0]))/2),y+2);
    cout << labelSV[0];
    y=y+6;
    for(int i=0; i<soItem-1; i++)
    {
        gotoxy(cotTextField-14,y+1);
        cout << setw(14) << right << labelSV[i+1];
        veKhung(cotTextField, y, dai, rong);
        if(i==3) // i la phai
        {
            gotoxy(cotTextField+1, y+1);
            cout << "<<  "<< setw(3) << left << ttsv[i] << "  >>";
        }
        else inTextField(ttsv[i], cotTextField + 1, y + 1, dai-1);
        pos[i]=y+1;
        y+=3;
    }
    veKhungNho(cotTextField+((dai-strlen(labelSV[soItem]))/2)-1,y,strlen(labelSV[soItem])+2,1);
    gotoxy(cotTextField+((dai-strlen(labelSV[soItem]))/2),y+1);
    pos[soItem-1]=y+1;
    cout << labelSV[soItem];
}
void veKhungTextField(int cotTextField, int y, int dai, int rong, int *pos, int soItem, char labelSV[][20])
{
    y=y+4;
    for(int i=0; i<soItem-1; i++)
    {
        gotoxy(cotTextField-14,y+1);
        cout << setw(14) << right << labelSV[i];
        veKhung(cotTextField, y, dai, rong);
        pos[i]=y+1;
        y+=3;
    }
    veKhungNho(cotTextField+6,y+2,7,1);
    gotoxy(cotTextField+8,y+3);
    pos[soItem-1]=y+3;
    cout << labelSV[soItem-1];
}
