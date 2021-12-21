#include <stdio.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <string.h>		//Header yang di gunakan untuk operasi string pada bahasa C
#include <time.h>		//Header yang di gunakan untuk operasi pada bahasa C
#define MAX 100			//Insiasliasi konstanta untuk antrean maksimal

//Struct User untuk menyimpan member nama, username, password, dan email
typedef struct user{
	char nama [50];
	char username [12];
	char password [10];
	char email [50];
}User;
User u;			//variabel u => pendeklarasian dari struct User

//Struct Queue untuk menyimpan data, data1, data2, data3, depan, belakang
typedef struct queue{
    int data[100];
    char data1[100][20];
    char data2[100][30];
    char data3[100][15];
    int depan, belakang;
}Queue;
Queue antrian;		//variabel antrian => pendeklarasian dari struct Queue
Queue no;		//variabel no => pendeklarasian dari struct Queue
Queue nama;		//variabel nama => pendeklarasian dari struct Queue
Queue poli;		//variabel poli => pendeklarasian dari struct Queue

// Deklarasi fungsi dan variabel
void welcome();		//fungsi untuk menampilkan pesan selamat datang
void keluar();		//fungsi untuk menampilkan pesan saat keluar
void error();		//fungsi untuk menampilkan pesan saat terjadi error
void waktu();		//fungsi untuk menampilkan waktu server saat mengakses program
void daftar();		//fungsi untuk mendaftar akun
void masuk();		//fungsi untuk masuk sebagai pasien
void admin();		//fungsi untuk masuk sebagai admin
void menu();		//fungsi untuk menampilkan pilihan menu
int pilihanPelayanan(); //fungsi untuk menampilkan pilihan layanan
void pilihanAntrian();	//fungsi untuk menampilkan pilihan antrian

int data, i, j;
char data1[20], data2[30], data3[15];   //variabel data1[20], data2[30], data3[15]=> berfungsi untuk menyimpan data pasien berupa nama, pelayanan, no rekam medis
int pilihan;				//variabel pilihan => berfungsi untuk menyimpan pilihan
int pilihan;				//variabel pilihan => berfungsi untuk menyimpan pilihan 
time_t waktuserver;			//variavel waktuserver => berfungsi untuk mengambil waktu dari sistem.
char namaFile[]="loginRecord.txt";	//assign namaFile agar menyimpan string "loginRecord.txt"
int queueArray[MAX];			//variabel queueArray => berfungsi untuk menyimpan antrian

//===================================================================//
//********* Fungsi Untuk Menampilakan Pesan Selamat Datang  ******** //
//===================================================================//
// Nama fungsi		:welcome				     //
// Input argumen	:-					     //
// Output argumen	:-					     //
// Deskripsi		:Fungsi ini digunakan untuk menampilkan pesan//
//			selamat datang kepada user di awal mengakses //
//		 	program.				     //
// Versi		: 1.0				Rev:0	     //
// Tanggal		: 03-12-2021				     //
// I Gusti Agung Intan Utami Putri (2105551020)			     //
// Kelas A							     //
//===================================================================//

void welcome(){
    printf("\n\n\n\n\n\t\t************************************************************\n");
    printf("\t\t  ========================================================\n\n");
    printf("\t\t\t    SELAMAT DATANG DI SISTEM PELAYANAN\n");
    printf("\t\t\t	     CLINIC PERMATA \n");
    printf("\t\t\t	JL.IMAM BONJOL NO.7 DENPASAR\n");
    printf("\t\t\t      NOMOR TELEPON: (0361) 978 154\n");
    printf("\t\t\t      EMAIL: info@clinicpermata\n");
    printf("\t\t\t    KAMI SIAP MELAYANI DENGAN KASIH\n\n");
    printf("\t\t  ========================================================");
    printf("\n\t\t************************************************************");
    printf("\n\n\n\n\n Press any key to continue......");
    getch();
    system("cls");
}

//======================================================================//
//*********	Fungsi Untuk Menampilakan Pesan Keluar		********//
//======================================================================// 
// Nama fungsi		: keluar					//
// Input argumen	: -						//
// Output argumen	: -						//
// Deskripsi		: Fungsi ini digunakan untuk menampilkan pesan	//
//			terima kasih kepada user ketika selesai		//
//			mengakses program.				//
// Versi		: 1.0				Rev:0		//
// Tanggal		: 03-12-2021					//
// I Gusti Agung Intan Utami Putri (2105551020)				//
// Kelas A								//
//======================================================================//

