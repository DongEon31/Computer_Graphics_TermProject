#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "bmpfuncs.h"
#include <GL/freeglut.h>
#include <gl/glut.h>
#include <GL/glext.h>
#include <iostream>
#include <stdio.h>
#include "ObjParser.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

// 전역 변수들 //
int current_width = 800, current_height = 600; // 윈도우 너비/높이
const double PI = 3.141592; // 원주율
double radius = 45; // 반지름
double radius_2 = 60; // Minimap Camera
double theta = 60, phi = 3; // 구면 좌표계에서 세타, 파이 값
double theta_2 = 3, phi_2 = 3; // Minimap Camera
int cam_mode = 1;
double cam_mode1[3]; // Camera 위치 좌표
double cam_mode2[3]; // Minimap Camera 위치 좌표
double up = 1; // Up Vector
int mov = 0; // Character 움직임
double mov_x = 0, mov_z = 0; // 상하좌우 move 변수
int count = 0; // 일정 거리만큼 move
int max = 200;
int jump = 0; // jump mode 0 : stop / 1 : up / 2 : down
double jump_y = 0.1; // jump 높이
int left = 0; // mouse left pushed 여부
int pos_x1, pos_y1; // 마우스 드래그 : Camera View move에 이용되는 변수
int pos_x2, pos_y2;
int light_pos = 0; // 조명 위치
int mode = 1; // Game Display Mode
bool axis_mode = true;
int robot_spin = 0; // Character Spin 여부
float coin_ang = 0.0;
float char_ang = 0.0;
float trash1_ang = 0.0;
float trash2_ang = 0.0;
int coin_x = 0, coin_z = 0; // coin의 random position
double razer_x, razer_z; // Razer의 이동
int razer = 2;
int razer_count = 0; // razer 발생 횟수
int razer_hit = 0; // razer 충돌 여부
double level = 2; // speed
int level_up = 0;
int path = 1; // Razer 경로 (4가지)
int height = 1; // Razer 높이 (1,2/3/4)
int count_next = 0;
double next = 0; // 레이저 발생 주기
int life = 3; // 목숨
double aabb_obj[6] = { 0.f, }; // obj의 min,max(x,y,z) 좌표를 저장
double aabb_razer[6] = { 0.f, }; // razer의 min,max(x,y,z) 좌표를 저장
clock_t start, end;
int t = 0; // time spent
int tick = 0; // game time 
int gen = 0; // time 십의자리 수
bool g_start = false; // Game 진행중
int map_size = 20;
int select = 0; // 
int g_nX, g_nY;
int char_select = 3; // Character select
int coin_position[40]; // Coin 위치
int a[2] = { 16,-16 }; // Coin 초기화배열 1
int b[3] = { -2,0,2 }; // Coin 초기화배열 2
int coin_posx = 100, coin_posz = 100;
int coin_hit = 0; // Coin 획득 여부
int coin_get = 0; // Coin 획득 개수

// 블렌더 Character
ObjParser* mychar1;
ObjParser* mychar2;
ObjParser* mychar3;
ObjParser* mychar4;
ObjParser* trash1;
ObjParser* trash2;

// Texture 변수들 //
GLuint texname[6];	// Cube
GLuint texname2[3];	// Cylinder
GLuint* coin = new GLuint(); // Coin
GLuint* side = new GLuint(); // Coin's Side
GLuint* razer1 = new GLuint(); // Razer 1
GLuint* razer2 = new GLuint(); // Razer 2
GLuint* texname3 = new GLuint(); // Sphere
GLuint texture;
GLuint g_nCubeTex; // UniverseBox
GLuint texturechar1;
GLuint texturechar2;
GLuint texturechar3;
GLuint texturechar4;
GLuint texturetrash1;
GLuint texturetrash2;

// GLUQuadric 객체 선언&생성
GLUquadricObj* qobj = gluNewQuadric();
GLUquadricObj* qobj2 = gluNewQuadric();

// Emission Arrays
GLfloat cyan_emit[] = { 0.0f, 1.0f, 1.0f, 1.0f };
GLfloat dft[] = { 0.0f, 0.0f, 0.0f, 1.0f };

// OpenGL 설정 함수 //
void init();
void resize(int, int);
void draw();
void light_setting();
void showinst();
int collision(); // 충돌 처리
void keyboard(unsigned char, int, int);
void special(int, int, int);
void mouse(int, int, int, int);
void motion(int, int);
void mousewheel(int, int, int, int);
void idle();
void main_menu(int);
void sub_menu(int);

// Texture Mapping 함수 //
void get_resource1(const char* str);
void get_resource2(const char* str);
void get_resource3(const char* str);
void get_resource4(const char* str);
void get_resource5(const char* str);
void get_resource6(const char* str);
void char1_tm();
void setchar1_tm();
void char2_tm();
void setchar2_tm();
void char3_tm();
void setchar3_tm();
void char4_tm();
void setchar4_tm();
void trash1_tm();
void settrash1_tm();
void trash2_tm();
void settrash2_tm();
void coin_tm();
void environment_mapping();

// draw 함수
void draw_char1(ObjParser* objParser);
void draw_char2(ObjParser* objParser);
void draw_char3(ObjParser* objParser);
void draw_char4(ObjParser* objParser);
void draw_trash1(ObjParser* objParser);
void draw_trash2(ObjParser* objParser);
void draw_universe();
void draw_textcoin(); // draw coin
void draw_razer(); // draw razer 
void draw_inst();
void draw_string(void*, const char*, float, float, float, float, float);
void draw_select();
void draw_trash();
void draw_line();
void minimap(double, double, double);
void ingame();

