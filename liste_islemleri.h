#include<string.h>
enum CINSIYET { BAYAN = 0, BAY , YOK};
enum DURUM { BOS = 0, DOLU, REZV};

typedef struct Koltuk
{
	int salla;
	int kNo;
	int cinsiyet;
	char isim [25];
	int tcNo;
	int durum;
	struct Koltuk *prev, *next;
}kListe;

typedef struct Sefer
{
	int kamil;
	int _seferNo;
	char tarih [11];
	char saat [6];
	char plaka [11];
	int fiyat;
	int _kapasite;
	int guzergah;
	char kaptan[31];
	 
	struct Koltuk *kListeBasi;
	struct Koltuk *kListeSonu;
	struct Sefer *once, *sonra;
}bListe;

bListe *listeBasi = NULL;
bListe *listeSonu = NULL;

bListe *SeferPtr;

static int seferNo = 1;
short sYon = 1;

void seferEkleme(bListe *eklenecekSefer)
{
	if(listeBasi != NULL)
	{
		listeSonu->sonra = eklenecekSefer;
		eklenecekSefer->once = listeSonu;
		listeSonu = eklenecekSefer;
		listeSonu->sonra = NULL;
	}
	else
	{
		listeBasi = eklenecekSefer;
		listeSonu = eklenecekSefer;
		listeBasi->sonra = NULL;
		listeBasi->once = NULL; 
	}
}

void ilkDegerAta(bListe *p, int _kpst)
{
	kListe *k;
	int j;
	
	j = 0;
	k = p->kListeBasi;
	
	for(j =0;j< _kpst;j++)
	{
		k->cinsiyet = YOK;
		k->kNo = j + 1;
		k->tcNo = 0;
		strcpy(k->isim, "");
		k->durum = BOS;
		k = k->next;
	}
}

void koltukEkleme(bListe *eklenecekSefer)
{
	kListe *eklenecekKoltuk;
	eklenecekKoltuk = (kListe *) malloc( sizeof( kListe));
	
	if(eklenecekSefer->kListeBasi != NULL)
	{
		eklenecekSefer->kListeSonu->next = eklenecekKoltuk;
		eklenecekKoltuk->prev = eklenecekSefer->kListeSonu;
		eklenecekSefer->kListeSonu = eklenecekKoltuk;
		eklenecekSefer->kListeSonu->next = NULL;
	}
	else
	{
		eklenecekSefer->kListeBasi = eklenecekKoltuk;
		eklenecekSefer->kListeSonu = eklenecekKoltuk;
		eklenecekSefer->kListeBasi->next = NULL;
		eklenecekSefer->kListeBasi->prev = NULL;
	}
}

void koltukEklemeDosya(bListe *eklenecekSefer, kListe *eklenecekKoltuk)
{
	if(eklenecekSefer->kListeBasi != NULL)
	{
		eklenecekSefer->kListeSonu->next = eklenecekKoltuk;
		eklenecekKoltuk->prev = eklenecekSefer->kListeSonu;
		eklenecekSefer->kListeSonu = eklenecekKoltuk;
		eklenecekSefer->kListeSonu->next = NULL;
	}
	else
	{
		eklenecekSefer->kListeBasi = eklenecekKoltuk;
		eklenecekSefer->kListeSonu = eklenecekKoltuk;
		eklenecekSefer->kListeBasi->next = NULL;
		eklenecekSefer->kListeBasi->prev = NULL;
	}
}

int kayitSil(int sfrNo)
{
	bListe *p;
	kListe *k;
	
	p = listeBasi;
	
	while( p != NULL)
	{
		if( p->_seferNo == sfrNo )
		{
			
			char gecici[10];
			sprintf(gecici, "%d.txt", p->_seferNo);
			printf("dosya adi %s \n", gecici);
			k = p->kListeBasi;
			
			while( k != NULL)
			{
				if( k->durum != BOS )
				{
					MessageBox(NULL, "Bilet Satýlmýþ Sefer Silinemez!", "Sefer Ýþlemleri",MB_OK);
					return 0;
				}
				k = k->next;
			}
			
			if( listeBasi == p)
			{
				if( p->sonra != NULL)
				{
					listeBasi = p->sonra;
					listeBasi->once = NULL;
				}
				else
				{
					listeBasi = NULL;
					listeSonu = NULL;
				}
			}
			else
			{
				p->once->sonra = p->sonra;
				
				if( p != listeSonu )
				{
					p->sonra->once = p->sonra;
				}
				else
				{
					if( p->once != NULL)
						listeSonu = p->once;
				}
			}
			
			remove(gecici);
			
			free(p);
			p = NULL;
			
			return 1;
		}
		else
		{
			p = p->sonra;
		}
	}
	
	MessageBox(NULL, "Böyle bir sefer bulunamadý!", "Sefer Ýþlemleri",MB_OK);
	return 0;
}

void yeniKayit()
{
	bListe *kayitAl;
	
	int i, kapasite;
	
	kayitAl = (bListe *) malloc(sizeof( bListe ));
	
	char _kapasite1[4];
	
	GetWindowText(seferler[7],_kapasite1, 3);
	kapasite = atoi(_kapasite1);
	kayitAl->_kapasite = kapasite;
	
	kayitAl->kListeBasi = NULL;
	kayitAl->kListeSonu = NULL;
	
	for(i=0;i<kapasite;i++)
		koltukEkleme(kayitAl);
	
	if( kayitAl == NULL)
		puts( bellek_yer );
	
	char fiyat_2[3];
	
	GetWindowText(seferler[3],kayitAl->tarih, 11);
	GetWindowText(seferler[5],kayitAl->saat, 6);
	GetWindowText(seferler[9],fiyat_2, 6);
	GetWindowText(seferler[11],kayitAl->plaka, 11);
	GetWindowText(seferler[13],kayitAl->kaptan, 31);
	
	kayitAl->fiyat = atoi(fiyat_2);
	
	kayitAl->guzergah = sYon;
	kayitAl->_seferNo = seferNo;
	seferNo++;
	
	
	ilkDegerAta(kayitAl, kapasite);
	
	seferEkleme(kayitAl);
	
	MessageBox(NULL, "Sefer Baþarýyla Eklendi!", "Sefer Kayýt",MB_OK);
}
