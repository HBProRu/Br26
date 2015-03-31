char *PIDName[] = { "Коэффициент P", "Коэффициент I", "Коэффициент D", "Окно PID в мс", "Мощн. на ТЭН ", "Калибровка   " };
//char *stageName[] ={"Mash In   ", "Пауза 1   ", "Пауза 2   ", "Пауза 3   ", "Пауза 4   ", "Пауза 5   ", "Пауза 6   ", "Mash Out  ", "Варка     "};
char *stageName[] = { "Mash In   ", "Фитаза    ", "Глюканаза ", "Протеаза  ", "b-Амилаза ", "a-Амилаза1", "a-Амилаза2", "Mash Out  ", "Варка     " };
char *unitName[] = { "Уст. шкалы гр.", "Датчик темп.  ", "Темп. кипения ", "Темп. кипения ", "Работа насоса ", "Простой насоса", "Опция насоса  ", "Останов насоса" };//11
char *GeneralName[] = { "Яркость      ", "Контраст     ", "Дата и время ", "Wi-Fi        ", "WLAN_SSID    ", "WLAN_PASS     " };

byte HeatONOFF[8] = { B00000, B01010, B01010, B01110, B01110, B01010, B01010, B00000 };  // [5] HEAT symbol
byte RevHeatONOFF[8] = { B11111, B10101, B10101, B10001, B10001, B10101, B10101, B11111 };  // [6] reverse HEAT symbol
byte Language[8] = { B11111, B00010, B01000, B11111, B00000, B10001, B10101, B11111 };  // [7] EN symbol

//byte Ciclo=0;

void LCDSpace(byte Num){
	for (byte i = 0; i < Num; i++){
		lcd.print(F(" "));
	}
}

void LCDClear(byte Riga){
	lcd.setCursor(0, Riga);
	LCDSpace(20);
}

void PrintTemp(float Temp){
	if (Temp < 10.0)LCDSpace(2);
	if (Temp >= 10.0 && Temp < 100.0)LCDSpace(1);
	lcd.print(Temp);

	//Gradi();
	lcd.write((byte)0);
}

void PrintTime(String time){
	//LCDClear(1);
	lcd.setCursor(6, 1);
	lcd.print(time);

}

void Clear_2_3(){
	LCDClear(2);
	LCDClear(3);
}

void Version(byte locX, byte locY){
	lcd.setCursor(locX, locY);
	//lcd.print(Version20);
	lcd.print(F("2.6.65a"));
	//lcd.write(7);
	//lcd.print(char(0xAC));
}

void Intestazione(){
	lcd.setCursor(0, 0);
	//lcd.print(F("Open ArdBir "));
	//Version(12,0);
	lcd.print(F(" HBPro Brauholic v2 "));
}

void LCD_Procedo(){
	lcd.setCursor(1, 3);
	lcd.print(F("Выберите:  Да  Нет"));
}


void LCD_Conferma(){
	lcd.setCursor(1, 3);
	//  lcd.print(F("Continue: Yes  ---"));
	lcd.print(F("Выберите:  Да  ---"));
}


void LCD_Default(float Temp){
	Intestazione();

	lcd.setCursor(6, 2);
	PrintTemp(Temp);

	//LCDClear(2);

	lcd.setCursor(1, 3);
	lcd.print(F("---  РУЧ  АВТО УСТ"));
}

void CntDwn(int Time){
	CountDown(Time, 11, 2, 2);
}

void Watch(int Time){
	CountDown(Time, 6, 2, 2);
}

void PauseScreen(){
	lcd.setCursor(0, 0);
	lcd.print(F("-----  "));
	lcd.setCursor(13, 0);
	lcd.print(F("  -----"));

	lcd.setCursor(1, 2);
	lcd.print(F("----"));
	lcd.setCursor(14, 2);
	lcd.print(F(" ----"));
}

void LCD_QQSO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("UP* *DWN skip   ok"));
	lcd.print(F("верх низ  -->   "));
	lcd.print(char(126));
}
void LCD_QQxO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("UP* *DWN  ---   ok"));
	lcd.print(F("верх низ  ---   "));
	lcd.print(char(126));
}
void LCD_SGEO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("up   dwn  quit  ok"));
	lcd.print(F("верх низ выход  "));
	lcd.print(char(126));
}
void LCD_xGEO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("---  dwn  quit  ok"));
	lcd.print(F("---  низ выход  "));
	lcd.print(char(126));
}