void keluar(){
	printf("\n\n\n\n\n\t\t************************************************************\n");
    printf("\t\t  ========================================================\n\n");
	printf("\t\t TERIMA KASIH TELAH MENGGUNAKAN SISTEM PELAYANAN KAMI \n");
	printf("\t\t\t SEMOGA LEKAS SEMBUH, HAVE A GREAT DAY! \n\n");
	printf("\t\t  ========================================================");
	printf("\n\t\t************************************************************");
}

//====================================================================//
//*********	Fungsi Untuk Menampilakan Pesan Error	     ******** //
//====================================================================// 
// Nama fungsi		: error					      //
// Input argumen	: -					      //
// Output argumen	: -					      //
// Deskripsi		: Fungsi ini digunakan untuk menampilkan pesan//
//			error kepada user ketika salah menginput      //
//			pilihan saat mengakses program.		      //
// Versi		: 1.0				Rev:0	      //
// Tanggal		: 09-12-2021				      //
// I Gusti Agung Intan Utami Putri (2105551020)			      //
// Kelas A							      //
//====================================================================//

void error(){
    printf("\t\t\t===============================================  \n");
    printf("\t\t\t||     Pilihan yang Anda masukan Salah!!!     || \n");
    printf("\t\t\t||   Silahkan Memilih Pilihan yang Tersedia	|| \n");
    printf("\t\t\t===============================================  \n");
}


//============================================================//
//*********	Fungsi Untuk Menampilkan Waktu	      ********//
//============================================================//
// Nama fungsi		: waktu				      //
// Input argumen	:-				      //
// Output argumen	:-				      //
// Deskripsi		: Fungsi ini digunakan untuk mengambil//
//			dan menampilkan waktu pada saat user  //
//			mengakses program.		      //
// Versi		: 1.0		Rev:0		      //
// Tanggal		: 14-12-2021			      //
// I Gusti Agung Intan Utami Putri (2105551020)		      //
// Kadek Intan Cahya Putri	(2105551032)		      //
// Kelas A						      //
//============================================================//

void waktu(){
	time(&waktuserver);
	struct tm*waktu = localtime (&waktuserver);
	printf ("\n\t\t\t||==========Tanggal: %d/%d/%d=========||\n\n", waktu -> tm_mday, waktu ->tm_mon +1, waktu -> tm_year +1900);
}

//======================================================================//
//********* Fungsi Untuk Login dan Regis Akun serta Username 	********//
//======================================================================//
// Nama fungsi		: masuk						//
// Input argumen	: char username[12], char password[10]		//
// Output argumen	: -						//
// Deskripsi		: Fungsi ini digunakan untuk menginput username	//
//			dan password  untuk dapat lanjut ke program 	//
// Versi		: 1.0					Rev:0	//
// Tanggal		: 14-12-2021					//
// I Gusti Agung Intan Utami Putri (2105551020)				//
// Kadek Intan Cahya Putri	(2105551032)				//
// Kelas A								//
//======================================================================//

