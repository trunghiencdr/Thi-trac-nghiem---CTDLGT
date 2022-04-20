#pragma once
#include "DoHoaManHinh.h"
#include "string"
const int YES = 1;
const int NO = 0;
// khong gian cua thanh thong bao
//==================================
int nhapChuoiKC(int x, int y, int sokitu, char *s, int max);
int doiChon2(char chon);
int nhapChuoiBT(int x, int y, int sokitu, char *s, int max);
int chonDapAn(int x, int y, int sokitu, char &dapAn );
int xacNhan(int x, int y, char *s);
void BaoLoi(int x, int y, char *S);
int xacNhan(int x, int y, char *s);
void BaoLoi2(int x, int y, char *S);
int khungTimKiem(int x, int y, char *s, int khungDai, int ktToiDa, char *noiDung);
int ktChuoiBT(char c);
int ktChuoiDB(char c);
void delKiTu(char *a, int &n, int pos);
void insertKiTu(char *a, int &n, int pos, char c);
bool ktTextField(bool *a, int n);
int chonPhai(int x, int y, int sokitu, char *s);
int nhapPassword(int x, int y, int sokitu, char *s, int &trangThai, int max);
void viethoa( char *x);
int timChuoiCon(const char *chuoiCha, char *chuoiCon);
int nhapChuoiSo(int x, int y, int sokitu, char *s, int max);
char doiChon(int chon);
//===============================
int xacNhan(int x, int y, char *s)
{
    anConTro();
    Normal();
    int chon;
    gotoxy(x+2, y);
    cout << s;
    int x1=wherex();
    cout<<"YES"<<"    "<<"NO";
    HighLight();
    gotoxy(x1,y);
    cout<<"YES";
    chon=YES;
    while(1)
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
                return chon;
            }
        }
    }
}
int ktChuoiDB(char c)
{

    if(c>=33 && c<=126) return 1;
    return 0;

}
void BaoLoi2(int x, int y, char *S)
{
    Normal();
    anConTro();
    int x1 = wherex(), y1 = wherey();
//	gotoxy(50, 20);
    gotoxy(x, y);
    cout<<S;
    Sleep(2000);
    gotoxy(x, y);
    cout <<setw(119-50)<<"";
    gotoxy(x1, y1 );
}
int khungTimKiem(int x, int y, char *s, int khungDai, int ktToiDa, char *noiDung)
{
    textcolor(4);
    veKhung(x, y, khungDai, 2);
    Normal();
    if(strcmp(s,"")==0)
    {
        textcolor(8);
        gotoxy(x+1,y+1);
        cout << noiDung;
    }
    Normal();
    gotoxy(x-10, y+1);
    cout << "Tim kiem";
    gotoxy(x+1, y+1);
    hienConTro();
    cout << s;
    int check=nhapChuoiBT(x+1, y+1, khungDai-2, s, ktToiDa);
    if(check==ESC) return ESC;
    if(check==Down) return Down;


}
int doiChon2(char chon)
{
    switch(chon)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'N':
        return 4;
    }
}
char doiChon(int chon)
{
    switch(chon)
    {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'N';
    }
}
int chonDapAn(int x, int y, int sokitu, char &dapAn )
{
    char dsDapAn[]= {'A', 'B', 'C', 'D'};
    int n=4;
    char c=0;
    gotoxy(x, y);
    if(dapAn=='\0')
    {

        cout << "<<  A  >>";
    }
    else cout << "<<  " << dapAn << "  >>";
    int i=0;
    while(c!=ENTER)
    {
        c=getch();
        if(c==0) c=getch();
        switch(c)
        {
        case LEFT:
        {
            xoaHang(x, y, sokitu);
            gotoxy(x, y);
            anConTro();
            if(i==0) i=n-1;
            else i--;
            cout << "<<  "<< dsDapAn[i] << "  >>";
            dapAn=dsDapAn[i];
            break;
        }
        case RIGHT:
        {
            xoaHang(x, y, sokitu);
            gotoxy(x, y);
            anConTro();
            if(i==n-1) i=0;
            else i++;
            cout << "<<  "<< dsDapAn[i] << "  >>";
            dapAn=dsDapAn[i];
            break;
        }
        case Up:
        case Down:
        case ESC:
            return c;
        case ENTER:
            return Down;
        }
    }
}

void BaoLoi(int x, int y, char *S)
{
    Normal();
    anConTro();
    int x1 = wherex(), y1 = wherey();
    gotoxy(x, y);
    cout<<S;
    Sleep(1000);
    gotoxy(x, y);
    cout <<setw(119-x)<<"";
    gotoxy(x1, y1 );
}
int ktChuoiBT(char c)
{
    if((c>=65&&c<=90)||(c>=97&&c<=122)||(c>=48&&c<=57)) return 1;
    return 0;
}