void LCD_SxEO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("up   ---  quit  ok"));
	lcd.print(F("верх --- выход  "));
	lcd.print(char(126));
}

void LCD_xxEO(){
	lcd.setCursor(1, 3);
	//lcd.print(F("up   ---  quit  ok"));
	lcd.print(F("--- --- выход  "));
	lcd.print(char(126));
}


void Menu_1(){
	lcd.clear();

	lcd.setCursor(4, 0);
	//lcd.print(F("MANUAL  MODE"));
	lcd.print(F("РУЧНОЙ РЕЖИМ"));
}

void Manuale(float Set, float Temp, float TempBoil){
	lcd.setCursor(1, 1);
	PrintTemp(Temp);

	lcd.setCursor(12, 1);
	if (Set < 100)LCDSpace(1);
	lcd.print(Set);
	lcd.write(2);

	lcd.setCursor(1, 3);
	//lcd.print(F("UP* *DWN Heat Pmp"));
	lcd.print(F("верх низ  ТЭН Насос"));
}


void Menu_2(){
	lcd.clear();

	//lcd.setCursor(3,0);
	//lcd.print(F("AUTOMATIC MODE"));
	lcd.setCursor(0, 0);
	lcd.print(F("АВТОМАТИЧЕСКИЙ РЕЖИМ"));
}
void AddMalt(){
	//lcd.setCursor(2,2);
	lcd.setCursor(1, 2);
	lcd.print(F(" Засыпь  внесена? "));

	LCD_Procedo();
	Buzzer(1, 1000);
}

void Stage(byte Stage, float Set, float Temp){
	lcd.setCursor(0, 0);
	lcd.print(F(" АВТО --> "));
	lcd.print(stageName[Stage]);

	lcd.setCursor(1, 1);
	PrintTemp(Temp);

	lcd.setCursor(8, 1);
	LCDSpace(4);
	if (Set < 100)LCDSpace(1);
	lcd.print(Set);
	lcd.write(2);

	lcd.setCursor(1, 3);
	lcd.print(F("верх низ пауза -->"));
}

void SaltoStep(){
	lcd.setCursor(1, 2);
	lcd.print(F("  Следующий шаг?  "));
	LCD_Procedo();
}

void RemoveMalt(){
	//lcd.setCursor(3,2);
	lcd.setCursor(1, 2);
	lcd.print(F("Дробина извлечена?"));
	LCD_Procedo();
	Buzzer(1, 1500);
}

void Temp_Wait(float Temp){
	lcd.setCursor(1, 1);
	PrintTemp(Temp);
}

void Boil(float Heat, float Temp, byte Tipo){
	if (Tipo == 1){
		lcd.setCursor(0, 0);
		lcd.print(F(" АВТО --> Варка     "));
	}

	lcd.setCursor(1, 1);
	PrintTemp(Temp);

	lcd.setCursor(1, 2);
	lcd.print(F("ШИМ="));    //Display output%
	if (Heat < 100 && Heat >= 10)LCDSpace(1);
	if (Heat < 10)LCDSpace(2);
	lcd.print(Heat, 0); //Display output%
	lcd.print(F("% "));
}

void NoBoil(){
	lcd.setCursor(1, 2);
	LCDSpace(9);
}

void HopAdd(byte HopAdd){
	//lcd.setCursor(10,0);
	lcd.setCursor(1, 0);
	lcd.print(F("  Внесите  хмель  "));
	if (HopAdd < 10)LCDSpace(1);
	lcd.print(HopAdd + 1);
}



void Menu_3(){
	lcd.clear();

	lcd.setCursor(0, 0);
	lcd.print(F("   МЕНЮ УСТАНОВОК   "));
}
void Menu_3_1(){
	lcd.setCursor(1, 1);
	lcd.print(F(" P.I.D. Параметры "));

	LCDClear(2);

	LCD_xGEO();
}
void Menu_3_1_x(byte i){
	lcd.setCursor(1, 2);
	lcd.print(PIDName[i]);
	LCD_QQxO();
}

void PidSet(int pidSet, byte i){
	lcd.setCursor(14, 2);
	if (i < 4)LCDSpace(1);

	if (i < 3 || i == 4 || i == 6){
		if (pidSet <= -10 && pidSet > -100)LCDSpace(1);
		if (pidSet<0 && pidSet>-10)LCDSpace(2);
		if (pidSet < 10 && pidSet >= 0)LCDSpace(3);
		if (pidSet >= 10 && pidSet < 100)LCDSpace(2);
		if (pidSet >= 100)LCDSpace(1);
	}

	if (i == 5){
		float OffSet = pidSet / 10.0;
		if (OffSet >= 0)LCDSpace(1);
		lcd.print(OffSet);
		return;
	}

	lcd.print(pidSet);

	if (i == 4)lcd.print(F("%"));
}