void masuk(){
	/*  Variabel username[12] digunakan untuk menyimpan input username
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan username yang sudah terdaftar pada file loginRecord.txt   */
	char username[12];
	
	/*  Variabel password[10] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file loginRecord.txt   */
	char password[10];
	
	// Variabel pilihan untuk pilihan user apakah ingin mendaftar, masuk ulang, atau keluar
	int pilihan;
	
	// Membuat pointer record untuk menunjuk pada file "loginRecord.txt"
	FILE *record;
	
	// Membuka file dengan mode "r"
	record = fopen (namaFile, "r");
	if (record == NULL){
		fputs ("Error, tidak terdapat file untuk menyimpan akun\n", stderr);
		exit(1);
	}
	
	// Instruksi untuk login
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| LOGIN\n");
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| Username: ");
	scanf ("%s", username);
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| Password: ");
	scanf ("%s", password);
	printf ("\t\t\t||====================||\n");
	
	// Membersikan layar terminal
	system ("cls");
	
	// Membeaca file "logRecord.txt"
	while (fread(&u, sizeof(u),1,record)){
		 /*  Mengkomparasi username serta password yang diinput user ke dalam fungsi
            	masuk() dengan username serta password yang sudah terdaftar */
		if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
			printf ("\t\t\t||====================||\n");
			printf ("\t\t\t|| 	Login Berhasil!	 ||\n");
			printf ("\t\t\t||====================||\n");	
		}
		//  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar, masuk ulang, atau keluar
		else {
			printf ("\t\t\t||============================||\n");
			printf ("\t\t\t|| 	Akun Tidak Terdaftar!	 ||\n");
			printf ("\t\t\t||============================||\n");
			
			instruksi:
			printf ("\t\t\t||============================||\n");
			printf ("\n\t\t\t||Ketik 1 untuk Daftar");
			printf ("\n\t\t\t||Ketik 2 untuk Masuk Ulang");
			printf ("\n\t\t\t||Ketik 3 untuk Keluar\n");
			printf ("\n\t\t\t||============================||\n");
			printf ("\n\t\t\t||Pilihan : ");
			scanf ("%d", &pilihan);
			system ("cls");
			if (pilihan == 1){
				daftar();
			}
			else if (pilihan == 2){
				masuk();
			}
			else if (pilihan == 3){
				keluar();
			}
			else {
				error();
				goto instruksi;
			}
		}
	}
	fclose (record);
	return;
}

//======================================================================//
//*********		Fungsi Untuk Daftar Akun		********//
//======================================================================//
// Nama fungsi		: daftar					//
// Input argumen	: char username[12], char password[10]		//
// Output argumen	: -						//
// Deskripsi		: Fungsi ini digunakan untuk menginput username	//
//			dan password untuk disimpan pada file 		//
//			loginRecord.txt yang nantinya divalidasi saat 	//
//			login.						//
// Versi		: 1.0				Rev:0		//
// Tanggal		: 14-12-2021					//
// I Gusti Agung Intan Utami Putri (2105551020)				//
// Kadek Intan Cahya Putri	(2105551032)				//
// Kelas A								//
//======================================================================//

void daftar(){
	// Membuat pointer regis untuk file "loginRecord.txt"
	FILE *regis;
	// Membuka file "loginRecord.txt" dengan mode "w"
	regis = fopen(namaFile, "w");
	if (regis == NULL){
		fputs ("ERROR, Tidak terdapat file untuk menyimpan data!\n", stderr);
	}
	
	//Instruksi untuk melakukan registrasi akun 
	printf ("\n\t\t\t Silahkan Registrasi Akun Anda! \n\n");
	getchar ();
	printf ("\n\t\t\t Nama Lengkap: ");
	gets (u.nama);
	printf ("\n\t\t\t Email: ");
	scanf ("%s", u.email);
	printf ("\n\t\t\t Hallo %s! \n", u.nama);
	printf ("\n\t\t\t Silahkan membuat username (max 12 karakter), serta password (max 10 karakter) \n");
	
	// Instruksi untuk menginput username serta password
	printf ("\n\t\t\t Masukkan Username : ");
	scanf ("%s", u.username);
	printf ("\n\t\t\t Masukkan Password : ");
	scanf ("%s", u.password);
	
	// Menuliskan nama yang diinput oleh pengguna kedalam file "loginRecord.txt"
	fwrite (&u, sizeof(u),1,regis);
	fclose (regis);
	printf ("\n\t\t\t Registrasi Selesai! ");
	printf ("\n\t\t\t Akun Anda Terdaftar, Silahkan Mencoba!");
	
	// Membersikan layar terminal
	system("cls");
	// Memanggil fungsi masuk()
	masuk ();	
}

//======================================================================//
//********		Fungsi Untuk Login Admin		********//
//======================================================================//
// Nama fungsi		: admin						//
// Input argumen	: char user[15], char pass[10]			//
// Output argumen	: -						//
// Deskripsi		: Fungsi ini digunakan untuk menginput username	//
//			dan password oleh admin untuk login dan dapat	//
//			mengakses program.				//
// Versi		: 1.0				Rev:0		//
// Tanggal		: 14-12-2021					//
// I Gusti Agung Intan Utami Putri (2105551020)				//
// Kadek Intan Cahya Putri	(2105551032)				//
// Kelas A								//
//======================================================================//

