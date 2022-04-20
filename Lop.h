#pragma once
#include "SinhVien.h"
#include "MonHoc.h"
#define MAXSVLOP 150
using  namespace std;
char truongThemLop [][20]= {"THEM LOP HOC", "Ma Lop:", "Ten Lop:", "THEM"};
char truongSuaLop [][20]= {"SUA TT LOP HOC", "Ma Lop:", "Ten Lop:", "SUA"};
const char* FileArt = "Data\\ttnart.txt";
struct lop
{
    char MaLop[11];
    char TenLop[41];
    PTRSV FirstSinhVien;
};
typedef struct lop Lop;
struct DanhSachLop
{
    int n;
    Lop lop[MAXLOP];
};
int demSV(Lop lop);
void save1Lop(Lop lop);
void themDSLop(DanhSachLop &ds, Lop Class, int &vitriLop);
int them1SinhVien(DanhSachLop ds, PTRSV &firstSV, sinhvien *&dssv, int &soLuongSV, int &vitriSV);
void suaSinhVien(DanhSachLop &ds);
int inDanhSachSV(Lop &lop, sinhvien *&dssv, int &soLuongSV, int &vitriSV);
PTRSV timSinhVienVaLop(DanhSachLop ds, char *masv, int &vitriLop);
int them1Lop(DanhSachLop &ds, int &vitriLop);
int sua1Lop(DanhSachLop &ds, int &vitriMang);
void suaLop(DanhSachLop &ds);
int timLop(DanhSachLop ds, char *maLop);
int timTenLop(DanhSachLop ds, char *tenLop);
void suaSinhVien(DanhSachLop &ds);
int inDanhSachLop(DanhSachLop ds, int &vitriLop);
int inDiemSV(Lop lop, char *maMH, PTRQ root);
void inBangDiem(int vtThongTin[], int y, sinhvien ds[], int n, char *maLop, char *maMH, int vitriHL, int oToiDa);
void inDanhSachDiem(DanhSachLop ds, monHoc *dsMH[], int soLuongMH, PTRQ root);
int xoa1Lop(DanhSachLop &ds, int &vitriLop);
int Xuat1CauHoiSV(PTRQ root, int id, char chon, int thutu);
int XuatDeThiSV(PTRSV sv, PTRQ root, char *maMH);
int DangNhap(DanhSachLop ds, PTRSV &sv, int &vitriLop);
chitietdethi taoCTDT(char *maMH, int *deThi, int *chon, int soCauThi);
void ThaydoiTTCT(PTRQ &root,int *deThi,int soCauThi);
PTRSV timSinhVienVaLop(DanhSachLop ds, char *masv, int &vitriLop);
void deleteClass(DanhSachLop &ds, Lop Class);
void showTTNArt();
void moveToLast(DanhSachLop &ds, int i);
void capNhatDSLop(DanhSachLop &ds, int &vitriLop);

//------Clear Lists------
void clearList(PTRSV &First);
void clearList(PTRD &First);
void clearList(DanhSachLop &ds);
void xoadong_d(int y, int n_row);
void moveToLast(DanhSachLop &ds, int i)
{
    Lop Class;
    for(; i < ds.n - 1; ++i)
    {
        Class = ds.lop[i];
        ds.lop[i] = ds.lop[i+1];
        ds.lop[i+1] = Class;
    }
}

//------Clear Lists------
void clearList(PTRSV &First)
{
    PTRSV p;
    while(First != NULL)
    {
        p = First;
        clearList(First->info.Firstdiem);
        First = First->next;
        delete p;
    }
}
void clearList(PTRD &First)
{
    PTRD p;
    while(First != NULL)
    {
        p = First;
        First = First->next;
        delete p;
    }
}
void clearList(DanhSachLop &ds)
{
    for(int i = 0; i < ds.n; ++i)
    {
        clearList(ds.lop[i].FirstSinhVien);
    }
    delete ds.lop;
}
void xoaDSMH(monHoc *ds[], int soLuongMH)
{
    for(int i=0; i<soLuongMH; i++)
    {
        delete ds[i];
    }
    delete []ds;
}
void xoaCayAVL(PTRQ &root)
{
    if(root!=NULL)
    {
        xoaCayAVL(root->left);
        xoaCayAVL(root->right);
        delete root;
    }
}
void xoadong_d(int y, int n_row)
{
    int i=0;
    gotoxy (0,y);
    for(i=0; i<n_row; i++)
    {
        cout<<"                                                                     "<<endl;
    }
    gotoxy (0,y);
}
void deleteClass(DanhSachLop &ds, Lop Class)
{
    for(int i = 0; i < ds.n; ++i)
    {
        if(stricmp(ds.lop[i].MaLop, Class.MaLop) == 0)
        {
            moveToLast(ds, i);
            break;
        }
    }
    --ds.n;
}
PTRSV timSinhVienVaLop(DanhSachLop ds, char *masv, int &vitriLop)
{
    PTRSV p ;
    for(int i=0; i<ds.n; i++)
        for(p = ds.lop[i].FirstSinhVien; p != NULL; p = p->next)
            if(strcmp(masv, "")!=0 && stricmp(p->info.MASV, masv) == 0)
            {
                vitriLop=i;
                return p;
            }

    return NULL;
}
void save1Lop(Lop lop){
	ofstream fileOut;
	char fileName[100] = "Data\\Ds_SinhVien\\";
	strcat(strcat(fileName, lop.MaLop),".txt");// tao ten file
	fileOut.open(fileName, ios_base::out);
	// kiem tra
	if(fileOut.fail()){
//		BaoLoi("Khong luu duoc CTDT");
	}
	fileOut << demSV(lop) << endl;
	for(PTRSV p=lop.FirstSinhVien; p!=NULL; p=p->next){
		fileOut << p->info.MASV << ",";
		fileOut << p->info.password << ",";
		fileOut << p->info.HO << ",";
		fileOut << p->info.TEN << ",";
		fileOut << p->info.PHAI << ",";
		fileOut << p->info.TrangThaiThi << endl;
		for(PTRD q = p->info.Firstdiem; q!=NULL; q=q->next){
			fileOut << q->info.maMH << ",";
			fileOut << q->info.mark << endl;
			fileOut << q->info.CTDT.SoCauThi << endl;
			for(int i=0; i<q->info.CTDT.SoCauThi; i++){
				fileOut << q->info.CTDT.IDCauThi[i] << ",";
				fileOut << q->info.CTDT.CauTraLoi[i] << endl;
			}
		}
	}
	fileOut.close();
}


void ThaydoiTTCT(PTRQ &root,int *deThi,int soCauThi)
{
    int id;
    for(int i=0; i<soCauThi; i++)
    {
        id=deThi[i];
        PTRQ p = search(root,id);
        p->info.trangThai=1;
    }
}