void Menu_3_2(){
	lcd.setCursor(1, 1);
	lcd.print(F("Параметры  системы"));

	LCDClear(2);

	LCD_SGEO();
}

void Menu_3_2_x(byte i){
	lcd.setCursor(1, 2);
	lcd.print(unitName[i]);
	LCD_QQxO();
}

void UnitSet(byte unitSet, byte i){
	//lcd.setCursor(12,2);
	lcd.setCursor(15, 2);
	switch (i){

	case(0) :// Scala Temp
		//lcd.setCursor(17,2);
		//LCDSpace(6);
		LCDSpace(2);
		lcd.write((byte)0);
		break;

	case(1) ://Sensore
		//lcd.setCursor(11,2);
		//LCDSpace(-1);
		if (unitSet == 0)lcd.print(F("Внут"));
		else lcd.print(F("Внеш"));
		break;

	default:// Temperatura di Ebollizione
		//lcd.setCursor(14,2);
		//LCDSpace(3);
		//LCDSpace(0);
		if (unitSet < 100)LCDSpace(1);
		lcd.print(unitSet);
		lcd.write((byte)0);
		break;
		/*
		case(3):// Temperatura di Ebollizione F
		//lcd.setCursor(14,2);
		LCDSpace(3);
		if (unitSet<100)LCDSpace(1);
		lcd.print(unitSet);
		lcd.write((byte)0);
		break;
		*/
	case(4) :// Durata Ciclo Pompa
		//lcd.setCursor(15,2);
		//LCDSpace(4);
		LCDSpace(1);
		if (unitSet < 10)LCDSpace(1);
		lcd.print(unitSet);
		lcd.print(F("'"));
		break;

	case(5) ://Durata Pausa Pompa
		//lcd.setCursor(16,2);
		//LCDSpace(5);
		LCDSpace(2);
		lcd.print(unitSet);
		lcd.print(F("'"));
		break;

	case(6) :
		//lcd.setCursor(15,2);
		//LCDSpace(4);
		//LCDSpace(0);
		if (unitSet == 0)lcd.print(F("Выкл"));
		if (unitSet == 1)lcd.print(F("Вкл "));
		break;

	case(7) :
		//lcd.setCursor(15,2);
		//LCDSpace(3);
		LCDSpace(0);
		if (unitSet < 100)LCDSpace(1);
		lcd.print(unitSet);
		//Gradi();
		lcd.write((byte)0);
	}
}


void Menu_3_3(){
	lcd.setCursor(1, 1);
	lcd.print(F("  Авто параметры  "));
	LCD_SGEO();
}
void Menu_3_3_x(byte Stage){
	lcd.setCursor(1, 2);
	lcd.print(stageName[Stage]);
	if (Stage == 0 || Stage == 6 || Stage == 7)LCD_QQxO();
	else LCD_QQSO();
}

void StageSet(float Temp){
	lcd.setCursor(12, 2);
	PrintTemp(Temp);
}

void TimeSet(int Time){
	lcd.setCursor(12, 2);
	if (Time < 10)LCDSpace(5);
	if (Time >= 10 && Time < 100)LCDSpace(4);
	if (Time>100)LCDSpace(3);
	lcd.print(Time);
	lcd.print(F("'"));
	LCD_QQxO();
}


void Menu_3_3_8(){
	lcd.setCursor(1, 2);
	lcd.print(F("Вносов хмеля    "));
	LCD_QQxO();
}
void NumHops(byte SetNumHops){
	lcd.setCursor(17, 2);
	if (SetNumHops < 10)LCDSpace(1);
	lcd.print(SetNumHops);
}

void Menu_3_3_9(){
	lcd.setCursor(1, 2);
	lcd.print(F("Варка         "));
	LCD_QQxO();
}

void Menu_3_3_10(byte SetHop){
	lcd.setCursor(1, 2);
	//lcd.print(F("№ хмеля ("));
	lcd.print(F("Хмель "));
	lcd.print(char(23));
	if (SetHop < 10)LCDSpace(1);
	lcd.print(SetHop);
	//lcd.print(F(")  "));
	LCD_QQxO();
}

