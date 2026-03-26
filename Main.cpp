#include <iostream>
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
    bool running = false;

public:
    void start() {
        start_point = std::chrono::high_resolution_clock::now();
        running = true;
        std::cout << "Таймер запущен..." << std::endl;
    }

    void stop() {
        if (!running) return;

        auto end_point = std::chrono::high_resolution_clock::now();
        running = false;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_point - start_point).count();
        
        double seconds = duration / 1000000.0;

        std::cout << "Прошло времени: " << seconds << " сек. (" << duration << " мкс)" << std::endl;
    }
};

int main() {
    Timer myTimer;

    myTimer.start();

    std::cout << "Нажмите Enter, чтобы остановить таймер..." << std::endl;
    std::cin.get();

    myTimer.stop();

    return 0;
}