void init(void)
{
	// 화면의 기본색 gray //
	glClearColor(0.0, 0.0, 0.0, 1.0f); // R,G,B,Alpha
	glutReshapeFunc(resize);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	// set antialiasing
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);
	glEnable(GL_LINE_SMOOTH);
	gluQuadricTexture(qobj, GL_TRUE); // Quadric Object 
	gluQuadricTexture(qobj2, GL_TRUE); // Quadric Object 

	// Texture Mapping Function
	glEnable(GL_TEXTURE_2D);
	coin_tm();
	setchar1_tm();
	setchar2_tm();
	setchar3_tm();
	setchar4_tm();
	settrash1_tm();
	settrash2_tm();
	environment_mapping();
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	showinst();
	light_setting(); // 조명을 설정하는 함수

	// COIN POSITION INITIATION
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for (int i = 0; i < 20; i++) {
		int x = rand() % 4;
		if (x == 0) { t1 = a[0]; t2 = a[0]; }
		else if (x == 1) { t1 = a[0]; t2 = a[1]; }
		else if (x == 2) { t1 = a[1]; t2 = a[0]; }
		else if (x == 3) { t1 = a[1]; t2 = a[1]; }
		int y = rand() % 9;
		if (y == 0) { t3 = b[0]; t4 = b[0]; }
		else if (y == 1) { t3 = b[0]; t4 = b[1]; }
		else if (y == 2) { t3 = b[0]; t4 = b[2]; }
		else if (y == 3) { t3 = b[1]; t4 = b[0]; }
		else if (y == 4) { t3 = b[1]; t4 = b[1]; }
		else if (y == 5) { t3 = b[1]; t4 = b[2]; }
		else if (y == 6) { t3 = b[2]; t4 = b[0]; }
		else if (y == 7) { t3 = b[2]; t4 = b[1]; }
		else if (y == 8) { t3 = b[2]; t4 = b[2]; }
		coin_position[2 * i] = t1 + t3;
		coin_position[2 * i + 1] = t2 + t4;
	}
}