//void ThiTracNghiem(PTRQ &root, PTRSV &sv, monHoc *dsMH[], int soLuongMH, Lop lop)
//{
//    int x1,y1;
//    int check1;
//    int soCauThi=0;
//    int thoiGianThi=0;
//    int soCauDung=0;
//    diem tempDiem;
//    time_t now ;
//    tm *ltm;
//    int vitriMH=0;
//
//    VeKhungThi();
//    gotoxy(2,2);
//    cout<<"THONG TIN THI SINH";
//    gotoxy(2,3);
//    cout<<"Ho & Ten: "<<sv->info.HO<<" "<<sv->info.TEN;
//    gotoxy(2,4);
//    cout<<"MSSV: "<<sv->info.MASV;
//    gotoxy(2,5);
//    cout<<"Gioi tinh: "<<sv->info.PHAI;
//    gotoxy(90, 2);
//    cout<<"THI TRAC NGHIEM\n";
//    while(1)
//    {
//
//check_ttn:
//        gotoxy(2,7);
//        cout << "F1: Tim kiem      ESC: Thoat";
//        int checkMonHoc = inDanhSachMH(45,18,dsMH, soLuongMH,vitriMH);
//        if(checkMonHoc==ESC)
//        {
//            int xn=xacNhan(50, 5, "Ban co chac muon thoat khong?");
//            if(xn==YES)
//            {
//                system("cls");
//                return;
//            }
//            else
//            {
//                xoaThongBao();
//            }
//        }
//        else if(checkMonHoc==ENTER)
//        {
//            int checkDeThi;
//            int soCauHoi = demSoCauHoi(root, dsMH[vitriMH]->maMH);
//            if(soCauHoi == 0)
//            {
//                BaoLoi(50, 5, "Mon hoc chua co cau hoi!");
//                goto check_ttn;
//            }
//            if(checkMonThi(sv, dsMH[vitriMH]->maMH)==1)
//            {
//                BaoLoi(50, 5, "Ban da thi mon hoc nay roi!");
//                goto check_ttn;
//            }
//            xoaKhungThi();
//            int checkTTThi=nhapThongTinThi(xThi+37, yThi+5, root, dsMH[vitriMH]->maMH, soCauThi, thoiGianThi);
//            if(checkTTThi==ESC)
//            {
//                xoaKhungThi();
//                goto check_ttn;
//            }
//            xoaKhungThi();
//            int *dsCauHoi=new int[soCauHoi];
//			 layDSCauHoi(root, dsCauHoi, dsMH[vitriMH]->maMH, soCauHoi);
//            int *chon = new int[soCauThi];
//            int *deThi=randomCauHoi(dsCauHoi, soCauHoi, soCauThi);
//            delete []dsCauHoi;
//            BaoLoi(xTB, yTB, "Bat dau thi");
//            xoaKhungThi();
//            now =time(0);
//            ltm = localtime(&now);
//            gotoxy(2,6);
//            cout << "Ngay: "<< ltm->tm_mday  <<"/"<< 1 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year;
//            gotoxy(2,7);
//            cout<<"Thoi gian bat dau thi: "<< ltm->tm_hour <<":"<< ltm->tm_min <<":"<< ltm->tm_sec;
//            gotoxy(2,8);
//            cout<<"Mon thi: "<<dsMH[vitriMH]->maMH;
//            gotoxy(2,9);
//            cout<<"So cau thi: "<<soCauThi;
//            gotoxy(2,10);
//            cout << "F2: Nop bai    F1: Tim cau hoi";
//
//            XuatDeThi(40,15, root, deThi,chon, soCauDung, soCauThi, thoiGianThi);
//            xoaDapAn();
//            xoaHang(2, 7,33);
//            xoaHang(2, 8,33);
//            xoaHang(2, 9,33);
//            xoaHang(2, 10,33);
//            strcpy(tempDiem.maMH,dsMH[vitriMH]->maMH);
//            inDiem(soCauDung, soCauThi, tempDiem.mark);
//            system("pause");
//            if(strcmp(sv->info.MASV,"")!=0) // khong phai la giao vien thi lam
//            {
//                sv->info.TrangThaiThi++;
//                chitietdethi x=taoCTDT(dsMH[vitriMH]->maMH, deThi, chon, soCauThi);
//                tempDiem.CTDT=x;
//                insertLast(sv->info.Firstdiem, tempDiem);
//                save1Lop(lop);
//                SaveCauHoi(root);
//            }
//            delete []chon;
//            delete []deThi;
//            xoaKhungThi();
//        }
//        else continue;
//
//
//    }// end while
//
//    delete ltm;
//}
//void ThiTracNghiem(PTRQ &root, PTRSV &sv, monHoc *dsMH[], int soLuongMH, Lop lop){
//		int x1,y1;
//		int check1;
//		int soCauThi=0;
//		int thoiGianThi=0;
//		int soCauDung=0;
//		diem tempDiem;
//		time_t now ;
//		tm *ltm;
//		int vitriMH=0;
//		
//			VeKhungThi();
//			gotoxy(2,2);
//			cout<<"THONG TIN THI SINH";
//			gotoxy(2,3);
//			cout<<"Ho & Ten: "<<sv->info.HO<<" "<<sv->info.TEN;
//			gotoxy(2,4);
//			cout<<"MSSV: "<<sv->info.MASV;
//			gotoxy(2,5);
//			cout<<"Gioi tinh: "<<sv->info.PHAI;
//			gotoxy(90, 2);
//			cout<<"THI TRAC NGHIEM\n";
//		while(1)
//		{
//			
//			check_ttn:
//			gotoxy(2,7);
//			cout << "F1: Tim kiem      ESC: Thoat";
//			int checkMonHoc = inDanhSachMH(45,15,dsMH, soLuongMH,vitriMH);
//			if(checkMonHoc==ESC) {
//				int xn=xacNhan(50, 5, "Ban co chac muon thoat khong?");
//				if(xn==YES) {
//					system("cls");
//					save1Lop(lop);
//					SaveCauHoi(root);
//					return;
//				}
//				else {
//					xoaThongBao();
//				}
//			}
//			else if(checkMonHoc==ENTER){
//				int checkDeThi;
//					int soCauHoi = demSoCauHoi(root, dsMH[vitriMH]->maMH);
//					if(soCauHoi == 0) {
//						BaoLoi(50, 5, "Mon hoc chua co cau hoi!");
//						goto check_ttn;
//					}
//					if(checkMonThi(sv, dsMH[vitriMH]->maMH)==1){
//						BaoLoi(50, 5, "Ban da thi mon hoc nay roi!");
//						goto check_ttn;
//					}
//					xoaKhungThi();
//					int checkTTThi=nhapThongTinThi(xThi+37, yThi+5, root, dsMH[vitriMH]->maMH, soCauThi, thoiGianThi);
//					if(checkTTThi==ESC){
//						xoaKhungThi();
//						goto check_ttn;
//					}
//						xoaKhungThi();
//						int *dsCauHoi=new int[soCauHoi];
//						layDSCauHoi(root, dsCauHoi, dsMH[vitriMH]->maMH, soCauHoi);
//						int *chon = new int[soCauThi];
//						int *deThi=randomCauHoi(dsCauHoi, soCauHoi, soCauThi);
//						delete []dsCauHoi;
//						BaoLoi(xTB, yTB, "Bat dau thi");
//						xoaKhungThi();
//						 now =time(0);
//						ltm = localtime(&now);
//						gotoxy(2,6);
//						cout << "Ngay: "<< ltm->tm_mday  <<"/"<< 1 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year;
//						gotoxy(2,7);
//						cout<<"Thoi gian bat dau thi: "<< ltm->tm_hour <<":"<< ltm->tm_min <<":"<< ltm->tm_sec;
//						gotoxy(2,8);
//						cout<<"Mon thi: "<<dsMH[vitriMH]->maMH;
//						gotoxy(2,9);
//						cout<<"So cau thi: "<<soCauThi;
//						gotoxy(2,10);
//						cout << "F2: Nop bai    F1: Tim cau hoi";
//						
//						XuatDeThi(40,15, root, deThi,chon, soCauDung, soCauThi, thoiGianThi);
//						xoaDapAn();
//						xoaHang(2, 7,33);
//						xoaHang(2, 8,33);
//						xoaHang(2, 9,33);
//						xoaHang(2, 10,33);
//						strcpy(tempDiem.maMH,dsMH[vitriMH]->maMH);
//						inDiem(soCauDung, soCauThi, tempDiem.mark);
//						system("pause");
//						if(strcmp(sv->info.MASV,"")!=0){// khong phai la giao vien thi lam
//							sv->info.TrangThaiThi++;
//							chitietdethi x=taoCTDT(dsMH[vitriMH]->maMH, deThi, chon, soCauThi);
//							tempDiem.CTDT=x;
//							insertLast(sv->info.Firstdiem, tempDiem);
//							cout << sv->info.TrangThaiThi;
//							getch();
//						}
//						delete []chon;
//						delete []deThi;
//						xoaKhungThi();
//					}
//					else continue;
//
//			
//		}// end while
//	
//	delete ltm;
//}
void ThiTracNghiem(PTRQ &root, PTRSV &sv, monHoc *dsMH[], int soLuongMH, Lop lop){
		int x1,y1;
		int check1;
		int soCauThi=0;
		int thoiGianThi=0;
		int soCauDung=0;
		diem tempDiem;
		time_t now ;
		tm *ltm;
		int vitriMH=0;
		
			VeKhungThi();
			gotoxy(2,2);
			cout<<"THONG TIN THI SINH";
			gotoxy(2,3);
			cout<<"Ho & Ten: "<<sv->info.HO<<" "<<sv->info.TEN;
			gotoxy(2,4);
			cout<<"MSSV: "<<sv->info.MASV;
			gotoxy(2,5);
			cout<<"Gioi tinh: "<<sv->info.PHAI;
			gotoxy(90, 2);
			cout<<"THI TRAC NGHIEM\n";
		while(1)
		{
			
			check_ttn:
			gotoxy(2,7);
			cout << "ESC: Thoat";
			Normal();
			XoaKhung(58,13,83,28);
			int checkMonHoc = inDanhSachMH(40,20,dsMH, soLuongMH,vitriMH);
			if(checkMonHoc==ESC) {
				int xn=xacNhan(50, 5, "Ban co chac muon thoat khong?");
				if(xn==YES) {
					system("cls");
					return;
				}
				else {
					
					xoaHang(50,5,50);
					
				}
			}
			else if(checkMonHoc==ENTER){
				int checkDeThi;
					int soCauHoi = demSoCauHoi(root, dsMH[vitriMH]->maMH);
					if(soCauHoi == 0) {
						BaoLoi(50, 5, "Mon hoc chua co cau hoi!");
						goto check_ttn;
					}
					if(checkMonThi(sv, dsMH[vitriMH]->maMH)==1){
						BaoLoi(50, 5, "Ban da thi mon hoc nay roi!");
						goto check_ttn;
					}
					xoaKhungThi();
					int checkTTThi=nhapThongTinThi(xThi+37, yThi+5, root, dsMH[vitriMH]->maMH, soCauThi, thoiGianThi);
					if(checkTTThi==ESC){
						xoaKhungThi();
						goto check_ttn;
					}
						xoaKhungThi();
						int *dsCauHoi= new int[soCauHoi];
						layDSCauHoi(root,dsCauHoi, dsMH[vitriMH]->maMH, soCauHoi);
						int *chon = new int[soCauThi];
						int *deThi=randomCauHoi(dsCauHoi, soCauHoi, soCauThi);
						delete []dsCauHoi;
						BaoLoi(xTB, yTB, "Bat dau thi");
						xoaKhungThi();
						 now =time(0);
						ltm = localtime(&now);
						gotoxy(2,6);
						cout << "Ngay: "<< ltm->tm_mday  <<"/"<< 1 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year;
						gotoxy(2,7);
						cout<<"Thoi gian bat dau thi: "<< ltm->tm_hour <<":"<< ltm->tm_min <<":"<< ltm->tm_sec;
						gotoxy(2,8);
						cout<<"Mon thi: "<<dsMH[vitriMH]->maMH;
						gotoxy(2,9);
						cout<<"So cau thi: "<<soCauThi;
						gotoxy(2,10);
						cout << "F2: Nop bai    F1: Tim cau hoi";
						
						XuatDeThi(40,15, root, deThi,chon, soCauDung, soCauThi, thoiGianThi);
						xoaDapAn();
						xoaHang(2, 7,33);
						xoaHang(2, 8,33);
						xoaHang(2, 9,33);
						xoaHang(2, 10,33);
						strcpy(tempDiem.maMH,dsMH[vitriMH]->maMH);
						inDiem(soCauDung, soCauThi, tempDiem.mark);
						system("pause");
						if(strcmp(sv->info.MASV,"")!=0){// khong phai la giao vien thi lam
							sv->info.TrangThaiThi++;
							chitietdethi x=taoCTDT(dsMH[vitriMH]->maMH, deThi, chon, soCauThi);
							tempDiem.CTDT=x;
							insertLast(sv->info.Firstdiem, tempDiem);
							save1Lop(lop);
							SaveCauHoi(root);
						}
						delete []chon;
						delete []deThi;
						xoaKhungThi();
					}
					else continue;

			
		}// end while
	
	delete ltm;
}
chitietdethi taoCTDT(char *maMH, int *deThi, int *chon, int soCauThi)
{
    chitietdethi x;
    x.SoCauThi = soCauThi;
    x.IDCauThi=new int[soCauThi];
    x.CauTraLoi=new char[soCauThi];
    for(int i=0; i<soCauThi; i++)
    {
        x.IDCauThi[i]=deThi[i];
        x.CauTraLoi[i] = doiChon(chon[i]);
    }
    return x;
}
int xoa1Lop(DanhSachLop &ds, int &vitriLop)
{

    if(ds.n<=0) return 0;
    if(vitriLop<0)// xoa dau
        vitriLop=0;
    if(vitriLop>=ds.n) // xoacuoi
        vitriLop=ds.n-1;
    for(int i=vitriLop; i<ds.n-1; i++)
        ds.lop[i]=ds.lop[i+1];
    if(vitriLop==ds.n-1 && ds.n!=1) vitriLop--;
    ds.n--;
    return 1;
}
bool timSinhVien(DanhSachLop ds, char *masv)
{
    for(int i=0; i<ds.n; i++)
    {
        for(PTRSV p=ds.lop[i].FirstSinhVien; p!=NULL; p=p->next)
            if(strcmp(masv,"")!=0 && stricmp(p->info.MASV,masv)==0) return true;
    }
    return false;
}
int them1Lop(DanhSachLop &ds, int &vitriMang)
{
    xoaKhungLamViec();
    int cotTextField = 45,y=20;
    int soKhung = 3;
    int dai=30, rong = 2;
    veKhung(cotTextField-15,y-2, dai+25, 23);
    // ve Khung nhap
    gotoxy(53,y+1);
    cout << "THEM LOP";
    // ve Khung nhap
    Lop temp;
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
    char labelSV[][20]= {"Ma lop:", "Ten lop:","THEM"};
    veKhungTextField(cotTextField, y, dai, rong, pos, soKhung,labelSV);
    char kytu;
    int vitri=0;
    int dichuyen;
    int trangThai=0;
    while(true)
    {
        switch(vitri)
        {
        case 0:// nhap ma sinh vien khong cach
        {
            hienConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            dichuyen=nhapChuoiKC(cotTextField+1, pos[vitri], dai-1, text[vitri],9);
            Normal();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            // kiem tra xem ma da co chua neu co roi thi thong bao da co roi

            if(strlen(text[vitri]) < 9)
            {
                xoaHang(cotTextField, pos[vitri]-2,25);
                gotoxy(cotTextField, pos[vitri]-2);
                textcolor(160);
                cout << "Ma lop co 9 ki tu";
                kt[vitri]=false;
                Normal();
            }
            else
            {
                int checkLop=timLop(ds, text[vitri]);
                if(checkLop==-1)
                {
                    xoaHang(cotTextField, pos[vitri]-2,25);
                    kt[vitri]=true;
                }
                else
                {
                    kt[vitri]=false;
                    gotoxy(cotTextField, pos[vitri]-2);
                    textcolor(160);
                    cout << "Ma lop da ton tai";
                    Normal();
                }
            }
            break;
        }
        case 1:// nhap ten
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri],40);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            int checktenLop=timTenLop(ds, text[vitri]);
                if(checktenLop==-1)
                {
                    xoaHang(cotTextField, pos[vitri]-5,25);
                    kt[vitri]=true;
                }
                else
                {
                    kt[vitri]=false;
                    gotoxy(cotTextField, pos[vitri]-5);
                    textcolor(160);
                    cout << "Ten lop da ton tai";
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
                        if(kt[0]==false)
                        {
                            BaoLoi(xTB, yTB, "Ma lop khong hop le!");
                            vitri=-1;
                            dichuyen=Down;
                            break;
                        }
                        if(kt[1]==false)
                        {
                            BaoLoi(xTB, yTB, "Ten lop khong hop le!");
                            vitri=0;
                            dichuyen=Down;
                            break;
                        }

                    }
                    else
                    {
                        temp.FirstSinhVien=NULL;
                        strcpy(temp.MaLop, text[0]);
                        strcpy(temp.TenLop, text[1]);
                        themDSLop(ds, temp, vitriMang);
                        BaoLoi(xTB, yTB, "Them lop thanh cong");
                        dichuyen=Down;
                        for(int i=0; i<soKhung-1; i++)
                        {
                            xoaHang(cotTextField+1, pos[i], dai-1);
                            strcpy(text[i], "");
                            trangThai=0;
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
            veKhungNho(cotTextField+6,pos[2]-1,7,1);
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
int sua1Lop( DanhSachLop &ds, int &vitriMang)  // kiem tra ma sv bi trung va neu thi roi thi khong sua duoc vi thi roi la chac chan dung du lieu roi
{
    int cotTextField = 45, y=yLamViec+1;
    int soKhung = 3;
    int dai=25, rong = 2;
    // ve Khung nhap

    // ve Khung nhap
    int pos[soKhung-1];
    bool kt[soKhung-1];
    char text[2][51] ;
    char tenLop[51];
    strcpy(text[0],ds.lop[vitriMang].MaLop);
    strcpy(text[1],ds.lop[vitriMang].TenLop);
    strcpy(tenLop, text[1]);
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=true;
    }
    kt[0]=true;
    char labelSV[][20]= {"SUA LOP","Ma lop:", "Ten lop:","SUA"};
    //veKhungTextField(cotTextField, y, dai, rong, pos, soKhung,labelSV);
    khungSuaSinhVien(text, cotTextField, y, dai, rong, pos, soKhung,labelSV);
    xoaHang(cotTextField+1, pos[1], dai-1);
    gotoxy(cotTextField+1, pos[1]);
    inString(text[1], dai-1);
    char kytu;
    int vitri=1;
    int dichuyen;
    while(true)
    {
        switch(vitri)
        {

        case 1:// nhap ten lop
        {
            hienConTro();
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri],50);
            if(stricmp(text[vitri], tenLop)!=0 && timTenLop(ds, text[vitri])!=-1)
            {
                xoaHang(cotTextField, pos[0]-2,25);
                gotoxy(cotTextField, pos[0]-2);
                textcolor(160);
                cout << "Ten lop da ton tai";
                kt[vitri]=false;
                Normal();
            }
            else
            {
                xoaHang(cotTextField, pos[0]-2,25);
                kt[vitri]=true;
            }
            Normal();
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            break;
        }

        case 2: // sua
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+((dai-strlen(labelSV[soKhung]))/2)-1,pos[vitri]-1,strlen(labelSV[soKhung])+2,1);
            Normal();
            do
            {
                char c=getch();
                if(c==ENTER)
                {
                    if(ktTextField(kt,soKhung-1)==false)
                    {
                        BaoLoi(xTB, yTB, "Ten lop khong hop le!");
                        dichuyen=Down;
                        break;
                    }
                    else
                    {
                        strcpy(ds.lop[vitriMang].TenLop, text[1]);
                        capNhatDSLop(ds, vitriMang);
                        BaoLoi(xTB, yTB, "Sua lop thanh cong");
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
                if(c==ESC) return ESC;
            }
            while(true);
            veKhungNho(cotTextField+((dai-strlen(labelSV[soKhung]))/2)-1,pos[vitri]-1,strlen(labelSV[soKhung])+2,1);
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
int timLop(DanhSachLop ds, char *maLop)
{
    for(int i=0; i<ds.n; i++)
    {
        if(strcmp(maLop,"")!=0 && stricmp(ds.lop[i].MaLop, maLop)==0) return i;
    }
    return -1;
}
int timTenLop(DanhSachLop ds, char *tenLop)
{
    for(int i=0; i<ds.n; i++)
    {
        if(strcmp(tenLop,"")!=0 && stricmp(ds.lop[i].TenLop, tenLop)==0) return i;
    }
    return -1;
}
//int timTenLop(DanhSachLop ds, char *tenLop)
//{
//    for(int i=0; i<ds.n; i++)
//    {
//        if(strcmp(tenLop,"")!=0 && stricmp(ds.lop[i].TenLop, tenLop)==0) return i;
//    }
//    return -1;
//}
void diChuyenBangDiem(int vtThongTin[], char *maMH,int y, sinhvien dssv[], int n, int &vitriHT,int oToiDa,int trangThai)
{

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
    gotoxy(vtThongTin[6]-3, y+chon);
    PTRD p=timDiem(dssv[vitriHT].Firstdiem, maMH);
    if(p!=NULL)
        cout << p->info.mark;
    else cout << "Chua thi";

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
    p=timDiem(dssv[vitriHT].Firstdiem, maMH);
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
    gotoxy(vtThongTin[6]-3, y+chon);
    if(p!=NULL)
        cout << p->info.mark;
    else cout << "Chua thi";

}
int Xuat1CauHoiSV(PTRQ root, int id, char luaChon, int thutu)
{
    xoaKhungDeThi();
    int sodapan = 4;
    int chon=	doiChon2(luaChon);
    int *posy = new int[sodapan];
    int temp=0;
    PTRQ p = search(root,id);
    char dapAnDung = p->info.dapan;
    string DapAn[4] ;
    DapAn[0]=p->info.A;
    DapAn[1]=p->info.B;
    DapAn[2]=p->info.C;
    DapAn[3]=p->info.D;


    gotoxy(xCTDT+5,yCTDT+3);
    cout << "Cau " << thutu+1 <<":"<< p->info.noidung ;
    gotoxy(xCTDT, wherey()+1);
    for (int i=0; i < sodapan ; i++)
    {
        posy[i] = wherey()+1;
        gotoxy(xCTDT+5, posy[i]);

        cout << doiChon(i) <<". ";
        inNoiDung(DapAn[i],70);
    }
    //hightligt dap an ngta dchon
    if(chon!=4)
    {
        textcolor(4);
        gotoxy(xCTDT+5, posy[chon]);
        cout << doiChon(chon)<<". ";
        inNoiDung(DapAn[chon],70);

    }
    textcolor(10);
    gotoxy(xCTDT+5, posy[doiChon2(dapAnDung)]);
    cout << dapAnDung <<". ";
    inNoiDung(DapAn[doiChon2(dapAnDung)], 70);
    Normal();
    gotoxy(xCTDT+5, posy[3]+3);
    cout << "DAP AN DUNG: " << dapAnDung;
    gotoxy(xCTDT+5, posy[3]+4);
    cout << "DAP AN CHON: " << luaChon;
    delete []posy;
}
int XuatDeThiSV( PTRSV sv, PTRQ root, char *maMH)
{
    xoaKhungLamViec();
    xoaChucNang();
    veKhungDeThi();
    veKhungNho(xLamViec+2, yLamViec+2, 30, 5);
    inTTSV(xLamViec+4, yLamViec+4, sv, maMH);
    gotoxy(xLamViec+37, yLamViec+3);
    cout << "DANH SACH CAC CAU HOI DA THI CUA SINH VIEN";
    int id=0;
    PTRD p=timDiem(sv->info.Firstdiem, maMH);
    int soCauThi=p->info.CTDT.SoCauThi;
    Xuat1CauHoiSV(root, p->info.CTDT.IDCauThi[id],  p->info.CTDT.CauTraLoi[id], id);
    char kytu;
    do
    {
        if(kbhit())
        {
            kytu=getch();
            if(kytu==0) kytu=getch();
            switch(kytu)
            {
            case LEFT:
            {
                if(id==0) id=soCauThi-1;
                else id--;
                Xuat1CauHoiSV(root, p->info.CTDT.IDCauThi[id],  p->info.CTDT.CauTraLoi[id], id);
                break;
            }
            case RIGHT:
            {
                if(id==soCauThi-1) id=0;
                else id++;
                Xuat1CauHoiSV( root, p->info.CTDT.IDCauThi[id],  p->info.CTDT.CauTraLoi[id], id);
                break;
            }
            case ESC:
                return ESC;
            }
        }
    }
    while(1);
}


void inBangDiem(int vtThongTin[], int y, sinhvien ds[], int n, char *maLop, char *maMH, int vitriHL, int oToiDa)
{
    if(n==0 || vitriHL >= n) return;
    PTRD p;
    int trangHienTai=vitriHL/oToiDa;
    int chon=vitriHL-(trangHienTai*oToiDa);
    int soTrang;
    if(n%oToiDa==0)	soTrang=n/oToiDa-1;
    else soTrang=n/oToiDa;
    xoaKhungLamViec();
    gotoxy(40, y-5);
    cout << "DANH SACH DIEM THI LOP " << maLop << " MON " << maMH;
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
    cout << maMH;
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
        gotoxy(vtThongTin[6]-3, wherey());
        p=timDiem(ds[i].Firstdiem, maMH);
        if(p!=NULL)
            cout << p->info.mark;
        else cout << "Chua thi";
    }
    p=timDiem(ds[vitriHL].Firstdiem, maMH);
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
    gotoxy(vtThongTin[6]-3, y+chon);
    if(p!=NULL)
        cout << p->info.mark;
    else cout << "Chua thi";
    ThongBaoTrang(trangHienTai+1, soTrang+1);
}
int inDiemSV(Lop lop, char *maMH, PTRQ root)
{
    Normal();
    int vitriMang=0;
    int oToiDa = 20;
    int chon=0;
    selectionSort(lop.FirstSinhVien);
    int pos[7];
    pos[0]=xLamViec+10; //stt 5
    pos[1]=pos[0]+6;//masv 15
    pos[2]=pos[1]+15; // ho sinh vien 50
    pos[3]=pos[2]+35;// ten 10
    pos[4]=pos[3]+14;// phai
    pos[5]=pos[4]+6;// password
    pos[6]=pos[5]+15;// maMH
    int y=yLamViec+6;
    int n=demSinhVien(lop.FirstSinhVien);
    sinhvien *dssv=new sinhvien[n];
    //  chuyen du lieu tu firstsv sang mang tuyen tinh de in ra va chon
    dslkSangMangSV(lop.FirstSinhVien, dssv);
    inBangDiem(pos, y, dssv, n, lop.MaLop, maMH, vitriMang, oToiDa);
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
            char maSV[11]="";
            while(1)
            {
                int timKiem=khungTimKiem(xTB, yTB-1, maSV, 30, 10, "Nhap ma sv");
                if(timKiem==Down) // ==ENTER
                {
                    PTRSV tempSV=searchStudent(lop.FirstSinhVien, maSV);
                    if(tempSV==NULL)
                    {
                        xoaThongBao();
                        BaoLoi(xTB, yTB, "Khong tim thay sinh vien");
                    }
                    else
                    {
                        vitriMang=timKiemMangSV(dssv, n, maSV);
                        inBangDiem(pos, y, dssv, n, lop.MaLop, maMH, vitriMang, oToiDa);
                        break;
                    }
                }
                if(timKiem==ESC) break;
            }
            xoaThongBao();
            break;
        }
        case LEFT:
        {

            if(n<=oToiDa) break; // neu chi co 1 trang thi khoi left or right
            else
            {

                int tempVt=(vitriMang/oToiDa)*oToiDa;
                if(tempVt < oToiDa) break;
                else
                {
                    vitriMang=tempVt-oToiDa;
                    chon=0;
                    inBangDiem(pos, y, dssv, n, lop.MaLop,maMH, vitriMang, oToiDa);
                }
                break;
            }

        }
        case RIGHT:
        {

            if(n<=oToiDa) break;
            else
            {
                int tempVt=(vitriMang/oToiDa)*oToiDa; // lay vi tri dau tien vd 45 se ve 40 dung temp vi tranh thay doi vitriMang
                if(tempVt > n-oToiDa) break; // kiem tra neu khong right duoc nua thi break
                else
                {
                    vitriMang=tempVt+oToiDa; // neu left duoc thi ta tru chon oToiDa de lui
                    inBangDiem(pos, y, dssv, n,lop.MaLop, maMH, vitriMang, oToiDa);
                    chon=0;
                }
                break;
            }
        }
        case Up :
            if (vitriMang%oToiDa > 0) // lay hang
            {
                diChuyenBangDiem(pos,maMH,y,dssv,n,vitriMang,oToiDa, Up);

            }
            break;
        case Down :
            if (vitriMang%oToiDa  < oToiDa-1  && vitriMang < n-1)// lay hang
            {
                diChuyenBangDiem(pos,maMH, y,dssv,n,vitriMang,oToiDa, Down);
            }
            break;
        case ESC:
            return ESC;
        case ENTER: // in cau truc de thi
        {
            PTRSV tempSV=searchStudent(lop.FirstSinhVien, dssv[vitriMang].MASV);
            if(tempSV->info.Firstdiem==NULL) BaoLoi(xTB, yTB, "Sinh vien nay chua thi");
            else
            {
                XuatDeThiSV( tempSV,root, maMH);
                inBangDiem(pos, y, dssv, n, lop.MaLop,maMH, vitriMang, oToiDa);
            }

            break;
        }
        }  // end switch
    }
    while (1);
}
void suaSinhVien(DanhSachLop &ds)
{
    int vitriLop=0;
    char c;
    while(1) //
    {
ktDanhSachLop:
        xoaChucNang();
        xoaKhungLamViec();

        if(ds.n==0)
        {
            phimChucNang("F2-Them lop");
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
                        them1Lop(ds, vitriLop);
                        xoaThongBao();
                        break;
                    }
                }
                if(c==ESC)// thoat ds lop tro ve menu chinh
                {
                    xoaKhungLamViec();
                    xoaChucNang();
                    return;
                }
            }

        }
        else // ds.n > 0 in danh sach lop
        {
            phimChucNang(cnSV);
            while(1)
            {

                xoaKhungLamViec();
                switch(inDanhSachLop(ds, vitriLop))
                {
                case ESC:
                {
                    xoaChucNang();
                    xoaKhungLamViec();
                    return;
                }
                case F2:
                {
                    xoaKhungLamViec();
                    them1Lop(ds, vitriLop);
                    break;
                }
                case F3:
                {
                    xoaKhungLamViec();
                    sua1Lop(ds, vitriLop);
                    break;
                }
                case F4:
                {
                    int soSV=demSinhVien(ds.lop[vitriLop].FirstSinhVien);
                    if(soSV>0)
                    {
                        BaoLoi(xTB, yTB, "Lop nay da co sinh vien khong xoa duoc");
                    }
                    else
                    {
                        int xn=xacNhan(xTB, yTB, "Ban co chac muon xoa lop nay khong? ");
                        if(xn==YES) xoa1Lop(ds, vitriLop);
                    }
                    break;
                }
                case ENTER:
                {
                	sinhvien *dssv;
                	int soLuongSV, vitriSV;
                	soLuongSV=demSinhVien(ds.lop[vitriLop].FirstSinhVien);
                    while(true)
                    {
ktDanhSachSV:
                        xoaKhungLamViec();
                        viethoa(ds.lop[vitriLop].MaLop);
                        if(soLuongSV==0)
                        {
							vitriSV=0;
                            phimChucNang("F2-Them sinh vien");
                            BaoLoi(xTB, yTB, "Danh sach sinh vien lop nay rong!");
                            while(true)
                            {
                                c=getch();
                                if(c==0)
                                {
                                    c=getch();
                                    if(c==F2) // them lop neu ds rong
                                    {
                                    	dssv=new sinhvien[1];
                                        xoaChucNang();
                                        gotoxy(55, yLamViec+1);
                                        cout << "LOP " << ds.lop[vitriLop].MaLop;
                                        them1SinhVien(ds, ds.lop[vitriLop].FirstSinhVien, dssv, soLuongSV, vitriSV);// them xong tro lai bang sinh vien
                                        xoaThongBao();
                                        break;
                                    }
                                }
                                if(c==ESC) // thoat bang sv ra bang lop
                                {
                                    xoaKhungLamViec();
                                    goto ktDanhSachLop;
                                }
                            }
                        }
                        else // co ng trong lop roi
                        {
                        	
							dssv=new sinhvien[MAXSVLOP];
                        	vitriSV=0;
    						//  chuyen du lieu tu firstsv sang mang tuyen tinh de in ra va chon
    						dslkSangMangSV(ds.lop[vitriLop].FirstSinhVien, dssv);
    						ktDanhSachSV2:
                            phimChucNang(cnSV);
                            int checkSV=0;
                            while(1)
                            {
                                xoaKhungLamViec();
                                anConTro();
                                switch(inDanhSachSV(ds.lop[vitriLop], dssv, soLuongSV, vitriSV))
                                {
                                case ESC:
                                {
                                    checkSV=ESC;
                                    break;
                                }
                                case F2:
                                {
                                	
                                    xoaKhungLamViec();
                                    gotoxy(55, yLamViec+1);
                                    if(soLuongSV==MAXSVLOP) {
                        				BaoLoi(xTB, yTB, "Da du 150 sinh vien khong the them!");
                        				
									}
									else{
										cout << "LOP " << ds.lop[vitriLop].MaLop;
                                    	them1SinhVien(ds, ds.lop[vitriLop].FirstSinhVien, dssv, soLuongSV, vitriSV);
									}
                                    
                                    goto ktDanhSachSV2;
                                }
                                case F4: // danh sach bi rong
                                {
                                    goto ktDanhSachSV;
                                }
                                }
                                if(checkSV==ESC) break;
                            }
                            break;
                        }
                    }
                    break;
                }
                }
            }
        }
    }
}
int them1SinhVien(DanhSachLop ds, PTRSV &firstSV, sinhvien *&dssv, int &soLuongSV, int &vitriSV)// danh sach de tra cuu ma sv
{
	
    int cotTextField = 50, y=yLamViec+1;
    int soKhung = 6;
    int dai=25, rong = 2;

    // ve Khung nhap

    int pos[6];
    bool kt[5];
    char *text[5];
    for(int i=0; i<5; i++)
    {
        text[i] = new char[100];
        strcpy(text[i], "");
    }
    for(int i=0; i<5; i++)
    {
        kt[i]=false;
    }
    khungThemSinhVien(cotTextField, y, dai, rong, pos, soKhung,truongThemSV);
    char kytu;
    int vitri=0;
    int dichuyen;
    int trangThai=0;
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

            if(strlen(text[vitri]) < 10)
            {
                xoaHang(cotTextField, pos[vitri]-2,25);
                gotoxy(cotTextField, pos[vitri]-2);
                textcolor(160);
                cout << "Ma sinh vien co 10 ki tu";
                kt[vitri]=false;
                Normal();
            }
            else
            {
                if(timSinhVien(ds, text[vitri]))
                {
                    xoaHang(cotTextField, pos[vitri]-2,25);
                    gotoxy(cotTextField, pos[vitri]-2);
                    textcolor(160);
                    cout << "Ma sv da ton tai";
                    kt[vitri]=false;
                    Normal();
                }
                else
                {
                    xoaHang(cotTextField, pos[vitri]-2,25);
                    kt[vitri]=true;
                }
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
            break;
        }
        case 2://Nhap ten
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapChuoiBT(cotTextField+1, pos[vitri], dai-1, text[vitri],10);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
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
            kt[vitri]=true;
            break;
        }
        case 4: // nhap dang password
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapPassword(cotTextField+1, pos[vitri], dai-1, text[vitri], trangThai,6);
            if(strcmp(text[vitri],"")!=0) kt[vitri]=true;
            else kt[vitri]=false;
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            break;
        }
        case 5: // add
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+(dai-strlen(truongThemSV[soKhung]))/2-1,pos[vitri]-1,(strlen(truongThemSV[soKhung])+2),1);
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
                            BaoLoi(xTB, yTB, "Ma so sinh vien khong hop le!");
                            break;
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
                        sinhvien x = newSinhVien(text[0],text[1],text[2], text[3], text[4]);
                        insertOrder(firstSV, x);
                        themDSSV(dssv, soLuongSV, x, vitriSV);
                        BaoLoi(xTB, yTB, "Them sinh vien thanh cong");
                        if(soLuongSV==MAXSVLOP) {
                        	BaoLoi(xTB, yTB, "Da du 150 sinh vien khong the them"); 
							return ESC;
						}
                        dichuyen=Down;
                        for(int i=0; i<soKhung-1; i++)
                        {
                            xoaHang(cotTextField+1, pos[i], dai-1);
                            strcpy(text[i], "");
                            trangThai=0;
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
            veKhungNho(cotTextField+(dai-strlen(truongThemSV[soKhung]))/2-1,pos[5]-1,(strlen(truongThemSV[soKhung])+2),1);
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
void inDanhSachDiem(DanhSachLop ds, monHoc *dsMH[], int soLuongMH, PTRQ root)
{
    int vitriLop=0;
    while(1)
    {
        if(ds.n==0)
        {
            BaoLoi(xTB, yTB, "Danh sach lop rong!");
            break;
        }
        else
        {
            int checkLop=inDanhSachLop(ds, vitriLop);
            if(checkLop==ESC)
            {
                xoaKhungLamViec();
                break;
            }
            if(checkLop==ENTER)
            {
                if(ds.lop[vitriLop].FirstSinhVien==NULL) BaoLoi(xTB, yTB, "Danh sach rong!");
                else
                {
                    int vitriMH=0;
                    while(1)
                    {
                        xoaKhungLamViec();
                        gotoxy(50, yLamViec+5);
                        cout << ds.lop[vitriLop].MaLop;
                        int checkMH=inDanhSachMH(xLamViec, yLamViec+6,dsMH, soLuongMH, vitriMH);
                        if(checkMH==ESC)
                        {
                            xoaKhungLamViec();
                            break;
                        }
                        if(checkMH==ENTER)
                        {
                            xoaKhungLamViec();
                            int checkSV=inDiemSV(ds.lop[vitriLop], dsMH[vitriMH]->maMH, root);
                            if(checkSV==ESC) xoaKhungLamViec();
                        }
                    }
                }
            }
        }
    }
}
int inDanhSachLop(DanhSachLop ds,int &vitriMang)
{
    // in toi da 10 lop neu lon hon se chay xuong
    // b1: in ra so lop < 10
    Normal();
    xoaKhungLamViec();
    anConTro();
    int x1=xLamViec+23;
    int y=yLamViec+6;
    int x2=x1+12;
    int x3=x2+17;
    int oToiDa = 20;
    int trangHienTai=vitriMang/oToiDa;
    int chon=vitriMang%oToiDa;
    // b1: in ra so lop < 10 theo trang
    int soTrang;
    if(ds.n%oToiDa==0)	soTrang=ds.n/oToiDa-1;
    else soTrang=ds.n/oToiDa;
    gotoxy(xLamViec+50, yLamViec+1);
    cout << "DANH SACH LOP";
    veBangLop(x1-3,y-4,oToiDa);
    gotoxy(x1, y-3);
    cout << "STT";
    gotoxy(x2, y-3);
    cout << "Ma Lop";
    gotoxy(x3, y-3);
    cout << "Ten Lop";
    gotoxy(x1, wherey()+2);
    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<ds.n; i++)
    {
        gotoxy(x1, wherey()+1);
        cout << i+1;
        gotoxy(x2, wherey());
        cout << ds.lop[i].MaLop;
        gotoxy(x3, wherey());
        cout << ds.lop[i].TenLop;
    }
    // b2: highlight lop dua vao vi tri mang


    HighLight2(x1-3, y+chon);
    gotoxy(x1, y+chon);
    cout << vitriMang+1;
    gotoxy(x2, y+chon);
    cout << ds.lop[vitriMang].MaLop;
    gotoxy(x3, y+chon);
    cout << ds.lop[vitriMang].TenLop;
    ThongBaoTrang(trangHienTai+1, soTrang+1);


    // b2: highlight lop dau tien
    char kytu;
    do
    {
        kytu = getch();
        if (kytu == 0) kytu = getch();
        switch (kytu)
        {
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
                    gotoxy(x1, y-3);
                    cout << "STT";
                    gotoxy(x2, y-3);
                    cout << "Ma Lop";
                    gotoxy(x3, y-3);
                    cout << "Ten Lop";
                    gotoxy(x1, wherey()+2);
                    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<ds.n; i++)
                    {
                        gotoxy(x1, wherey()+1);
                        cout << i+1;
                        gotoxy(x2, wherey());
                        cout << ds.lop[i].MaLop;
                        gotoxy(x3, wherey());
                        cout << ds.lop[i].TenLop;
                    }
                    // b2: highlight lop dau tien

                    HighLight2(x1-3, y);
                    gotoxy(x1, y);
                    cout << trangHienTai*oToiDa+1;
                    gotoxy(x2, y);
                    cout << ds.lop[trangHienTai*oToiDa].MaLop;
                    gotoxy(x3, y);
                    cout << ds.lop[trangHienTai*oToiDa].TenLop;

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
                    gotoxy(x1, y-3);
                    cout << "STT";
                    gotoxy(x2, y-3);
                    cout << "Ma Lop";
                    gotoxy(x3, y-3);
                    cout << "Ten Lop";
                    gotoxy(x1, wherey()+2);
                    for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<ds.n; i++)
                    {
                        gotoxy(x1, wherey()+1);
                        cout << i+1;
                        gotoxy(x2, wherey());
                        cout << ds.lop[i].MaLop;
                        gotoxy(x3, wherey());
                        cout << ds.lop[i].TenLop;
                    }
                    // b2: highlight lop dau tien

                    HighLight2(x1-3, y);
                    gotoxy(x1, y);
                    cout << trangHienTai*oToiDa+1;
                    gotoxy(x2, y);
                    cout << ds.lop[trangHienTai*oToiDa].MaLop;
                    gotoxy(x3, y);
                    cout << ds.lop[trangHienTai*oToiDa].TenLop;
                    ThongBaoTrang(trangHienTai+1, soTrang+1);
                }
            }
            break;
        }
        case Up :
            if (chon  > 0)
            {
                int vitri=trangHienTai*oToiDa;
                Normal2(x1-3,y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds.lop[chon+vitri].MaLop;
                gotoxy(x3, y+chon);
                cout << ds.lop[chon+vitri].TenLop;
                chon --;
                HighLight2(x1-3, y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds.lop[chon+vitri].MaLop;
                gotoxy(x3, y+chon);
                cout << ds.lop[chon+vitri].TenLop;
            }
            break;
        case Down :
            if (chon  < oToiDa-1 )
            {
                int vitri=trangHienTai*oToiDa;
                Normal2(x1-3,y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds.lop[chon+vitri].MaLop;
                gotoxy(x3, y+chon);
                cout << ds.lop[chon+vitri].TenLop;
                if((chon+vitri)<(ds.n-1))
                {
                    chon ++;
                }
                HighLight2(x1-3, y+chon);
                gotoxy(x1, y+chon);
                cout << chon+vitri+1;
                gotoxy(x2, y+chon);
                cout << ds.lop[chon+vitri].MaLop;
                gotoxy(x3, y+chon);
                cout << ds.lop[chon+vitri].TenLop;


            }

            break;
        case ESC:
            return ESC;
        case F1:// tim kiem lop hoc
        {
            // search bang ma
            char maLop[11]="";
            while(1)
            {

                int timKiem=khungTimKiem(xTB, yTB-1, maLop, 30, 10, "Nhap ma lop");
                if(timKiem==Down) // ==ENTER
                {
                    vitriMang=timLop(ds, maLop);
                    if(vitriMang==-1)
                    {
                        xoaThongBao();
                        BaoLoi(xTB, yTB, "Khong tim thay lop");

                    }
                    else
                    {
                        trangHienTai=vitriMang/oToiDa;
                        chon=vitriMang%oToiDa;
                        xoaKhungLamViec();
                        veBangLop(x1-3,y-4,oToiDa);
                        gotoxy(x1, y-3);
                        cout << "STT";
                        gotoxy(x2, y-3);
                        cout << "Ma Lop";
                        gotoxy(x3, y-3);
                        cout << "Ten Lop";
                        gotoxy(x1, wherey()+2);
                        for(int i=trangHienTai*oToiDa; i<((trangHienTai+1)*oToiDa) && i<ds.n; i++)
                        {
                            gotoxy(x1, wherey()+1);
                            cout << i+1;
                            gotoxy(x2, wherey());
                            cout << ds.lop[i].MaLop;
                            gotoxy(x3, wherey());
                            cout << ds.lop[i].TenLop;
                        }
                        // b2: highlight lop dua vao vi tri mang
                        HighLight2(x1-3, y+chon);
                        gotoxy(x1, y+chon);
                        cout << vitriMang+1;
                        gotoxy(x2, y+chon);
                        cout << ds.lop[vitriMang].MaLop;
                        gotoxy(x3, y+chon);
                        cout << ds.lop[vitriMang].TenLop;
                        ThongBaoTrang(trangHienTai+1, soTrang+1);
                        break;
                    }
                }
                if(timKiem==ESC) break;
            }
            xoaThongBao();
            break;
        }
        case F2:
            return F2;//them
        case F4:
            vitriMang=chon+trangHienTai*oToiDa;
            return F4;// xoa
        case F3:
            vitriMang=chon+trangHienTai*oToiDa;
            return F3;
        case 13:
            vitriMang=chon+trangHienTai*oToiDa;
            return ENTER;

        }  // end switch
    }
    while (1);
}
int Full_List(DanhSachLop ds)
{
    return (ds.n == MAXLOP ? TRUE : FALSE);
}
int Empty_List(DanhSachLop ds)
{
    return (ds.n == 0 ? TRUE : FALSE);
}
Lop *searchClass(DanhSachLop ds, char *MaLop)
{
    int i;
    Lop *result;
    for(i = 0; i < ds.n && strcasecmp(MaLop, ds.lop[i].MaLop) != 0; ++i);
    return (i==ds.n?result=NULL:result=&ds.lop[i]);
}
void dichPhai(DanhSachLop &ds, int i)
{
    int x, y;
    for(int j = ds.n; j > i ; --j)
    {
        ds.lop[j] = ds.lop[j - 1];
    }
    ++ds.n;
}
void themDSLop(DanhSachLop &ds, Lop Class, int &vitriLop)
{
    int i;
    for (i = 0; i < ds.n; ++i)
    {
        if(stricmp(Class.TenLop, ds.lop[i].TenLop) < 0)
        {
            dichPhai(ds, i);
            ds.lop[i] = Class;// them vao ma lop vua lon hon
            vitriLop=i;
            break;
        }
    }
    if(i == ds.n)		//Cuoi danh sach , khong co ma lop nao lon hon class
    {
        ds.lop[ds.n] = Class;
        vitriLop=ds.n;
        ds.n++;
    }
}

