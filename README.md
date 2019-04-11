# 너의 목소리가 들려
###### team project in capstone_design I
<br/>
    
## Introduction
어린이집 등하원 차량에 아이가 혼자 남겨질 경우, 이를 파악하여 운전자, 어린이집 선생님, 또는 부모님에게 알려주는 서비스<br/>
차량이 현재 주행 중인지, 정차 중인지, 또는 완전히 주차한 상황인지를 파악하고 차량 내부에 아이가 남아있는지를 파악합니다
<br/><br/>
## Technology
<img src="https://github.com/micaellajimini/capstone_team/blob/master/diagram.jpeg" width=210>

1. PART 1
    - **Node.js** ~~(or Django)~~ 이용하여 **EC2**에서 웹서버 구동
    - Node MCU에서 **마이크 모듈**로부터 값을 받아 서버로 보냄
    - EC2에 **RDS**를 설치하고 데이터 모으기
    - 서버 내에 **python**으로 FFT 알고리즘 통해 아이 울음 소리 주파수 추출 프로그램 만들기

2. PART 2
    - 데이터 받아오는 과정은 똑같음
    - 서버에 아이 울음 소리 주파수에 해당하는 주파수의 값이 있으면 **pushbullet** application을 통해 알림하는 프로그램 만들기
    
    

<br/>

## Dataflow in detail
<img src="https://github.com/micaellajimini/capstone_team/blob/master/dataflow.png" width=500>
<br/>

##### **_네트워크가 연결되어 있음. 아두이노에 전원이 공급되어 있음을 가정_**
* 자동차 실내 내부에 마이크모듈을 부착한 아두이노 설치 후 데이터 수집`데이터 발생`
* 진동센서 ~~(or 자이로/가속기 센서)~~ 의 데이터 DB에 모음`데이터 수집`
* 마이크를 통해 입력되는 소리의 세기 변화를 DB에 모음`데이터 수집`
* 데이터 분석 후 정지상태의 데이터 기준과 아기 울음소리 주파수 영역 얻기`데이터 분석`
* 마이크 모듈, 진동센서를 이용해 **1분에 한 번씩** 데이터 측정`현재 데이터 측정`
* 측정한 데이터가 차가 정지한 상태를 나타내고 + 아기 울음소리 주파수 영역에 해당되면 pushbullet으로 알림 보내기`endpoint`
> to be continued
* PIR센서를 사용하여 아기의 움직임 감지하여 아기 울음소리 감지 기능과 함께 판단하여 신뢰도 높이기
