#include <IRremote.h>

#define IR_SEND_PIN 3
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

    // Imprime el protocolo detectado
    switch (IrReceiver.decodedIRData.protocol) {
      case SAMSUNG:
        Serial.println("Protocolo Samsung detectado");
        break;
      case LG:
        Serial.println("Protocolo LG detectado");
        break;
      case NEC:
        Serial.println("Protocolo NEC detectado");
        break;
      case SONY:
        Serial.println("Protocolo Sony detectado");
        break;
      case RC5:
        Serial.println("Protocolo RC5 detectado");
        break;
      case RC6:
        Serial.println("Protocolo RC6 detectado");
        break;
      default:
        Serial.println("Protocolo desconocido");
        break;
    }
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
  Serial.println("Créditos:");
  Serial.println("Equipo 2");
  Serial.println("Integrantes:");
  Serial.println("Diaz Espinosa Christian Alejandro");
  Serial.println("Garcia Ramos Joe Jafet");
  Serial.println("Sanchez Vivar Zaida");
  Serial.println("Velazco Hernandez Angel Uriel");
  Serial.println("Yanez Ramirez Itzel");
  Serial.println("Roa Carrillo Zayuri Denisse");
}

void menu(char opc) {
  switch (opc) {
    case 'a':
      Serial.println("Opción a: Encender Blu-ray");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCF302D2D, 32);  // Código IR para encender el Blu-ray
      Serial.println("Enviado");
      delay(2000);
      break;
    case 'b':
      Serial.println("Opción b: Abrir bandeja");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xC9362D2D, 32);  // Código IR para abrir la bandeja
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'c':
      Serial.println("Opción c: Avanzar");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCC332D2D, 32);  // // Código IR para la acción "Avanzar"
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'd':
      Serial.println("Opción d: Retroceder");
      Serial.flush();                   // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCD32D2D, 32);  // Código IR para la accion "Retroceder" pararetroceder
      Serial.println("Enviado");
      delay(2000);                      // Espera a 2 segundos antes de continuar
      break;
    case 'e':
      Serial.println("Opción e : Siguiente");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCD342D2D, 32);  // Código IR para la accion "Siguiente" parasiguiente
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'f':
      Serial.println("Opción f: Regresar");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCA352D2D, 32);  // Código IR para la accion "Regresar" pararegresar
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'g':
      Serial.println("Opción g: Reproduccion");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCE312D2D, 32);  // Código IR para la accion "Reproducir" parareproducir
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'h':
      Serial.println("Opción h: Pausa");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xC7382D2D, 32);  // Código IR para la accion "Pausar" parapausar
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'i':
      Serial.println("Opción i: Arriba");
      Serial.flush();                     // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xCB8472D2D, 32);  // Código IR para la accion "Arriba" paraarriba
      Serial.println("Enviado");
      delay(2000);                        // Espera a 2 segundos antes de continuar
      break;
    case 'j':
      Serial.println("Opción j: Abajo");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xB7482D2D, 32);  // Código IR para la accion "Abajo" paraabajo
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'k':
      Serial.println("Opción k: izquierda");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xA6592D2D, 32);  // Código IR para la accion "Izquierda" paraizquierda
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
      break;
    case 'l':
      Serial.println("Opción l: Derecha");
      Serial.flush();                    // Espera a que se envíen completamente los datos por el puerto serial
      IrSender.sendNEC(0xA55A2D2D, 32);  // Código IR para la accion "Derecha" para derecha
      Serial.println("Enviado");
      delay(2000);                       // Espera a 2 segundos antes de continuar
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