void TimeHops(int Time){
	lcd.setCursor(15, 2);
	if (Time < 10)LCDSpace(2);
	if (Time >= 10 && Time < 100)LCDSpace(1);
	lcd.print(Time);
	lcd.print(F("'"));
}



void Menu_3_4(){
	lcd.setCursor(1, 1);
	lcd.print(F("Менеджер  рецептов"));

	LCDClear(2);

	LCD_SGEO();
	//  LCD_SxEO();
}
void Menu_3_4_1(){
	lcd.setCursor(1, 2);
	lcd.print(F("    Загрузить     "));
	LCD_xGEO();
}
void Menu_3_4_2(){
	lcd.setCursor(1, 2);
	lcd.print(F("    Сохранить     "));
	LCD_SGEO();
}
void Menu_3_4_3(){
	lcd.setCursor(1, 2);
	lcd.print(F("     Удалить      "));
	LCD_SGEO();
}
void Menu_3_4_4(){
	lcd.setCursor(1, 2);
	lcd.print(F("  Инициализация   "));
	LCD_SxEO();
}

void NoRecipe(){
	LCDClear(2);

	lcd.setCursor(1, 3);
	lcd.print(F("Ничего не найдено "));

	Buzzer(3, 50);
	delay(1500);
}

void Ricetta(byte numRicetta, byte Tipo){
	//Tipo 0 = Load
	//Tipo 1 = Save

	lcd.setCursor(2, 2);
	if (numRicetta < 10)lcd.print(F("0"));
	lcd.print(numRicetta);
	lcd.print(F(" > "));

	if (Tipo == 0)LCD_Procedo();
	else{
		lcd.setCursor(1, 3);
		//lcd.print(F("UP* *DWN  back  ok"));
		lcd.print(F("верх низ  назад "));
		lcd.print(char(126));
	}
}

void LCD_NomeRicetta(byte pos, byte Lettera){
	lcd.setCursor(pos + 7, 2);
	lcd.print((char)Lettera);
}

void LeggoRicetta(byte Ricetta){
	LCDClear(2);

	lcd.setCursor(1, 3);
	lcd.print(F("   Загрузка ...   "));
	Buzzer(2, 35);
	delay(1500);

	lcd.setCursor(1, 3);
	//lcd.print(F("Setting "));
	//lcd.print(F("Рецепт "));
	lcd.print(F("   Загружен "));
	lcd.print(char(23));
	if (Ricetta < 10)lcd.print(F("0"));
	lcd.print(Ricetta);
	//lcd.print(F(" Loaded "));
	//lcd.print(F(" загруж "));
	delay(1500);
}


void SalvataggioRicetta(byte Ricetta){
	lcd.setCursor(1, 2);
	//lcd.print(F(" Save Setting  "));
	lcd.print(F(" Сохр. рецепт "));
	lcd.print(char(23));
	if (Ricetta < 10)lcd.print(F("0"));
	lcd.print(Ricetta);
	lcd.print(F("?"));

	LCD_Procedo();
}

void SalvaRicetta(){
	LCDClear(2);

	lcd.setCursor(1, 3);
	lcd.print(F("  Сохранение ...  "));
	Buzzer(5, 35);
	delay(1500);

	lcd.setCursor(1, 3);
	lcd.print(F(" Рецепт сохранен  "));
	delay(1500);
}

void CancelloRicetta(byte Ricetta){
	lcd.setCursor(0, 2);
	//lcd.print(F(" Delete Setting "));
	lcd.print(F(" Удал. рецепт "));
	lcd.print(char(23));
	if (Ricetta < 10)lcd.print(F("0"));
	lcd.print(Ricetta);
	LCDSpace(1);

	LCD_Procedo();
}

void Cancellazione(byte Ricetta){
	LCDClear(2);

	lcd.setCursor(1, 3);
	lcd.print(F("   Удаление ...   "));
	Buzzer(2, 35);
	delay(1500);

	lcd.setCursor(1, 3);
	lcd.print(F("  Рецепт удален   "));
	delay(1500);
}

void Inizializzazione(){
	lcd.setCursor(1, 2);
	lcd.print(F("  Инициализация   "));

	LCD_Procedo();
}
void Inizializza(){
	LCDClear(2);

	lcd.setCursor(1, 3);
	//lcd.print(F(" Initialize EEPROM"));
	lcd.print(F("Инициализ. EEPROM "));
	delay(1500);

	lcd.setCursor(1, 3);
	//lcd.print(F("  EEPROM   ready  "));
	lcd.print(F("  EEPROM   готов  "));
	Buzzer(3, 75);
	delay(1500);
}

