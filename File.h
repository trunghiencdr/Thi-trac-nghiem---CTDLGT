#pragma once
#include "Lop.h"
const char* FileLop = "Data\\Lop.txt";
const char* FileMH = "Data\\monHoc.txt";
//==========================================================================================
void LoadDiem(ifstream &filein, PTRD &firstDiem)
{
    diem x;
    char Buffer[2000];
    filein.getline(x.maMH,11,',');
    filein >> x.mark;
    filein.getline(Buffer,100,'\n');// bo endline
    filein.getline(Buffer,100,'\n');
    int n=atoi(Buffer);//load so cau thi
    x.CTDT.SoCauThi=n;
    x.CTDT.IDCauThi = new int[n];
    x.CTDT.CauTraLoi = new char [n];
    for(int i=0; i<n; i++)
    {
        filein.getline(Buffer,100,',');
        x.CTDT.IDCauThi[i]=atoi(Buffer);
        filein.getline(Buffer,100,'\n');
        x.CTDT.CauTraLoi[i]=Buffer[0];
    }
    insertLast(firstDiem, x);
}
void LoadSinhVien(ifstream &filein, PTRSV &firstSinhVien)
{
    char Buffer[1000];
    filein.getline(Buffer,100,'\n');
    int soluong = atoi(Buffer);// so luong sinh vien
    for(int j=0; j<soluong; j++)
    {
        sinhvien sv;
        filein.getline(sv.MASV, 12, ',');
        filein.getline(sv.password, 10, ',');
        filein.getline(sv.HO, 52, ',');
        filein.getline(sv.TEN, 12, ',');
        filein.getline(sv.PHAI, 7, ',');
        filein.getline(Buffer,100,'\n'); // load so mon thi
        sv.Firstdiem =NULL;
        sv.TrangThaiThi = atoi(Buffer);
        for(int i=0; i<sv.TrangThaiThi; i++)
        {
            LoadDiem(filein,sv.Firstdiem);
        }
        insertLast(firstSinhVien,sv);
    }
}
void LoadDanhSachLop(DanhSachLop &ds)
{
    ifstream LoadL,LoadSV;
    char Buffer[2000];
    LoadL.open(FileLop,ios_base::in);
    if(LoadL.fail())
    {
       cout << "Khong mo duoc file lop" << endl;
        Sleep(2000);
    }
    else
    {
        LoadL.getline(Buffer,100,'\n');
        ds.n = atoi(Buffer);
        for(int i=0; i<ds.n; i++)
        {
            LoadL.getline(ds.lop[i].MaLop,11,',');
            LoadL.getline(ds.lop[i].TenLop,51,'\n');
            ds.lop[i].FirstSinhVien=NULL;
            // load file sinh vien
            char filesv[50] = "Data\\Ds_SinhVien\\";
            strcat(strcat(filesv,ds.lop[i].MaLop),".txt");// tao ten file
            LoadSV.open(filesv,ios_base::in);
            if(LoadSV.fail())
            {
				cout << "Khong mo duoc file sinh vien" << endl;
        		Sleep(2000);
            }
            else
            {
                LoadSinhVien(LoadSV, ds.lop[i].FirstSinhVien);
            }
            LoadSV.close();
        }
    }
    LoadL.close();
}

void loadMH(monHoc *dsMH[], int &soLuongMH)
{
    ifstream ipMH;
    char Buffer[2000];
    ipMH.open(FileMH, ios_base::in);
    // kiem tra mo file
    if(ipMH.fail())
    {
		cout << "Khong mo duoc file mon hoc" << endl;
        Sleep(2000);
    }
    //get so luong
    ipMH.getline(Buffer,100,'\n');
    soLuongMH = atoi(Buffer);
    for(int i=0; i<soLuongMH; i++)
    {
        ipMH.getline(dsMH[i]->maMH,11,',');
        ipMH.getline(dsMH[i]->tenMH,51,'\n');
    }
    ipMH.close();
}

void LoadCauHoi(PTRQ &root)
{
    char buffer[2000];
    ifstream ifs;
    ifs.open(FileCauHoi,ios_base::in);
    if(ifs.fail())
    {
		cout << "File cau hoi hong" << endl;
        Sleep(2000);
    }
    ifs.getline(buffer, 100, '\n');
    int maxid = atoi(buffer);
    for(int i = 0; i < maxid; ++i)					//Doc cay nhi phan
    {
        cauhoi quest;
        int id;
        ifs.getline(buffer, 100, ',');
        id = atoi(buffer);
        ifs.getline(buffer, 10, '\n');
        quest.trangThai=atoi(buffer);
        ifs.getline(quest.maMH, 100, '\n');
        ifs.getline(buffer, 2000, '\n');
        quest.noidung = buffer;
        ifs.getline(buffer, 3, ' ');
        ifs.getline(buffer, 2000, '\n');
        quest.A = buffer;
        ifs.getline(buffer, 3, ' ');
        ifs.getline(buffer, 2000, '\n');
        quest.B = buffer;
        ifs.getline(buffer, 3, ' ');
        ifs.getline(buffer, 2000, '\n');
        quest.C = buffer;
        ifs.getline(buffer, 3, ' ');
        ifs.getline(buffer, 2000, '\n');
        quest.D = buffer;
        ifs.getline(buffer, 100, '\n');
        quest.dapan=buffer[0];
        root = insert(root, id, quest);
    }
    ifs.close();
}


void SaveMonHoc(monHoc *dsMH[], int &soLuongMH)
{
    ofstream SaveMH;
    SaveMH.open(FileMH, ios_base::out);
    SaveMH << soLuongMH <<endl;
    for(int i = 0; i < soLuongMH; ++i)
    {
        SaveMH << dsMH[i]->maMH<<",";
        SaveMH << dsMH[i]->tenMH<<endl;
    }
    SaveMH.close();

}
void SaveDSLop(DanhSachLop ds)
{
    ofstream SaveL;
    SaveL.open(FileLop,ios_base::out);
    SaveL << ds.n << endl;
    for(int i = 0; i < ds.n; ++i)
    {
        SaveL << ds.lop[i].MaLop << ",";
        SaveL << ds.lop[i].TenLop << endl;
        //luu dssv 1 lop
        save1Lop(ds.lop[i]);
    }
}