void admin (){
	// Insisialisasi variabel username[15] dengan "CLINICPERMATA" dan password[10] dengan "admin2021"
	char username [15]= "CLINICPERMATA", password [10]= "admin2021";
	
	/* Variabel user[6] digunakan untuk menimpan input username oleh admin
    	variabel pass[10] digunakan untuk menyimpan input password oleh admin
    	kedua inputan ini kemudian akan dicompare dengan username dan password
    	yang telah diinisialisasi sebelumnya */
	char user[15], pass[10];
	
	//Instruksi untuk menginput username dan password yang sesuai
	printf ("\t\t\t||========================================================||\n");
	printf ("\t\t\t||SILAHKAN LOGIN DENGAN USERNAME DAN PASSWORD YANG SESUAI!||\n");
	printf ("\t\t\t||========================================================||\n");
	printf ("\n\n\t\t\t Username : ");
	scanf ("%s", &user);
	printf ("\n\n\t\t\t Password : ");
	scanf ("%s", &pass);
	
	//Melakukan komparasi string yaitu username dan password yang diinput dengan yang sudah diinisialisasi
	if (strcmp(username, user)==0 && strcmp(password, pass)==0){
		printf ("\n\n\t\t\t Akses Diterima! ");
	}
	else{
		printf ("\n\n\t\t\t Username atau Password yang Anda Masukkan Salah! ");
	}
}

//==================================================================//
//*********		Fungsi Untuk Pilihan Menu	    ********//
//==================================================================//
// Nama fungsi		: menu					    //
// Input argumen	: pilihan (1,2,3,4)			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih menu   //
// Versi		: 1.0				Rev:0	    //
// Tanggal		: 14-12-2021			    	    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kadek Intan Cahya Putri	(2105551032)			    //
// Kelas A							    //
//==================================================================//

void menu(){
	//variabel pilihan untuk menyimpan pilihan yang diinput user pada switch case
	int pilihan;
	
	instruksi:
	printf ("\t\t\t||=======================================||\n");
	printf ("\t\t\t|| 	PILIHAN MENU MASUK		||\n");
	printf ("\t\t\t||=======================================||\n");
	printf ("\t\t\t||	No	|	Menu Masuk	||\n");
	printf ("\t\t\t||=======================================||\n");
	printf ("\t\t\t||	1	|	Masuk		||\n");
	printf ("\t\t\t||	2	|	Registrasi	||\n");
	printf ("\t\t\t||	3	|	Admin		||\n");
	printf ("\t\t\t||	4	|	Keluar		||\n");
	printf ("\t\t\t||=======================================||\n");
	printf ("\t\t\t||=======================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||=======================================||\n");
	system ("cls");
	
	/* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan untuk menuju ke pilihan menu masuk yang diinput user  */
	switch (pilihan){
		case 1:
			masuk();
			break;
		case 2:
			daftar();
			break;
		case 3:
			admin();
			break;
		case 4:
			keluar();
			break;
		default:
			error();
			break;
	}
}

//==================================================================//
//*********	Fungsi Untuk Pilihan Jalur Pelayanan	    ********//
//==================================================================//
// Nama fungsi		: pilihanJalurLayanan			    //
// Input argumen	: int pilihan (1)			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jalur  //
//			pelayanan 				    //
// Versi		: 1.0			Rev:0		    //
// Tanggal		: 21-12-2021				    //
// Kadek Intan Cahya Putri (2105551032)				    //
// Kelas A							    //
//==================================================================//
int pilihanJalurLayanan(){
	int jalur;
	
	instruksi:
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t|| 	PILIH JALUR PELAYANAN 		||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	No	|	Jalur Pelayanan	||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	1	|	UMUM		||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &jalur);
	printf ("\t\t\t||======================================||\n");
	return(jalur);
	system("cls");
	}