/// idle 상태에 대한 Callback 함수 /// : jump, move, coin의 spin 구현 ...
void idle() {

	///////////////    Time    ///////////////
	if (mode != 3) {
		end = clock();
		if (mode == 2 && g_start == true && tick == 0) {
			tick = 1;
			start = clock();
			count_next = 0;
			razer_x = 0;
			razer_z = 0;
			razer_hit = 0;
			PlaySound(TEXT("sound/start.wav"), NULL, SND_ASYNC | SND_ALIAS);
		}
		t = (int)(end - start) / 1000; // 초단위 시간 측정.
		if (mode == 2 && g_start == false)
			t = 0;
	}
	///////////////   Collision    ///////////////

	if (path == 1) {
		if (height == 1 || height == 2) {
			aabb_razer[0] = -40 + razer_x - 0.2;
			aabb_razer[1] = -0.2;
			aabb_razer[2] = -20;
			aabb_razer[3] = -40 + razer_x + 0.2;
			aabb_razer[4] = 0.2;
			aabb_razer[5] = 20;
		}
		else if (height == 3) {
			aabb_razer[0] = -40 + razer_x - 0.2;
			aabb_razer[1] = 0.8;
			aabb_razer[2] = -20;
			aabb_razer[3] = -40 + razer_x + 0.2;
			aabb_razer[4] = 1.2;
			aabb_razer[5] = 20;
		}
		else if (height == 4) {
			aabb_razer[0] = -40 + razer_x - 0.2;
			aabb_razer[1] = 1.8;
			aabb_razer[2] = -20;
			aabb_razer[3] = -40 + razer_x + 0.2;
			aabb_razer[4] = 2.2;
			aabb_razer[5] = 20;
		}
	}
	else if (path == 2) {
		if (height == 1 || height == 2) {
			aabb_razer[0] = 40 + razer_x - 0.2;
			aabb_razer[1] = -0.2;
			aabb_razer[2] = -20;
			aabb_razer[3] = 40 + razer_x + 0.2;
			aabb_razer[4] = 0.2;
			aabb_razer[5] = 20;
		}
		else if (height == 3) {
			aabb_razer[0] = 40 + razer_x - 0.2;
			aabb_razer[1] = 0.8;
			aabb_razer[2] = -20;
			aabb_razer[3] = 40 + razer_x + 0.2;
			aabb_razer[4] = 1.2;
			aabb_razer[5] = 20;
		}
		else if (height == 4) {
			aabb_razer[0] = 40 + razer_x - 0.2;
			aabb_razer[1] = 1.8;
			aabb_razer[2] = -20;
			aabb_razer[3] = 40 + razer_x + 0.2;
			aabb_razer[4] = 2.2;
			aabb_razer[5] = 20;
		}
	}
	else if (path == 3) {
		if (height == 1 || height == 2) {
			aabb_razer[0] = -20;
			aabb_razer[1] = -0.2;
			aabb_razer[2] = -40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 0.2;
			aabb_razer[5] = -40 + razer_z + 0.2;
		}
		else if (height == 3) {
			aabb_razer[0] = -20;
			aabb_razer[1] = 0.8;
			aabb_razer[2] = -40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 1.2;
			aabb_razer[5] = -40 + razer_z + 0.2;
		}
		else if (height == 4) {
			aabb_razer[0] = -20;
			aabb_razer[1] = 1.8;
			aabb_razer[2] = -40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 2.2;
			aabb_razer[5] = -40 + razer_z + 0.2;
		}
	}
	else if (path == 4) {
		if (height == 1 || height == 2) {
			aabb_razer[0] = -20;
			aabb_razer[1] = -0.2;
			aabb_razer[2] = 40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 0.2;
			aabb_razer[5] = 40 + razer_z + 0.2;
		}
		else if (height == 3) {
			aabb_razer[0] = -20;
			aabb_razer[1] = 0.8;
			aabb_razer[2] = 40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 1.2;
			aabb_razer[5] = 40 + razer_z + 0.2;
		}
		else if (height == 4) {
			aabb_razer[0] = -20;
			aabb_razer[1] = 1.8;
			aabb_razer[2] = 40 + razer_z - 0.2;
			aabb_razer[3] = 20;
			aabb_razer[4] = 2.2;
			aabb_razer[5] = 40 + razer_z + 0.2;
		}
	}
	aabb_obj[0] = mov_x - 0.5;
	aabb_obj[2] = mov_z - 0.5;
	aabb_obj[3] = mov_x + 0.5;
	aabb_obj[5] = mov_z + 0.5;
	if (char_select == 4) {
		aabb_obj[1] = jump_y - 0.5;
		aabb_obj[4] = jump_y - 0.5 + 2.7;
	}
	else if (char_select == 3) {
		aabb_obj[1] = jump_y - 0.5;
		aabb_obj[4] = jump_y - 0.5 + 0.7;
	}
	else {
		aabb_obj[1] = jump_y - 0.5;
		aabb_obj[4] = jump_y - 0.5 + 1.7;
	}

	///////////////    Jump    ///////////////
	if (jump == 1 && jump_y == 0.11) {
		PlaySound(TEXT("sound/jump.wav"), NULL, SND_ASYNC | SND_ALIAS);
	}
	if (char_select == 4) {
		if (jump == 1) {
			jump_y += 0.01;
			if (jump_y > (double)5)
				jump = 2;
		}
		else if (jump == 2) {
			jump_y -= 0.01;
			if (jump_y < (double)0) {
				jump = 0;
				jump_y = 0.1;
			}
		}
	}
	else {
		if (jump == 1) {
			jump_y += 0.01;
			if (jump_y > (double)3)
				jump = 2;
		}
		else if (jump == 2) {
			jump_y -= 0.01;
			if (jump_y < (double)0) {
				jump = 0;
				jump_y = 0.1;
			}
		}
	}
	///////////////    Move    ///////////////
	if (char_select == 4) {
		if (mov == 1 && mov_z > (double) -18) { // w
			mov_z -= 0.03;
			count++;
			if (count == max / 2) {
				mov = 0;
				count = 0;
			}
		}
		if (mov == 3 && mov_z < (double)18) { // s
			mov_z += 0.03;
			count++;
			if (count == max / 2) {
				mov = 0;
				count = 0;
			}
		}
		if (mov == 2 && mov_x > (double)-18) { // a
			mov_x -= 0.03;
			count++;
			if (count == max / 2) {
				mov = 0;
				count = 0;
			}
		}
		if (mov == 4 && mov_x < (double)18) { // d
			mov_x += 0.03;
			count++;
			if (count == max / 2) {
				mov = 0;
				count = 0;
			}
		}
	}
	else {
		if (mov == 1 && mov_z > (double)-18) { // w
			mov_z -= 0.02;
			count++;
			if (count == max) { // max = 200 : 총 거리 2 move
				mov = 0;
				count = 0;
			}
		}
		if (mov == 3 && mov_z < (double)18) { // s
			mov_z += 0.02;
			count++;
			if (count == max) {
				mov = 0;
				count = 0;
			}
		}
		if (mov == 2 && mov_x > (double)-18) { // a
			mov_x -= 0.02;
			count++;
			if (count == max) {
				mov = 0;
				count = 0;
			}
		}
		if (mov == 4 && mov_x < (double)18) { // d
			mov_x += 0.02;
			count++;
			if (count == max) {
				mov = 0;
				count = 0;
			}
		}
	}

	///////////////   Spin     ///////////////

	coin_ang = coin_ang + 0.06;
	if (coin_ang > 360) coin_ang -= 360;

	char_ang = char_ang + 0.05;
	if (char_ang > 360) char_ang -= 360;

	trash1_ang = trash1_ang + 0.05;
	if (trash1_ang > 360) trash1_ang -= 360;

	trash2_ang = trash2_ang + 0.03;
	if (trash2_ang > 360) trash2_ang -= 360;

	///////////////   Razer    ///////////////
	if (mode == 2 && g_start == true) {
		if (razer_count % 4 == 0) level_up = 0;

		next = 80 / 0.01 / level;
		//	printf("%f %f\n", razer_x, razer_z);
		if (count_next == 0)
			razer_hit = 0;
		count_next++;
		if (count_next == (int)next) { // next는 razer_x * f
			razer_count++;
			count_next = 0;
			razer_x = 0;
			razer_z = 0;
			razer_hit = 0;
			path = (rand() % 4) + 1;
			height = (rand() % 4) + 1;
		}

		if (path == 1)razer_x += 0.01 * level;
		else if (path == 2) razer_x -= 0.01 * level;
		else if (path == 3) razer_z += 0.01 * level;
		else if (path == 4) razer_z -= 0.01 * level;

		if (razer_count % 4 == 3 && level_up == 0) {
			level += 0.25;
			level_up = 1;
		}
	}
	///////////////   Coin    ///////////////
	if (mode == 2 && g_start == true) {
		gen = (t / 10) + 1;
		if (t % 10 == 0) coin_hit = 0;

		if (t % 10 >= 3 && t % 10 <= 9 && coin_hit == 0) { // ..3초 ~ ..9초까지 Coin이 등장
			coin_posx = coin_position[2 * gen];
			coin_posz = coin_position[2 * gen + 1];
		}

		if ((coin_hit == 0 && t % 10 >= 3 && t % 10 <= 9) // Coin Get
			&& (coin_posx == (int)mov_x || coin_posx == (int)mov_x - 1 || coin_posx == (int)mov_x + 1)
			&& (coin_posz == (int)mov_z || coin_posz == (int)mov_z - 1 || coin_posz == (int)mov_z + 1)) {
			PlaySound(TEXT("sound/coin.wav"), NULL, SND_ASYNC | SND_ALIAS);
			coin_hit = 1;
			coin_get++;
		}
	}

	if (life == 0 && mode == 2) {
		g_start = false;
		mode = 3;
		PlaySound(TEXT("sound/end.wav"), NULL, SND_ASYNC | SND_ALIAS); // GAME OVER 효과음
	}
	if (g_start == true && collision() == 1 && razer_hit == 0) { // 충돌 시 Life 감소
		if (life > 1)PlaySound(TEXT("sound/collision.wav"), NULL, SND_ASYNC | SND_ALIAS); // 충돌 효과음
		life--;
		razer_hit = 1;
	}
}

