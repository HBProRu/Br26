#define DS1307_I2C_ADDRESS 0x68

byte decToBcd(byte val)
{
	return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val)
{
	return ((val / 16 * 10) + (val % 16));
}

void setDateDs1307(byte second,        // 0-59
	byte minute,        // 0-59
	byte hour,          // 1-23
	byte dayOfWeek,     // 1-7
	byte dayOfMonth,    // 1-28/29/30/31
	byte month,         // 1-12
	byte year)          // 0-99
{
	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write(0);
	Wire.write(decToBcd(second));
	Wire.write(decToBcd(minute));
	Wire.write(decToBcd(hour));
	Wire.write(decToBcd(dayOfWeek));
	Wire.write(decToBcd(dayOfMonth));
	Wire.write(decToBcd(month));
	Wire.write(decToBcd(year));
	Wire.endTransmission();
}

void getDateDs1307(byte *second,
	byte *minute,
	byte *hour,
	byte *dayOfWeek,
	byte *dayOfMonth,
	byte *month,
	byte *year)
{

	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write(0);
	Wire.endTransmission();

	Wire.requestFrom(DS1307_I2C_ADDRESS, 7);

	*second = bcdToDec(Wire.read() & 0x7f);
	*minute = bcdToDec(Wire.read());
	*hour = bcdToDec(Wire.read() & 0x3f);
	*dayOfWeek = bcdToDec(Wire.read());
	*dayOfMonth = bcdToDec(Wire.read());
	*month = bcdToDec(Wire.read());
	*year = bcdToDec(Wire.read());
}

void getDateDs(byte pdata[3])
{
	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write(0);
	Wire.endTransmission();

	Wire.requestFrom(DS1307_I2C_ADDRESS, 7);

	//*second
	pdata[0] = bcdToDec(Wire.read() & 0x7f);
	//*minute
	pdata[1] = bcdToDec(Wire.read());
	//*hour
	pdata[2] = bcdToDec(Wire.read() & 0x3f);
	//  *dayOfWeek  = bcdToDec(Wire.read());
	//  *dayOfMonth = bcdToDec(Wire.read());
	//  *month      = bcdToDec(Wire.read());
	//  *year       = bcdToDec(Wire.read());
	//  Serial.print(hour, DEC);
	//  Serial.print(":");
	//  Serial.print(minute, DEC);
	//  Serial.print(":");
	//  Serial.print(second, DEC);
	//  Serial.print("  ");
}

void setupe()
{
	byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
	Wire.begin();
	//Serial.begin(9600);

	//  second = 45;
	//  minute = 06;
	//  hour = 2;
	//  dayOfWeek = 5;
	//  dayOfMonth = 13;
	//  month = 06;
	//  year = 14;
	//  setDateDs1307(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
	//  setDateDs1307(timeExtract.sec, timeExtract.min, timeExtract.hour, timeExtract.wday, timeExtract.mday, timeExtract.mon, timeExtract.year);
}

void loope()
{
	byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

	getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);

	//  Serial.print(hour, DEC);
	//  Serial.print(":");
	//  Serial.print(minute, DEC);
	//  Serial.print(":");
	//  Serial.print(second, DEC);
	//  Serial.print("  ");
	//  Serial.print(month, DEC);
	//  Serial.print("/");
	//  Serial.print(dayOfMonth, DEC);
	//  Serial.print("/");
	//  Serial.print(year, DEC);
	//  Serial.print("  Day_of_week:");
	//  Serial.println(dayOfWeek, DEC);

	//delay(1000);
}