//==================================================================//
//*********	Fungsi Untuk Pelayanan Rawat Jalan	    ********//
//==================================================================//
// Nama fungsi		: rawatjalan				    //
// Input argumen	: int pilihan (1,2)			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis  //
//			pelayanan rawat jalan			    //
// Versi		: 1.0				Rev:0	    //
// Tanggal		: 21-12-2021				    //
// Kadek Intan Cahya Putri (2105551032)				    //
// Kelas A							    //
//==================================================================//
void rawatjalan(){
	int pilihan;
	pilihanJalurLayanan();
    	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t|| 	SILAKAN PILIH POLIKLINIK YANG ANDA INGINKAN  ||\n");
	printf ("\t\t\t||===================================================||\n");
   	printf ("\t\t\t||	No	|	Poliklinik		     ||\n");
   	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t||	1	|	POLIKLINIK UMUM		     ||\n");
	printf ("\t\t\t||	2	|	POLIKLINIK GIGI		     ||\n");
	printf ("\t\t\t||===================================================||\n");
    	printf ("\t\t\t|| SILAHKAN MASUKKAN PILIHAN ANDA : ");
    	scanf("%d", &pilihan);
    	printf ("\t\t\t||===================================================||\n");
}


//===================================================================//
//*********	Fungsi Untuk Pelayanan Covid		     ********//
//===================================================================//
// Nama fungsi		: pelayanancovid			     //
// Input argumen	: int pilihan (1,2)			     //
// Output argumen	: -					     //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis   //
//			pelayanan khusus covid-19		     //
// Versi		: 1.0			Rev:0		     //
// Tanggal		: 21-12-2021				     //
// Kadek Intan Cahya Putri (2105551032)				     //
// Kelas A							     //
//===================================================================//
void pelayanancovid(){
    int pilihan;
   	pilihanJalurLayanan();
    	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t|| 	SILAKAN PILIH LAYANAN YANG ANDA BUTUHKAN     ||\n");
	printf ("\t\t\t||===================================================||\n");
   	printf ("\t\t\t||	No	|	Layanan Covid Khusus  	     ||\n");
   	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t||	1	|	PCR			     ||\n");
	printf ("\t\t\t||	2	|	SWAB ANTIGEN		     ||\n");
	printf ("\t\t\t||===================================================||\n");
    	printf ("\t\t\t|| SILAHKAN MASUKKAN PILIHAN ANDA : ");
    	scanf("%d", &pilihan);
    	printf ("\t\t\t||===================================================||\n");
}

//==================================================================//
//*********	Fungsi Untuk Pelayanan Farmasi		    ********//
//==================================================================//
// Nama fungsi		: farmasi				    //
// Input argumen	: int pilihan (1,2,3,4)			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis  //
//			pelayanan farmasi			    //
// Versi		: 1.0			Rev:0	 	    //
// Tanggal		: 21-12-2021				    //
// Kadek Intan Cahya Putri (2105551032)				    //
// Kelas A							    //
//==================================================================//
void farmasi(){
	int pilihan;
	pilihanJalurLayanan();
	printf ("\t\t\t||==============================================================||\n");
	printf ("\t\t\t|| 			Layanan Menu Farmasi			||\n");
	printf ("\t\t\t||==============================================================||\n");
	printf ("\t\t\t||	No	|Pilihan Layanan Yang Digunakan Sebelumnya	||\n");
	printf ("\t\t\t||==============================================================||\n");
	printf ("\t\t\t||	1	|	POLIKLINIK UMUM				||\n");
	printf ("\t\t\t||	2	|	POLIKLINIK GIGI		   		||\n");
	printf ("\t\t\t||	3	|	PCR					||\n");
	printf ("\t\t\t||	4	|	SWAB ANTIGEN				||\n");	
	printf ("\t\t\t||==============================================================||\n");
	printf ("\t\t\t||==============================================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||======================================||\n");	
}

//==================================================================//
//*********	Fungsi Untuk Pelayanan Laboratorium	    ********//
//==================================================================//
// Nama fungsi		: laboratorium				    //
// Input argumen	: int pilihan (1,2)			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis  //
//			pelayanan laboratorium			    //
// Versi		: 1.0				Rev:0	    //
// Tanggal		: 21-12-2021			    	    //
// Kadek Intan Cahya Putri (2105551032)				    //
// Kelas A							    //
//==================================================================//
void laboratorium(){
	int pilihan;
	pilihanJalurLayanan();
    	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t|| 	Pilih Jenis Pemeriksaan Pada Laboratorium    ||\n");
	printf ("\t\t\t||===================================================||\n");
   	printf ("\t\t\t||	No	|	Layanan Laboratorium	     ||\n");
   	printf ("\t\t\t||===================================================||\n");
	printf ("\t\t\t||	1	|	Cek Darah		     ||\n");
	printf ("\t\t\t||	2	|	Test Narkoba		     ||\n");
	printf ("\t\t\t||===================================================||\n");
   	 printf ("\t\t\t|| SILAHKAN MASUKKAN PILIHAN ANDA : ");
   	 scanf("%d", &pilihan);
    	printf ("\t\t\t||===================================================||\n");
}

