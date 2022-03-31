```
단국대학교 네트워크 소켓프로그래밍 실습하시는 학생들 안녕하세요, 송인호 입니다
본 코드는 Socket programming Skeleton Code입니다. 
각각은 Packet으로 String, Struct를 서로 주고 받습니다.
Struct는 로컬에서 돌려봤는데 잘 도니까 String이 안된다면 Struct를 참고해서 고쳐보세요

여러분들 과제를 위해서는 위 코드에 다음 부분이 필요합니다.
1. Packet을 재구성
2. Server의 loop Listening (Server Listen 코드 부분에 loop를 구현해야합니다. 화이팅)
3. Host IP 재설정
4. 실제 과제함에 있어서 Packet을 처리하고 다시 주고 받는 과정
(packet을 주고 받으려면 loop를 돌면서 주고받을겁니다. send(), recv()를 어떻게 잘 쓸 수 있을까 고민해보세요)
등등을 구현해주세요

Socket Programming은 당장 여러분 졸업작품에도 활용될 수 있는 지식이니 한번에 집중해서 내공 쌓아놓으면 편할겁니다.
이거로 연습하고 실제로 쓰이는 응용 : Websocket, HTTP, Apache Kafka 등을 공부해보세요(Apache Kafka는 하둡과 더불어 카카오 네이버 모두 필수 스킬로 생각하고 있는듯 합니다)
1분반 학생들은 올려드린 PPT를 보시면 follow up 할 수 있습니다
Python Language라면 인터넷에 많은 예제가 있으니 그걸 참고하시면 될겁니다. 
실무에서 Python보다는 다른 언어를 쓴다고 하니 관심있는 분들은 Python으로 입문하시고 다른 언어로 프로그래밍 하는걸 추천해봅니다.

그리고 되게 중요한거를 못말헀는데, localhost가 아니라 remote에서 수행되기 위해서는
Server와 Client 모두 (1)사용하려는 Port와 그거에 대한 (2)방화벽을 해제해야합니다.
그때문에 유명한 프로토콜들은 모두 고유 포트가 존재합니다 (SSH 22 TCP 8080 HTTP 80 HTTPS 443 )
'포트 여는법' '방화벽 해제'등을 검색해보세요. (참고 : https://jusunglee.tistory.com/entry/netstat-port%ED%99%95%EC%9D%B8)
최종적으로 server는 해당 포트를 Listen할 수 있게 동작해야합니다
```


# socket_proggraming
2022 DKU Computer Network Socket Programming Practice

# DKU Computer Nexwork course 2022

DKU Computer Network Socket programming Practice
## Description
This vanilla code presume run client-server model in localhost.
you need to change id address of remote server and open port and disable firewall w.r.t port
$ENV : Ubuntu 20.04 LTS Linux 5.10.0 generic 

## Getting Started
```
git clone https://github.com/inhoinno/socket_proggraming.git
$ cd socket_proggraming/ ; make

```

### Basic Client-Server model : String

* Describe any prerequisites, libraries, OS version, etc., needed before installing program.
```
$ make clean; make
$ ./basic_server & ./basic_client
```

### Basice Client-Server model : Struct
```
$ make clean; make
$ ./struct_server & ./struct_client
```

## Help
  You can free to use, modify this code. 
  If source code has error, please let me know bellow email
  mearrong123@gmail.com 

## Authors
  송 인호
## Version History

## License

This project is licensed under the GNU General Public License version 3.0 (GPLv3) License 
- see the LICENSE.md file for details

## Acknowledgments
* Wolfgang Mauereer, Professional Linux Kernel Architecture, O Wiely
* [Sockets Programming in C](http://www.spec.gmu.edu/~pparis/classes/project_465/CSockets.pdf)
