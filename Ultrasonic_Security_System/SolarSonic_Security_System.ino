#define trigPin 2
//второй пин отвечает за отправку ультразвука
//the second pin is responsible for sending ultrasound
#define echoPin 3
//третий пин отвечает за принятие ульразвука
//the third pin is responsible for reading ultrasound
#define LEDlampRed 4
//положительный полюс красной лампочки установлен на 4 пине
//the positive pole of the red light is set to 4 pin
#define LEDlampYellow 5
//положительный полюс жёлтой лампочки установлен на 5 пине
//the positive pole of the yellow light bulb is set to 5 pin
#define LEDlampGreen 6 
//положительный полюс зелёной лампочки установлен на 6 пине
//the positive pole of the green light is set to 6 pin
#define soundbuzzer 7
//положительный полюс пъезоизлучателя (пищалки) подключается к 7 пину
//the positive pole of the piezo-emitter is connected to 7 pin
int sound = 500;
//тональность звука - 500 : писк на 0.5 секунд
//sound tone - 500 : a squeak for 0.5 seconds


void setup() {
  //повторяется 1 раз при включении
  //repeat 1 time at power on
  Serial.begin (9600);
  //обновление информации со скоростью 9600 бит в секунду
  //update the information at a speed of 9600 bits per second
  pinMode(trigPin, OUTPUT);
  //настраивается порт, отвечающий за чтение ультразвука
  //configure the port responsible for ultrasound reading
  pinMode(echoPin, INPUT);
  //настраивается порт, отвечающий за отправку ультразвука
  //configure the port responsible for ultrasound sending
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  //настраиваются лампочки
  //LED lamps are configured
  pinMode(soundbuzzer, OUTPUT);
  //piezo-emitter is tuned
  //настраивается пищалка
 
}
void loop() {
  //действие будет повторяться до выключения
  //the action will be repeated until the shutdown
  long durationindigit, distanceincm;
  //вводится 2 переменные, которые будут округляться до целого значения
  //2 variables are deaclared, which will be rounded to the whole value
  //'long' - целочисленный тип данных
  //integer data type without a comma
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //настройка датчика 'ultrasonic' который отправляет сигнал 10 мс с
  //setting the 'ultrasonic' sensor which sends a 10 ms signal with
  //задержкой в 2 мс
  //2 ms delay
  durationindigit = pulseIn(echoPin, HIGH);
  //считывает изменение в расстоянии
  //reads the change in distance
  distanceincm = (durationindigit/5) / 29.1;
  //преобразует принятые данные в сантиметры
  //converts received data into centimeters
 
  if (distanceincm < 50) {
      digitalWrite(LEDlampGreen, HIGH);
      //если расстояние до датчика 'ultrasonic' не превышает 50 см,
      //то загорается зелёный светодиод
      //if the distance to the 'ultrasonic' sensor does not exceed 50 cm,
      //then the green LED lights up
}
  else {
      digitalWrite(LEDlampGreen, LOW);
      //если нет, то зелёный светодиод не загорается
      //if not, the green LED does not light up
  }
  
  if (distance < 20) {
    digitalWrite(LEDlampYellow, HIGH);
    //если расстояние до датчика 'ultrasonic' не превышает 20 см,
    //то загорается жёлтый светодиод
    //if the distance to the 'ultrasonic' sensor does not exceed 20 cm,
    //then the yellow LED lights up
}
  else {
    digitalWrite(LEDlampYellow,LOW);
    //если нет, то жёлтый светодиод не загорается
    //if not, the yellow LED does not light up
  }
  if (distance < 5) {
    digitalWrite(LEDlampRed, HIGH);
    sound = 1000;
    //если расстояние до датчика 'ultrasonic' не превышает 5 см,
    //то загорается красный светодиод и пъезоизлучатель пищит с тональностью 1000
    //if the distance to the 'ultrasonic' sensor does not exceed 5 cm,
    //then the red LED lights up and the piezo-emitter beeps with a tonality of 1000
}
  else {
    digitalWrite(LEDlampRed,LOW);
    //если нет, то красный светодиод не загорается
    //if not, the red LED does not light up
  }
 
  if (distanceincm > 5 || distanceinsm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
    //'ultrasonic' не корректно наблюдает расстояние между 0 и 5 см
    //эта самая ошибка передаётся в монитор порта
    //пьезо молчит
    //'ultrasonic' does not correctly observe the distance between 0 and 5 cm
    //this error is passed to the port monitor
    //piezo is silent
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
    //если полученная информация не входит в диапазон ошибки, то 
    //программа выводит измеренную информацию в сантиметрах, что 
    //отображается на мониторе порта
    //if the information received is not within the error range, then
    //the program displays the measured information in centimeters, that
    //displayed on the port monitor
  }
  delay(300);
  //предыдущие действия продолжаются 0.3 секунды, после чего
  //алгоритм прерывается и повторяется в очередной раз
  //the previous actions continue for 0.3 seconds, after which
  //the algorithm is interrupted and repeated one more time
}
