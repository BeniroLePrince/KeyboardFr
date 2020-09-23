#include "KeyboardFr.h"

/*
 * KeyboardFr test
 *
 * For the Arduino Leonardo, Micro or Due
 *
 * After initializing the connection, this program simulates pressing
 * all the keys corresponding to an ASCII character on an AZERTY
 * keyboard :
 *
 *     ! " # $ % & ' ( )
 *   * + , - . / 0 1 2 3
 *   4 5 6 7 8 9 : ; < =
 *   > ? @ A B C D E F G
 *   H I J K L M N O P Q
 *   R S T U V W X Y Z [
 *   \ ] ^ _ ` a b c d e
 *   f g h i j k l m n o
 *   p q r s t u v w x y
 *   z { | } ~
 *
 * The circuit:
 * - none
 */

void setup() {
	Keyboard.begin();

	delay(2000);

    char c;

    for (c=' ';c<='~';c++) {
        Keyboard.write(' ');
        Keyboard.write(c);
        if ((c-' '+1) % 10 == 0) {
    	    Keyboard.press(KEY_RETURN);Keyboard.release(KEY_RETURN);
        }
    }

    /*
     * Note : It is possible to send a key code directly, instead of
     * a letter. To do this, add 0x88 to the key code (available at
     * https://raw.githubusercontent.com/msommacal/KeyboardFr/master
     * /img/key_code.png).
     *
     * Thus the following line displays the character "è":
     * Keyboard.write(0x24+0x88);
     */

    Keyboard.end();
}

void loop() {
	// nothing
}