//===================================================================//
//*********	  Fungsi Untuk Pilihan Pelayanan	     ********//
//===================================================================//
// Nama fungsi		: pilihanPelayanan			    //
// Input argumen	: int pilihan (1,2,3,4,5)		    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis  //
//			pelayanan				    //
// Versi		: 1.0			Rev:0		    //
// Tanggal		: 21-12-2021				    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kelas A							    //
//==================================================================//
int pilihanPelayanan(){
	//variabel pilihan untuk menyimpan pilihan yang diinput user pada switch case
	int pilihan;
	
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t|| 	PILIHAN PELAYANAN CLINIC PERMATA 	  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||	No	|	Jenis Pelayanan		  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||	1	|	Rawat Jalan		  ||\n");
	printf ("\t\t\t||	2	|	Pelayanan Khusus COVID-19 ||\n");
	printf ("\t\t\t||	3	|	Farmasi			  ||\n");
	printf ("\t\t\t||	4	|	Laboratorium 		  ||\n");
	printf ("\t\t\t||	5	|	Keluar		  	  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||================================================||\n");
	system ("cls");
	
	/* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan untuk menuju ke pilihan jenis pelayanan yang diinput user  */
	switch (pilihan){
		case 1: 
			rawatjalan();
			break;
		case 2:
			pelayanancovid();
			break;
		case 3:
			farmasi();
			break;
		case 4: 
			laboratorium();
			break;
		case 5:
			keluar();
			break;
		default:
			error();
			break;
	}
}

//===================================================================//
//*********	Fungsi Untuk Pengecekan Antrian Kosong	     ********//
//===================================================================//
// Nama fungsi		: isEmpty				     //
// Input argumen	: -					     //
// Output argumen	: -				             //
// Deskripsi		: Fungsi ini digunakan untuk melakukkan	     //
//			pengecekan apakah antrian penuh atau tidak.  //
// Tanggal		: 21-12-2021				     //
// I Gusti Agung Intan Utami Putri (2105551020)			     //
// Kelas A							     //
//===================================================================//
int isEmpty(){
    if (antrian.belakang==-1)
    	return 1;
    else
        return 0;
}

//==================================================================//
//*********	  Fungsi Untuk Pengecekan Antrian Penuh	    ********//
//==================================================================//
// Nama fungsi		: isFull				    //
// Input argumen	: -					    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini melakukkan pengecekan apakah   //
//			antrian penuh atau tidak.		    //
// Versi		: 1.0			Rev:0		    //
// Tanggal		: 21-12-2021				    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kelas A							    //
//==================================================================//

int isFull(){
    if(antrian.belakang==100)
        return 1;
    else
        return 0;
}

//===================================================================//
//*********	Fungsi Untuk Menambah Data Antrian	     ********//
//===================================================================//
// Nama fungsi		: isFull			 	     //
// Input argumen	: int data, char data1[20], char data2[30],  //
//			 char data3[15]				     //
// Output argumen	: -					     //
// Deskripsi		: Fungsi ini berfungsi untuk menambahkan data//
//			antrian.		    		     //
// Versi		: 1.0	Rev:0				     //
// Tanggal		: 21-12-2021				     //
// I Gusti Agung Intan Utami Putri (2105551020)			     //
// Kelas A							     //
//===================================================================//

