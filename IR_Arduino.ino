#include <IRremote.h>

#define IR_SEND_PIN 2
#define IR_RECEIVE_PIN 11     // Se puede omitir la definición de IR_RECEIVE_PIN si se utiliza el pin 2, que es el predeterminado para la recepción en la librería IRremote.
unsigned long key_value = 0;  // Variable para almacenar el valor de la tecla


void setup() {
  Serial.begin(9600);                                                                                     // Inicializa la comunicación serial
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\n Using library version " VERSION_IRREMOTE));  // se imprime en el monitor la informacion del archivo de donde se esta compilando, la fecha y la version de libreria que se esta ocupando
  Serial.println("Conexión Serial realizada");

  IrReceiver.begin(IR_RECEIVE_PIN);  // Inicializa el receptor IR en el pin especificado
  Serial.print(F("Listo para recibir señal de "));
  Serial.println();
  IrSender.begin(IR_SEND_PIN);  //Inicializa el emisor en el pin especificado
  Serial.print(F("Emisor Iniciado correctamente"));
}

void loop() {
  if (IrReceiver.decode()) {  // Si el receptor ha decodificado una señal, entra en el if
    key_value = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Código recibido en HEX: ");
    Serial.println(key_value, HEX);  //se imprime en valor hexadecimal la informacion proveniente del control remoto, se recive como argumento key_value

    IrReceiver.printIRResultShort(&Serial); //Imprime la informacion recibida, protocolo, comando recibido, informacion RAW, bits
    IrReceiver.printIRSendUsage(&Serial);//Imprime la manera correcta de enviarlo a traves de IRSender 

    Serial.println();
    IrReceiver.resume();
    Serial.println("Espere al siguiente mensaje para recibir el siguiete codigo");
    Serial.println("Listo para recibir el siguiente codigo");
  }


  if (Serial.available()) {
    // Lee el carácter que se envia desde el bluetooth
    char opc = Serial.read();
    menu(opc);  // Llama a la función menú
  }
}
//funcion que imprime los creditos
void imprimirCreditos() {
  
}

void menu(char opc) {
  switch (opc) {
    case 'a':
      Serial.println("Opción a: Encender Blu-ray");
      Serial.flush();  // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x15, 2, 20);
      Serial.println("Enviado");
      delay(2000);
      break;
    case 'b':
      Serial.println("Opción b: Abrir bandeja");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x16, 2, 20);// Código IR para abrir la bandeja
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'c':
      Serial.println("Opción c: Avanzar");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x1C, 2, 20); // // Código IR para la acción "Avanzar"
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'd':
      Serial.println("Opción d: Retroceder");
      Serial.flush();                   // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x1B, 2, 20);  // Código IR para la accion "Retroceder" pararetroceder
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'e':
      Serial.println("Opción e : Siguiente");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x56, 2, 20);  // Código IR para la accion "Siguiente" parasiguiente
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'f':
      Serial.println("Opción f: Regresar");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x57, 2, 20);  // Código IR para la accion "Regresar" pararegresar
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'g':
      Serial.println("Opción g: Reproduccion");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x1A, 2, 20);  // Código IR para la accion "Reproducir" parareproducir
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'h':
      Serial.println("Opción h: Pausa");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x19, 2, 20);  // Código IR para la accion "Pausar" parapausar
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'i':
      Serial.println("Opción i: Arriba");
      Serial.flush();                     // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x39, 2, 20);  // Código IR para la accion "Arriba" paraarriba
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'j':
      Serial.println("Opción j: Abajo");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x3A, 2, 20);  // Código IR para la accion "Abajo" paraabajo
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'k':
      Serial.println("Opción k: izquierda");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x3B, 2, 20);  // Código IR para la accion "Izquierda" paraizquierda
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'l':
      Serial.println("Opción l: Derecha");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendSony(0x1C5A, 0x3C, 2, 20);  // Código IR para la accion "Derecha" para derecha
      Serial.println("Enviado");
      delay(2000);  // Espera a 2 segundos antes de continuar
      break;
    case 'm':
      Serial.println("Imprimir creditos");
      imprimirCreditos();  //Lamado a funcion de imprimir creditos
      delay(2000);         // Espera a 2 segundos antes de continuar
      break;
    default:
      Serial.println("Opción no válida");
      break;
  }
}
