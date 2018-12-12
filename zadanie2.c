#include "head.h"

int main(void) {
	printf("Uruchamiam odbieranie ramek Ethernet.\n"); /* prints  */

	//Utworzenie bufora dla odbieranych ramek Ethernet
	char* buffer = (void*) malloc(ETH_FRAME_LEN);

	//Otwarcie gniazda pozwalającego na odbiór wszystkich ramek Ethernet
	int iEthSockHandl = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	//Kontrola czy gniazdo zostało otwarte poprawnie, w przypadku bledu wyświetlenie komunikatu.
	if (iEthSockHandl<0)
			printf("Problem z otwarciem gniazda : %s!\n", strerror(errno));



	//Pętla nieskończona do odbierania ramek Ethernet
	while (1) {

		//Odebranie ramki z utworzonego wcześniej gniazda i zapisanie jej do bufora
		iDataLen = recvfrom(iEthSockHandl, buffer, ETH_FRAME_LEN, 0, NULL, NULL);
		struct icmp_data{
					unsigned char datatab[*wsk-42];
					}data_icmp;
		//Kontrola czy nie było bledu podczas odbierania ramki
		if (iDataLen == -1)
			printf("Nie moge odebrac ramki: %s! \n", strerror(errno));
		else { //jeśli ramka odebrana poprawnie wyświetlenie jej zawartości------------tutaj glowna czesc programu

			//sprawdzenie czy odebrał UDP
			for(int j=0;j<iDataLen;j++)
				{
					if(j==23)   //pole typu w ipv4
					{
					if(buffer[j]==0x11)//sprawdza czy udp
						{
						for(int l=0;l<iDataLen;l++)
							{
								if(l==12)
									{
									header_icmp.typ_ether[0]=buffer[l];
									header_icmp.typ_ether[1]=buffer[l+1];  ///L+1
									}
								if(l==34)
									{
									header_icmp.port_wej[0]=buffer[l];
									header_icmp.port_wej[1]=buffer[l+1];
									}
								if(l==36)
									{
									header_icmp.port_wyj[0]=buffer[l];
									header_icmp.port_wyj[1]=buffer[l+1];
									}
								if(l==38)
									{
									header_icmp.dlug[0]=buffer[l];
									header_icmp.dlug[1]=buffer[l+1];
									}
								if(l==40)
									{
									header_icmp.suma_kontr[0]=buffer[l];
									header_icmp.suma_kontr[1]=buffer[l+1];
									}
								///dane z udp
								if(l==42)
									{
									int m=0;
									for(int n=43;n<iDataLen;n++)
										{
										data_icmp.datatab[m]=buffer[n];
										m++;
				 						}
									}

								}
						printf("------odebarno ramke UDP-----------\n");
						printf("pole typu w Ethernet: Ox%02X%02X\n",header_icmp.typ_ether[0],header_icmp.typ_ether[1]);
						printf("source port: Ox%02X%02X\n",header_icmp.port_wej[0],header_icmp.port_wej[1]);
						printf("destination port: Ox%02X%02X\n",header_icmp.port_wyj[0],header_icmp.port_wyj[1]);
						printf("length: Ox%02X%02X\n",header_icmp.dlug[0],header_icmp.dlug[1]);
						printf("checksum: Ox%02X%02X\n",header_icmp.suma_kontr[0],header_icmp.suma_kontr[1]);
						printf("--------------UDP-data---------\n");
						for(int o=0;o<iDataLen-42;o++)
							{
							printf("%02X ",data_icmp.datatab[o]);
							}
							printf("\n   \n");
						}
						}

					}

	}
	}

return EXIT_SUCCESS;
}
