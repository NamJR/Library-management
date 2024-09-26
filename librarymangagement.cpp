#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;

struct dausach{
	string masach, tensach, tacgia, theloai, tinhtrang;
	string ts;
	long long sotrang, namxuatban;
	void nhap(){
		cout <<"ma sach: ";
		cin.ignore();
		getline(cin, masach);
		cout << "ten sach: "; 
		getline(cin, tensach); 
		cout <<"so trang: ";
	    cin >> sotrang; 
		cin.ignore();
		cout << "ten tac gia: ";
		getline(cin, tacgia); 
		cout << "the loai: ";
		getline(cin, theloai); 
		cout << "nam xuat ban: ";
		cin >> namxuatban; 
	    cin.ignore();
	    cout << "tinh trang sach: ";
		getline(cin, tinhtrang); 	
			}
	void in(){
		cout << masach << endl << tensach << endl << tacgia << endl << sotrang << endl << theloai << endl << namxuatban << endl << tinhtrang << endl;
	}
    int timkiem(){
    	cin.ignore();
    	cout << "ten sach can tim: ";
    	getline(cin, ts);
    	if(ts.compare(tensach) == 0) return 1;
    	else return 0;
	}
    int suathongtinsach(){
    	string ma;
    	cin.ignore();
    	getline(cin, ma);
    	if(ma.compare(masach) == 0) return 1;
    	else return 0;
}

};

struct thongtinsv{
	string hoten, mssv, lop, sachmuon;
 void nhap(){
 	cout << "ho va ten: "; 
 	getline(cin, hoten); 
 	cout <<"mssv: ";
 	getline(cin, mssv); 
 	cout <<"lop: ";
 	getline(cin, lop); 
 	cout << "ma sach muon: ";
 	getline(cin, sachmuon); 
 	cout << "----------------" << endl; 
 }
 void in(){
 	cout << hoten << endl << mssv << endl << lop << endl << sachmuon << endl;
 }
}; 

int main(){
	long long n, m;
	int lc;
	fstream fbook;
    	cout <<"So sach co trong thu vien: ";
	    cin >> n;
	    dausach x[1000];
    	for(int i = 0; i < n; i++){
		x[i].nhap();
		cout << endl;
	   }
	   fbook.open("book informaton.txt");
	 for(int i = 0; i < n; i++){
	 	fbook << x[i].masach << endl;
	 	fbook << x[i].tensach << endl;
	 	fbook << x[i].sotrang << endl;
	 	fbook << x[i].tacgia << endl;
	 	fbook << x[i].theloai << endl;
	 	fbook << x[i].namxuatban << endl;
	 	fbook << x[i].tinhtrang << endl;
	 	fbook << endl;
	 }
      fbook.close();
	fstream fhs;
	cout << "so sinh vien muon sach: ";
	cin >> m;
	cin.ignore();
	thongtinsv sv[m];
	fhs.open("student information.txt");
	for(int i = 0; i < m; i++){
	sv[i].nhap();
                }
    for(int i = 0; i < m; i++){
    	fhs << sv[i].hoten << endl;
    	fhs << sv[i].mssv << endl;
    	fhs << sv[i].lop << endl;
    	fhs << sv[i].sachmuon << endl;
	}
    fhs.close();
	
    do{
    cout << "---------------Menu----------------" << endl;
    cout << "0_Thoat chuong trinh:" << endl;
    cout << "1_Tim kiem sach" << endl;
    cout << "2_Liet ke thong tin sinh vien muon sach:" << endl;
    cout << "3_Them sach" << endl;
    cout << "4_Sua thong tin sach" << endl;
    cout << "5_Liet ke cac sach co trong thu vien" << endl;
    cout << endl;
	cout << "Nhap lua chon cua ban: " ; cin >> lc;
	 cout << endl;
    switch(lc){
    	case 0: break;
	    case 1:{
	    	int cnt = 0, i = 0;
	    	while(i < n){
	    		if(x[i].timkiem()){
				x[i].in(); 
				 ++cnt;
				 break;
			}
			++i;
		}
		if(cnt == 0) cout << "ten sach khong co trong thu vien" << endl;			
	break;
}
	    case 2:{
           for(int i = 0; i < m; i++){
           	sv[i].in();
		   }
           break;
	        }
	    case 3:{
	    	int k;
    	cout <<"So sach them vao trong thu vien: ";
	    cin >> k;
    	for(int i = n; i < n+k; i++){
		x[i].nhap();
		cout << endl;
	   }
	fbook.open("book informaton.txt");
	   for(int i = n; i < n+k; i++){
	   		fbook << x[i].masach << endl;
	 	fbook << x[i].tensach << endl;
	 	fbook << x[i].sotrang << endl;
	 	fbook << x[i].tacgia << endl;
	 	fbook << x[i].theloai << endl;
	 	fbook << x[i].namxuatban << endl;
	 	fbook << x[i].tinhtrang << endl;
	 	fbook << endl;
	   }
	   fbook.close();
	   n = n+k;
	break;
	      }
	     	case 4:{
	cout << "nhap ma sach can sua: ";
		for(int i = 0; i < n; i++){
			if(x[i].suathongtinsach()){
				x[i].nhap();
				break;
			}
			else{
				cout << "ma sach khong co trong thu vien" << endl;
				break;
			}
		}
		break;
	} 
	    case 5:{
	    	for(int i = 0; i < n; i++){
	    		x[i].in();
	    		cout << endl;
			}
			break;
		}
		default:{
			cout << "lua chon khong hop le!" << endl;
	      break;
	      }
	   }
    }while(lc != 0);
    
    return 0;
}
