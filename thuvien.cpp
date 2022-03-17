#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Khai báo struct
typedef struct
{
	int ngay, thang, nam;
} Date;
typedef struct
{
	char TenNguoiMuon[100];
	Date NgayMuon;
	Date NgayTra;
} Human;
typedef struct Sach
{
	char TenSach[50];
	char TacGia[100];
	char TheLoai[50];
	char MaSach[10];
	char NhaXuatBan[50];
	int NamXB;
	int SoLuong;
	int SLNguoiMuon;
	Human NguoiMuon;
} Book;
//Nhap Ngay Thang Nam
void NhapDate(Date &a)
{
	int dem = 0;
	while (true)
	{
		printf("\tNgay: ");
		scanf("%d", &a.ngay);
		printf("\tThang: ");
		scanf("%d", &a.thang);
		printf("\tNam: ");
		scanf("%d", &a.nam);
		if (a.nam > 1900)
		{
			switch (a.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				if (a.ngay < 1 || a.ngay > 31)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if (a.ngay < 1 || a.ngay > 30)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 2:
			{
				if (a.nam % 4 == 0)
				{
					if (a.ngay < 1 || a.ngay > 29)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
				else
				{
					if (a.ngay < 1 || a.ngay > 28)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
			}
			default:
			{
				dem = 1;
				break;
			}
			}
		}
		else
			dem = 1;
		if (dem == 1)
		{
			printf("\nNgay thang nam khong hop le!\nVui long nhap lai.\n");
			dem = 0;
		}
		else
			break;
	}
}
//So sanh ngay muon va ngay tra
int SoSanhNgay(Date a, Date b)
{
	if (a.nam > b.nam)
	{
		return 1;
	}
	else if (a.nam == b.nam)
	{
		if (a.thang > b.thang)
		{
			return 1;
		}
		else if (a.thang == b.thang)
		{
			if (a.ngay > b.ngay)
			{
				return 1;
			}
		}
	}
	return 0;
}
//Nhap nguoi muon
void NhapNguoiMuon(Human a, int &dem)
{
	printf("Nhap ten nguoi muon: ");
	fflush(stdin);
	gets(a.TenNguoiMuon);
	while (true)
	{
		printf("Nhap ngay muon: \n");
		NhapDate(a.NgayMuon);
		printf("Nhap ngay tra: \n");
		NhapDate(a.NgayTra);
		if (SoSanhNgay(a.NgayMuon, a.NgayTra) == 1)
		{
			printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
		}
		else
			dem++;
		break;
	}
}
//Nhap thong tin sach
void Nhap(Book &a)
{
	printf("Nhap ma sach: ");
	fflush(stdin);
	gets(a.MaSach);
	printf("Nhap ten sach: ");
	gets(a.TenSach);
	printf("Nhap ten tac gia: ");
	gets(a.TacGia);
	printf("Nhap the loai: ");
	gets(a.TheLoai);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &a.NamXB);
	printf("Nhap ten nha xuat ban: ");
	fflush(stdin);
	gets(a.NhaXuatBan);
	do
	{
		printf("Nhap so luong: ");
		scanf("%d", &a.SoLuong);
		if (a.SoLuong <1)
		{
			printf("So luong khong hợp le!\nYeu cau nhap lai.\n");
		}
	} while (a.SoLuong <1);
}
//Nhap DS Sach
void NhapDS(Book a[], int &n)
{
	n = 0;
	while (n <= 0)
	{
		printf("Nhap so luong sach: ");
		scanf("%d", &n);
	}
	for (int i = 0; i < n; i++)
	{
		printf("\n\nNhap thong tin sach thu %d\n", i + 1);
		Nhap(a[i]);
	}
}
//Xuat ngay thang nam
void XuatDate(Date a)
{
	printf("%d/%d/%d", a.ngay, a.thang, a.nam);
}
//Xuat DS nguoi muon
void XuatNguoiMuon(Human a)
{
	printf("\nNguoi muon: %s", a.TenNguoiMuon);
	printf("\nNgay muon: ");
	XuatDate(a.NgayMuon);
	printf("\nNgay Tra: ");
	XuatDate(a.NgayTra);
}
void DSNguoiMuon(Human a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		XuatNguoiMuon(a[i]);
	}
}
//Xuat DS Sach
void Xuat(Book a)
{
	printf("\nMa sach: %s", a.MaSach);
	printf("\nTen sach: %s", a.TenSach);
	printf("\nTac gia: %s", a.TacGia);
	printf("\nThe loai: %s", a.TheLoai);
	printf("\nNam xuat ban: %d", a.NamXB);
	printf("\nNha xuat ban: %s", a.NhaXuatBan);
	printf("\nSoLuong: %d", a.SoLuong);
}
void XuatDS(Book a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		Xuat(a[i]);
	}
}
//Hàm đổi chỗ
void DoiCho(Book &a, Book &b)
{
	Book c = a;
	a = b;
	b = c;
}
//Sắp xếp theo tên
void SapXepTen(Book a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].TenSach, a[j].TenSach) > 0)
			{
				DoiCho(a[i], a[j]);
			}
		}
	}
}
//Ham Main
int main()
{
	Book a[50];
	int n;
	NhapDS(a, n);
	XuatDS(a, n);
}
