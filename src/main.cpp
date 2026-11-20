/**
 * VÍ DỤ 5-2b: VỆ TINH NHẬN LỆNH ĐIỀU KHIỂN QUA THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_EPS eps;
PTIT_COM myLoRa;

void setup() {
    cdh.begin(115200);

    // Kích hoạt hạ áp cấp nguồn ngoại vi trên PCB vệ tinh qua thư viện EPS
    eps.setBuckState(true);

    myLoRa.init();
}

void loop() {
    String cmd = myLoRa.update();
    if (cmd.length() > 0) {
        cdh.println("RX: " + cmd);
    }
    delay(10);
}
