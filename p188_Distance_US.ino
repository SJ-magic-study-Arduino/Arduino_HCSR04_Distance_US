/************************************************************
■参考
	■Arduino 電子工作 実践講座
		p188
	
■超音波距離センサーの使い方(HC-SR04)
	https://nobita-rx7.hatenablog.com/entry/27884818

■ＨＣ－ＳＲ０４データシートＰＤＦ
	https://akizukidenshi.com/download/ds/sainsmar/hc-sr04_ultrasonic_module_user_guidejohn_b.pdf

■距離計 > Link > HC-SR04 > Opening angle > 30度(左右15度ずつ)くらい
	https://qiita.com/7of9/items/0e2fa318d10be7ccc1ca
		HC-SR04の画角は、中心方向から左右15deg程度らしい

■光学式センサと超音波センサの比較
	■超音波センサと光学式センサの比較
		https://www.keyence.co.jp/ss/products/sensor/sensorbasics/us_comparison.jsp
	
	■距離センサーとは？Arduinoとの互換性を言えば、どれを選ぶ？距離測定センサーの種類と選択方法
		https://jp.seeedstudio.com/blog/2020/08/10/distance-sensors-types-and-selection-guide/
	
	■距離測定をするセンサとは？使用環境による最適解を提案！
		https://emb.macnica.co.jp/articles/8294/
	
	■ToFセンサを使用した距離測定とジェスチャ認識の基礎
		https://www.digikey.jp/ja/articles/fundamentals-distance-measurement-gesture-recognition-tof-sensors
		
■自動運転実現で注目を集める LiDARのしくみと種類（1/2）
	https://www.keyence.co.jp/ss/general/automotive-manufacturing/010/
************************************************************/
#define PLOTTER

/************************************************************
************************************************************/
#include "HCSR04.h"

/************************************************************
************************************************************/
const int TRIG = 6;
const int ECHO = 7;

HCSR04 hcsr04( TRIG, ECHO );

/************************************************************
************************************************************/

/******************************
******************************/
void setup(){
	hcsr04.begin();

	Serial.begin( 9600 );
}

/******************************
******************************/
void loop(){
	float distance;
	
#ifdef PLOTTER
	Serial.print( millis() / 1000 % 2 * 10 );
	Serial.print(",");
	
	distance = hcsr04.get_length();
	if ( distance != -1 ){
		Serial.println( distance );
	} else {
		Serial.println(-1);
	}

	delay (100);
	
#else
	distance = hcsr04.get_length();
	if ( distance != -1 ){
		Serial.print("Distance:");
		Serial.print( distance );
		Serial.println("cm");
	} else {
		Serial.println("Out Range.");
	}
	
	delay (1000);
#endif
	
}

