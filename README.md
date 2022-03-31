```
단국대학교 네트워크 소켓프로그래밍 실습하시는 학생들 안녕하세요, 송인호 입니다
본 코드는 Socket programming Skeleton Code입니다. 
각각은 Packet으로 String, Struct를 서로 주고 받습니다.
Struct는 로컬에서 돌려봤는데 잘 도니까 String이 안된다면 Struct를 참고해서 고쳐보세요

여러분들 과제를 위해서는 위 코드에 다음 부분이 필요합니다.
1. Packet을 재구성
2. Server의 loop Listening (Server Listen 부분에 loop를 구현해야합니다)
3. Host IP 재설정
4. 실제 과제함에 있어서 Packet을 처리하고 다시 주고 받는 과정(packet을 주고 받으려면 loop를 )
등등을 구현해주세요

1분반 학생들은 올려드린 PPT를 보시면 follow up 할 수 있습니다
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
$ git clone https://github.com/inhoinno/socket_proggraming.git
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
