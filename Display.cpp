/*
 *   Copyright (C) 2016,2017 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Display.h"
#include "Defines.h"
#include "Log.h"

#include <cstdio>
#include <cassert>
#include <cstring>

CDisplay::CDisplay() :
m_timer1(3000U, 3U),
m_timer2(3000U, 3U),
m_mode1(MODE_IDLE),
m_mode2(MODE_IDLE)
{
}

CDisplay::~CDisplay()
{
}

void CDisplay::setIdle()
{
	m_timer1.stop();
	m_timer2.stop();

	m_mode1 = MODE_IDLE;
	m_mode2 = MODE_IDLE;

	setIdleInt();
}

void CDisplay::setLockout()
{
	m_timer1.stop();
	m_timer2.stop();

	m_mode1 = MODE_IDLE;
	m_mode2 = MODE_IDLE;

	setLockoutInt();
}

void CDisplay::setError(const char* text)
{
	assert(text != NULL);

	m_timer1.stop();
	m_timer2.stop();

	m_mode1 = MODE_IDLE;
	m_mode2 = MODE_IDLE;

	setErrorInt(text);
}

void CDisplay::writeDStar(const char* my1, const char* my2, const char* your, const char* type, const char* reflector)
{
	assert(my1 != NULL);
	assert(my2 != NULL);
	assert(your != NULL);
	assert(type != NULL);
	assert(reflector != NULL);

	m_timer1.start();
	m_mode1 = MODE_IDLE;

	writeDStarInt(my1, my2, your, type, reflector);
}

void CDisplay::writeDStarRSSI(unsigned char rssi)
{
	if (rssi != 0U)
		writeDStarRSSIInt(rssi);
}

void CDisplay::writeDStarBER(float ber)
{
	writeDStarBERInt(ber);
}

void CDisplay::clearDStar()
{
	if (m_timer1.hasExpired()) {
		clearDStarInt();
		m_timer1.stop();
		m_mode1 = MODE_IDLE;
	} else {
		m_mode1 = MODE_DSTAR;
	}
}

void CDisplay::writeDMR(unsigned int slotNo, const std::string& src, bool group, const std::string& dst, const char* type)
{
	assert(type != NULL);

	if (slotNo == 1U) {
		m_timer1.start();
		m_mode1 = MODE_IDLE;
	} else {
		m_timer2.start();
		m_mode2 = MODE_IDLE;
	}
	writeDMRInt(slotNo, src, group, dst, type);


// INI File Read

FILE *cfgfile;
 int maxline = 256;
 int i=0;
 char ctrl[2][256];
std::string path ("/home/pi/MMDVMHost/etc/ctrl.ini");

const char* file = path.c_str();
cfgfile = fopen (file, "r");
if (cfgfile==NULL) printf("can't open file\n");
  while (fgets(ctrl[i], maxline, cfgfile)) {
     ctrl[i][strlen(ctrl[i])-1] = '\0';
    i++;
   }  
 fclose(cfgfile);


		if  (strncmp (ctrl[0],"1",1) == 0){ 

//TTS
	char voice[80];
	strcpy (voice,"echo \"");
		if (strcmp (ctrl[1],src.c_str()) !=0){ 

		std::string s =src.c_str();

for (char & c : s)
		{
		if (c == 'A'){
		strcat(voice," Alfa ");
	}
	else if (c == 'B'){
		strcat(voice," Bravo ");
	}
	else if (c == 'C'){
		strcat(voice," Charli ");
	}
	else if (c == 'D'){
		strcat(voice," Delta ");
	}
	else if (c == 'E'){
		strcat(voice," Eko ");
	}
	else if (c == 'F'){
		strcat(voice," Foxtrot ");
	}
	else if (c == 'G'){
		strcat(voice," Golf ");
	}
	else if (c == 'H'){
		strcat(voice," Hotel ");
	}
	else if (c == 'I'){
		strcat(voice," India ");
	}
	else if (c == 'J'){
		strcat(voice," Yuliet ");
	}
	else if (c == 'K'){
		strcat(voice," Kilo ");
	}
	else if (c == 'L'){
		strcat(voice," Lima ");
	}	
	else if (c == 'M'){
		strcat(voice," Maik ");
	}
	else if (c == 'N'){
		strcat(voice," November ");
	}
	else if (c == 'O'){
		strcat(voice," Oscar ");
	}
	else if (c == 'P'){
		strcat(voice," Papa ");
	}
	else if (c == 'Q'){
		strcat(voice," Quebec ");
	}
	else if (c == 'R'){
		strcat(voice," Romeo ");
	}
	else if (c == 'S'){
		strcat(voice," Sierra ");
	}
	else if (c == 'T'){
		strcat(voice," Tango ");
	}
	else if (c == 'U'){
		strcat(voice," Union ");
	}
	else if (c == 'V'){
		strcat(voice," Victor ");
	}
	else if (c == 'W'){
		strcat(voice," G�isski ");
	}
	else if (c == 'X'){
		strcat(voice," Exray ");
	}
	else if (c == 'Y'){
		strcat(voice," Yanki ");
	}
	else if (c == 'Z'){
		strcat(voice," Zulu ");
	}
	else if (c == '0'){
		strcat(voice," 0 ");
	}
	else if (c == '1'){
		strcat(voice," uno ");
	}
	else if (c == '2'){
		strcat(voice," 2 ");
	}
	else if (c == '3'){
		strcat(voice," treess ");
	}
	else if (c == '4'){
		strcat(voice," 4 ");
	}
	else if (c == '5'){
		strcat(voice," 5 ");
	}
	else if (c == '6'){
		strcat(voice," seiiss ");
	}
	else if (c == '7'){
		strcat(voice," 7 ");
	}
	else if (c == '8'){
		strcat(voice," 8 ");
	}
	else if (c == '9'){
		strcat(voice," 9 ");
	}

    c = '*';
}


// strcat (voice,src.c_str());
	strcat (voice,"\"| festival --tts\n");
//strcat (voice,"\n");
//printf ("%s\n",voice);

	FILE *fpa;
 	fpa = fopen ( "/ram/mm_voice.sh", "r+" );
 	fprintf (fpa,voice);
 	fclose ( fpa );
	
	system ("/ram/mm_voice.sh &");
	LogMessage ("Voice TG:%s",dst.c_str());
	LogMessage ("Voice Callsign:%s",src.c_str());
	}
}

//REMOTE Commands

	if ((strcmp ("99",dst.c_str()) ==0)){
	LogMessage ("Remote Command Reboot");
	system("sudo shutdown -r now");
	}
	else if ((strcmp ("98",dst.c_str()) ==0)){
	LogMessage ("Remote Command Shutdown");
	system("sudo shutdown -h now");
	}
	else if ((strcmp ("40",dst.c_str()) ==0)){
	LogMessage  ("Remote Command DmrPlus");
	system("mm_plus");
	}	
	else if ((strcmp ("50",dst.c_str()) ==0)){
	LogMessage  ("Remote Command DMRGateway");
	system("mm_gate");
	}
	else if ((strcmp ("30",dst.c_str()) ==0)){
	LogMessage  ("Remote Command BrandMeister");
	system("mm_BM");
	}
	else if ((strcmp ("21",dst.c_str()) ==0)){
	LogMessage ("Remote Command Wifi On");
	system("sudo rfkill unblock 0");
	}
	else if ((strcmp ("20",dst.c_str()) ==0)){
	LogMessage  ("Remote Command Wifi Off");
	system("sudo rfkill block 0");
	}
	else if ((strcmp ("11",dst.c_str()) ==0)){
	LogMessage  ("Remote Command Audio On");
	FILE *fp;
 	char cadena[20] = "1\n";
 	fp = fopen ( "/home/pi/MMDVMHost/etc/ctrl.ini", "r+" );
 	fputs( cadena, fp );
	fputs(ctrl[1],fp);
	fputs ("\n",fp);
 	fclose ( fp );	
	}	
	else if ((strcmp ("10",dst.c_str()) ==0)){
	LogMessage  ("Remote Command Audio Off");
	FILE *fp;
 	char cadena[20] = "0\n";
 	fp = fopen ( "/home/pi/MMDVMHost/etc/ctrl.ini", "r+" );
 	fputs( cadena, fp );
	fputs(ctrl[1],fp);
	fputs ("\n",fp);
 	fclose ( fp );	

	
	}
}

void CDisplay::writeDMRRSSI(unsigned int slotNo, unsigned char rssi)
{
	if (rssi != 0U)
		writeDMRRSSIInt(slotNo, rssi);
}

void CDisplay::writeDMRTA(unsigned int slotNo, unsigned char* talkerAlias, const char* type)
{
    char TA[32U];
    unsigned char *b;
    unsigned char c;
    int j;
    unsigned int i,t1,t2, TAsize, TAformat;

    if (strcmp(type," ")==0) { writeDMRTAInt(slotNo, (unsigned char*)TA, type); return; }

    TAformat=(talkerAlias[0]>>6U) & 0x03U;
    TAsize = (talkerAlias[0]>>1U) & 0x1FU;
    ::strcpy(TA,"(could not decode)");
    switch (TAformat) {
	case 0U:		// 7 bit
		::memset (&TA,0,32U);
		b=&talkerAlias[0];
		t1=0; t2=0; c=0;
		for (i=0;(i<32U)&&(t2<TAsize);i++) {
		    for (j=7U;j>=0;j--) {
			c = (c<<1U) | (b[i] >> j);
			if (++t1==7U) { if (i>0) {TA[t2++]=c & 0x7FU; } t1=0; c=0; }
		    }
		}
		break;
	case 1U:		// ISO 8 bit
	case 2U:		// UTF8
		::strcpy(TA,(char*)talkerAlias+1U);
		break;
	case 3U:		// UTF16 poor man's conversion
		t2=0;
		::memset (&TA,0,32U);
		for(i=0;(i<15)&&(t2<TAsize);i++) {
		    if (talkerAlias[2U*i+1U]==0)
			TA[t2++]=talkerAlias[2U*i+2U]; else TA[t2++]='?';
		}
		TA[TAsize]=0;
		break;
    }
    LogMessage("DMR Talker Alias (Data Format %u, Received %u/%u char): '%s'", TAformat, ::strlen(TA), TAsize, TA);
    if (::strlen(TA)>TAsize) { if (strlen(TA)<29U) strcat(TA," ?"); else strcpy(TA+28U," ?"); }
    if (strlen((char*)TA)>=4U) writeDMRTAInt(slotNo, (unsigned char*)TA, type);

}

void CDisplay::writeDMRBER(unsigned int slotNo, float ber)
{
	writeDMRBERInt(slotNo, ber);
}
void CDisplay::clearDMR(unsigned int slotNo)
{
	if (slotNo == 1U) {
		if (m_timer1.hasExpired()) {
			clearDMRInt(slotNo);
			m_timer1.stop();
			m_mode1 = MODE_IDLE;
		} else {
			m_mode1 = MODE_DMR;
		}
	} else {
		if (m_timer2.hasExpired()) {
			clearDMRInt(slotNo);
			m_timer2.stop();
			m_mode2 = MODE_IDLE;
		} else {
			m_mode2 = MODE_DMR;
		}
	}
}

void CDisplay::writeFusion(const char* source, const char* dest, const char* type, const char* origin)
{
	assert(source != NULL);
	assert(dest != NULL);
	assert(type != NULL);
	assert(origin != NULL);

	m_timer1.start();
	m_mode1 = MODE_IDLE;

	writeFusionInt(source, dest, type, origin);
}

void CDisplay::writeFusionRSSI(unsigned char rssi)
{
	if (rssi != 0U)
		writeFusionRSSIInt(rssi);
}

void CDisplay::writeFusionBER(float ber)
{
	writeFusionBERInt(ber);
}

void CDisplay::clearFusion()
{
	if (m_timer1.hasExpired()) {
		clearFusionInt();
		m_timer1.stop();
		m_mode1 = MODE_IDLE;
	} else {
		m_mode1 = MODE_YSF;
	}
}

void CDisplay::writeP25(const char* source, bool group, unsigned int dest, const char* type)
{
	assert(source != NULL);
	assert(type != NULL);

	m_timer1.start();
	m_mode1 = MODE_IDLE;

	writeP25Int(source, group, dest, type);
}

void CDisplay::writeP25RSSI(unsigned char rssi)
{
	if (rssi != 0U)
		writeP25RSSIInt(rssi);
}

void CDisplay::writeP25BER(float ber)
{
	writeP25BERInt(ber);
}

void CDisplay::clearP25()
{
	if (m_timer1.hasExpired()) {
		clearP25Int();
		m_timer1.stop();
		m_mode1 = MODE_IDLE;
	} else {
		m_mode1 = MODE_P25;
	}
}

void CDisplay::writeCW()
{
	m_timer1.start();
	m_mode1 = MODE_CW;

	writeCWInt();
}

void CDisplay::clock(unsigned int ms)
{
	m_timer1.clock(ms);
	if (m_timer1.isRunning() && m_timer1.hasExpired()) {
		switch (m_mode1) {
		case MODE_DSTAR:
			clearDStarInt();
			m_mode1 = MODE_IDLE;
			m_timer1.stop();
			break;
		case MODE_DMR:
			clearDMRInt(1U);
			m_mode1 = MODE_IDLE;
			m_timer1.stop();
			break;
		case MODE_YSF:
			clearFusionInt();
			m_mode1 = MODE_IDLE;
			m_timer1.stop();
			break;
		case MODE_P25:
			clearP25Int();
			m_mode1 = MODE_IDLE;
			m_timer1.stop();
			break;
		case MODE_CW:
			clearCWInt();
			m_mode1 = MODE_IDLE;
			m_timer1.stop();
			break;
		default:
			break;
		}
	}

	// Timer/mode 2 are only used for DMR
	m_timer2.clock(ms);
	if (m_timer2.isRunning() && m_timer2.hasExpired()) {
		if (m_mode2 == MODE_DMR) {
			clearDMRInt(2U);
			m_mode2 = MODE_IDLE;
			m_timer2.stop();
		}
	}

	clockInt(ms);
}

void CDisplay::clockInt(unsigned int ms)
{
}

void CDisplay::writeDStarRSSIInt(unsigned char rssi)
{
}

void CDisplay::writeDStarBERInt(float ber)
{
}

void CDisplay::writeDMRRSSIInt(unsigned int slotNo, unsigned char rssi)
{
}

void CDisplay::writeDMRTAInt(unsigned int slotNo, unsigned char* talkerAlias, const char* type)
{
}

void CDisplay::writeDMRBERInt(unsigned int slotNo, float ber)
{
}

void CDisplay::writeFusionRSSIInt(unsigned char rssi)
{
}

void CDisplay::writeFusionBERInt(float ber)
{
}

void CDisplay::writeP25RSSIInt(unsigned char rssi)
{
}

void CDisplay::writeP25BERInt(float ber)
{
}
