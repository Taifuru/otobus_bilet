#include <time.h>

void dosyaOku()
{
	FILE *di, *di2;
	bListe *p;
	kListe *p1;
	
	unsigned int n;
	unsigned int k;
	
	unsigned int n1;
	unsigned int k1;
	
	if( ( di = fopen( "talip.txt" , "r") ) != NULL )
	{
		//sefer
		fseek(di, 0, 2);
		n = ftell( di ) / (sizeof(bListe) - 2 * sizeof( p ) );
		fseek(di, 0, 0);
		
		for(k=0; k <n; k++)
		{
			p = (bListe *) malloc( sizeof(bListe) );
			
			if ( p == NULL)
			{
				printf( bellek_yer );
				break;
			}
			
			fread(p, sizeof( bListe ) - 2 * sizeof( p ), 1, di);
			
			char gecici[10];
			sprintf(gecici, "%d.txt", p->_seferNo);
			
			if( ( di2 = fopen( gecici , "r") ) != NULL )
			{
				p->kListeBasi = NULL;
				p->kListeSonu = NULL;
				
				//sefer
				fseek(di2, 0, 2);
				n1 = ftell( di2 ) / ( sizeof(kListe) - 2 * sizeof( p1 ) );
				fseek(di2, 0, 0);
				
				for(k1=0; k1<n1; k1++)
				{
					p1 = (kListe *) malloc( sizeof(kListe) );
					
					if ( p1 == NULL)
					{
						printf( bellek_yer );
						break;
					}
					
					fread(p1, sizeof( kListe ) - 2 * sizeof( p1 ), 1, di2);
					
					koltukEklemeDosya(p, p1);
				}
			}
			else
			{
				puts("koltuk dosyasi okuma acilamadi");
			}
			
			seferEkleme(p);
		}
		
		p = listeBasi;
		
		while( p != NULL)
		{
			if( p == NULL)
				break;
			
			if ( p->sonra == NULL)
			{
				seferNo = p->_seferNo + 1;
				p = NULL;
			}
			else
			{
				p = p->sonra;
			}
		}
		
		fclose(di);
		fclose(di2);
	}
	else
	{
		puts("sefer dosyasi okuma acilamadi");
	}
	
}

void dosyaYaz()
{
	bListe *p;
	kListe *k;
	
	FILE *di, *di2;
	
	if( ( di=fopen( "talip.txt" , "w") ) == NULL )
	{
		puts("sefer dosyasi acilamadi");
	}
	
	p = listeBasi;
		
	while( p != NULL )
	{
		fwrite(p, sizeof( bListe ) - 2 * sizeof( p ), 1, di);
		
		char gecici[10];
		sprintf(gecici, "%d.txt", p->_seferNo);
		
		if( ( di2=fopen( gecici , "w") ) == NULL )
		{
			puts("koltuk dosyasi acilamadi");
		}
		
		k = p->kListeBasi;
	
		while( k != NULL )
		{
			fwrite(k, sizeof( kListe ) - 2 * sizeof( k ), 1, di2);
			
			k = k->next;
		}
		
		p = p->sonra;
		fclose(di2);
	}
	
	fclose(di);
}

void loglama( char mesaj[200])
{
	FILE *di;
	
	time_t t;
	time(&t);
	
	if( (di=fopen("log.txt", "a+") ) == NULL )
	{
		printf("Dosya Acma Hatasi");
	}
	else
	{
		fprintf(di, "%s --- %s", mesaj, ctime(&t) );
	}
	
	fclose(di);
}
