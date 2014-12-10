// Define CC3000 chip pins
//#define ADAFRUIT_CC3000_IRQ   8
//#define ADAFRUIT_CC3000_VBAT  9
//#define ADAFRUIT_CC3000_CS    10
Adafruit_CC3000 cc3000 = Adafruit_CC3000(SPI_CLOCK_DIV2);//ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
uint32_t ip;
int port = 80;
// WiFi network (change with your settings !)
//#define WLAN_SSID       "ABCD"        // cannot be longer than 32 characters!
//#define WLAN_PASS       "0987654321"
#define WLAN_SSID       "MyInet"        // cannot be longer than 32 characters!
#define WLAN_PASS       "Inet724I"

#define WLAN_SECURITY   WLAN_SEC_WPA2 // This can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WEBSITE         "dvc.hbpro.ru"
#define IDLE_TIMEOUT_MS  100
//----------------------------------------SNTP------------------------------------------//
sntp mysntp = sntp(NULL, "time.nist.gov", (short)(+4 * 60), (short)(+4 * 60), true);

// Type SNTP_Timestamp is 64-bit NTP time. High-order 32-bits is seconds since 1/1/1900
//   Low order 32-bits is fractional seconds
SNTP_Timestamp_t now;

// Type NetTime_t contains NTP time broken out to human-oriented values:
//	uint16_t millis; ///< Milliseconds after the second (0..999)
//	uint8_t	 sec;    ///< Seconds after the minute (0..59)
//	uint8_t	 min;    ///< Minutes after the hour (0..59)
//	uint8_t	 hour;   ///< Hours since midnight (0..23)
//	uint8_t	 mday;   ///< Day of the month (1..31)
//	uint8_t	 mon;    ///< Months since January (0..11)
//	uint16_t year;   ///< Year.
//	uint8_t	 wday;	 ///< Days since Sunday (0..6)
//	uint8_t	 yday;   ///< Days since January 1 (0..365)
//	bool	 isdst;  ///< Daylight savings time flag, currently not supported
NetTime_t timeExtract;

#define pF(string_pointer) (reinterpret_cast<const __FlashStringHelper *>(pgm_read_word(string_pointer)))

const prog_char   janStr[] PROGMEM = "January";
const prog_char   febStr[] PROGMEM = "February";
const prog_char   marStr[] PROGMEM = "March";
const prog_char   aprStr[] PROGMEM = "April";
const prog_char   mayStr[] PROGMEM = "May";
const prog_char   junStr[] PROGMEM = "June";
const prog_char   julStr[] PROGMEM = "July";
const prog_char   augStr[] PROGMEM = "August";
const prog_char   sepStr[] PROGMEM = "September";
const prog_char   octStr[] PROGMEM = "October";
const prog_char   novStr[] PROGMEM = "November";
const prog_char   decStr[] PROGMEM = "December";

PROGMEM const char* const monthStrs[] = { janStr, febStr, marStr, aprStr, mayStr, junStr,
julStr, augStr, sepStr, octStr, novStr, decStr };

const prog_char   sunStr[] PROGMEM = "Sunday";
const prog_char   monStr[] PROGMEM = "Monday";
const prog_char   tueStr[] PROGMEM = "Tuesday";
const prog_char   wedStr[] PROGMEM = "Wednesday";
const prog_char   thuStr[] PROGMEM = "Thursday";
const prog_char   friStr[] PROGMEM = "Friday";
const prog_char   satStr[] PROGMEM = "Saturday";

PROGMEM const char* const dayStrs[] = { sunStr, monStr, tueStr, wedStr,
thuStr, friStr, satStr };
//----------------------------------------SNTP------------------------------------------//