int collision() {
	if (razer_hit == 1) return 0;
	else {
		if (aabb_obj[3] < aabb_razer[0] || aabb_razer[3] < aabb_obj[0]) return 0;
		else if (aabb_obj[4] < aabb_razer[1] || aabb_razer[4] < aabb_obj[1]) return 0;
		else if (aabb_obj[5] < aabb_razer[2] || aabb_razer[5] < aabb_obj[2]) return 0;
		else return 1;
	}
}

void setchar1_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/mychar1.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturechar1);
	glBindTexture(GL_TEXTURE_2D, texturechar1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void setchar2_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/mychar2.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturechar2);
	glBindTexture(GL_TEXTURE_2D, texturechar2);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void setchar3_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/mychar3.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturechar3);
	glBindTexture(GL_TEXTURE_2D, texturechar3);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void setchar4_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/mychar4.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturechar4);
	glBindTexture(GL_TEXTURE_2D, texturechar4);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void settrash1_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/trash1.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturetrash1);
	glBindTexture(GL_TEXTURE_2D, texturetrash1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void settrash2_tm() {
	int imgWidth, imgHeight, channels;
	uchar* img = readImageData("img/trash2.bmp", &imgWidth, &imgHeight, &channels);

	int texNum = 1;
	glGenTextures(texNum, &texturetrash2);
	glBindTexture(GL_TEXTURE_2D, texturetrash2);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void draw_char1(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturechar1);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void draw_char2(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturechar2);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void draw_char3(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturechar3);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void draw_char4(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturechar4);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void draw_trash1(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturetrash1);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void draw_trash2(ObjParser* objParser)
{
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturetrash2);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glBegin(GL_TRIANGLES);
	for (unsigned int n = 0; n < objParser->getFaceSize(); n += 3) {
		glTexCoord2f(objParser->textures[objParser->textureIdx[n] - 1].x,
			objParser->textures[objParser->textureIdx[n] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n] - 1].x,
			objParser->normal[objParser->normalIdx[n] - 1].y,
			objParser->normal[objParser->normalIdx[n] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n] - 1].x,
			objParser->vertices[objParser->vertexIdx[n] - 1].y,
			objParser->vertices[objParser->vertexIdx[n] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 1] - 1].x,
			objParser->textures[objParser->textureIdx[n + 1] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 1] - 1].x,
			objParser->normal[objParser->normalIdx[n + 1] - 1].y,
			objParser->normal[objParser->normalIdx[n + 1] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 1] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 1] - 1].z);

		glTexCoord2f(objParser->textures[objParser->textureIdx[n + 2] - 1].x,
			objParser->textures[objParser->textureIdx[n + 2] - 1].y);
		glNormal3f(objParser->normal[objParser->normalIdx[n + 2] - 1].x,
			objParser->normal[objParser->normalIdx[n + 2] - 1].y,
			objParser->normal[objParser->normalIdx[n + 2] - 1].z);
		glVertex3f(objParser->vertices[objParser->vertexIdx[n + 2] - 1].x,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].y,
			objParser->vertices[objParser->vertexIdx[n + 2] - 1].z);
	}
	glEnd();
	glPopMatrix();
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void get_resource1(const char* str)
{
	mychar1 = new ObjParser(str);
}

void get_resource2(const char* str)
{
	mychar2 = new ObjParser(str);
}

void get_resource3(const char* str)
{
	mychar3 = new ObjParser(str);
}

void get_resource4(const char* str)
{
	mychar4 = new ObjParser(str);
}

void get_resource5(const char* str)
{
	trash1 = new ObjParser(str);
}

void get_resource6(const char* str)
{
	trash2 = new ObjParser(str);
}

void draw_universe() {
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glEnable(GL_TEXTURE_CUBE_MAP);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
	float g_nSkySize = 60.0f;
	glBegin(GL_QUADS);
	// px
	glTexCoord3d(1.0, -1.0, -1.0); glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
	glTexCoord3d(1.0, -1.0, 1.0); glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(1.0, 1.0, 1.0); glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
	glTexCoord3d(1.0, 1.0, -1.0); glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
	// nx
	glTexCoord3d(-1.0, -1.0, -1.0); glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
	glTexCoord3d(-1.0, -1.0, 1.0); glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, 1.0, 1.0); glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, 1.0, -1.0); glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
	// py
	glTexCoord3d(1.0, 1.0, 1.0); glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, 1.0, 1.0); glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, 1.0, -1.0); glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
	glTexCoord3d(1.0, 1.0, -1.0); glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
	// ny
	glTexCoord3d(1.0, -1.0, 1.0); glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, -1.0, 1.0); glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, -1.0, -1.0); glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
	glTexCoord3d(1.0, -1.0, -1.0); glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
	// pz
	glTexCoord3d(1.0, -1.0, 1.0); glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, -1.0, 1.0); glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
	glTexCoord3d(-1.0, 1.0, 1.0); glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
	glTexCoord3d(1.0, 1.0, 1.0); glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
	// nz
	glTexCoord3d(1.0, -1.0, -1.0); glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
	glTexCoord3d(-1.0, -1.0, -1.0); glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
	glTexCoord3d(-1.0, 1.0, -1.0); glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
	glTexCoord3d(1.0, 1.0, -1.0); glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);

	glEnd();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_CUBE_MAP);
}

void environment_mapping() {
	glGenTextures(1, &g_nCubeTex);
	
	int width, height, channels;
	// Texture 불러오기
	uchar* img0 = readImageData("img/background.bmp", &width, &height, &channels);

	// Texture Mapping
	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, img0);

	// Texture 속성 지정
	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	//glEnable(GL_TEXTURE_CUBE_MAP);
}

