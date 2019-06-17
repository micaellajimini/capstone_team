# 너의 목소리가 들려
###### team project in capstone_design I
<br/>
    
## Introduction <img src="https://github.com/micaellajimini/capstone_team/blob/master/image/introduction.png" width=30> 
어린이집 등하원 차량에 아이가 혼자 남겨질 경우, 이를 파악하여 운전자, 어린이집 선생님, 또는 부모님에게 알려주는 서비스<br/>
차량이 현재 주행 중인지, 정차 중인지, 또는 완전히 주차한 상황인지를 파악하고 차량 내부에 아이가 남아있는지를 파악합니다
<br/><br/>
## Technology
<img src="https://github.com/micaellajimini/capstone_team/blob/master/image/diagram.png" width=750>

1. PART 1
    - **Node.js** ~~(or Django)~~ 이용하여 **EC2**에서 웹서버 구동
    - Node MCU 1 에서 운전자 유무 판단 후 서버로 전송
    - Node MCU 2 에서 서버로부터 운전자 유무 정보 얻음
    - Node MCU 2 에서 **마이크 모듈**로부터 값을 받아옴
    - FFT를 통하여 시간당 amplitude => 주파수별 amplitude 로 변환
    - Node MCU에서 다른 센서로부터 값을 받아 자체 알고리즘을 통해 차내 유아 유무 판단
    - 아이 유무 판단 결과 서버로 전송

2. PART 2
    - 서버에 알림 요청이 들어오면 **line notify api** 를 통해 알림    
    

<br/>

## Dataflow in detail
<img src="https://github.com/micaellajimini/capstone_team/blob/master/image/dataflow.png" width=600>
<br/>

##### **_네트워크가 연결되어 있음. 아두이노에 전원이 공급되어 있음을 가정_**
* 아이 좌석 위 마이크모듈을 부착한 아두이노 설치 후 데이터 수집`데이터 발생`
* 운전자 좌석 위 초음파거리센서를 부착한 아두이노 설치 후 데이터 수집`데이터 발생`
* 데이터 분석 후 정지상태의 데이터 기준과 아기 울음소리 주파수 영역 얻기`데이터 분석`
* 마이크 모듈, 초음파거리센서, PIR센서를 이용해 **약 1초에 한 번씩** 데이터 측정`현재 데이터 측정`
* 마이크를 통해 입력되는 소리의 세기 변화를 일시적으로 모음`데이터 수집`
* 측정한 데이터가 운전자가 없고 + 차가 정지한 상태이고 + 아기 울음소리 주파수 영역에 해당되면 line api으로 알림 보내기`endpoint`
* 측정한 데이터가 운전자가 없고 + 차가 정지한 상태이고 + 어른이라고 알림이 오지 않았을 경우 line api으로 알림 보내기`endpoint`
~~<br/> _to be continued_
* PIR센서를 사용하여 아기의 움직임 감지하여 아기 울음소리 감지 기능과 함께 판단하여 신뢰도 높이기~~

> Advice 
* 차 안의 온도, 산소, 이산화탄소 농도같은 요소도 측정해보시는게 좋아보입니다.
* ~~체온센서 활용 등 더 다양한 센서로 측정 필요~~

## Code

[Arduino code](https://github.com/micaellajimini/capstone_team/blob/master/merge/merge.ino)
<br/>
[Server code](https://github.com/micaellajimini/capstone_team/blob/master/index.js)

## How to use

* config_wifi.h
```
const char * wifiName = "";
const char * passwd = "";
```

* Arduino PinMode
```
#define ~~
#define ~~

in arduino code
```

* Install Line app