void Enqueue(int data, char data1[20], char data2[30], char data3[15]) {
    if(isEmpty()==1){
        antrian.depan=antrian.belakang=0;
        nama.depan=nama.belakang=0;
        poli.depan=poli.belakang=0;
        no.depan=no.belakang=0;
        antrian.data[antrian.belakang]=data;
        for(i=0;i<20;i++){
		nama.data1[nama.belakang][i]=data1[i];
	}
        for(i=0;i<30;i++){
		poli.data2[poli.belakang][i]=data2[i];
	}
        for(i=0;i<15;i++){
		no.data3[no.belakang][i]=data3[i];
	}
        printf("\n\n\t\t\t\tData Anda Telah Masuk. Silakan Menunggu Dipanggil!");
    }
    else if(isFull()==0){
        antrian.belakang++;
        nama.belakang++;
        poli.belakang++;
        no.belakang++;
        antrian.data[antrian.belakang]=data;
        for(i=0;i<20;i++){
		nama.data1[nama.belakang][i]=data1[i];
	}
        for(i=0;i<30;i++){
		poli.data2[poli.belakang][i]=data2[i];
	}
        for(i=0;i<15;i++){
		no.data3[no.belakang][i]=data3[i];
	}
    printf("\n\n\t\t\t\t Data Anda Telah Masuk. Silahkan Menunggu Dipanggil!");
    }
}

//==================================================================//
//*********		Fungsi Untuk Membuat Antrian	    ********//
//==================================================================//
// Nama fungsi		: buat					    //
// Input argumen	: -					    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini berfungsi untuk membuat antrian//
//			antrian.				    //
// Versi		: 1.0			Rev:0		    //
// Tanggal		: 21-12-2021				    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kelas A							    //
//==================================================================//

void buat(){
    antrian.depan=antrian.belakang=-1;
    nama.depan=nama.belakang=-1;
    poli.depan=poli.belakang=-1;
    no.depan=no.belakang=-1;
}

//==================================================================//
//*********	Fungsi Untuk Pilihan Menu Antrian   	    ********//
//==================================================================//
// Nama fungsi		: pilihanAntrian			    //
// Input argumen	: int pilihan (1,2,3) 			    //
// Output argumen	: -					    //
// Deskripsi		: Fungsi ini digunakan untuk memilih jenis  //
//			menu antrian oleh pasien.		    //
// Versi		: 1.0				Rev:0	    //
// Tanggal		: 21-12-2021				    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kelas A							    //
//==================================================================//
void pilihanAntrian(){
    system("cls");
    int n;
    buat();
    do{
	system("cls");
    	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t|| 		PILIHAN ANTRIAN CLINIC PERMATA 	  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||	No	|	Menu Antrian	  	  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||	1	|	Mendaftar		  ||\n");
	printf ("\t\t\t||	2	|	Cek Antrian 		  ||\n");
	printf ("\t\t\t||	3	|	Batal			  ||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t||================================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||================================================||\n");
	system ("cls");
		
	/* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       	pilihan untuk menuju ke pilihan jenis menu antrian yang diinput pasien  */
        switch(pilihan){
            case 1:
                printf("\n\n\t\t\t\tNomor Antrean Anda Adalah %i\n", n);
                data=n;
                printf("\n\t\t\t\tNomor Rekam Medis(apabila memiliki) :"); scanf("%s",&data3);
                printf("\n\t\t\t\tNama Lengkap(gunakan tanda (_) untuk spasi) :"); scanf("%s",&data1);
                printf("\n\t\t\t\tKonfirmasi Jenis Pelayanan(gunakan tanda (_) untuk spasi) :"); scanf("%s",&data2);
                Enqueue(data, data1, data2, data3);
                n++;
            	break;
            case 2:
                if(isEmpty()==1){
                        printf("\n\n\t\t\t\tAntrean kosong!");
                break;
                }
                puts("\n\n\t\t\t\tANTREAN           NO REKAM MEDIS             NAMA             PELAYANAN");
                for(i=antrian.depan;i<=antrian.belakang;i++){
                    printf("\n\n\t\t\t\t%i                    %s                       %s                 %s\n", antrian.data[i], no.data3[i], nama.data1[i], poli.data2[i]);
                }
                break;
            case 3:
                keluar();
            	break;
            default:
                puts("\n\n\t\t\t\tHarap pilih sesuai dengan pilihan yang tersedia!\n");
            	break;
        }getch();
    }while(pilihan!=4);
}

//fungsi main () adalah fungsi utama program ini, dimana program akan di eksekusi oleh fungsi main
int main(){	
	welcome();
	waktu();
	menu();
	pilihanPelayanan();
	pilihanAntrian();
	return 0;
}
