# 너의 목소리가 들려
###### team project in capstone_design I
<br/>
    
## Introduction
어린이집 등하원 차량에 아이가 혼자 남겨질 경우, 이를 파악하여 운전자, 어린이집 선생님, 또는 부모님에게 알려주는 서비스<br/>
차량이 현재 주행 중인지, 정차 중인지, 또는 완전히 주차한 상황인지를 파악하고 차량 내부에 아이가 남아있는지를 파악합니다
<br/><br/>
## Technology
<img src="https://github.com/micaellajimini/capstone_team/blob/master/diagram.jpeg" width=210>

* **Node.js** ~~(or Django)~~ 이용하여 **EC2**에서 웹서버 구동
* Node MCU에서 **마이크 모듈**로부터 값을 받아 서버로 보냄
* EC2에 **RDS**를 설치하고 데이터 모으기
* 서버 내에 **python**으로 FFT 알고리즘 통해 아이 울음 소리 주파수 추출
* 

<br/>

## Dataflow in detail
