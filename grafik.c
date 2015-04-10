#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tr_lang.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND anaPencere, seferButon, biletButon , seferler[21], bilet_baslik[30], veriler[10][15];

HWND bilet_satis[9], koltuk_baslik[13], koltuk_veri[16];

#include "liste_islemleri.h" 
#include "seferIslemleri.h"
#include "biletIslemleri.h"
#include "dosyaIslemi.h"

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc; /* A properties struct of our window */
	MSG Msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX); 
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+25);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0; 
	}
	
	anaPencere = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass", otobus_seferleri, WS_VISIBLE|WS_MINIMIZEBOX|WS_SYSMENU,
		20 , /* x */
		20 , /* y */
		1250, /* width */
		700, /* height */
		NULL,NULL,hInstance,NULL);
	
	if(anaPencere == NULL)
	{
		MessageBox(NULL, pencere_hata, hata_mesaj,MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate key codes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	
	return Msg.wParam;
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND anaPencere, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_CREATE:
		{
			//gerekli pencerelerin daha program baþlangýcýnda oluþturulmasý
			seferButon = CreateWindow("BUTTON", sefer_islemleri,WS_VISIBLE|WS_CHILD|WS_BORDER,
														20,10,150,25, anaPencere,(HMENU) _seferIslemleri,NULL,NULL);
			biletButon = CreateWindow("BUTTON", bilet_islemleri,WS_VISIBLE|WS_CHILD|WS_BORDER,
														20,40,150,25, anaPencere,(HMENU) _biletIslemleri,NULL,NULL);
			dosyaOku(); 
			
			break;
		}
		 
		case WM_COMMAND :
		{
			switch(LOWORD(wParam))
			{
				case _seferIslemleri:
				{
					seferler[0] = CreateWindow("BUTTON", seferEkle,WS_VISIBLE|WS_CHILD|WS_BORDER,
														200,10,150,25, anaPencere,(HMENU) _seferEkle ,NULL,NULL);
					
					seferler[19] = CreateWindow("BUTTON", "Sefer Sil",WS_VISIBLE|WS_CHILD|WS_BORDER,
														380,10,150,25, anaPencere,(HMENU) _seferSil ,NULL,NULL);
					
					seferler[20] = CreateWindow("EDIT", "SeferNo",WS_VISIBLE|WS_CHILD|WS_BORDER,
														560,10,80,25, anaPencere,NULL ,NULL,NULL);
					seferler[21] = CreateWindow("BUTTON", "Sefer Gelir",WS_VISIBLE|WS_CHILD|WS_BORDER,
										670,10,150,25, anaPencere,(HMENU) _seferGelir ,NULL,NULL);
					
					int i;
					for(i=0;i<=12;i++)
						DestroyWindow( koltuk_baslik[i] );
					
					
					for(i=0;i<=15;i++)
						DestroyWindow( koltuk_veri[i] );
						
					for(i=0;i<=8;i++)
						DestroyWindow( bilet_satis[i]);
					
					baslikGoster();
					veriGoster();
					loglama("Program Çalýþtýrýldý");
					break;
				}
				
				case _biletIslemleri:
				{
					int i;
					for(i = 0; i<= 21;i++)
						DestroyWindow( seferler[i] );
					
					for(i=0;i<=15;i++)
						DestroyWindow( koltuk_veri[i] );
					
					baslikGoster();
					veriGoster();
					biletSatis();
					loglama("Bilet Ýþlemlerine Girildi");
					break;
				}
				
				case _seferEkle :
				{
					DestroyWindow(seferler[0]);
					seferEkleG();
					loglama("Sefer Ekleme Bölümüne Girildi");
					break;
				}
				
				case yonDegis :
				{
					yonDegistir();
					break;
				}
				
				case seferKaydetButon :
				{
					yeniKayit();
					
					int i;
					for(i=0;i<21;i++)
						DestroyWindow(seferler[i]);
					
					seferEkleG();

					veriGoster();
					
					loglama("Sefer Ekleme Butonuna Basýldý");
					break;
				}
				
				case kltk_gstr :
				{
					int i;
					
					for(i=15; i<28;i++)
						DestroyWindow(bilet_baslik[i]);
					
					for(i=0;i<=15;i++)
						DestroyWindow( koltuk_veri[i] );
					
					koltukGoster();
					loglama("Koltuk Gösterildi");
					break;
				}
				
				case bilet_sat :
				{
					int i;
					for(i=0;i<=12;i++)
						DestroyWindow( koltuk_baslik[i] );
						
					biletSatFonk();
					loglama("Bilet satmaya Çalýþýldý");
					break;
				}
				
				case bilet_iptal :
				{
					biletIptalFonk();
					loglama("Bilet Ýptal Edilmeye Çalýþýldý");
					break;
				}
				
				case _seferSil :
				{
					char gecici[5];
					GetWindowText(seferler[20], gecici, 5);
					
					DestroyWindow(seferler[20]);
					
					kayitSil( atoi(gecici));  

					veriGoster();
					
					seferler[20] = CreateWindow("EDIT", "SeferNo",WS_VISIBLE|WS_CHILD|WS_BORDER,
																560,10,80,25, anaPencere,NULL ,NULL,NULL);
					loglama("Sefer Silinmeye Çalýþýldý");
					break;
				}
				
				case _seferGelir :
				{
					char gecici[20];
					char gecici2[5];
					
					int para = 0;
					
					GetWindowText(seferler[20], gecici2, 5);
					DestroyWindow(seferler[20]);
					
					para = gelirHesapla( atoi(gecici2)); 
					
					sprintf( gecici, "%d numaralý seferin geliri : %d", atoi(gecici2), para );
					
					seferler[20] = CreateWindow("EDIT", "SeferNo",WS_VISIBLE|WS_CHILD|WS_BORDER,
																560,10,80,25, anaPencere,NULL ,NULL,NULL);
					loglama("Sefer Geliri Hesaplandi");
					MessageBox(NULL, gecici, "Sefer Geliri",MB_OK);
				}
			}
			break;
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY:
		{
			dosyaYaz();
			loglama("Programdan Çýkýldý");
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(anaPencere, Message, wParam, lParam);
	}
	return 0;
}