void delKiTu(char *a, int &n, int pos)
{
    if(pos>=0 && pos < n)
    {
        for(int i=pos; i<n-1; i++)
        {
            a[i]=a[i+1];
        }
    }

    a[n-1]='\0';
    n--;
}
void insertKiTu(char *a, int &n, int pos, char c)
{
    if(pos >= 0 && pos <= n)
    {
        for(int i = n; i > pos; i--)
        {
            a[i]=a[i-1];
        }
    }
    a[pos]=c;
    n++;
}

int nhapChuoiBT(int x, int y, int sokitu, char *s, int max)
{
    int len=strlen(s);
    if(len>=sokitu) gotoxy(x+sokitu-1, y);
    else gotoxy(len+x, y);
    char c = '0';
    while(c!=ENTER)
    {
        c = getch();
        if(c==-32 || c==0)
        {
            c=getch();
            if(c==Up || c==Down)
            {
                if(s[len-1]==SPACE && len!=0) s[len-1]='\0';
                else s[len]='\0';
                return (int)c;
            }
        }
        else
        {
            if(c==ESC)
            {

                return ESC;
            }
            if(c==BSPACE)
            {
                if(len==0) continue;
                else s[--len]=NULL;
            }
            if(ktChuoiBT(c))
            {
                if(len>=max) continue;
                else s[len++]=c;
            }
            if(len > 0 && len < max)
            {
                if(c==SPACE && s[len-1]!=SPACE) s[len++]=c;
            }
        }
        if(len<=sokitu-1)
        {

            xoaHang(x,y,sokitu);
            anConTro();
            gotoxy(x,y);
            for(int i=0; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
        else
        {
            anConTro();
            gotoxy(x,y);
            for(int i=len-sokitu+1; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
    }
    if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
    else s[len]='\0';
    return Down;
}
int nhapChuoiDB(int x, int y, int sokitu, char *s, int max)
{
    int len=strlen(s);
    if(len>=sokitu) gotoxy(x+sokitu-1, y);
    else gotoxy(len+x, y);
    char c = '0';
    while(c!=ENTER)
    {
        c = getch();
        if(c==-32 || c==0)
        {
            c=getch();
            if(c==Up || c==Down)
            {
                if(s[len-1]==SPACE && len!=0) s[len-1]='\0';
                else s[len]='\0';
                return (int)c;
            }
        }
        else
        {
            if(c==ESC)
            {

                return ESC;
            }
            if(c==BSPACE)
            {
                if(len==0) continue;
                else s[--len]=NULL;
            }
            if(ktChuoiDB(c))
            {
                if(len>=max) continue;
                else s[len++]=c;
            }
            if(len > 0 && len < max)
            {
                if(c==SPACE && s[len-1]!=SPACE) s[len++]=c;
            }
        }
        if(len<=sokitu-1)
        {

            xoaHang(x,y,sokitu);
            anConTro();
            gotoxy(x,y);
            for(int i=0; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
        else
        {
            anConTro();
            gotoxy(x,y);
            for(int i=len-sokitu+1; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
    }
    if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
    else s[len]='\0';
    return Down;
}
bool ktTextField(bool *a, int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==false) return false;
    }
    return true;
}
int nhapChuoiKC(int x, int y, int sokitu, char *s, int max)
{
    int len=strlen(s);
    if(len>=sokitu) gotoxy(x+sokitu-1, y);
    else gotoxy(len+x, y);
    char c = 0;
    while(c!=ENTER )
    {
        c = getch();
        if(c==-32)
        {
            c=getch();
            if(c==Up || c==Down)
            {
                if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
                else s[len]='\0';
                return (int)c;
            }
        }
        else
        {
            if(c==ESC)
            {
                if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
                else s[len]='\0';
                return ESC;
            }
            if(c==BSPACE)
            {
                if(len==0) continue;
                else	s[--len]=NULL;
            }
            if(ktChuoiBT(c) )
            {
                if(len>=max) continue;
                else s[len++]=c;
            }
        }
        if(len<=sokitu-1)
        {
            xoaHang(x,y,sokitu);
            anConTro();
            gotoxy(x,y);
            for(int i=0; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
        else
        {
            anConTro();
            gotoxy(x,y);
            for(int i=len-sokitu+1; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
    }
    if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
    else s[len]='\0';
    return Down;
}

int chonPhai(int x, int y, int sokitu, char *s)
{

    char c=0;
    gotoxy(x, y);
    if(stricmp(s,"")==0)
    {

        cout << "<<  Nam  >>";
        strcpy(s, "Nam");
    }
    else cout << "<<  "<< setw(3) << left << s << "  >>";
    while(c!=ENTER)
    {
        c=getch();
        if(c==-32)
        {
            c=getch();
            if(c==LEFT || c==RIGHT)
            {
                xoaHang(x, y, sokitu);
                gotoxy(x, y);
                anConTro();
                if(stricmp(s,"Nam")==0)
                {

                    cout << "<<  Nu   >>";
                    strcpy(s, "Nu");

                }
                else
                {

                    cout << "<<  Nam  >>";
                    strcpy(s, "Nam");
                }
            }
            if(c==Up || c==Down) return (int)c;
        }
        else
        {
            if(c==ESC) return ESC;
            if(c==ENTER) return Down;
        }
    }
}
int nhapPassword(int x, int y, int sokitu, char *s, int &trangThai, int max)
{
    int len=strlen(s);
    if(len>=sokitu) gotoxy(x+sokitu-1, y);
    else gotoxy(len+x, y);
    char c = '0';
    while(c!=ENTER )
    {
        c = getch();
        if(c==-32||c==0)
        {
            c=getch();
            if(c==Up || c==Down)
            {
                if(s[len-1]==SPACE && len!=0) s[len-1]='\0';
                else s[len]='\0';
                return (int)c;
            }
            if(c==(int)F2) trangThai++;
        }
        else
        {
            if(c==ESC)
            {
                if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
                else s[len]='\0';
                return c;
            }
            if(c==BSPACE)
            {
                if(len==0) continue;
                else
                {
                    s[--len]=NULL;
                }
            }
            if(ktChuoiBT(c)==1)
            {
                if(len>=max) continue;
                else s[len++]=c;
            }
        }
        if(trangThai%2!=0)
        {
            if(len<=sokitu-1)
            {
                xoaHang(x, y, sokitu);
                gotoxy(x,y);

                for(int i=0; i<len; i++)
                {
                    cout << s[i];
                }
            }
            else
            {
                xoaHang(x, y, sokitu);
                gotoxy(x,y);
                for(int i=len-sokitu+1; i<len; i++)
                {
                    cout << s[i];
                }
            }
        }
        else
        {
            xoaHang(x, y, sokitu);
            gotoxy(x,y);
            for(int i=0; i<len && i < sokitu; i++)
            {
                cout << "*";
            }
        }
    }
    if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
    else s[len]='\0';
    return Down;
}
void viethoa(char *x)
{
    int i=0;
    while(x[i])
    {
        x[i]=toupper(x[i]);
        i++;
    }
}

int timChuoiCon(const char *chuoiCha, char *chuoiCon)
{
    char *c=new char[strlen(chuoiCha)+1];
    strcpy(c, chuoiCha);
    char *s=new char[strlen(chuoiCon)+1];
    strcpy(s, chuoiCon);
    viethoa(c);
    viethoa(s);
    string str(c);
    string substr(s);
    int found = str.find(substr);
    delete []c;
    delete []s;
    return found;

}
int nhapChuoiSo(int x, int y, int sokitu, char *s, int max)
{
    int len=strlen(s);
    if(len>=sokitu) gotoxy(x+sokitu-1, y);
    else gotoxy(len+x, y);
    char c = 0;
    while(c!=ENTER )
    {
        c = getch();
        if(c==-32)
        {
            c=getch();
            if(c==Up || c==Down)
            {
                if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
                else s[len]='\0';
                return (int)c;
            }
        }
        else
        {
            if(c==ESC)
            {
                if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
                else s[len]='\0';
                return ESC;
            }
            if(c==BSPACE)
            {
                if(len==0) continue;
                else	s[--len]=NULL;
            }
            if(c >= 48 && c<=57 )
            {
                if(len>=max) continue;
                if(c=='0' && len==0) continue;
                s[len++]=c;

            }
        }
        if(len<=sokitu-1)
        {
            xoaHang(x,y,sokitu);
            anConTro();
            gotoxy(x,y);
            for(int i=0; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
        else
        {
            anConTro();
            gotoxy(x,y);
            for(int i=len-sokitu+1; i<len; i++)
            {
                cout << s[i];
            }
            hienConTro();
        }
    }
    if(s[len-1]==SPACE&& len!=0) s[len-1]='\0';
    else s[len]='\0';
    return Down;
}
