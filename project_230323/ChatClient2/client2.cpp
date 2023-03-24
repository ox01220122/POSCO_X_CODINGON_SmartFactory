#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <WS2tcpip.h>
#define MAX_SIZE 1024
using std::cout;
using std::cin;
using std::endl;
using std::string;
SOCKET client_sock;
string my_nick;


int chat_recv() {
	char buf[MAX_SIZE] = {};
	string msg;
	while (1) {
		ZeroMemory(&buf, MAX_SIZE);
		if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {// 0: 정상종료 >0:값이 잘 들어감
			msg = buf;
			string user;
			std::stringstream ss(msg); // stringstream = (slice해줌)-> user랑 masage분리
			//기본적으로 공백을 기준으로 잘라준다
			ss >> user;

			//cout << buf << endl;
			// 전체가 보이면 헷갈리기 때문에 내 닉네임이 아닌 경우에만 출력
			if (user != my_nick) cout << buf << endl;
		}
		else {
			cout << "Server Off!" << endl;
			return -1;
		}
	}
}
int main() {
	WSADATA wsa;
	int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (!code) {
		cout << "사용할 닉네임 입력 >>";
		cin >> my_nick;
		client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

		SOCKADDR_IN client_addr = {};
		client_addr.sin_family = AF_INET; //주소체계정의
		client_addr.sin_port = htons(7777); //포트할당
		InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);
		//client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

		while (1) {
			if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) {
				//connect()는 정상연결 되었을 때 0 반환
				cout << "Server Connect" << endl;
				send(client_sock, my_nick.c_str(), my_nick.length(), 0);
				break;
				//닉네임을 서버로 보내주기
			}
			cout << "connecting..." << endl;
		}
		std::thread th2(chat_recv);

		while (1) { //채팅내용(문자열)받아서 보내주기
			string text;
			std::getline(cin, text);
			const char* buffer = text.c_str();
			send(client_sock, buffer, strlen(buffer), 0);
		}
		th2.join();
		closesocket(client_sock);
	}

	WSACleanup();
	return 0;
}
