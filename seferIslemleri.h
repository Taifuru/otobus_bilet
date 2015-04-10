enum sefer{
	_sefer = 0, _seferIslemleri, _biletIslemleri, _seferEkle, _seferSil, yonDegis, seferKaydetButon,
	kltk_gstr, bilet_sat, bilet_iptal, _seferGelir
};

enum SeferYonu {
_seferYonu = 0, KocIst, IstKoc, KocAnk, AnkKoc, KocIzm, IzmKoc 
};

short seferSec = 1;

void seferEkleG()
{
	seferler[1] = CreateWindow("STATIC", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,70,345,325, anaPencere,NULL ,NULL,NULL);
										
	seferler[2] = CreateWindow("STATIC", tarih,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,10,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[3] = CreateWindow("EDIT", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,10,150,25, seferler[1],NULL ,NULL,NULL);
									
	seferler[4] = CreateWindow("STATIC", saat,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,40,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[5] = CreateWindow("EDIT", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,40,150,25, seferler[1],NULL ,NULL,NULL);
									
	seferler[6] = CreateWindow("STATIC", kapasite,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,70,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[7] = CreateWindow("EDIT", "1",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,70,150,25, seferler[1],NULL ,NULL,NULL);
	
	seferler[8] = CreateWindow("STATIC", fiyat,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,100,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[9] = CreateWindow("EDIT", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,100,150,25, seferler[1],NULL ,NULL,NULL);
	
	seferler[10] = CreateWindow("STATIC", plaka,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,130,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[11] = CreateWindow("EDIT", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,130,150,25, seferler[1],NULL ,NULL,NULL);
	
	seferler[12] = CreateWindow("STATIC", kaptan,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,160,140,25, seferler[1],NULL ,NULL,NULL);
	seferler[13] = CreateWindow("EDIT", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,160,150,25, seferler[1],NULL ,NULL,NULL);
	
	seferler[14] = CreateWindow("STATIC", seferNoYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,190,140,25, seferler[1],NULL ,NULL,NULL);
										
	char seferNoStr[3] = "";
	sprintf(seferNoStr, "%d", seferNo);
	seferler[15] = CreateWindow("STATIC", seferNoStr,WS_VISIBLE|WS_CHILD|WS_BORDER,
										170,190,150,25, seferler[1],NULL ,NULL,NULL);
	
	seferler[16] = CreateWindow("STATIC", seferYonu[_seferYonu],WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,220,140,25, seferler[1],NULL ,NULL,NULL);
	//AnaPencere içerisinde
	seferler[17] = CreateWindow("BUTTON", seferYonu[KocIst],WS_VISIBLE|WS_CHILD|WS_BORDER,
										970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
	
	seferler[18] = CreateWindow("BUTTON", kaydet,WS_VISIBLE|WS_CHILD|WS_BORDER,
										1020,360,100,25, anaPencere,(HMENU) seferKaydetButon,NULL,NULL);
	
	DestroyWindow(seferler[19]);
	seferler[19] = CreateWindow("BUTTON", "Sefer Sil",WS_VISIBLE|WS_CHILD|WS_BORDER,
										380,10,150,25, anaPencere,(HMENU) _seferSil ,NULL,NULL);
	DestroyWindow(seferler[20]);
	seferler[20] = CreateWindow("EDIT", "SeferNo",WS_VISIBLE|WS_CHILD|WS_BORDER,
										560,10,80,25, anaPencere,NULL ,NULL,NULL);
	DestroyWindow(seferler[21]);
	seferler[21] = CreateWindow("BUTTON", "Sefer Gelir",WS_VISIBLE|WS_CHILD|WS_BORDER,
										670,10,150,25, anaPencere,(HMENU) _seferGelir ,NULL,NULL);
}

void yonDegistir()
{
	switch(sYon)
	{
		case KocIst :
		{
			DestroyWindow( seferler[17]);
			sYon = 2;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[IstKoc],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
		case IstKoc :
		{
			DestroyWindow( seferler[17]);
			sYon = 3;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[KocAnk],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
		case KocAnk :
		{
			DestroyWindow( seferler[17]);
			sYon = 4;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[AnkKoc],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
		case AnkKoc :
		{
			DestroyWindow( seferler[17]);
			sYon = 5;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[KocIzm],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
		case KocIzm :
		{
			DestroyWindow( seferler[17]);
			sYon = 6;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[IzmKoc],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
		case IzmKoc :
		{
			DestroyWindow( seferler[17]);
			sYon = 1;
			//AnaPencere içerisinde
			seferler[17] = CreateWindow("BUTTON", seferYonu[KocIst],WS_VISIBLE|WS_CHILD|WS_BORDER,
						970,290,150,25, anaPencere,(HMENU) yonDegis,NULL,NULL);
			break;
		}
	}
}

int gelirHesapla(int sfrNo)
{
	bListe *p;
	kListe *k;
	
	p = listeBasi;
	
	while( p != NULL)
	{
		if(p == NULL)
			break;
		
		if( p->_seferNo == sfrNo)
		{
			k = p->kListeBasi;
			int i=0;
			
			while(k != NULL)
			{
				if( k == NULL)
					break;
				
				if( (k->durum == DOLU) || (k->durum == REZV) )
				{
					i++;
					k = k->next;
				}
				else
				{
					k = k->next;
				}
			}
			
			return (i * p->fiyat);
		}
		else
		{
			p = p->sonra;
		}
	}
	
	return 0; 
}
