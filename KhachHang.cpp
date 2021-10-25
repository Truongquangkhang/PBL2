#include<iostream>
#include<string>
#include<fstream>
#include"KhachHang.h"
using namespace std;

void KhachHang::xuat(){
    ifstream k;
    string Name;
    int len;
    k.open("KhachHang.txt");
    cout<<"MaKH                          TenKH                         SDT                           Dia chi                       Phuong thuc thanh toan\n"<<endl;
    while(!k.eof()){
            getline(k,Name);
            len=Name.length();
            cout<<Name;
            for(int i=0;i<30-len;i++)cout<<" ";
            getline(k,Name);
            cout<<Name;
            len=Name.length();
            for(int i=0;i<30-len;i++)cout<<" ";
            getline(k,Name);
            cout<<Name;
            len=Name.length();
            for(int i=0;i<30-len;i++)cout<<" ";
             getline(k,Name);
            cout<<Name;
             len=Name.length();
            for(int i=0;i<30-len;i++)cout<<" ";
            getline(k,Name);
             cout<<Name<<endl;
    }

    k.close();
}
void KhachHang::nhap(){

    ofstream l;
     l.open("KhachHang.txt", ios::app);
     string s;
     cin.ignore();
     
         cout<<"\nNhap Ma Khach Hang: ";
         getline(cin,s);
         l<<s<<endl;
         cout<<"\nNhap Ten Khach Hang: ";
         getline(cin,s);
         l<<s<<endl;
         cout<<"\nNhap SDT             ";
         getline(cin,s);
         l<<s<<endl;
         cout<<"\nNhap Dia Chi         ";
         getline(cin,s);
         l<<s<<endl;
         cout<<"\nNhap Phuong Thuc Thanh Toan       ";
         getline(cin,s);
         l<<s<<endl;
         cout<<"1: Tiep Tuc                       2: Dung Lai"<<endl;
         getline(cin,s);
         
}
void KhachHang::Xoa(){
    fstream stud;
    fstream temp;
    stud.open("KhachHang.txt", ios::in);
    temp.open("Temp.txt",ios::out);
    string key;
    string a,b,c,d,e;
    cout<<"Nhap Ma Khach Hang Ban Can Xoa: ";cin>>key;cout<<endl;
    while(!stud.eof()){
        getline(stud,a);
        getline(stud,b);
        getline(stud,c);
        getline(stud,d);
        getline(stud,e);
        if(a!=key){
            temp<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n";
        }
        else break;
    }
    int count=0;
    while(!stud.eof()){
        getline(stud,a);
        if(count%5==0){
            if(a[3]=='0'){
                a[2]-=1;
                a[3]='9';
            }
            else a[3]-=1;
        }

        temp<<a<<endl;
        count++;
    }
    stud.close();
    temp.close();

    stud.open("KhachHang.txt",ios::out);
    temp.open("Temp.txt",ios::in);
    while(!temp.eof()){
        getline(temp,a);
        stud<<a<<endl;
    }
    stud.close();
    temp.close();
    remove("Temp.txt");
}
void KhachHang::Tim(){
    ifstream f;
    f.open("KhachHang.txt",ios::in);
    string key;
    cin.ignore();
    cout<<"Nhap ten Khach Hang: ";getline(cin,key);cout<<endl;
    string a,b,c,d,e;
    
    while(!f.eof()){

        getline(f,a);
        getline(f,b);
        getline(f,c);
        getline(f,d);
        getline(f,e);
        if(b==key)break;
        
        
    }
    if(f.eof())cout<<"Khong co Khach Hang Nay!!";
    else{
        f.close();
        cout<<"Ma Khach Hang:  "<<a<<endl;
        cout<<"Ten Khach hang: "<<b<<endl;
        cout<<"SDT:            "<<c<<endl;
        cout<<"Dia Chi:        "<<d<<endl;
        cout<<"Phuong Thuc TT: "<<e<<endl;
    }
    f.close();
}
// Trả về true nếu tìm thấy userName && password và đồng thời tìm mã khách hàng của tài khoản 
bool KhachHang::Account(string Name, string SDT,string &x){
    
    ifstream f;
    f.open("C:\\Users\\win\\OneDrive\\Desktop\\PBL2\\code\\HIHI\\Database\\Account\\Account_User.txt",ios::in);
    string a,b,c;
    while(!f.eof()){
        getline(f,a);
        getline(f,b);
        getline(f,c);
        if(a==Name && b==SDT)break;
        
    }
    if(f.eof()){
        f.close();
        return false;
    }
    f.close();
    x=c;
    return true;   
}
// Hàm Đăng ký tk cho khách hàng sẽ bổ thông tin khách hàng vào file KhachHang.txt và thông tin tk_mk vào file account
void KhachHang::Register(){
    string a,b,c,d,e,Code;
    fstream f;
    // cin.ignore();
    f.open("KhachHang.txt",ios::in);
    while (true)
    {
        getline(f,a);
        if(a.length()==4)Code=a;
        getline(f,b);
        getline(f,c);
        getline(f,d);
        getline(f,e);
        if(f.eof())break;
    }
    if(Code[3]=='9'){
        Code[2]+=1;
        Code[3]='0';
    }
    else Code[3]+=1;
    f.close();
    f.open("KhachHang.txt",ios::app);
    cout<<"Nhap Ten Cua Ban: ";getline(cin,b);cout<<endl;
    cout<<"Nhap SDT cua Ban: ";getline(cin,c);cout<<endl;
    cout<<"Nhap Dia Chi:     ";getline(cin,d);cout<<endl;
    cout<<"Phuong Thuc TT Cua Ban la: ";getline(cin,e);cout<<endl;
    f<<Code<<endl;
    f<<b<<endl;
    f<<c<<endl;
    f<<d<<endl;
    f<<e<<endl;
    f.close();
    system("cls");
    cin.ignore();
    f.open("C:\\Users\\win\\OneDrive\\Desktop\\PBL2\\code\\HIHI\\Database\\Account\\Account_User.txt",ios::app);
    cout<<"Nhap Ten Dang Nhap hoac SDT cua Ban: ";cin>>a;cout<<endl;
    cout<<"Nhap MK:                             ";cin>>b;cout<<endl;
    f<<a<<endl;
    f<<b<<endl;
    f<<Code<<endl;
}