void light_setting() {
	// 조명 관련 Code //
	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat diffuseLight[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	GLfloat specularLight[] = { 0.5, 0.5f, 0.9f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambientLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, ambientLight);

	GLfloat ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f,1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMateriali(GL_FRONT, GL_SHININESS, 40);

	glDisable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
}

void draw_line() {
	glColor3f(0.5f, 0.5f, 0.5f);
	glLineWidth(0.3);
	int i;
	int offset = 2;
	glBegin(GL_LINES);
	for (i = -map_size; i < map_size + 2; i += offset) {
		glVertex3f(i, -0.9f, -map_size);
		glVertex3f(i, -0.9f, map_size);
	}
	for (i = -map_size; i < map_size + 2; i += offset) {
		glVertex3f(-map_size, -0.9f, i);
		glVertex3f(map_size, -0.9f, i);
	}
	glEnd();
}

void draw_field() { // [-20,-20] x [20, 20]
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.6f, 0.6f);
	glVertex3i(map_size, -1, map_size);
	glVertex3i(map_size, -1, -map_size);
	glVertex3i(-map_size, -1, -map_size);
	glVertex3i(-map_size, -1, map_size);
	glEnd();

	glFlush();
}

void coin_tm() {
	glGenTextures(1, coin);
	int imgWidth, imgHeight, channels;
	glBindTexture(GL_TEXTURE_2D, *coin);
	char buf[100];
	sprintf(buf, "img/coin33.bmp");
	buf[strlen(buf)] = 0;
	uchar* img = readImageData(buf, &imgWidth, &imgHeight, &channels);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void draw_axis() {
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); // X : Red
	glVertex3f(0, 0, 0);
	glVertex3f(-8, 0, 0);

	glColor3f(0, 1, 0); // Y : Green
	glVertex3f(0, 0, 0);
	glVertex3f(0, 8, 0);

	glColor3f(0, 0, 1); // Z : Blue
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -8);
	glEnd();
	glutPostRedisplay();
}

