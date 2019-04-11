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
**_네트워크가 연결되어 있음. 아두이노에 전원이 공급되어 있음을 가정_**
<br/>
* 자동차 실내 내부에 마이크모듈을 부착한 아두이노 설치 후 데이터 수집(데이터 발생)
