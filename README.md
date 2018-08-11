### AutoRefactor  
  
#### 사용법
  
make ptree.o
make refactorguide
make autorefactor
./a.out ALARMFILE  

**인풋(알람 파일) 포맷**  
[클론의 수]  
[첫번째 클론 파일의 위치  클론의 첫 라인  클론의 끝 라인]  
[두번재 클론 파일의 위치  클론의 첫 라인  클론의 끝 라인]  
[첫번째 클론의 Caller 갯수]  
[Caller 파일의 위치]  
[Caller 객체명  Caller 함수명  기존 함수명(패치 이전)]  
[Caller 호출시 인자 갯수  인자값1  인자값2  ...  인자값n]  
[Caller 라인넘버]  
[두번째 클론의 Caller 갯수]  
[Caller 파일의 위치]  
[Caller 객체명  Caller 함수명  기존 함수명(패치 이전)]  
[Caller 호출시 인자 갯수  인자값1  인자값2  ...  인자값n]  
[Caller 라인넘버]  
  