void MemoriaPiena(){
	LCDClear(2);

	lcd.setCursor(1, 3);
	//lcd.print(F("    ATTENZIONE    "));
	lcd.print(F("     ВНИМАНИЕ     "));
	Buzzer(3, 125);
	delay(1500);

	lcd.setCursor(1, 3);
	//lcd.print(F("   FULL  MEMORY   "));
	lcd.print(F(" ПАМЯТЬ ЗАПОЛНЕНА "));
	delay(2000);
}


void Menu_3_5(){
	LCDClear(2);
	lcd.setCursor(1, 1);
	lcd.print(F(" Общие  настройки "));
	LCD_SGEO();
}

void Menu_3_5_x(byte i){
	lcd.setCursor(1, 2);
	lcd.print(GeneralName[i]);
	LCD_QQxO();
}

void Menu_3_6(){
	lcd.setCursor(1, 1);
	lcd.print(F("   Дата и время   "));
	LCD_SxEO();
}

void PrintDatetimeM36(String datetime) {
	lcd.setCursor(1, 2);
	lcd.print(datetime);
}

/*void viewCredits(byte X, byte Y, const char* Testo, int Pausa){
  lcd.setCursor(X,Y);
  lcd.print (Testo);
  delay(Pausa);
  }
  void Credits(){
  lcd.clear();
  Intestazione();
  delay(1500);
  viewCredits(2,2,"Idea  Originale:",750);
  viewCredits(2,3,"Stephen Mathison",2000);
  Clear_2_3();
  viewCredits(4,2,"Modifica FW:",750);
  viewCredits(4,3,"Mike  Wilson",1750);
  viewCredits(4,3,"Massimo Nevi",1750);
  Clear_2_3();
  viewCredits(4,2,"PCB & Tests:",750);
  viewCredits(3,3,"  DanielXan ",999);
  viewCredits(3,3,"SavioThechnic",999);
  viewCredits(3,3,"   A. Tidei  ",999);
  viewCredits(3,3," D. Arzarello",999);
  viewCredits(3,3,"L. Di Michele",999);
  Clear_2_3();
  viewCredits(3,2,"Translations:",750);
  viewCredits(3,3," A. Moiseyev ",999);//Russo
  viewCredits(3,3," A. Mondejar ",999);//Spagnolo
  viewCredits(3,3," C.M. Macedo ",999);//Portoghese
  Clear_2_3();
  }*/



/*
void Menu_4(){
lcd.clear();
lcd.setCursor(3,0);
lcd.print(F("TEST DELLA RAM"));
}
void Menu_4_1(){
lcd.setCursor(3,1);
lcd.print(F("Memoria Libera"));
lcd.setCursor(6,2);
//if (freeRam()<1000&&freeRam()>=100)LCDSpace(1);
if (freeRam()<100&&freeRam()>=10)LCDSpace(1);
if (freeRam()<10)LCDSpace(2);
lcd.print(freeRam());
LCDSpace(2);
lcd.print(F("byte"));
LCDClear(3);
delay(3500);
lcd.clear();
}
*/
void GeneralSet(int generalSet, byte i){
	int generalSet_p;

	switch (i)
	{
	case(0) :

		lcd.setCursor(13, 2);
		generalSet_p = generalSet * 100 / 255;
		if (generalSet_p < 10 && generalSet_p >= 0)LCDSpace(3);
		if (generalSet_p >= 10 && generalSet_p < 100)LCDSpace(2);
		if (generalSet_p >= 100)LCDSpace(1);
		lcd.print(generalSet_p);
		lcd.print(F("%"));
		break;

	case (1) :

		lcd.setCursor(13, 2);
		generalSet_p = 100 - generalSet * 100 / 50;
		if (generalSet_p < 10 && generalSet_p >= 0)LCDSpace(3);
		if (generalSet_p >= 10 && generalSet_p < 100)LCDSpace(2);
		if (generalSet_p >= 100)LCDSpace(1);
		lcd.print(generalSet_p);
		lcd.print(F("%"));
		break;

	default:
		lcd.setCursor(14, 2);
		if (generalSet < 10 && generalSet >= 0)LCDSpace(3);
		if (generalSet >= 10 && generalSet < 100)LCDSpace(2);
		if (generalSet >= 100)LCDSpace(1);
		lcd.print(generalSet);
		break;
	}

	//lcd.setCursor(14,2);
	////if(i<2)LCDSpace(1);


	//  // if (generalSet<=-10 && generalSet>-100)LCDSpace(1);
	//   //if (generalSet<0 && generalSet>-10)LCDSpace(2);
	//   if (generalSet<10 && generalSet>=0)LCDSpace(3);
	//   if (generalSet>=10 && generalSet<100)LCDSpace(2);
	//   if (generalSet>=100)LCDSpace(1);

	/*   if(i==5){
		float OffSet=generalSet/10.0;
		if (OffSet>=0)LCDSpace(1);
		lcd.print(OffSet);
		return;
		} */

	//lcd.print(generalSet);

	//if(i==4)lcd.print(F("%"));

}


