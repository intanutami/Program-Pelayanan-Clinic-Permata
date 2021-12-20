#include <stdio.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <string.h>		//Header yang di gunakan untuk operasi string pada bahasa C
#include <time.h>		//Header yang di gunakan untuk operasi pada bahasa C

//Struct User untuk menyimpan member nama, username, password, dan email
typedef struct user{
	char nama [50];
	char username [12];
	char password [10];
	char email [50];
}User;

// Deklarasi fungsi dan variabel
void welcome();		//fungsi untuk menampilkan pesan selamat datang
void keluar();		//fungsi untuk menampilkan pesan saat keluar
void error();		//fungsi untuk menampilkan pesan saat terjadi error
void waktu();		//fungsi untuk menampilkan waktu server saat mengakses program
void daftar();		//fungsi untuk mendaftar akun
void masuk();		//fungsi untuk masuk sebagai pasien
void admin();		//fungsi untuk masuk sebagai admin
void menu();		//fungsi untuk menampilkan pilihan menu

int pilihan;				//variabel pilihan => berfungsi untuk menyimpan pilihan 
User u;					//variabel u => pendeklarasian dari struct User
time_t waktuserver;			//variavel waktuserver => berfungsi untuk mengambil waktu dari sistem.
char namaFile[]="loginRecord.txt";	//assign namaFile agar menyimpan string "loginRecord.txt"

//==================================================================//
//********* Fungsi Untuk Menampilakan Pesan Selamat Datang  ********//
//==================================================================//
// Nama fungsi		:welcome				    //
// Input argumen	:-					    //
// Output argumen	:-					    //
// Deskripsi		:Fungsi ini digunakan untuk menampilkan pesan//
//			selamat datang kepada user di awal mengakses//
//		 	program.				    //
// Versi		: 1.0				Rev:0	    //
// Tanggal		: 03-12-2021				    //
// I Gusti Agung Intan Utami Putri (2105551020)			    //
// Kelas A							    //
//==================================================================//

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

//==================================================================//
//*********		Fungsi Untuk Menampilakan Pesan Error		********//
//==================================================================// 
// Nama fungsi		: error											//
// Input argumen	: -												//
// Output argumen	: -												//
// Deskripsi		: Fungsi ini digunakan untuk menampilkan pesan	//
//					 error kepada user ketika salah menginput		//
//					 pilihan saat mengakses program.				//
// Versi			: 1.0							Rev:0			//
// Tanggal			: 09-12-2021									//
// I Gusti Agung Intan Utami Putri (2105551020)						//
// Kelas A															//
//==================================================================//

void error(){
	printf("\t\t\t===============================================  \n");
    printf("\t\t\t||     Pilihan yang Anda masukan Salah!!!     || \n");
    printf("\t\t\t||   Silahkan Memilih Pilihan yang Tersedia	|| \n");
    printf("\t\t\t===============================================  \n");
}


//==========================================================//
//*********		Fungsi Untuk Menampilkan Waktu		********//
//==========================================================//
// Nama fungsi		: waktu									//
// Input argumen	:-										//
// Output argumen	:-										//
// Deskripsi		: Fungsi ini digunakan untuk mengambil	//
//					 dan menampilkan waktu pada saat user 	//
//					 mengakses program.						//
// Versi			: 1.0					Rev:0			//
// Tanggal			: 14-12-2021							//
// I Gusti Agung Intan Utami Putri (2105551020)				//
// Kadek Intan Cahya Putri	(2105551032)					//
// Kelas A													//
//==========================================================//

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

//fungsi main () adalah fungsi utama program ini, dimana program akan di eksekusi oleh fungsi main
int main(){	
	welcome();
	waktu();
	menu();
	return 0;
}