void capNhatDSLop(DanhSachLop &ds, int &vitriLop)
{
    Lop temp=ds.lop[vitriLop];
    xoa1Lop(ds, vitriLop);
    themDSLop(ds, temp, vitriLop);
}
int checkMaLop(DanhSachLop ds, char *maLop)
{
    for(int i=0; i<ds.n; i++)
    {
        if(stricmp(ds.lop[i].MaLop, maLop)==0) return i;
    }
    return -1;
}
int demSV(Lop lop)
{
    int count = 0;
    for(PTRSV p=lop.FirstSinhVien; p!=NULL; p=p->next) count++;
    return count;
}
void suaLop(DanhSachLop &ds)
{
    int vitriLop=0;
    while(1) //
    {
        anConTro();
        phimChucNang("ESC:Tro ve   Enter:Chon   F1:Tim kiem   F2:Sua   F3:Xoa");
        int checkLop = inDanhSachLop(ds, vitriLop);
        if(checkLop==ESC)
        {
            xoaKhungLamViec();
            break;
        }

        if(checkLop==F2)
        {
            int checkSua=sua1Lop(ds, vitriLop);
            if(checkSua==ESC) xoaKhungLamViec();

        }
    }
}
int inDanhSachSV(Lop &lop, sinhvien *&dssv, int &soLuongSV, int &vitriSV)
{
    Normal();
    int oToiDa = 20;
    int chon=0;
    int pos[7];
    pos[0]=xLamViec+10; //stt 5
    pos[1]=pos[0]+6;//masv 15
    pos[2]=pos[1]+15; // ho sinh vien 50
    pos[3]=pos[2]+35;// ten 10
    pos[4]=pos[3]+14;// phai
    pos[5]=pos[4]+6;// password
    pos[6]=pos[5]+15;// mon thi
    int y=yLamViec+6;
    
    
    inBangSV(pos, y, dssv, lop.MaLop, soLuongSV, vitriSV, oToiDa);

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
            char maSV[11]="";

            while(1)
            {

                int timKiem=khungTimKiem(xTB, yTB-1, maSV, 30, 10, "Nhap ma sv");

                if(timKiem==Down) // ==ENTER
                {
                    PTRSV tempSV=searchStudent(lop.FirstSinhVien, maSV);
                    if(tempSV==NULL)
                    {
                        xoaThongBao();
                        BaoLoi(xTB, yTB, "Khong tim thay sinh vien");

                    }
                    else
                    {
                        vitriSV=timKiemMangSV(dssv, soLuongSV, maSV);
                        inBangSV(pos, y, dssv, lop.MaLop, soLuongSV, vitriSV, oToiDa);
                        break;
                    }
                }
                if(timKiem==ESC) break;
            }
            xoaThongBao();
            break;
        }
        case F3: // sua sinh vien
        {
            PTRSV sv = searchStudent(lop.FirstSinhVien, dssv[vitriSV].MASV);
            if(sv->info.TrangThaiThi>0)
            {
                BaoLoi(xTB, yTB, "Sinh vien nay da thi roi khong sua duoc");
                break;
            }
            else
            {
                xoaKhungLamViec();
                gotoxy(55, yLamViec+1);
                cout << "LOP " << lop.MaLop;
                hienConTro();
                int checkSuaSV = sua1SinhVien(sv);
                selectionSort(lop.FirstSinhVien);
                capNhatDSSV(dssv, soLuongSV, vitriSV);
                xoaKhungLamViec();
                inBangSV(pos, y, dssv, lop.MaLop, soLuongSV, vitriSV, oToiDa);
                break;
            }

        }



        case F4:  // xoa sinh vien
        {
            if(dssv[vitriSV].TrangThaiThi>0)
            {
                BaoLoi(xTB, yTB, "Sinh vien nay da thi roi khong xoa duoc");
                break;
            }
            else
            {
                int xn=xacNhan(xTB, yTB, "Ban co chac muon xoa sinh vien nay khong?(y/n):");
                xoaThongBao();
                if(xn==YES)
                {

                    xoaSinhVien(lop.FirstSinhVien, dssv[vitriSV].MASV);
                    xoaDSSV(dssv, soLuongSV, vitriSV);
                    xoaKhungLamViec();
                    inBangSV(pos, y, dssv, lop.MaLop, soLuongSV, vitriSV, oToiDa);
                    if(soLuongSV==0)
                    {
                        xoaKhungLamViec();
                        return F4;
                    }
                }
                break;
            }

        }
        case F2:
            return F2;
        case LEFT:
        {

            if(soLuongSV<=oToiDa) break; // neu chi co 1 trang thi khoi left or right
            else
            {

                int tempVt=(vitriSV/oToiDa)*oToiDa;
                if(tempVt <= oToiDa) break;
                else
                {
                    vitriSV=tempVt-oToiDa;
                    chon=0;
                    inBangSV(pos, y, dssv, lop.MaLop, soLuongSV, vitriSV, oToiDa);
                }
                break;
            }

        }
        case RIGHT:
        {

            if(soLuongSV<=oToiDa) break;
            else
            {
                int tempVt=(vitriSV/oToiDa)*oToiDa; // lay vi tri dau tien vd 45 se ve 40 dung temp vi tranh thay doi vitriMang
                if(tempVt >= soLuongSV-oToiDa) break; // kiem tra neu khong right duoc nua thi break
                else
                {
                    vitriSV=tempVt+oToiDa; // neu right duoc thi ta tru cho oToiDa de lui
                    inBangSV(pos, y, dssv, lop.MaLop,soLuongSV, vitriSV, oToiDa);
                    chon=0;
                }
                break;
            }
        }
        case Up :
            if (vitriSV%oToiDa > 0) // lay hang
            {
                diChuyenBangSV(pos,y,dssv,soLuongSV, vitriSV,oToiDa, Up);

            }
            break;
        case Down :
            if (vitriSV%oToiDa  < oToiDa-1 && vitriSV < soLuongSV-1)// lay hang
            {
                diChuyenBangSV(pos,y,dssv,soLuongSV, vitriSV,oToiDa, Down);
            }
            break;
        case ESC:
            xoaKhungLamViec();
            return ESC;

        }  // end switch
    }
    while (1);
}


