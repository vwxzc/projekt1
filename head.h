#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <errno.h>
#include <string.h>

#include <sys/socket.h>
#include <linux/if_ether.h>
//Zmienna do przechowywania rozmiaru odebranych danych
	int iDataLen = 0;
	int *wsk=&iDataLen;
//naglowek icmp
struct icmp_header{
		unsigned char typ_ether[2];
		unsigned char port_wej[2];
		unsigned char port_wyj[2];
		unsigned char dlug[2];
		unsigned char suma_kontr[2];
			}header_icmp;
