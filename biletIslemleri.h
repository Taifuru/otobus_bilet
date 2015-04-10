void baslikGoster()
{
	int i;
	for(i=0;i<=8;i++)
		DestroyWindow( bilet_baslik[i] );
	
	bilet_baslik[0] = CreateWindow("STATIC", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										20,70,750,500, anaPencere,NULL ,NULL,NULL);
	
	bilet_baslik[1] = CreateWindow("STATIC", seferNoYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										40,80,70,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_baslik[2] = CreateWindow("STATIC", _tarih,WS_VISIBLE|WS_CHILD|WS_BORDER,
										120,80,90,25, anaPencere,NULL ,NULL,NULL);
										
	bilet_baslik[3] = CreateWindow("STATIC", fiyat,WS_VISIBLE|WS_CHILD|WS_BORDER,
										220,80,50,25, anaPencere,NULL ,NULL,NULL);	
																		
	bilet_baslik[4] = CreateWindow("STATIC",kaptan,WS_VISIBLE|WS_CHILD|WS_BORDER,
										280,80,110,25, anaPencere,NULL ,NULL,NULL);
										
	bilet_baslik[5] = CreateWindow("STATIC", plaka,WS_VISIBLE|WS_CHILD|WS_BORDER,
										400,80,90,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_baslik[6] = CreateWindow("STATIC", _saat,WS_VISIBLE|WS_CHILD|WS_BORDER,
										500,80,50,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_baslik[7] = CreateWindow("STATIC", "Kapasite",WS_VISIBLE|WS_CHILD|WS_BORDER,
										560,80,90,25, anaPencere,NULL ,NULL,NULL);
										
	bilet_baslik[8] = CreateWindow("STATIC", "Güzergah",WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,80,90,25, anaPencere,NULL ,NULL,NULL);
}

void biletSatis()
{
	int i;
	for(i=0;i<=8;i++)
		DestroyWindow( bilet_satis[i]);
	
	bilet_satis[0] = CreateWindow("EDIT", seferNoYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,70,150,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_satis[1] = CreateWindow("EDIT", _koltukNo,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,100,150,25, anaPencere,NULL ,NULL,NULL);
										
	bilet_satis[2] = CreateWindow("EDIT", bay_bayan,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,130,150,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_satis[3] = CreateWindow("EDIT", koltukIslemi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,160,150,25, anaPencere,NULL ,NULL,NULL);
	
	bilet_satis[4] = CreateWindow("BUTTON", koltukGosterYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,40,120,25, anaPencere,(HMENU) kltk_gstr,NULL,NULL);
															
	bilet_satis[5] = CreateWindow("BUTTON", biletSat,WS_VISIBLE|WS_CHILD|WS_BORDER,
										930,40,120,25, anaPencere,(HMENU) bilet_sat,NULL,NULL);

	bilet_satis[6] = CreateWindow("BUTTON", biletIptal,WS_VISIBLE|WS_CHILD|WS_BORDER,
										1070,40,120,25, anaPencere,(HMENU) bilet_iptal,NULL,NULL);
										
	bilet_satis[7] = CreateWindow("EDIT", isimYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,190,150,25, anaPencere,NULL,NULL,NULL);

	bilet_satis[8] = CreateWindow("EDIT", tcNoYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,220,150,25, anaPencere,NULL,NULL,NULL);
}

void koltukGoster()
{
	bListe *p;
	kListe *t;
	
	int siraNo_veri;
	int koltuk_no;

	p = listeBasi;
	
	char gecici[4] = "";
	
	GetWindowText( bilet_satis[0] , gecici, 3);
	siraNo_veri = atoi(gecici);
	
	GetWindowText( bilet_satis[1] , gecici, 3);
	koltuk_no = atoi(gecici);
	
	while( p != NULL)
	{
		
		if( p->_seferNo == siraNo_veri)
		{
			t = p->kListeBasi;
			
			while( t != NULL)
			{
				if( t->kNo == koltuk_no)
				{
					int i;
					for(i=0;i<=12;i++)
						DestroyWindow( koltuk_baslik[i] );
					
					koltuk_baslik[0] = CreateWindow("STATIC", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
														780,300,250,200, anaPencere,NULL ,NULL,NULL);
			
					koltuk_baslik[1] = CreateWindow("STATIC", seferNoYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,310,100,25, anaPencere,NULL ,NULL,NULL);
														
					koltuk_baslik[2] = CreateWindow("STATIC", koltuk,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,340,100,25, anaPencere,NULL ,NULL,NULL);																																			
					
					koltuk_baslik[3] = CreateWindow("STATIC", cinsiyet,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,370,100,25, anaPencere,NULL ,NULL,NULL);
														
					koltuk_baslik[4] = CreateWindow("STATIC", durum,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,400,100,25, anaPencere,NULL ,NULL,NULL);
					
					koltuk_baslik[5] = CreateWindow("STATIC", isimYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,430,100,25, anaPencere,NULL,NULL,NULL);	
									
					koltuk_baslik[6] = CreateWindow("STATIC", tcNoYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
														800,460,100,25, anaPencere,NULL,NULL,NULL);	
										
					koltuk_baslik [7] = CreateWindow("STATIC", t->isim,WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,430,100,25, anaPencere,NULL,NULL,NULL);								
					
					sprintf(gecici, "%d", t->tcNo);
					koltuk_baslik[8] = CreateWindow("STATIC", gecici,WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,460,100,25, anaPencere,NULL,NULL,NULL);
					
					sprintf(gecici, "%d", p->_seferNo);
					koltuk_baslik[9] = CreateWindow("STATIC", gecici,WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,310,100,25, anaPencere,NULL ,NULL,NULL);
					
					sprintf(gecici, "%d", t->kNo);
					koltuk_baslik[10] = CreateWindow("STATIC", gecici ,WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,340,100,25, anaPencere,NULL ,NULL,NULL);
					
					if( t->cinsiyet == BAYAN)
					{
						koltuk_baslik[11] = CreateWindow("STATIC", "Bayan",WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,370,100,25, anaPencere,NULL ,NULL,NULL);
					}
					else
					{
						koltuk_baslik[11] = CreateWindow("STATIC", "Bay",WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,370,100,25, anaPencere,NULL ,NULL,NULL);
					}
					
					if( t->durum == BOS)
					{
						koltuk_baslik[12] = CreateWindow("STATIC", "Boþ",WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,400,100,25, anaPencere,NULL ,NULL,NULL);
					}
					else if( t->durum == DOLU)
					{
						koltuk_baslik[12] = CreateWindow("STATIC", "Dolu",WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,400,100,25, anaPencere,NULL ,NULL,NULL);
					}
					else
					{
						koltuk_baslik[12] = CreateWindow("STATIC", "Rzrv",WS_VISIBLE|WS_CHILD|WS_BORDER,
														910,400,100,25, anaPencere,NULL ,NULL,NULL);
					}
					
					t = NULL;
				}
				else
				{
					if(t->next != NULL)
						t = t->next;
					else
						break;
				}
			}
			p = NULL;
		}
		else
		{
			if(p->sonra != NULL)
				p = p->sonra;
			else
				break;
		}
	}
}

void koltuktanVeriGoster(bListe *p1, kListe *t)
{
	char gecici[15];
	int i;
	for(i = 0; i <= 15; i++ )
		DestroyWindow( koltuk_veri[i] );
	
	koltuk_veri[0] = CreateWindow("STATIC", "",WS_VISIBLE|WS_CHILD|WS_BORDER,
										780,300,250,200, anaPencere,NULL ,NULL,NULL);
			
	koltuk_veri[1] = CreateWindow("STATIC", seferNoYazi,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,310,100,25, anaPencere,NULL ,NULL,NULL);
										
	koltuk_veri[2] = CreateWindow("STATIC", koltuk,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,340,100,25, anaPencere,NULL ,NULL,NULL);																																			
	
	koltuk_veri[3] = CreateWindow("STATIC", cinsiyet,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,370,100,25, anaPencere,NULL ,NULL,NULL);
										
	koltuk_veri[4] = CreateWindow("STATIC", durum,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,400,100,25, anaPencere,NULL ,NULL,NULL);
	
	koltuk_veri[5] = CreateWindow("STATIC", isimYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,430,100,25, anaPencere,NULL,NULL,NULL);	
	
	koltuk_veri[6] = CreateWindow("STATIC", tcNoYaz,WS_VISIBLE|WS_CHILD|WS_BORDER,
										800,460,100,25, anaPencere,NULL,NULL,NULL);	
										
	koltuk_veri [7] = CreateWindow("STATIC", t->isim,WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,430,100,25, anaPencere,NULL,NULL,NULL);								
	
	sprintf(gecici, "%d", t->tcNo);
	koltuk_veri[8] = CreateWindow("STATIC", gecici,WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,460,100,25, anaPencere,NULL,NULL,NULL);
	
	sprintf(gecici, "%d", p1->_seferNo);
	koltuk_veri[9] = CreateWindow("STATIC", gecici,WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,310,100,25, anaPencere,NULL ,NULL,NULL);
	
	sprintf(gecici, "%d", t->kNo);
	koltuk_veri[10] = CreateWindow("STATIC", gecici ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,340,100,25, anaPencere,NULL ,NULL,NULL);
	
	if( t->cinsiyet == BAYAN)
	{
		koltuk_veri[11] = CreateWindow("STATIC", "Bayan",WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,370,100,25, anaPencere,NULL ,NULL,NULL);
	}
	else
	{
		koltuk_veri[12] = CreateWindow("STATIC", "Bay",WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,370,100,25, anaPencere,NULL ,NULL,NULL);
	}
	
	if( t->durum == BOS)
	{
		koltuk_veri[13] = CreateWindow("STATIC", "Boþ",WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,400,100,25, anaPencere,NULL ,NULL,NULL);
	}
	else if( t->durum == DOLU)
	{
		koltuk_veri[14] = CreateWindow("STATIC", "Dolu",WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,400,100,25, anaPencere,NULL ,NULL,NULL);
	}
	else
	{
		koltuk_veri[15] = CreateWindow("STATIC", "Rzrv",WS_VISIBLE|WS_CHILD|WS_BORDER,
										910,400,100,25, anaPencere,NULL ,NULL,NULL);
	}
}

void veriGoster()
{
	bListe *r;
	
	int j ;
	int i ;
	
	r = listeBasi;
	
	for(i=0;i<=7;i++)
		for(j=0;j<100;j++)
			DestroyWindow( veriler[i][j] );
	
	i=0;
	j=0;
	
	while(r !=NULL)
	{
		char gecici[3] = "";
		
		sprintf(gecici, "   %d", r->_seferNo);
		veriler[0][i] = CreateWindow("STATIC", gecici ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										40,110 +(j*30) ,70,25, anaPencere, NULL,NULL,NULL);
										
		veriler[1][i] = CreateWindow("STATIC", r->tarih ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										120,110 +(j*30),90,25, anaPencere, NULL,NULL,NULL);
										
		sprintf(gecici, "   %d", r->fiyat);
		veriler[2][i] = CreateWindow("STATIC", gecici ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										220,110 +(j*30),50,25, anaPencere,NULL ,NULL,NULL);
										
		veriler[3][i] = CreateWindow("STATIC", r->kaptan ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										280,110 +(j*30),110,25, anaPencere,NULL ,NULL,NULL);
										
		veriler[4][i] = CreateWindow("STATIC", r->plaka ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										400,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
										
		veriler[5][i] = CreateWindow("STATIC", r->saat ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										500,110+(j*30),50,25, anaPencere,NULL ,NULL,NULL);
		
		sprintf(gecici, "  %d", r->_kapasite);
		veriler[6][i] = CreateWindow("STATIC", gecici ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										560,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
		switch(r->guzergah)
		{
			case KocIst :
			{
				veriler[7][i] = CreateWindow("STATIC", "Koc-Ist" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
			
			case IstKoc :
			{
				veriler[7][i] = CreateWindow("STATIC", "Ist-Koc" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
			
			case KocAnk :
			{
				veriler[7][i] = CreateWindow("STATIC", "Koc-Ank" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
			
			case AnkKoc :
			{
				veriler[7][i] = CreateWindow("STATIC", "Ank-Koc" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
			
			case KocIzm :
			{
				veriler[7][i] = CreateWindow("STATIC", "Koc-Izm" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
			
			case IzmKoc :
			{
				veriler[7][i] = CreateWindow("STATIC", "Izm-Koc" ,WS_VISIBLE|WS_CHILD|WS_BORDER,
										660,110+(j*30),90,25, anaPencere,NULL ,NULL,NULL);
				break;
			}
		}
		
		j++;
		i++;
		
		r = r->sonra;
	}
}

int biletSatFonk()
{
	bListe *p;
	kListe *k;
	
	p = listeBasi;
	
	char gecici[13];
	int sNo;
	int _kNo;
	
	GetWindowText(bilet_satis[0], gecici, 10);
	sNo = atoi(gecici);
	
	GetWindowText(bilet_satis[1], gecici, 10);
	_kNo = atoi(gecici);
	
	while( p != NULL)
	{
		if( p->_seferNo == sNo)
		{
			k = p->kListeBasi;
			
			while( k != NULL)
			{
				if( k->kNo == _kNo)
				{
					if( k->durum == BOS)
					{
						GetWindowText(bilet_satis[3], gecici, 10);
						if( strcasecmp( "Sat", gecici) == 0)
						{
							GetWindowText(bilet_satis[2], gecici, 6);
							
							if( strcasecmp("bayan", gecici) == 0)
							{
								k->cinsiyet = BAYAN;
								k->durum = DOLU;
								
								GetWindowText(bilet_satis[7], gecici, 10);
								strcpy(k->isim, gecici);
								
								GetWindowText(bilet_satis[8], gecici, 13);
								k->tcNo = atoi(gecici);
								
							}
							else
							{
								k->cinsiyet = BAY;
								k->durum = DOLU;
								
								GetWindowText(bilet_satis[7], gecici, 10);
								strcpy(k->isim, gecici);
								
								GetWindowText(bilet_satis[8], gecici, 13);
								k->tcNo = atoi(gecici);
							}
						}
						else if( strcasecmp( "rezerve", gecici) == 0 )
						{
							GetWindowText(bilet_satis[2], gecici, 10);
							if( strcasecmp("bayan", gecici) == 0)
							{
								k->cinsiyet = BAYAN;
								k->durum = REZV;
								
								GetWindowText(bilet_satis[7], gecici, 10);
								strcpy(k->isim, gecici);
								
								GetWindowText(bilet_satis[8], gecici, 13);
								k->tcNo = atoi(gecici);
								
							}
							else
							{
								k->cinsiyet = BAY;
								k->durum = REZV;
								
								GetWindowText(bilet_satis[7], gecici, 10);
								strcpy(k->isim, gecici);
								
								GetWindowText(bilet_satis[8], gecici, 13);
								k->tcNo = atoi(gecici);
							}
						}
						else
						{
							MessageBox(NULL, " \"Sat\" ya da \" Rezerve\" yazýn!", "Bilet Satýþ",MB_OK);
						}
						
						MessageBox(NULL, "Bilet Satýldý!", "Bilet Satýþ",MB_OK);
						
						koltuktanVeriGoster(p, k);
						
						return 1;
					}
					else
					{
						MessageBox(NULL, "Koltuk Dolu", "Satýþ Hatasý",MB_OK);
						return 0;
					}
					
					k = NULL;
				}
				else
				{
					k = k->next;
				}
			}
			
			p = NULL;
		}
		else
		{
			p = p->sonra;
		}
	}
	
	return 1;
}

void biletIptalFonk()
{
	bListe *p;
	kListe *k;
	
	p = listeBasi;
	
	char gecici[13];
	int sNo;
	int _kNo;
	
	GetWindowText(bilet_satis[0], gecici, 10);
	sNo = atoi(gecici);
	
	GetWindowText(bilet_satis[1], gecici, 10);
	_kNo = atoi(gecici);
	
	while( p != NULL)
	{
		if( p->_seferNo == sNo)
		{
			k = p->kListeBasi;
			
			while( k != NULL)
			{
				if( k->kNo == _kNo)
				{
					if( k->durum == DOLU)
					{
						k->cinsiyet = BAY;
						k->durum = BOS;
						k->tcNo = 0;
						
						strcpy(k->isim, "");
						MessageBox(NULL, "Bilet Ýptal Edildi.", "Bilet Ýptal",MB_OK);
						
						koltuktanVeriGoster(p, k);
					}
					else if ( k->durum == REZV)
					{
						k->cinsiyet = BAY;
						k->durum = BOS;
						k->tcNo = 0;
						
						strcpy(k->isim, "");
						MessageBox(NULL, "Bilet Ýptal Edildi.", "Bilet Ýptal",MB_OK);
						
						koltuktanVeriGoster(p, k);
					}
					else if( k->durum == BOS)
					{
						MessageBox(NULL, "Koltuk zaten boþ!", "Ýptal Hatasý",MB_OK);
					}
					k = NULL;
				}
				else
				{
					k = k->next;
				}
			}
			
			p = NULL;
		}
		else
		{
			p = p->sonra;
		}
	}
}
