#pragma once
#include <iostream>
#include <string.h>
// ctdl chua chi tiet de thi
struct chitietdethi
{
    int SoCauThi;
    int *IDCauThi;
    char *CauTraLoi;
};
struct diem
{
    char maMH[7];
    float mark;
    chitietdethi CTDT;
};
struct nodediem
{
    diem info;
    struct nodediem *next;
};
typedef nodediem *PTRD;
// khai bao nguyen mau ham
void insertLast(PTRD &FirstDiem, diem x);
PTRD timDiem(PTRD firstDiem, char *maMH)
{
    PTRD p;
    for(p=firstDiem; p!=NULL ; p=p->next)
        if(stricmp(p->info.maMH, maMH)==0) return p;
    return NULL;
}
// dinh nghia ham
void insertLast(PTRD &FirstDiem, diem x)
{
    PTRD p=new nodediem;
    p->info=x;
    p->next=NULL;
    if(FirstDiem==NULL) FirstDiem=p;
    else
    {
        PTRD Last=FirstDiem;
        for(; Last->next!=NULL; Last=Last->next);
        Last->next=p;
    }
}