/* ########## Other Functions ########## */
bool displayConnectionDetails(void)
{
	uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;

	if (!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv, &dnsserv))
	{
		Serial.println(F("Unable to retrieve the IP Address!"));
		return false;
	}
	else
	{
		Serial.println("Connection info...");
		Serial.print(F("\nIP Addr: ")); cc3000.printIPdotsRev(ipAddress);
		Serial.print(F("\nNetmask: ")); cc3000.printIPdotsRev(netmask);
		Serial.print(F("\nGateway: ")); cc3000.printIPdotsRev(gateway);
		Serial.print(F("\nDHCPsrv: ")); cc3000.printIPdotsRev(dhcpserv);
		Serial.print(F("\nDNSserv: ")); cc3000.printIPdotsRev(dnsserv);
		Serial.println("\n");
		return true;
	}
}

void cc3000_init()
{
	Serial.begin(115200);
	Serial.println("If you start me up...");

	// Initialise the CC3000
	Serial.println(F("\nInitialising the CC3000..."));
	if (!cc3000.begin())
	{
		Serial.println(F("Unable to initialise the CC3000! Check your wiring?"));
		while (1);
	}

	// Delete old connection data
	Serial.println(F("Deleting old connection profiles..."));
	if (!cc3000.deleteProfiles()) {
		Serial.println(F("Failed!"));
		while (1);
	}

	// Connect to Wifi
	Serial.print(F("Attempting to connect to ")); Serial.print(WLAN_SSID); Serial.println(F("..."));

	if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
		Serial.println(F("Failed!"));
		while (1);
	}

	Serial.print(F("Connected to ")); Serial.print(WLAN_SSID); Serial.println(F("..."));


	// Wait for DHCP to finish
	Serial.println(F("Request DHCP..."));
	while (!cc3000.checkDHCP())
	{
		delay(100); // ToDo: Insert a DHCP timeout!
	}


	// Show the connection details
	while (!displayConnectionDetails()) {
		delay(1000);
	}
}

// NTP Set time
void UpdateNTPTime()
{
	Serial.println(F("UpdateNTPTime"));
	mysntp.UpdateNTPTime();

	Serial.println(F("Current local time is:"));
	mysntp.ExtractNTPTime(mysntp.NTPGetTime(&now, true), &timeExtract);

	Serial.print(String(timeExtract.hour).toInt());
	Serial.print(F(":"));
	Serial.print(String(timeExtract.min).toInt());
	Serial.print(F(":"));
	Serial.print(String(timeExtract.sec).toInt());
	Serial.print(F("."));
	Serial.println(String(timeExtract.millis).toInt());
	//Serial.print(pF(&dayStrs[timeExtract.wday]));
	Serial.print(F("Days since Sunday: "));
	Serial.println(String(timeExtract.wday + 1).toInt());
	Serial.print(F("Day of the month: "));
	Serial.println(String(timeExtract.mday).toInt());
	Serial.print(F("Months since January: "));
	Serial.println(String(timeExtract.mon + 1).toInt());
	Serial.print(F("Year: "));
	Serial.println(String(timeExtract.year).toInt());


}


// This is the function that the wifi weather station used in their example
void send_request(String request)
{

	ip = 0;
	// Try looking up the website's IP address
	Serial.print(WEBSITE); Serial.print(F(" -> "));
	while (ip == 0) {
		if (!cc3000.getHostByName(WEBSITE, &ip)) {
			Serial.println(F("Couldn't resolve!"));
		}
		delay(500);
	}

	cc3000.printIPdotsRev(ip);

	Adafruit_CC3000_Client www = cc3000.connectTCP(ip, 80);
	if (www.connected()) {
		www.print(request);
		www.print(F("Host: "));
		www.print(WEBSITE);
		www.print(F("\r\n"));
		www.print(F("User-Agent: Uniholic/1.0\r\n"));
		www.print(F("\r\n"));
		www.println();
	}
	else {
		Serial.println(F("Connection failed"));
		return;
	}

	Serial.println(F("-------------------------------------"));

	/* Read data until either the connection is closed, or the idle timeout is reached. */
	unsigned long lastRead = millis();
	while (www.connected() && (millis() - lastRead < IDLE_TIMEOUT_MS)) {
		while (www.available()) {
			char c = www.read();
			Serial.print(c);
			lastRead = millis();
		}
	}
	www.close();
	Serial.println(F("-------------------------------------"));


}