void Pause_Stage(float Temp, int Time){
	PauseScreen();

	lcd.setCursor(1, 1);
	//lcd.print(F("     In Pause     " ));
	lcd.print(F("      ПАУЗА       "));

	lcd.setCursor(6, 0);
	PrintTemp(Temp);

	//  CountDown(Time,6,2,2);
	Watch(Time);

	lcd.setCursor(1, 3);
	lcd.print(F("---  --- выход ---"));
}

void prompt_for_water(){
	lcd.setCursor(1, 1);
	//lcd.print(F("  Water  Added? "));
	lcd.print(F(" Вода наполнена?  "));
	LCD_Procedo();
	Buzzer(1, 750);
}

void Resume(){
	lcd.setCursor(1, 1);
	lcd.print(F("   Возобновить?   "));
	LCD_Procedo();
	Buzzer(1, 750);
}

void PausaPompa(float Temp, int Time){
	//  if (Ciclo>=225){
	//    Buzzer(2,35);
	//    Ciclo=0;
	//  }

	lcd.setCursor(1, 1);
	PrintTemp(Temp);

	//  CountDown(Time,11,2,2);
	CntDwn(Time);

	lcd.setCursor(1, 3);
	lcd.print(F("- Простой насоса -"));

	//  Ciclo++;
}

void Iodine(float Temp, int Time){
	PauseScreen();


	lcd.setCursor(1, 1);
	lcd.print(F("   Йодная проба   "));

	lcd.setCursor(7, 0);
	PrintTemp(Temp);

	//  CountDown(Time,6,2,2);
	Watch(Time);

	lcd.setCursor(1, 3);
	lcd.print(F("---  ---   Да  ---"));
}

void End(){
	lcd.clear();

	delay(500);
	//Buzzer(3,250);

	lcd.setCursor(4, 1);
	lcd.print(F("Варка  сусла"));
	lcd.setCursor(6, 2);
	lcd.print(F("окончена"));

	Buzzer(1, 3000);
	delay(2500);
}

void PumpPrime(){
	lcd.setCursor(2, 1);
	lcd.print(F("Прокачка насоса"));  // priming the pump
}

void ledHeatON(){
	lcd.setCursor(0, 1);
	lcd.write(6);
	lcd.setCursor(19, 1);
	lcd.write(6);

}

void ledHeatStatus(boolean mheat){
	lcd.setCursor(0, 1);
	if (mheat)lcd.write(5);
	else LCDSpace(1);
	lcd.setCursor(19, 1);
	if (mheat)lcd.write(5);
	else LCDSpace(1);
}

void ledPumpON(){
	lcd.setCursor(0, 2);
	lcd.write(4);
}

void ledPumpStatus(boolean mpump){
	lcd.setCursor(0, 2);
	if (mpump)lcd.write(3);
	else LCDSpace(1);
}

void ArdBir(){
	Presentazione(2, 1);
	ArdBir1(6, 1);
}

void PartenzaRitardata(){
	Clear_2_3();
	lcd.setCursor(1, 1);
	lcd.print(F("Запустить  сейчас?"));
	//lcd.setCursor(13,3);
	//lcd.print(F("Yes No"));
	LCD_Procedo();
}

void ImpostaTempo(unsigned long Time){
	lcd.setCursor(1, 1);
	lcd.print(F("Установка отсрочки"));

	CountDown(Time * 60, 6, 2, 2);

	LCD_SGEO();
}

void StartDelay(unsigned long Tempo){
	lcd.setCursor(1, 1);
	lcd.print(F("   Запуск через   "));
	CountDown(Tempo, 6, 2, 2);
}

void TemperaturaRaggiunta(){
	LCDClear(2);
	lcd.setCursor(1, 2);
	lcd.print(F("Темп-ра достигнута"));
	//lcd.setCursor(1,3);
	//lcd.print(F("Continue: Yes --- "));
	LCD_Conferma();
}
