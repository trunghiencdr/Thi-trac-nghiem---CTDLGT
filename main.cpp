
#include "Lop.h"
#include "File.h"

using namespace std;

int main()
{
    DanhSachLop ds;
    monHoc *dsMH[MAXMH];
    initialize(dsMH, MAXMH);
    int soLuongMH=0;
    PTRQ root = NULL, sq;
    sq=new nodecauhoi;
    PTRSV sv;
    loadMH(dsMH, soLuongMH);
    LoadCauHoi(root);
    LoadDanhSachLop(ds);
    int vitriLop;
ktDangNhap:
    system("cls");
    int check = DangNhap(ds,sv, vitriLop);
    if(check == ESC)
    {
        Normal();
        int xn=xacNhan(30, 25, "Ban co chac muon thoat chuong trinh khong?");
        if(xn==YES)
        {
            system("cls");
            gotoxy(30,10);
            cout << "Cam on ban da su dung chuong trinh!";
            return 0;
        }
        if(xn==NO) goto ktDangNhap;
    }
    else if(check == 0)				//Giao vien
    {
        // cho tt ao de giao vien thi
        sv=new nodesv;
        strcpy(sv->info.MASV,"");
        strcpy(sv->info.HO,"G");
        strcpy(sv->info.TEN,"V");
        strcpy(sv->info.PHAI,"Nam");
        strcpy(sv->info.password,"");
        sv->next=NULL;
        sv->info.Firstdiem=NULL;
        sv->info.TrangThaiThi=0;
        VeKhung();
        int chon = 0;
        while(1)
        {


            int phim=MenuDong(menuGV,chon);
            xoaHang(xMenu-8, yMenu+chon,8);
            switch(chon)
            {
            case 0:	// thao tac lop
            {
                suaSinhVien(ds);
                break;
            }
            case 1:
            {
                //Sua sinh vien
                dieuChinhMonHoc(root, dsMH, soLuongMH);
                break;
            }
            case 2:  // in diem
            {
                inDanhSachDiem(ds, dsMH, soLuongMH, root);
                break;
            }
            case 3: // thi trac nghiem
            {
                Normal();
                ThiTracNghiem(root, sv, dsMH, soLuongMH, ds.lop[vitriLop]);
                VeKhung();
                break;
            }
            case 4: // dang xuat va luu file
            {
                SaveCauHoi(root);
                SaveDSLop(ds);
                SaveMonHoc(dsMH,soLuongMH);
                Normal();
                goto ktDangNhap;
            }
            default:
                break;


            }
        }
    }
    else if(check == 1)				//Sinh vien
    {
        anConTro();
        ThiTracNghiem(root, sv, dsMH, soLuongMH, ds.lop[vitriLop]);
        
        goto ktDangNhap;

    }
    xoaCayAVL(root);
    clearList(ds);
    xoaDSMH(dsMH, soLuongMH);
    return 0;
}

