#include <cmath>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <sstream>
#include <termios.h>
#include <unistd.h>
#include <vector>

using namespace std;

// Chirp信号参数
float start_freq = 100;    // 起始频率
float end_freq = 1000;     // 终止频率
float duration = 1;        // 信号时长
float sample_rate = 44100; // 采样率

// 线程控制变量
bool running = false;
pthread_t thread_id;

// 获取按键输入
int getch() {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

// Chirp信号线程
void *chirp_thread(void *arg) {
  float t = 0;
  float delta_f = (end_freq - start_freq) / duration;
  float delta_t = 1 / sample_rate;
  vector<float> values;
  vector<float> times;
  while (running && t < duration) {
    float freq = start_freq + delta_f * t;
    float amplitude = sin(2 * M_PI * freq * t);
    values.push_back(amplitude);
    times.push_back(t);
    t += delta_t;
    usleep(1000);
  }

  // 保存到CSV文件
  ofstream file("output.csv");
  if (file.is_open()) {
    file << "Time,Value\n";
    for (int i = 0; i < values.size(); i++) {
      file << times[i] << "," << values[i] << "\n";
    }
    file.close();
    cout << "Output saved to output.csv" << endl;
  } else {
    cout << "Failed to save output to file" << endl;
  }

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  // 解析命令行参数
  if (argc > 1) {
    start_freq = atof(argv[1]);
  }
  if (argc > 2) {
    end_freq = atof(argv[2]);
  }
  if (argc > 3) {
    duration = atof(argv[3]);
  }
  if (argc > 4) {
    sample_rate = atof(argv[4]);
  }

  // 启动线程
  running = true;
  pthread_create(&thread_id, NULL, chirp_thread, NULL);
  cout << "Press any key to stop..." << endl;
  getch();
  running = false;
  pthread_join(thread_id, NULL);

  return 0;
}