void showTTNArt()
{
    ifstream f;
    f.open(FileArt);
    string temp;
    int line = 0;
    while (!f.eof())
    {
        gotoxy(10, line++);
        getline(f, temp);
        cout << temp << endl;
    }
    f.close();
}
int DangNhap(DanhSachLop ds, PTRSV &sv, int &vitriLop)
{
    resizeConsole(1000,900);
    showTTNArt();
    int cotTextField=55, y=10;
    int soKhung = 3;
    int dai=25, rong = 2;
    // ve Khung nhap
    gotoxy(cotTextField+4,y-2);
    cout << "DANG NHAP";
    int pos[soKhung];
    bool kt[soKhung-1];
    char *text[soKhung-1];
    for(int i=0; i<soKhung-1; i++)
    {
        text[i] = new char[100];
        strcpy(text[i], "");
    }
    for(int i=0; i<soKhung-1; i++)
    {
        kt[i]=false;
    }
    char truongDangNhap[][20]= {"Ten tai khoan:","Mat khau:", "DANG NHAP"};
    veKhungDangNhap(cotTextField, y, dai, rong, pos, soKhung,truongDangNhap);
    char kytu;
    int vitri=0;
    int dichuyen;
    int trangThai=0;
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
            sv=timSinhVienVaLop(ds, text[vitri], vitriLop);
            if(sv==NULL && stricmp(text[vitri], "GV")!=0) // neu nhap khong phai la gv va ko dung ma sv thi bao loi
            {
                gotoxy(cotTextField, pos[vitri]-2);
                textcolor(mauThongBao);
                cout << "Tai khoan khong ton tai";
                kt[vitri] = false;
                Normal();
            }
            else
            {
                xoaHang(cotTextField, pos[vitri]-2,24);// xoa thanh thong bao tai khoan ton tai
                kt[vitri]=true;
            }
            break;
        }
        case 1: // nhap dang password
        {
            textcolor(4);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            Normal();
            dichuyen=nhapPassword(cotTextField+1, pos[vitri], dai-1, text[vitri], trangThai, 6);
            veKhung(cotTextField,pos[vitri]-1, dai,rong);
            if(strcmp(text[vitri], "")!=0) kt[vitri]=true;
            break;
        }
        case 2: //dang nhap
        {
            anConTro();
            textcolor(4);
            veKhungNho(cotTextField+2,pos[vitri]-1,12,1); // highlight khung
            Normal();
            do
            {
                char c=getch();
                if(c!=-32 && c!=0)
                {


                    if(c==ENTER)
                    {
                        if(!ktTextField(kt, soKhung-1))  // neu tk kkhong ton tai or password trong thi dang nhap that bai
                        {
                            BaoLoi(50, 25,"TEN TAI KHOAN HOAC MAT KHAU KHONG DUNG!");
                            dichuyen=Down;
                            break;
                        }
                        else
                        {
                            if(stricmp(text[0],"GV")==0 && stricmp(text[1],"GV")==0 )
                            {
                                return 0;
                            }
                            if(sv!=NULL && stricmp(text[0], sv->info.MASV)==0 && stricmp(text[1], sv->info.password)==0)  // gv co the dung tk nhung sai mk
                            {													// ta phai kiem tra sv!=Null hay khong
                                return 1;
                            }
                            BaoLoi(50, 25,"TEN TAI KHOAN HOAC MAT KHAU KHONG DUNG!");

                        }
                    }
                    if(c==ESC) return ESC;
                }
                else
                {
                    c=getch();
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
            }
            while(true);
            veKhungNho(cotTextField+2,pos[vitri]-1,12,1);
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
    for(int i=0; i<soKhung-1; i++)
    {
        delete [] text[i];
    }
    delete []text;
}

