#ifndef __HelloCubeNative__main__
#define __HelloCubeNative__main__

#include <stdio.h>
#include <string>
#ifdef __ANDROID__
#include <GLES/gl.h>
#elif __APPLE__
#include <OpenGLES/ES1/gl.h>
#endif

struct saved_state {
	float angle;
	int32_t x;
	int32_t y;
};

struct engine {
	struct android_app* app;

	ASensorManager* sensorManager;
	const ASensor* accelerometerSensor;
	ASensorEventQueue* sensorEventQueue;

	int animating;
	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;
	int32_t width;
	int32_t height;
	struct saved_state state;
};
extern engine* cur_engine;
void tearDownGL();

#include<iostream>
const std::string base_game_path = "/sdcard/sebi_089";
struct MyFile { char* data; int length; };
MyFile load_file(std::string path);
void save_file(MyFile file, std::string path);
void println(std::string text);
std::string float_to_string(float val);
std::string int_to_string(int val);
int millis();

void setup_program();
void draw_program();
void pushMap(double px, double py, double pz);
void popMap();
void background(float r, float g, float b, float a);
/*
void mousePressed();
void mouseReleased();
*/
#define MIN(a,b) ((a) < (b) ? (a) : (b))



class Texture {
public:
	GLuint texture_id;
	void load(std::string path);
	void render(float px, float py, float dx, float dy);
	/*
	int width, height;
	void loadFile(const char* path);
	int* loadPixels();//glGetTexImage
	void updatePixels(int* pixels); //delte recreate
	void delete();
	*/
};

class Mesh {
	void loadFile(const char* path, Texture* t);//obj
	void set(float* vbo, int* ibo, Texture* t);//
	void render();
};
struct Vector3D {
	float x, y, z;
};
class Player {
public:
	double px = 0.0;
	double py = 0.0;
	double pz = 0.0;

	float angx = 0.0;
	float angy = 0.0;
	float angz = 0.0;

	void update();
	bool isPlayerMouse();
	void move2D(float ang, float speed);
	//move
	//angles update
};

void box(float dx, float dy, float dz);
void rect(float px, float py, float dx, float dy);
void text(std::string s, float scale);
void sphere(float r);

extern Player myPlayer;
extern bool isMousePressed;
extern int WIDTH;
extern int HEIGHT;
extern int mouseX;
extern int mouseY;
extern int pmouseX;
extern int pmouseY;

//void download_a_file();
//void play_mp3();
//char* load_a_file();

#endif



//Input Mouse Camera Move
//rect Box
//VBO, IBO load textured
//load png texture+edit it
//Text
//intersect tri sphere+Box physics Test

// sound .mp3
// Load Resource
// Download from URL
// Server connect

//Round Grid
//render engine combile static and dynamic. direct Render
//chunk load unload eninge