void draw_razer() {
	glMaterialfv(GL_FRONT, GL_EMISSION, cyan_emit); // Emission
	if (height == 1 || height == 2) glColor3f(0.f, 1.f, 1.f);
	else if (height == 3) glColor3f(1.f, 1.f, 0.f);
	else if (height == 4) glColor3f(1.f, 0.f, 0.f);
	glTranslatef(0, -1, 0);
	if (path == 1 || path == 2) { // x축을 따라 이동하는 Razer
		if (height == 1 || height == 2) glTranslatef(razer_x, 1, razer_z);
		else if (height == 3) glTranslatef(razer_x, 2, razer_z);
		else if (height == 4) glTranslatef(razer_x, 3, razer_z);
		if (path == 1) 	glTranslatef(-40, 0, -20);
		else if (path == 2) glTranslatef(40, 0, -20);
		// Top
		glPushMatrix();
		GLfloat light_position1[] = { 0,0,0,1.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
		glPopMatrix();
		// Body
		glPushMatrix();
		GLfloat light_position2[] = { 0 ,0,15,1.0 };
		glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
		glutSolidCylinder(0.5, 40, 10, 10);
		glPopMatrix();
		// Bottom
		glPushMatrix();
		GLfloat light_position3[] = { 0 ,0,30,1.0 };
		glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
		glRotatef(180, 1, 0, 0); // 바닥이므로 180도 회전한다
		glPopMatrix();
	}
	else if (path == 3 || path == 4) { // z축을 따라 이동하는 Razer
		if (height == 1 || height == 2) glTranslatef(razer_x, 1, razer_z);
		else if (height == 3) glTranslatef(razer_x, 2, razer_z);
		else if (height == 4) glTranslatef(razer_x, 3, razer_z);
		if (path == 3) 	glTranslatef(-20, 0, -40);
		else if (path == 4) glTranslatef(-20, 0, 40);
		glRotatef(90, 0, 1, 0);
		// Top
		glPushMatrix();
		GLfloat light_position1[] = { 0,0,0,1.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
		glPopMatrix();
		// Body
		glPushMatrix();
		GLfloat light_position2[] = { 0 ,0,15,1.0 };
		glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
		glutSolidCylinder(0.5, 40, 10, 10);
		glPopMatrix();
		// Bottom
		glPushMatrix();
		GLfloat light_position3[] = { 0 ,0,30,1.0 };
		glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
		glRotatef(180, 1, 0, 0); // 바닥이므로 180도 회전한다
		glPopMatrix();
	}
	glMaterialfv(GL_FRONT, GL_EMISSION, dft);
	glFlush();
}

void draw_textcoin() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glColor3f(1.0f, 1.0f, 1.0f);
	// 앞면
	glPushMatrix();
	glTranslatef(0, 0.8, 0.1);
	glBindTexture(GL_TEXTURE_2D, *coin);
	gluPartialDisk(qobj, 0, 1, 30, 2, 0, 360);
	glPopMatrix();
	// Body
	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	glBindTexture(GL_TEXTURE_2D, *coin);
	gluCylinder(qobj, 1, 1, 0.2, 20, 20);
	glPopMatrix();
	// Bottom
	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	glRotatef(180, 1, 0, 0); // 바닥이므로 180도 회전한다
	glBindTexture(GL_TEXTURE_2D, *coin);
	gluPartialDisk(qobj, 0, 1, 30, 2, 0, 360);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void draw_trash() {
	glPushMatrix();
	glRotatef(trash1_ang, 0, 0.5, 0.5);
	glTranslatef(45, 0, 0);
	draw_trash1(trash1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(trash1_ang, 0, 0.7, 0.2);
	glTranslatef(50, 0, 0);
	draw_trash1(trash2);
	glPopMatrix();

	glPushMatrix();
	glRotatef(trash2_ang, 0.5, -0.5, 0);
	glTranslatef(55, 0, 0);
	draw_trash1(trash1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(trash2_ang, 0, 0.4, 1);
	glTranslatef(35, 0, 0);
	draw_trash1(trash2);
	glPopMatrix();

	glPushMatrix();
	glRotatef(trash1_ang, 0, 1, 1);
	glTranslatef(45, 0, 0);
	draw_trash1(trash1);
	glPopMatrix();
	glFlush();
}

void minimap(double x, double y, double z) {
	glViewport(0.75 * current_width, 0.7 * current_height, 0.25 * current_width, 0.3 * current_height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, 0, 0, 0, 0, up, 0); // Viewing Transform
	glPushMatrix();
	glTranslatef(mov_x, 1, mov_z);
	glColor3f(0.0f, 1.0f, 0.0f); // 캐릭터 -> Green Sphere
	gluSphere(qobj2, 1.3, 30, 30);
	glPopMatrix();
	glPushMatrix();
	draw_field(); // Field
	glPopMatrix();
	glPushMatrix();
	draw_axis(); // Axis -> Blue : 앞(W), Red : 좌(A)
	glPopMatrix();
	if (t % 10 >= 3 && t % 10 <= 9 && coin_hit == 0) { // ..3초 ~ ..9초까지 Coin이 등장
		glPushMatrix();
		glTranslatef(coin_posx, 1, coin_posz);
		glColor3f(1.0f, 1.0f, 0.0f);
		gluSphere(qobj2, 0.8, 30, 30); // Coin -> Yellow Sphere
		glPopMatrix();
	}
	glFlush();
}

void showinst() { // Key 안내
	printf("=================Key Instructions=================\n");
	printf("'W','A','S','D' : 앞, 좌, 뒤, 우 MOVE\n");
	printf("'Spacebar' : JUMP\n");
	printf("Left-Click + Drag : 카메라 시점 변환\n");
	printf("Wheel Up/Down : Zoom-In, Zoom-Out\n");
	printf("press '5' : Show Instructions again\n");
	printf("1, 2, 3, 4 : Character Select\n");
}

void resize(int width, int height) {
	glMatrixMode(GL_PROJECTION); // Projection Mode
	glLoadIdentity();
	gluPerspective(45, (float)width / (float)height, 1, 500); // Projection Transform
	glMatrixMode(GL_MODELVIEW); // 환원
	glFlush();
}

void ingame() {
	// draw Field
	glPushMatrix();
	draw_field(); draw_line();
	glPopMatrix();

	draw_trash();
	draw_inst();

	// draw character
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glTranslatef(mov_x, jump_y, mov_z);
	switch (robot_spin) {
	case 2:
		break;
	case 1:
		glRotatef(90, 0, 1, 0);
		break;
	case 0:
		glRotatef(180, 0, 1, 0);
		break;
	case 3:
		glRotatef(270, 0, 1, 0);
		break;
	}
	if (char_select == 1) draw_char1(mychar1);
	else if (char_select == 2) draw_char2(mychar2);
	else if (char_select == 3) draw_char3(mychar3);
	else if (char_select == 4) draw_char4(mychar4);
	glPopMatrix();

	// Cylinder
	glPushMatrix();
	if (g_start == true && razer_hit == 1) draw_string(GLUT_BITMAP_9_BY_15, "Life -1", 3, 0, 1.0, 0, 0);
	else if (g_start == true && razer_hit == 0) draw_razer();
	glPopMatrix();

	// Coin
	if (t % 10 >= 3 && t % 10 <= 9 && coin_hit == 0) { // ..3초 ~ ..9초까지 Coin이 등장
		glPushMatrix();
		glTranslatef(coin_posx, 0, coin_posz);
		glRotatef(coin_ang, 0, 1, 0);
		draw_textcoin();
		glPopMatrix();
	}
}

void result() {
	glViewport(0, 0, current_width, current_height); // Viewport Transform
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double x = 20 * sin(60 * PI / 180) * sin(60 * PI / 180);
	double y = 20 * cos(60 * PI / 180);
	double z = 20 * sin(60 * PI / 180) * cos(60 * PI / 180);
	GLfloat pos[] = { 0,0,0,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	GLfloat light_position[] = { x,y,z,1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	gluLookAt(x, y, z, 0, 0, 0, 0, up, 0); // 카메라 설정

	draw_field();
	draw_line();
	draw_trash();

	glPushMatrix();
	glTranslatef(0, 2, 0);
	glRotatef(char_ang, 0, 1, 0);
	if (char_select == 1) draw_char1(mychar1);
	else if (char_select == 2) draw_char2(mychar2);
	else if (char_select == 3) draw_char3(mychar3);
	else if (char_select == 4) draw_char4(mychar4);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Result", -5.5, 3, 0.0, 1.0, 0);
	char buf[50];
	sprintf(buf, "Time: %d s", t);
	draw_string(GLUT_BITMAP_9_BY_15, buf, -5.5, 2, 0.0, 1.0, 1.0);

	char buf2[50];
	sprintf(buf2, "Coin: %d ", coin_get);
	draw_string(GLUT_BITMAP_9_BY_15, buf2, -5.5, 1, 1.0, 1.0, 0.0);

	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "PRESS 'R' TO RESTART", -3.5, -5, 1.0, 0.5, 0.0);
	glFlush();
	glPopMatrix();
	glutPostRedisplay();
}

void draw_inst() {
	glPushMatrix();
	glLoadIdentity();

	if (mode == 2 && g_start == false) {
		draw_string(GLUT_BITMAP_9_BY_15, "press F to start", -3, 3, 1.0, 1.0, 0.0);

	}
	char buf[50];
	sprintf(buf, "Timer: %d s", t);
	draw_string(GLUT_BITMAP_9_BY_15, buf, -9.5, 9, 0.0, 1.0, 1.0);

	char buf2[50];
	sprintf(buf2, "Coin: %d ", coin_get);
	draw_string(GLUT_BITMAP_9_BY_15, buf2, -9.5, 7, 1.0, 1.0, 0.0);

	char buf3[50];
	sprintf(buf3, "Level: %.2f ", level);
	draw_string(GLUT_BITMAP_HELVETICA_18, buf3, -1, 9, 0, 1.0, 0.0);

	char buf4[50];
	sprintf(buf4, "Life : %d ", life);
	draw_string(GLUT_BITMAP_HELVETICA_18, buf4, -9.5, 8, 1.0, 0.0, 0.0);

	glFlush();
	glPopMatrix();
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (mode == 2) { // mode 2 : game display
		glViewport(0, 0, current_width, current_height); // Viewport Transform
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Camera의 좌표를 구면좌표계로 변환
		cam_mode1[0] = mov_x + radius * sin(theta * PI / 180) * sin(phi * PI / 180);
		cam_mode1[1] = jump_y + radius * cos(theta * PI / 180);
		cam_mode1[2] = mov_z + radius * sin(theta * PI / 180) * cos(phi * PI / 180);
		GLfloat pos[] = { 0,0,0,1 };
		glLightfv(GL_LIGHT0, GL_POSITION, pos);
		GLfloat light_pos[] = { cam_mode1[0], cam_mode1[1], cam_mode1[2],1 };
		glLightfv(GL_LIGHT1, GL_POSITION, light_pos);

		// Minimap Camera 좌표
		cam_mode2[0] = radius_2 * sin(theta_2 * PI / 180) * sin(phi_2 * PI / 180);
		cam_mode2[1] = radius_2 * cos(theta_2 * PI / 180);
		cam_mode2[2] = radius_2 * sin(theta_2 * PI / 180) * cos(phi_2 * PI / 180);

		gluLookAt(cam_mode1[0], cam_mode1[1], cam_mode1[2], mov_x, jump_y, mov_z + 2, 0, up, 0); // Viewing Transform

		draw_universe();
		glMatrixMode(GL_MODELVIEW);
		ingame();

		if (gen > 0 && t % 10 >= 0 && t % 10 <= 5 && g_start == true)
			draw_string(GLUT_BITMAP_HELVETICA_18, "COIN WILL APPEAR! ", -2, 6, 1.0, 0.0, 0.0);

		if (coin_hit == 1)
			draw_string(GLUT_BITMAP_9_BY_15, "COIN GET!", -5, -5, 1.0, 1.0, 0.0);

		// Multi Viewport - Minimap 
		minimap(cam_mode2[0], cam_mode2[1], cam_mode2[2]);
	}

	else if (mode == 1) { // mode 1 : character select
		draw_universe();
		glMatrixMode(GL_MODELVIEW);
		draw_select();
	}

	else if (mode == 3) {
		draw_universe();
		glMatrixMode(GL_MODELVIEW);
		result();
	}
	glFlush();
	glutSwapBuffers();
}

void draw_select() { // mode 1
	glViewport(0, 0, current_width, current_height); // Viewport Transform
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double x = 17 * sin(60 * PI / 180) * sin(60 * PI / 180);
	double y = 17 * cos(60 * PI / 180);
	double z = 17 * sin(60 * PI / 180) * cos(60 * PI / 180);
	GLfloat pos[] = { 0,0,0,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	GLfloat light_position[] = { x,y,z,1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	gluLookAt(x, y, z, 0, 0, 0, 0, up, 0); // 카메라 설정
	glPushMatrix();
	draw_field(); 
	draw_line();
	draw_trash();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 2, 6);
	glRotatef(char_ang, 0, 1, 0);
	draw_char1(mychar1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 2, 0);
	glRotatef(char_ang, 0, 1, 0);
	draw_char2(mychar2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, 2, -5);
	glRotatef(char_ang, 0, 1, 0);
	draw_char3(mychar3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 2, -3);
	glRotatef(char_ang, 0, 1, 0);
	draw_char4(mychar4);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "RAZER AND ME", -9, 8, 1.0, 1.0, 1.0);
	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Choose your Character !!!", -4, -4, 1.0, 1.0, 0);
	glFlush();
	glPopMatrix();
	glutPostRedisplay();
}

void draw_string(void* font, const char* str, float x_position, float y_position,
	float R, float G, float B) {
	glDisable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(R, G, B);
	glRasterPos3f(x_position, y_position, 0);
	for (int i = 0; i < strlen(str); i++)
		glutBitmapCharacter(font, str[i]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

/// 키보드 입력에 대한 Callback 함수 ///
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		if (mode == 1) {
			char_select = 1;
			mode = 2;
			life = 3;
			level = 2;
			razer_hit = 0;
			razer_count = 0;
			tick = 0;
			coin_hit = 0;
			coin_get = 0;
			razer_x = 0;
			razer_z = 0;
			printf("You selected Red\n");
		}
		break;
	case '2':
		if (mode == 1) {
			char_select = 2;
			mode = 2;
			life = 3;
			level = 2;
			razer_hit = 0;
			razer_count = 0;
			tick = 0;
			coin_hit = 0;
			coin_get = 0;
			razer_x = 0;
			razer_z = 0;
			printf("You selected Yellow\n");
		}
		break;
	case '3':
		if (mode == 1) {
			char_select = 3;
			mode = 2;
			life = 3;
			level = 2;
			razer_hit = 0;
			razer_count = 0;
			tick = 0;
			coin_hit = 0;
			coin_get = 0;
			razer_x = 0;
			razer_z = 0;
			printf("You selected Blue\n");
		}
		break;
	case '4':
		if (mode == 1) {
			char_select = 4;
			mode = 2;
			life = 3;
			level = 2;
			razer_hit = 0;
			razer_count = 0;
			tick = 0;
			coin_hit = 0;
			coin_get = 0;
			razer_x = 0;
			razer_z = 0;
			printf("You selected Green\n");
		}
		break;
	case '5':
		showinst();
		break;
	case 32:
		jump = 1;
		break;
	case 'w':
		mov = 1;
		robot_spin = 0;
		break;
	case 'a':
		mov = 2;
		robot_spin = 3;
		break;
	case 's':
		mov = 3;
		robot_spin = 2;
		break;
	case 'd':
		mov = 4;
		robot_spin = 1;
		break;
	case 'W':
		mov = 1;
		robot_spin = 0;
		break;
	case 'A':
		mov = 2;
		robot_spin = 3;
		break;
	case 'S':
		mov = 3;
		robot_spin = 2;
		break;
	case 'D':
		mov = 4;
		robot_spin = 1;
		break;
	case 'R':
		if (mode == 3) mode = 1;
		break;
	case 'r':
		if (mode == 3) mode = 1;
		break;
	case 'F':
		if (mode == 2 && g_start == false) g_start = true;
		break;
	case 'f':
		if (mode == 2 && g_start == false) g_start = true;
		break;
	}
	glutPostRedisplay();
}

/// 마우스 Wheel 입력에 대한 Callback 함수 ///
void mousewheel(int button, int dir, int x, int y) {

	if (dir > 0 && radius > 5) { // Wheel UP : 사물 확대
		radius -= 1;
	}
	else if (dir < 0 && radius < 100) { // Wheel DOWN : 사물 축소
		radius += 1;
	}
	glutPostRedisplay();
}

/// 방향키 입력에 대한 Callback 함수 ///
void special(int key, int x, int y)
{
	switch (key) { // 0 < phi, theta <= 360
	case GLUT_KEY_LEFT:
		if (phi == 0) phi = 357;
		else phi -= 3;
		//	printf("Move Left(press LEFT key)\n");
		break;
	case GLUT_KEY_RIGHT:
		if (phi == 360) phi = 3;
		else phi += 3;
		//	printf("Move Right(press RIGHT key)\n");
		break;
	case GLUT_KEY_UP:
		if (theta == 0) theta = 357;
		else theta -= 3;
		if (theta == 0) theta = 360;
		//	printf("Move Up(press UP key)\n");
		break;
	case GLUT_KEY_DOWN:
		if (theta == 360) theta = 3;
		else theta += 3;
		//	printf("Move Down(press DOWN key)\n");
		break;
	}
	// theta가 y축을 지나가면 Up Vector를 반전시킴
	if (theta > 180)
		up = -1;
	else
		up = 1;
	glutPostRedisplay();
}

/// 마우스 입력에 대한 Callback 함수 ///
void mouse(int button, int state, int x, int y) {
	if (button == 0 && state == GLUT_UP) {
		left = 1; // 좌클릭을 누르고 있는 case
		if (cam_mode == 1)
			pos_x1 = x, pos_y1 = y;
		else if (cam_mode == 2)
			pos_x2 = x, pos_y2 = y;
	}
	else if (button == 2 && state == GLUT_DOWN)
		left = 0; // 좌클릭을 뗀 case
}

/// 마우스 움직임에 대한 Callback 함수 /// : Camera View 이동 구현
void motion(int x, int y) {
	if (left == 1) { // 좌클릭을 누르고 있는 case라면
		if (cam_mode == 1) {
			if (x > pos_x1) { // 오른쪽 drag : turn left
				if (phi == 0) {
					phi = 357; phi_2 = 357;
				}
				else {
					phi -= 3; phi_2 -= 3;
				}
				pos_x1 = x;
			}
			else if (x < pos_x1) { // 왼쪽 drag : turn right
				if (phi == 360) {
					phi = 3; phi_2 = 3;
				}
				else {
					phi += 3; phi_2 += 3;
				}
				pos_x1 = x;
			}
			else if (y < pos_y1) { // 위쪽 drag : turn down
				if (theta == 360) theta = 3;
				else theta += 3;
				pos_y1 = y;
			}
			else if (y > pos_y1) { // 아래쪽 drag : turn up
				if (theta == 0) theta = 357;
				else theta -= 3;
				if (theta == 0) theta = 360;
				pos_y1 = y;
			}
		}
		else if (cam_mode == 2) {
			if (x > pos_x2) { // 오른쪽 drag : turn left
				if (phi == 0) phi = 357;
				else phi -= 3;
				pos_x2 = x;
			}
			else if (x < pos_x2) { // 왼쪽 drag : turn right
				if (phi == 360) phi = 3;
				else phi += 3;
				pos_x2 = x;
			}
			else if (y < pos_y2) { // 위쪽 drag : turn down
				if (theta == 360) theta = 3;
				else theta += 3;
				pos_y2 = y;
			}
			else if (y > pos_y2) { // 아래쪽 drag : turn up
				if (theta == 0) theta = 357;
				else theta -= 3;
				if (theta == 0) theta = 360;
				pos_y2 = y;
			}
		}
	}
	// theta가 y축을 지나가면 Up Vector를 반전시킴
	if (theta > 180)
		up = -1;
	else
		up = 1;
}

void main_menu(int option) {
	if (option == 999) {
		exit(0);
	}
}

void sub_menu(int option) {
	if (option == 1) {
		level = 1;
		printf("Easy selected\n");
	}
	else if (option == 2) {
		level = 2;
		printf("Normal selected\n");
	}
	else if (option == 3) {
		level = 3;
		printf("Hard selected\n");
	}
	// 처음부터 시작
}

int main(int argc, char** argv) {
	srand((unsigned int)time(NULL));
	int submenu1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // DEPTH TEST
	glutInitWindowSize(current_width, current_height);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("RAZER AND ME");
	glutReshapeFunc(resize); // resize Callback 함수
	init(); // 사용자 초기화 함수 

	// 리소스 로드 함수
	get_resource1("obj/mychar1.obj");
	get_resource2("obj/mychar2.obj");
	get_resource3("obj/mychar3.obj");
	get_resource4("obj/mychar4.obj");
	get_resource5("obj/trash1.obj");
	get_resource6("obj/trash2.obj");

	/// Callback 함수 정의 ///
	glutDisplayFunc(draw); // 도형을 그리는 함수
	glutKeyboardFunc(keyboard); // 키보드 입력을 처리
	glutSpecialFunc(special); // 방향키 입력을 처리
	glutMouseWheelFunc(mousewheel); // Mouse Wheel 입력을 처리
	glutMouseFunc(mouse); // Mouse 입력을 처리
	glutMotionFunc(motion); // Mouse 이동 입력을 처리
	glutIdleFunc(idle); // 유휴 상태 처리

	/// Menu 생성 ///
	submenu1 = glutCreateMenu(sub_menu); // Difficulty
	glutAddMenuEntry("Easy", 1);
	glutAddMenuEntry("Normal", 2);
	glutAddMenuEntry("Hard", 3);

	glutCreateMenu(main_menu);
	glutAddSubMenu("Choose Difficulty", submenu1);
	glutAddMenuEntry("Quit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/// Looping 시작 ///
	glutMainLoop();

	return 0;
}